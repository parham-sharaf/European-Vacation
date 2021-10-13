#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "moddedlineedit.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent)
        , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("European Vacation Application");
    pix.load("./UI/Europe_countries_map_en_2.png");


    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    scene->addPixmap(pix);

    ui->tabWidget->setTabEnabled(1, false);

    Map *AmsterdamLoc = new Map("Amsterdam");
    AmsterdamLoc->setDotCoord(435, 625);
    scene->addItem(AmsterdamLoc);
    euroMap.push_back(AmsterdamLoc);

    Map *BerlinLoc = new Map("Berlin");
    BerlinLoc->setDotCoord(600, 620);
    scene->addItem(BerlinLoc);
    euroMap.push_back(BerlinLoc);

    Map *BrusselsLoc = new Map("Brussels");
    BrusselsLoc->setDotCoord(420, 660);
    scene->addItem(BrusselsLoc);
    euroMap.push_back(BrusselsLoc);

    Map *BudapestLoc = new Map("Budapest");
    BudapestLoc->setDotCoord(720, 780);
    scene->addItem(BudapestLoc);
    euroMap.push_back(BudapestLoc);

    Map *HamburgLoc = new Map("Hamburg");
    HamburgLoc->setDotCoord(535, 590);
    scene->addItem(HamburgLoc);
    euroMap.push_back(HamburgLoc);

    Map *LisbonLoc = new Map("Lisbon");
    LisbonLoc->setDotCoord(40, 955);
    scene->addItem(LisbonLoc);
    euroMap.push_back(LisbonLoc);

    Map *LondonLoc = new Map("London");
    LondonLoc->setDotCoord(340, 630);
    scene->addItem(LondonLoc);
    euroMap.push_back(LondonLoc);

    Map *MadridLoc = new Map("Madrid");
    MadridLoc->setDotCoord(185, 960);
    scene->addItem(MadridLoc);
    euroMap.push_back(MadridLoc);

    Map *ParisLoc = new Map("Paris");
    ParisLoc->setDotCoord(385, 715);
    scene->addItem(ParisLoc);
    euroMap.push_back(ParisLoc);

    Map *PragueLoc = new Map("Prague");
    PragueLoc->setDotCoord(620, 700);
    scene->addItem(PragueLoc);
    euroMap.push_back(PragueLoc);

    Map *RomeLoc = new Map("Rome");
    RomeLoc->setDotCoord(565, 950);
    scene->addItem(RomeLoc);
    euroMap.push_back(RomeLoc);

    Admin newAdmin;
    newAdmin.AddNewCity("Vienna");

    ui->citiesTreeWidget->setHeaderLabels(QStringList() << "Cities & their foods" << "Cost($)");
    ui->citiesTreeWidget->setColumnCount(2);
    //ui->citiesTreeWidget->setHeaderHidden(true);

    myCities.ReadData();

    // testing buying 5 stroopwaffles from amsterdam
    myCities.GetEuroCities().at(0)->tradFoodList.at(0).purchase(5);

    // INPUTTING ITEMS INTO TREE WIDGET
    ui->updatepurchases_pushButton->setDisabled(true);
    ui->totalDistanceTraveled_LineEdit->setReadOnly(true);
    ui->totalDistanceTraveled_LineEdit->setAlignment(Qt::AlignHCenter);
    ui->totalspent_LineEdit->setReadOnly(true);

    // setting up tree widget
    for (auto & city : myCities.GetEuroCities())
    {
        auto* cities = new QTreeWidgetItem;
        cities->setText(0, QString::fromStdString(city->name));
        for (auto & dot: euroMap) {
            if (dot->GetLocation() == city->name)
                dot->setAvailability(true);
        }
        for (auto & foodItem: city->tradFoodList)
        {
            auto* food = new QTreeWidgetItem;
            auto* food_costLineEdit = new QLineEdit;

            food->setText(0, QString::fromStdString(foodItem.foodName));
            food_costLineEdit->setText(QString::number(foodItem.cost, 'f', 2));
            food_costLineEdit->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Minimum);

            //check for admin perms here
            food_costLineEdit->setDisabled(true);
            food_costLineEdit->setStyleSheet("QLineEdit {color : black; }");
            food_costLineEdit->setAlignment(Qt::AlignHCenter);

            cities->addChild(food);

            ui->citiesTreeWidget->setItemWidget(food, 1, food_costLineEdit);

        }
        cities->setData(0, Qt::CheckStateRole, Qt::Unchecked);
        cities->setFlags(cities->flags() | Qt::ItemIsUserCheckable);
        ui->citiesTreeWidget->insertTopLevelItem(0, cities);

        for (int i = 0; i < myCities.GetDistancesFromBerlin().size(); i++)
        {
            if (myCities.GetDistancesFromBerlin().at(i).at(0) == cities->text(0).toStdString())
            {
                QLineEdit* distFromBerlin = new QLineEdit();
                distFromBerlin->setText(QString::fromStdString(myCities.GetDistancesFromBerlin().at(i).at(1)));
                distFromBerlin->setAlignment(Qt::AlignHCenter);
                distFromBerlin->setReadOnly(true);

                ui->citiesTreeWidget->setItemWidget(cities, 2, distFromBerlin);
            }
        }
    }

    ui->citiesTreeWidget->setColumnWidth(0, 193);
    ui->citiesTreeWidget->setColumnWidth(1, 50);
    ui->citiesTreeWidget->setColumnWidth(2, 100);
    connect(ui->citiesTreeWidget, SIGNAL(itemChanged(QTreeWidgetItem*, int)), this, SLOT(itemChanged(QTreeWidgetItem*, int)));
    connect(ui->citiesTreeWidget, SIGNAL(itemChanged(QTreeWidgetItem*, int)), this, SLOT(setPlan(QTreeWidgetItem*, int)));
    connect(ui->submitPlan, SIGNAL(clicked()), this, SLOT(on_submitPlan_clicked()), Qt::UniqueConnection);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::recursiveChecks(QTreeWidgetItem* parent)
{
    Qt::CheckState checkState = parent->checkState(0);
    for(int i = 0; i < parent->childCount(); ++i)
    {
        parent->child(i)->setCheckState(0, checkState);
        recursiveChecks(parent->child(i));
    }
}

