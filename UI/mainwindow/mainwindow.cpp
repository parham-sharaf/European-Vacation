#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "../ModdedLineEdit/moddedlineedit.h"
#include "../TreeWidget/Interface.h"
#include "../Map/Europe_png.h"

Interface uiInterface;

std::vector<Map*> Map::euroMap;

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent)
        , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("European Vacation Application");
    pix.loadFromData(Europe_png, Europe_png_len);


    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    scene->addPixmap(pix);

    ui->tabWidget->setTabEnabled(1, false);

    Map *AmsterdamLoc = new Map("Amsterdam", 435, 625);
    scene->addItem(AmsterdamLoc);
    Map::euroMap.push_back(AmsterdamLoc);

    Map *BerlinLoc = new Map("Berlin", 600, 620);
    scene->addItem(BerlinLoc);
    Map::euroMap.push_back(BerlinLoc);

    Map *BrusselsLoc = new Map("Brussels", 420, 660);
    scene->addItem(BrusselsLoc);
    Map::euroMap.push_back(BrusselsLoc);

    Map *BudapestLoc = new Map("Budapest", 720, 780);
    scene->addItem(BudapestLoc);
    Map::euroMap.push_back(BudapestLoc);

    Map *HamburgLoc = new Map("Hamburg", 535, 590);
    scene->addItem(HamburgLoc);
    Map::euroMap.push_back(HamburgLoc);

    Map *LisbonLoc = new Map("Lisbon", 40, 955);
    scene->addItem(LisbonLoc);
    Map::euroMap.push_back(LisbonLoc);

    Map *LondonLoc = new Map("London", 340, 630);
    scene->addItem(LondonLoc);
    Map::euroMap.push_back(LondonLoc);

    Map *MadridLoc = new Map("Madrid", 185, 960);
    scene->addItem(MadridLoc);
    Map::euroMap.push_back(MadridLoc);

    Map *ParisLoc = new Map("Paris", 385, 715);
    scene->addItem(ParisLoc);
    Map::euroMap.push_back(ParisLoc);

    Map *PragueLoc = new Map("Prague", 620, 700);
    scene->addItem(PragueLoc);
    Map::euroMap.push_back(PragueLoc);

    Map *RomeLoc = new Map("Rome", 565, 950);
    scene->addItem(RomeLoc);
    Map::euroMap.push_back(RomeLoc);

    Map *ViennaLoc = new Map("Vienna", 655, 755);
    scene->addItem(ViennaLoc);
    Map::euroMap.push_back(ViennaLoc);

    Map *StockholmLoc = new Map("Stockholm", 680, 410);
    scene->addItem(StockholmLoc);
    Map::euroMap.push_back(StockholmLoc);

    myCities.ReadData();


    ui->citiesTreeWidget->setHeaderLabels(QStringList() << "Cities & their Foods" << "Cost($)" << "Distance to Berlin (km)");
    ui->citiesTreeWidget->header()->setDefaultAlignment(Qt::AlignCenter);

    myCities.ReadData();

    // Special Line Edit for # Cities from London
    connect(ui->citiesFromLondon_LineEdit, SIGNAL(textChanged(const QString&)), this, SLOT(on_citiesFromLondon_LineEdit_textEdited(const QString&)));

    // INPUTTING ITEMS INTO TREE WIDGET
    ui->updatepurchases_pushButton->setDisabled(true);
    ui->totalDistanceTraveled_LineEdit->setReadOnly(true);
    ui->totalDistanceTraveled_LineEdit->setAlignment(Qt::AlignHCenter);
    ui->totalspent_LineEdit->setReadOnly(true);

    uiInterface.createTravelerTree(ui, myCities);
    connect(ui->citiesTreeWidget, SIGNAL(itemChanged(QTreeWidgetItem*, int)), this, SLOT(itemChanged(QTreeWidgetItem*, int)));
    connect(ui->citiesTreeWidget, SIGNAL(itemChanged(QTreeWidgetItem*, int)), this, SLOT(setPlan(QTreeWidgetItem*, int)));
    connect(ui->submitPlan, SIGNAL(clicked()), this, SLOT(on_submitPlan_clicked()), Qt::UniqueConnection);
    connect(ui->clearPlan, SIGNAL(clicked()), this, SLOT(on_clearPlan_clicked()), Qt::UniqueConnection);

    uiInterface.createAdminTree(ui, newAdmin, myCities);
    connect(ui->addCityButton, SIGNAL(clicked()), this, SLOT(adminNewCity()));
    connect(ui->cityComboBox, SIGNAL(currentTextChanged(const QString)), this, SLOT(updateChangePriceFoodsComboBox()));
    connect(ui->changeFoodPriceButton, SIGNAL(clicked()), this, SLOT(adminChangePrice()));
    connect(ui->addFoodButton, SIGNAL(clicked()), this, SLOT(adminAddFood()));
    connect(ui->delFoodCityComboBox, SIGNAL(currentTextChanged(const QString)), this, SLOT(updateDelFoodsComboBox()));
    connect(ui->delFoodButton, SIGNAL(clicked()), this, SLOT(adminDelFood()));
}

