#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "ManageCities.h"
#include "City.h"
#include <QSqlDriver>
#include <iostream>
#include <iomanip>
#include <QList>
#include <QtCore>
#include <QString>
#include <QLineEdit>
//#include <QtGui>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // setting up tree widget
    ui->citiesTreeWidget->setHeaderLabels(QStringList() << "Cities & their foods" << "Cost($)" << "Quantity to buy");
    ui->citiesTreeWidget->setColumnCount(3);
    //ui->citiesTreeWidget->setHeaderHidden(true);

    //spdlog::set_level(spdlog::level::trace);
    ManageCities myCities;
    for (auto& record: myCities.distanceList) {
        for (auto &r: record)
            cout << r << endl;
        cout << endl;
    }

    myCities.ReadData();

    myCities.AddCity("London", myCities.GetTravelPlan());
    for (auto & city: myCities.GetTravelPlan()) cout << city->name << "[" << city->distance << "]" << " --> ";
    cout << endl;
    myCities.AddCity("Amsterdam", myCities.GetTravelPlan());
    for (auto & city: myCities.GetTravelPlan()) cout << city->name << "[" << city->distance << "]" << " --> ";
    cout << endl;
    myCities.AddCity("Lisbon", myCities.GetTravelPlan());
    for (auto & city: myCities.GetTravelPlan()) cout << city->name << "[" << city->distance << "]" << " --> ";
    cout << endl;
    myCities.AddCity("Madrid", myCities.GetTravelPlan());
    for (auto & city: myCities.GetTravelPlan()) cout << city->name << "[" << city->distance << "]" << " --> ";
    cout << endl;
    myCities.AddCity("Paris", myCities.GetTravelPlan());
    for (auto & city: myCities.GetTravelPlan()) cout << city->name << "[" << city->distance << "]" << " --> ";
    cout << endl;
    myCities.AddCity("Budapest", myCities.GetTravelPlan());
    for (auto & city: myCities.GetTravelPlan()) cout << city->name << "[" << city->distance << "]" << " --> ";
    cout << endl;
    //spdlog::debug("total distance before efficient sort: {0}", myCities.GetTotalDistance(myCities.GetTravelPlan()));
    myCities.ShortestPath("London");
    for (auto & city: myCities.GetTravelPlan()) cout << city->name << "[" << city->distance << "]" << " --> ";
    cout << endl;
    //spdlog::debug("total distance after efficient sort: {0}", myCities.GetTotalDistance(myCities.GetTravelPlan()));

    // testing buying 5 stroopwaffles from amsterdam
    myCities.GetEuroCities().at(0)->tradFoodList.at(0).purchase(5);
    cout << "TESTING: " << myCities.GetEuroCities().at(0)->tradFoodList.at(0).amountBought << " SPENT: " << fixed <<
            setprecision(2) << myCities.GetEuroCities().at(0)->tradFoodList.at(0).amountSpent;

    // INPUTTING ITEMS INTO TREE WIDGET
    for (int i = 0; i < myCities.GetEuroCities().size(); i++)
    {
        QTreeWidgetItem* cities = new QTreeWidgetItem;
        cities->setText(0, QString::fromStdString(myCities.GetEuroCities().at(i)->name));
        int z = 0;
        for (int j = 0; j < myCities.foodList.size(); j++)
        {
            if (myCities.GetEuroCities().at(i)->name == myCities.foodList.at(j).at(2))
            {
                QTreeWidgetItem* food = new QTreeWidgetItem;
                QLineEdit* food_costLineEdit = new QLineEdit;
                QLineEdit* quantity_foodLineEdit = new QLineEdit;

                food->setText(0, QString::fromStdString(myCities.GetEuroCities().at(i)->tradFoodList.at(z).foodName));
                food_costLineEdit->setText(QString::number(myCities.GetEuroCities().at(i)->tradFoodList.at(z).cost, 'f', 2));
                food_costLineEdit->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Minimum);

                //check for admin perms here
                food_costLineEdit->setDisabled(true);
                food_costLineEdit->setStyleSheet("QLineEdit {color : black; }");

                quantity_foodLineEdit->setText(QString::number(0));
                quantity_foodLineEdit->setDisabled(true);
                quantity_foodLineEdit->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Minimum);

                cities->addChild(food);
                ui->citiesTreeWidget->setItemWidget(food, 1, food_costLineEdit);
                ui->citiesTreeWidget->setItemWidget(food, 2, quantity_foodLineEdit);
                cout << "\nTESTING in 3 FOR LOOP: " << &food << endl;                //ui->citiesTreeWidget->itemWidget(food, 2)->setDisabled(false);

                z++;
            }
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

    // test
    // UI for customizing trip



    //    myCities.ShortestPath("Melbourne", myCities.travelPlan);

    mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("C:/Users/Hiep/European-Vacation/DB/cities-table.sqlite");

    mydb.open();

    QSqlQueryModel * modal = new QSqlQueryModel();

    QSqlQuery* qry = new QSqlQuery(mydb);

    qry->prepare("select city_name, food_name, cost from food");

    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);

}

MainWindow::~MainWindow()
{

    delete ui;
}

void MainWindow::printPlan(ManageCities(toAdd))
{
    for (auto & city: toAdd.GetTravelPlan())
    {
        cout << city->name << "[" << city->distance << "]" << " --> ";
//        QTreeWidgetItem *cities = new QTreeWidgetItem;
//        cities->setText(0, QString::fromStdString(city->name));
//        citiesTree.append(cities);
////        cout << "TESTING: " << (cities->text(0).toStdString());
//        auto itr = std::find_if(citiesTree.begin(), citiesTree.end(), [](QTreeWidgetItem* someclass) { return someclass->text(0).toStdString() == "Lisbon"; });
//        if(itr != citiesTree.end()) {
//            (*itr)->text(0) = "NEW";
//            citiesTree.removeLast();
//        }
////        if (iterator != citiesTree.end())
    }
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
    toggle++;
    if(col != 0)
            return;

    recursiveChecks(item);
//    cout << "\nITEM CHANGED TEST: " << item->childCount() << endl;
//    for (int i = 0; i < item->childCount(); i++)
//    {
//        cout << "TESTING LOOP: " << &item << endl;
//        ui->citiesTreeWidget->itemWidget(item, 2)->setDisabled(false);
//    }
}

void MainWindow::on_pushButton_clicked()
{

}

