#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "UI/ModdedLineEdit/moddedlineedit.h"

using namespace std;
std::vector<Map*> Map::euroMap;

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

    Admin newAdmin;
    newAdmin.AddNewCity("Vienna");

    ui->citiesTreeWidget->setHeaderLabels(QStringList() << "Cities & their Foods" << "Cost($)" << "Distance to Berlin (km)");
    ui->citiesTreeWidget->header()->setDefaultAlignment(Qt::AlignCenter);
    //ui->citiesTreeWidget->setHeaderHidden(true);

    myCities.ReadData();


    // INPUTTING ITEMS INTO TREE WIDGET
    ui->updatepurchases_pushButton->setDisabled(true);
    ui->totalDistanceTraveled_LineEdit->setReadOnly(true);
    ui->totalDistanceTraveled_LineEdit->setAlignment(Qt::AlignHCenter);
    ui->totalspent_LineEdit->setReadOnly(true);

    // setting up tree widget
    for (auto & city : myCities.GetEuroCities())
    {
        cities = new QTreeWidgetItem;
        cities->setText(0, QString::fromStdString(city.first));
        for (auto & foodItem: city.second->tradFoodList)
        {
            auto* food = new QTreeWidgetItem;
            auto* food_costLineEdit = new QLineEdit;

            food->setText(0, QString::fromStdString(foodItem.foodName));
            food_costLineEdit->setText(QString::number(foodItem.cost, 'f', 2));
            food_costLineEdit->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Minimum);

            //check for admin perms here
            food_costLineEdit->setDisabled(true);
            food_costLineEdit->setStyleSheet("QLineEdit {color : black; border: 1px solid black;}");
            food_costLineEdit->setAlignment(Qt::AlignHCenter);

            cities->addChild(food);

            ui->citiesTreeWidget->setItemWidget(food, 1, food_costLineEdit);

        }
        cities->setData(0, Qt::CheckStateRole, Qt::Unchecked);
        cities->setFlags(cities->flags() | Qt::ItemIsUserCheckable);
        ui->citiesTreeWidget->insertTopLevelItem(0, cities);

        for (auto & i : myCities.GetDistancesFromBerlin())
        {
            if (i.at(0) == cities->text(0).toStdString())
            {
                QLineEdit* distFromBerlin = new QLineEdit();
                distFromBerlin->setText(QString::fromStdString(i.at(1)));
                distFromBerlin->setAlignment(Qt::AlignHCenter);
                distFromBerlin->setStyleSheet("border: 1px solid black;");
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
    connect(ui->clearPlan, SIGNAL(clicked()), this, SLOT(on_clearPlan_clicked()), Qt::UniqueConnection);
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
            for (auto & dot: Map::euroMap) {
                if (dot->GetLocation() == item->text(0).toStdString()) {
                    dot->setPressed(true);
                    cout << Map::getStartingCity() << endl;
                    cout << dot->GetLocation() << endl;
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
        cout << "Removed: " << item->text(0).toStdString() << endl;
        for (auto & city: myCities.GetTravelPlan()) cout << city.first << "[" << city.second->distance << "]" << " --> ";
        cout << endl;
        for (auto & dot: Map::euroMap) {
            if (dot->GetLocation() == item->text(0).toStdString()) {
                dot->setPressed(false);
            }
        }
    }
    cout << Map::getStartingCity() << endl;
}

void MainWindow::on_submitPlan_clicked()
{
    myCities.setStartingCity(Map::getStartingCity());
    myCities.ShortestPath();
    for (auto & city: myCities.GetTravelPlan()) cout << city.first << "[" << city.second->distance << "]" << " --> ";
    cout << endl;
    ui->totalDistanceTraveled_LineEdit->setText(QString::number(myCities.GetTotalDistance()));

    // setting up Tree Widget
    ui->planTreeWidget->clear();
    ui->updatepurchases_pushButton->setStyleSheet("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1,   stop:0 rgba(60, 186, 162, 255), stop:1 rgba(98, 211, 162, 255));");
    ui->totalspent_LineEdit->setText("0.00");
    ui->updatepurchases_pushButton->setDisabled(false);

    ui->planTreeWidget->setHeaderLabels(QStringList() << "Cities & their Foods" << "Cost($)" << "Quantity to Buy");
    ui->planTreeWidget->setColumnCount(3);
    ui->planTreeWidget->header()->setDefaultAlignment(Qt::AlignCenter);

    int orderInTrip = 1;
    for (auto & city: myCities.GetShortTravelPlan())
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
            food_costLineEdit->setStyleSheet("QLineEdit {color : black; border: 1px solid black}");
            food_costLineEdit->setStyleSheet("QLineEdit {color : black; }");
            food_costLineEdit->setAlignment(Qt::AlignHCenter);

            quantity_foodLineEdit->setText(QString::number(0));
            quantity_foodLineEdit->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Minimum);
            quantity_foodLineEdit->setAlignment(Qt::AlignHCenter);
            quantity_foodLineEdit->setStyleSheet("QLineEdit {color : black; border: 1px solid black}");

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
            spentAtCity_lineedit->setStyleSheet("QLineEdit {color : black; border: 1px solid black}");
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

void MainWindow::on_clearPlan_clicked() {
    myCities.GetShortTravelPlan().clear();
    myCities.GetTravelPlan().clear();
    for (auto &dot: Map::euroMap) {
        dot->setAvailability(true);
        dot->setIsSelected(false);
    }
//    for (int i = 0; i < cities->childCount(); i++)
//        cities->child(i)->setCheckState(0, Qt::Unchecked);
//    ui->citiesTreeWidget->topLevelItem(0)->parent()->child(5)->setCheckState(0, Qt::Unchecked);
}