void MainWindow::adminNewCity() {
    newAdmin.AddNewCity(ui->newCityComboBox->currentText().toStdString());

    myCities.ReadData();
    ui->newCityComboBox->clear();

    for (auto& group : newAdmin.readNewCities()) {
        if (myCities.GetEuroCities().find(group) == myCities.GetEuroCities().end())
            ui->newCityComboBox->addItem(QString::fromStdString(group));
    }

    ui->cityComboBox->clear();
    ui->addFoodCityComboBox->clear();
    ui->delFoodCityComboBox->clear();
    for (auto& group : newAdmin.readAvailableCities()) {
        ui->cityComboBox->addItem(QString::fromStdString(group));
        ui->addFoodCityComboBox->addItem(QString::fromStdString(group));
        ui->delFoodCityComboBox->addItem(QString::fromStdString(group));
    }
}

void MainWindow::adminChangePrice() {
    city = ui->cityComboBox->currentText().toStdString();
    food = ui->tradFoodComboBox->currentText().toStdString();
    price = ui->priceDoubleSpinBox->value();

    newAdmin.ChangePrice(city, food, price);
}

void MainWindow::adminAddFood() {
    city = ui->addFoodCityComboBox->currentText().toStdString();
    food = ui->newFoodLineEdit->displayText().toStdString();
    price = ui->addFoodPriceDoubleSpinBox->value();

    if (food != "" && price != 0)
        newAdmin.AddNewTradFood(city, food, price);

    ui->delTradFoodComboBox->clear();
    for (auto& group : newAdmin.readFoodFromCity(ui->delFoodCityComboBox->currentText().toStdString())) ui->delTradFoodComboBox->addItem(QString::fromStdString(group));

    ui->tradFoodComboBox->clear();
    for (auto& group : newAdmin.readFoodFromCity(ui->cityComboBox->currentText().toStdString())) ui->tradFoodComboBox->addItem(QString::fromStdString(group));
}

void MainWindow::adminDelFood() {
    city = ui->delFoodCityComboBox->currentText().toStdString();
    food = ui->delTradFoodComboBox->currentText().toStdString();

    newAdmin.RemoveTradFood(city, food);

    ui->delTradFoodComboBox->clear();
    for (auto& group : newAdmin.readFoodFromCity(ui->delFoodCityComboBox->currentText().toStdString())) ui->delTradFoodComboBox->addItem(QString::fromStdString(group));

    ui->tradFoodComboBox->clear();
    for (auto& group : newAdmin.readFoodFromCity(ui->cityComboBox->currentText().toStdString())) ui->tradFoodComboBox->addItem(QString::fromStdString(group));
}

void MainWindow::updateChangePriceFoodsComboBox() {
    ui->tradFoodComboBox->clear();
    for (auto& group : newAdmin.readFoodFromCity(ui->cityComboBox->currentText().toStdString())) ui->tradFoodComboBox->addItem(QString::fromStdString(group));
}

