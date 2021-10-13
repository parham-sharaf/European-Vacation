#include "mainwindow.h"
#include "./ui_mainwindow.h"


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
//    myMap = new Map();
//    scene->addItem(myMap);

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

    // setting up tree widget

    ui->citiesTreeWidget->setHeaderLabels(QStringList() << "Cities & their foods" << "Cost($)");
    ui->citiesTreeWidget->setColumnCount(2);
    //ui->citiesTreeWidget->setHeaderHidden(true);

    myCities.ReadData();

    // testing buying 5 stroopwaffles from amsterdam
    myCities.GetEuroCities().at(0)->tradFoodList.at(0).purchase(5);

    // INPUTTING ITEMS INTO TREE WIDGET
    for (auto & city : myCities.GetEuroCities())
    {
        auto* cities = new QTreeWidgetItem;
        cities->setText(0, QString::fromStdString(city->name));
        for (auto & foodItem: city->tradFoodList)
        {
            auto* food = new QTreeWidgetItem;
            auto* food_costLineEdit = new QLineEdit;
            auto* quantity_foodLineEdit = new QLineEdit;

            food->setText(0, QString::fromStdString(foodItem.foodName));
            food_costLineEdit->setText(QString::number(foodItem.cost, 'f', 2));
            food_costLineEdit->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Minimum);

            //check for admin perms here
            food_costLineEdit->setDisabled(true);
            food_costLineEdit->setStyleSheet("QLineEdit {color : black; }");

            quantity_foodLineEdit->setText(QString::number(0));
            quantity_foodLineEdit->setDisabled(true);
            quantity_foodLineEdit->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Minimum);

            cities->addChild(food);
            ui->citiesTreeWidget->setItemWidget(food, 1, food_costLineEdit);
        }
        cities->setData(0, Qt::CheckStateRole, Qt::Unchecked);
        cities->setFlags(cities->flags() | Qt::ItemIsUserCheckable);
        //cities->setCheckState(0, Qt::Unchecked);
        citiesTree.append(cities);
    }

    ui->citiesTreeWidget->insertTopLevelItems(0, citiesTree);
    //connect(ui->citiesTreeWidget, SIGNAL(itemChanged(QTreeWidgetItem*, int)), this, SLOT(updateChecks(QTreeWidgetItem*,int)));

    ui->citiesTreeWidget->setColumnWidth(0, 193);
    ui->citiesTreeWidget->setColumnWidth(1, 50);
    ui->citiesTreeWidget->setColumnWidth(2, 80);
    connect(ui->citiesTreeWidget, SIGNAL(itemChanged(QTreeWidgetItem*, int)), this, SLOT(itemChanged(QTreeWidgetItem*, int)));
    connect(ui->citiesTreeWidget, SIGNAL(itemChanged(QTreeWidgetItem*, int)), this, SLOT(setPlan(QTreeWidgetItem*, int)));
    connect(ui->submitPlan, SIGNAL(clicked()), this, SLOT(on_submitPlan_clicked()), Qt::UniqueConnection);


//    newAdmin.RemoveCity("Vienna");
//    myCities.ReadData();
//    newAdmin.RemoveCity("Vienna");
//    newAdmin.RemoveCity("Vienna");
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
    }
}

void MainWindow::on_submitPlan_clicked()
{

    myCities.ShortestPath();
    for (auto & city: myCities.GetTravelPlan()) cout << city->name << "[" << city->distance << "]" << " --> ";
    cout << endl;
    cout << "Total Distance travelled: " << myCities.GetTotalDistance(myCities.GetTravelPlan()) << endl;

    // setting up Tree Widget
    ui->planTreeWidget->setHeaderLabels(QStringList() << "Cities & their foods" << "Cost($)" << "Quantity to Buy");
    ui->planTreeWidget->setColumnCount(3);
    for (auto & city: myCities.GetTravelPlan())
    {
        QTreeWidgetItem* newCity = new QTreeWidgetItem();
        newCity->setText(0, QString::fromStdString(city->name));
        ui->planTreeWidget->addTopLevelItem(newCity);
        for (auto & foodItem: city->tradFoodList)
        {
            auto* food = new QTreeWidgetItem;
            auto* food_costLineEdit = new QLineEdit;
            auto* quantity_foodLineEdit = new QLineEdit;

            food->setText(0, QString::fromStdString(foodItem.foodName));
            food_costLineEdit->setText(QString::number(foodItem.cost, 'f', 2));
            food_costLineEdit->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Minimum);

            //check for admin perms here
            food_costLineEdit->setDisabled(true);
            food_costLineEdit->setStyleSheet("QLineEdit {color : black; }");

            quantity_foodLineEdit->setText(QString::number(0));
            quantity_foodLineEdit->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Minimum);

            newCity->addChild(food);
            ui->planTreeWidget->setItemWidget(food, 1, food_costLineEdit);
            ui->planTreeWidget->setItemWidget(food, 2, quantity_foodLineEdit);

        }
        QTreeWidgetItem* spentAtCity = new QTreeWidgetItem();
        QLineEdit* spentAtCity_lineedit = new QLineEdit();
        spentAtCity_lineedit->setText(QString::number(0));
        spentAtCity->setText(0, "Amount Spent: ");
        newCity->addChild(spentAtCity);
        ui->planTreeWidget->setItemWidget(spentAtCity, 1, spentAtCity_lineedit);
    }
}

void MainWindow::on_actionLogin_triggered()
{
    login log;
    log.setModal(true);
    log.exec();
}

//void MainWindow::paintEvent(QPaintEvent *e) {
//    QWidget::paintEvent(e);
//
//    QPainter painter(&pix);
//
////    ui->map->setPixmap(pix);
////    ui->map->show();
////    QPen paintPen(Qt::darkCyan, 3, Qt::DashDotDotLine);
////    painter.setPen(paintPen);
//
//    if (myCities.GetTravelPlan().size() > 1) {
//        for (int i = 0; i < myCities.GetTravelPlan().size() - 1; i++) {
//            painter.drawLine(myCities.GetTravelPlan().at(i)->getCoordinate(),
//                             myCities.GetTravelPlan().at(
//                                     i + 1)->getCoordinate());
//        }
//    }
//}

