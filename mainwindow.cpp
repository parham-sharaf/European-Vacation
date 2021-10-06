#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "ManageCity/ManageCities.h"
#include "ManageCity/City/City.h"
#include <iostream>
#include <iomanip>
#include <QList>
#include <QtCore>
#include <QString>
#include <QLineEdit>
//#include <QtGui>
#include "UI/login/login.h"
#include "UI/account/account.h"

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

    myCities.ReadData();

    // testing buying 5 stroopwaffles from amsterdam
    myCities.GetEuroCities().at(0)->tradFoodList.at(0).purchase(5);
    cout << "TESTING: " << myCities.GetEuroCities().at(0)->tradFoodList.at(0).amountBought << " SPENT: " << fixed <<
         setprecision(2) << myCities.GetEuroCities().at(0)->tradFoodList.at(0).amountSpent;

    // INPUTTING ITEMS INTO TREE WIDGET
    for (auto & city : myCities.GetEuroCities())
    {
        auto* cities = new QTreeWidgetItem;
        cities->setText(0, QString::fromStdString(city->name));
        int z = 0;
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
            ui->citiesTreeWidget->setItemWidget(food, 2, quantity_foodLineEdit);
            cout << "\nTESTING in 3 FOR LOOP: " << &food << endl;                //ui->citiesTreeWidget->itemWidget(food, 2)->setDisabled(false);

            z++;
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
    connect(ui->submitPlan, &QPushButton::released, this, &MainWindow::on_submitPlan_clicked);

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
    if (myCities.GetTravelPlan().empty())
        myCities.setStartingCity(item->text(0).toStdString());
    myCities.AddCity(item->text(0).toStdString(), myCities.GetTravelPlan());
    for (auto & city: myCities.GetTravelPlan()) cout << city->name << "[" << city->distance << "]" << " --> ";
    cout << endl;
}

void MainWindow::on_submitPlan_clicked()
{
    myCities.ShortestPath();
    for (auto & city: myCities.GetTravelPlan()) cout << city->name << "[" << city->distance << "]" << " --> ";
    cout << endl;
}

void MainWindow::on_actionLogin_triggered()
{
    login log;
    log.setModal(true);
    log.exec();
}


void MainWindow::on_actionCreate_New_Account_triggered()
{
    account acc;
    acc.setModal(true);
    acc.exec();
}