void MainWindow::updateDelFoodsComboBox() {
    ui->delTradFoodComboBox->clear();
    for (auto& group : newAdmin.readFoodFromCity(ui->delFoodCityComboBox->currentText().toStdString())) ui->delTradFoodComboBox->addItem(QString::fromStdString(group));
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::itemChanged(QTreeWidgetItem* item, int col)
{
    if (item->checkState(0) == Qt::Checked) ++itemsChecked;
    else --itemsChecked;
    if (itemsChecked > 0)
        ui->citiesFromLondon_LineEdit->setDisabled(true);
    else
        ui->citiesFromLondon_LineEdit->setDisabled(false);
}

void MainWindow::setPlan(QTreeWidgetItem* item, int col)
{
    if (item->checkState(0) == Qt::Checked) {
        if (myCities.GetTravelPlan().empty())
            for (auto & dot: Map::euroMap) {
                if (dot->GetLocation() == item->text(0).toStdString()) {
                    dot->setPressed(true);
                    dot->QGraphicsItem::update();
                    myCities.setStartingCity(dot->GetLocation());
                }
            }

        myCities.AddCity(item->text(0).toStdString());
        for (auto & city: myCities.GetTravelPlan()) cout << city.first << "[" << city.second->distance << "]" << " --> ";
        cout << endl;
        if (myCities.GetTravelPlan().size() != 1) {
            for (auto &dot: Map::euroMap) {
                if (dot->GetLocation() == item->text(0).toStdString())
                    dot->setIsSelected(true);
            }
        }
    }
    else if (item->checkState(0) != Qt::Checked) {
        myCities.EraseCity(item->text(0).toStdString());
        for (auto & city: myCities.GetTravelPlan()) cout << city.first << "[" << city.second->distance << "]" << " --> ";
        cout << endl;
        for (auto & dot: Map::euroMap) {
            if (dot->GetLocation() == item->text(0).toStdString()) {
                dot->setPressed(false);
                dot->setIsSelected(false);
            }
        }
    }
}

void MainWindow::on_submitPlan_clicked()
{
    uiInterface.submitPlanTree(ui, myCities);
    connect(ui->updatepurchases_pushButton, SIGNAL(clicked()), this, SLOT(updateSpent()));
}

void MainWindow::on_actionLogin_triggered()
{
    login log;
    ui->tabWidget->setTabEnabled(0, log.GetCred());
    ui->tabWidget->setTabEnabled(1, !log.GetCred());
    ui->tabWidget->setCurrentIndex(log.GetCred());

    log.setModal(true);
    log.exec();
}


void MainWindow::on_updatepurchases_pushButton_clicked()
{

}

void MainWindow::updateSpent()
{
    QTreeWidgetItemIterator it(ui->planTreeWidget, QTreeWidgetItemIterator::NoChildren);
    double totalSpentOnTrip = 0;
    double totalSpentAtCity = 0;
    int totalBoughtAtCity = 0;
    int index = 0;
    while (*it) {
        if (ui->planTreeWidget->itemWidget(*it, 2))
        {
            totalSpentOnTrip += ui->planTreeWidget->itemWidget(*it, 1)->accessibleName().toDouble() * ui->planTreeWidget->itemWidget(*it, 2)->accessibleName().toDouble();
            totalSpentAtCity += ui->planTreeWidget->itemWidget(*it, 1)->accessibleName().toDouble() * ui->planTreeWidget->itemWidget(*it, 2)->accessibleName().toDouble();
            totalBoughtAtCity += ui->planTreeWidget->itemWidget(*it, 2)->accessibleName().toInt();
            index++;
        }
        if (repurchase && index == (*it)->parent()->childCount() - 2)
        {
            (*it)->parent()->takeChild((*it)->parent()->childCount() - 1);
            (*it)->parent()->takeChild((*it)->parent()->childCount() - 1);
        }
        if (index == (*it)->parent()->childCount() && (*it)->parent()->childCount() > 0 /*&& repurchase == false*/)
        {
            QTreeWidgetItem* boughtAtCity = new QTreeWidgetItem();
            QLineEdit* boughtAtCity_lineedit = new QLineEdit();
            boughtAtCity_lineedit->setText(QString::number(totalBoughtAtCity));
            boughtAtCity_lineedit->setReadOnly(true);
            boughtAtCity_lineedit->setAlignment(Qt::AlignHCenter);
            boughtAtCity_lineedit->setStyleSheet("QLineEdit {color : black; border: 1px solid black}");
            boughtAtCity->setText(0, "# of Foods Bought:");
            (*it)->parent()->addChild(boughtAtCity);
            ui->planTreeWidget->setItemWidget(boughtAtCity, 1, boughtAtCity_lineedit);

            QTreeWidgetItem* spentAtCity = new QTreeWidgetItem();
            QLineEdit* spentAtCity_lineedit = new QLineEdit();
            spentAtCity_lineedit->setText(QString::number(totalSpentAtCity, 'f', 2));
            spentAtCity_lineedit->setReadOnly(true);
            spentAtCity_lineedit->setAlignment(Qt::AlignHCenter);
            spentAtCity_lineedit->setStyleSheet("QLineEdit {color : black; border: 1px solid black}");
            spentAtCity->setText(0, "Amount Spent (USD)");
            (*it)->parent()->addChild(spentAtCity);
            ui->planTreeWidget->setItemWidget(spentAtCity, 1, spentAtCity_lineedit);

            totalBoughtAtCity = 0;
            totalSpentAtCity = 0;
            index = 0;
            ++it;
        }
        ++it;
    }

    repurchase = true;
    ui->totalspent_LineEdit->setText(QString::number(totalSpentOnTrip, 'f', 2));
    ui->totalspent_LineEdit->setAlignment(Qt::AlignHCenter);
}

void MainWindow::on_clearPlan_clicked() {
    myCities.GetShortTravelPlan().clear();
    myCities.GetTravelPlan().clear();
    for (auto & dot: Map::euroMap)
        if (myCities.GetEuroCities().find(dot->GetLocation()) != myCities.GetEuroCities().end()) {
            dot->setAvailability(true);
            dot->setIsSelected(false);
        }

    disconnect(ui->citiesTreeWidget, SIGNAL(itemChanged(QTreeWidgetItem*, int)), this, SLOT(itemChanged(QTreeWidgetItem*, int)));
    disconnect(ui->citiesTreeWidget, SIGNAL(itemChanged(QTreeWidgetItem*, int)), this, SLOT(setPlan(QTreeWidgetItem*, int)));
    for (int i = 0; ui->citiesTreeWidget->topLevelItem(i); i++)
        ui->citiesTreeWidget->topLevelItem(i)->setCheckState(0, Qt::Unchecked);
    connect(ui->citiesTreeWidget, SIGNAL(itemChanged(QTreeWidgetItem*, int)), this, SLOT(itemChanged(QTreeWidgetItem*, int)));
    connect(ui->citiesTreeWidget, SIGNAL(itemChanged(QTreeWidgetItem*, int)), this, SLOT(setPlan(QTreeWidgetItem*, int)));

    repurchase = false;
    ui->citiesFromLondon_LineEdit->setDisabled(false);
    ui->totalDistanceTraveled_LineEdit->setText("");
    ui->totalspent_LineEdit->setText("");
    ui->citiesFromLondon_LineEdit->setText("");
    ui->planTreeWidget->clear();
    ui->updatepurchases_pushButton->setDisabled(true);
    ui->updatepurchases_pushButton->setStyleSheet("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1,   stop:0 rgba(215, 215, 215, 255), stop:1 rgba(215, 215, 215, 255));");
}

void MainWindow::on_citiesFromLondon_LineEdit_textEdited(const QString &arg1)
{
    ui->citiesTreeWidget->blockSignals(true);
    myCities.GetShortTravelPlan().clear();
    for (int i = 0; ui->citiesTreeWidget->topLevelItem(i); i++)
    {
        ui->citiesTreeWidget->topLevelItem(i)->setCheckState(0, Qt::Unchecked);
    }

    if (arg1.toStdString() != "0" && !arg1.toStdString().empty())
    {
        for (int i = 0; i < ui->citiesTreeWidget->topLevelItemCount(); i++)
            ui->citiesTreeWidget->topLevelItem(i)->setDisabled(true);
        ui->citiesTreeWidget->blockSignals(false);

        myCities.BaseCityPlan("London", ui->citiesFromLondon_LineEdit->text().toInt());
        disconnect(ui->citiesTreeWidget, SIGNAL(itemChanged(QTreeWidgetItem*, int)), this, SLOT(itemChanged(QTreeWidgetItem*, int)));
        for (auto & cityInPlan: myCities.GetShortTravelPlan())
        {
            for (int i = 0; ui->citiesTreeWidget->topLevelItem(i); i++)
            {
                if (ui->citiesTreeWidget->topLevelItem(i)->text(0).toStdString() == cityInPlan->name)
                    ui->citiesTreeWidget->topLevelItem(i)->setCheckState(0, Qt::Checked);
            }
        }
        connect(ui->citiesTreeWidget, SIGNAL(itemChanged(QTreeWidgetItem*, int)), this, SLOT(itemChanged(QTreeWidgetItem*, int)));
    }
    else
    {
        on_clearPlan_clicked();
        if(arg1.toStdString().empty())
        {
            for (int i = 0; ui->citiesTreeWidget->topLevelItem(i); i++)
                ui->citiesTreeWidget->topLevelItem(i)->setDisabled(false);
        }
    }
    ui->citiesTreeWidget->blockSignals(false);
}

void MainWindow::on_adminSubmit_clicked()
{
    myCities.ReadData();
    ui->citiesTreeWidget->clear();
    uiInterface.createTravelerTree(ui, myCities);
    ui->tabWidget->setTabEnabled(0, true);
    ui->tabWidget->setTabEnabled(1, false);
    ui->tabWidget->setCurrentIndex(false);

    for (auto & dot: Map::euroMap)
        if (myCities.GetEuroCities().find(dot->GetLocation()) != myCities.GetEuroCities().end()) {
            dot->setAvailability(true);
            dot->setIsSelected(false);
        }
}