void MainWindow::itemChanged(QTreeWidgetItem* item, int col)
{

}

void MainWindow::setPlan(QTreeWidgetItem* item, int col)
{
    if (item->checkState(0) == Qt::Checked) {
        if (myCities.GetTravelPlan().empty())
            myCities.setStartingCity(item->text(0).toStdString());
        myCities.AddCity(item->text(0).toStdString(), myCities.GetTravelPlan());
        for (auto & city: myCities.GetTravelPlan()) cout << city->name << "[" << city->distance << "]" << " --> ";
        cout << endl;
        for (auto & dot: euroMap) {
            if (dot->GetLocation() == item->text(0).toStdString())
                dot->setIsSelected(true);
        }
    }
    else if (item->checkState(0) != Qt::Checked) {
        myCities.EraseCity(item->text(0).toStdString(), myCities.GetTravelPlan());
        cout << "Removed: " << item->text(0).toStdString() << endl;
        for (auto & city: myCities.GetTravelPlan()) cout << city->name << "[" << city->distance << "]" << " --> ";
        cout << endl;
        for (auto & dot: euroMap) {
            if (dot->GetLocation() == item->text(0).toStdString())
                dot->setIsSelected(false);
        }
    }
}

void MainWindow::on_submitPlan_clicked()
{
    myCities.ShortestPath();
    for (auto & city: myCities.GetTravelPlan()) cout << city->name << "[" << city->distance << "]" << " --> ";
    cout << endl;
    cout << "Total Distance travelled: " << myCities.GetTotalDistance(myCities.GetTravelPlan()) << endl;
    ui->totalDistanceTraveled_LineEdit->setText(QString::number(myCities.GetTotalDistance(myCities.GetTravelPlan())));

    // setting up Tree Widget
    ui->planTreeWidget->clear();
    ui->totalspent_LineEdit->setText("0.00");
    ui->updatepurchases_pushButton->setDisabled(false);

    ui->planTreeWidget->setHeaderLabels(QStringList() << "Cities & their Foods" << "Cost($)" << "Quantity to Buy");
    ui->planTreeWidget->setColumnCount(3);
    ui->planTreeWidget->header()->setDefaultAlignment(Qt::AlignCenter);

    int orderInTrip = 1;
    for (auto & city: myCities.GetTravelPlan())
    {
        QTreeWidgetItem* newCity = new QTreeWidgetItem();
        newCity->setText(0, QString::number(orderInTrip) + ". " + QString::fromStdString(city->name));
        ++orderInTrip;
        ui->planTreeWidget->addTopLevelItem(newCity);

        for (auto & foodItem: city->tradFoodList)
        {
            auto* food = new QTreeWidgetItem;
            auto* food_costLineEdit = new moddedLineEdit;
            auto* quantity_foodLineEdit = new moddedLineEdit;

            connect(food_costLineEdit, SIGNAL(textChanged(const QString &)), food_costLineEdit, SLOT(updateAccessibleName()));
            food->setText(0, QString::fromStdString(foodItem.foodName));
            food_costLineEdit->setText(QString::number(foodItem.cost, 'f', 2));
            food_costLineEdit->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Minimum);

            //check for admin perms here
            food_costLineEdit->setDisabled(true);
            food_costLineEdit->setStyleSheet("QLineEdit {color : black; }");
            food_costLineEdit->setAlignment(Qt::AlignHCenter);

            quantity_foodLineEdit->setText(QString::number(0));
            quantity_foodLineEdit->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Minimum);
            quantity_foodLineEdit->setAlignment(Qt::AlignHCenter);

            newCity->addChild(food);
            ui->planTreeWidget->setItemWidget(food, 1, food_costLineEdit);
            ui->planTreeWidget->setItemWidget(food, 2, quantity_foodLineEdit);

            // testing set accessible name
            ui->planTreeWidget->itemWidget(food, 2)->setAccessibleName("0");
            connect(quantity_foodLineEdit, SIGNAL(textChanged(const QString &)), quantity_foodLineEdit, SLOT(updateAccessibleName()));
        }
    }
    ui->planTreeWidget->setColumnWidth(0, 193);
    ui->planTreeWidget->setColumnWidth(1, 50);
    ui->planTreeWidget->setColumnWidth(2, 100);

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
    int test = 0;
    while (*it) {
        if (ui->planTreeWidget->itemWidget(*it, 2))
        {
            totalSpentOnTrip += ui->planTreeWidget->itemWidget(*it, 1)->accessibleName().toDouble() * ui->planTreeWidget->itemWidget(*it, 2)->accessibleName().toDouble();
            totalSpentAtCity += ui->planTreeWidget->itemWidget(*it, 1)->accessibleName().toDouble() * ui->planTreeWidget->itemWidget(*it, 2)->accessibleName().toDouble();
            test++;
        }
        if (repurchase && test == it.operator*()->parent()->childCount() - 1)
        {
           it.operator*()->parent()->takeChild(it.operator*()->parent()->childCount() - 1);
        }
        if (test == it.operator*()->parent()->childCount() && it.operator*()->parent()->childCount() > 0)
        {
            QTreeWidgetItem* spentAtCity = new QTreeWidgetItem();
            QLineEdit* spentAtCity_lineedit = new QLineEdit();
            spentAtCity_lineedit->setText(QString::number(totalSpentAtCity, 'f', 2));
            spentAtCity_lineedit->setReadOnly(true);
            spentAtCity_lineedit->setAlignment(Qt::AlignHCenter);

            spentAtCity->setText(0, "Amount Spent (USD)");
            it.operator*()->parent()->addChild(spentAtCity);
            ui->planTreeWidget->setItemWidget(spentAtCity, 1, spentAtCity_lineedit);
            totalSpentAtCity = 0;
            test = 0;
            ++it;
        }
        ++it;
    }

    repurchase = true;
    ui->totalspent_LineEdit->setText(QString::number(totalSpentOnTrip, 'f', 2));
    ui->totalspent_LineEdit->setAlignment(Qt::AlignHCenter);
}

