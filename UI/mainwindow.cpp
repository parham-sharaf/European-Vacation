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
#include <QPainter>
//#include <QtGui>
#include "UI/login/login.h"
#include "UI/account/account.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pix.load("C:/Users/Hiep/Downloads/CS1D Fall 2021 European Vacation Project/EuropeanVacation/UI/Europe_countries_map_en_2.png");


//    int w = ui->map->width();
//    int h = ui->map->height();
//
//    ui->map->setPixmap(pix.scaled(500,500,Qt::KeepAspectRatio));

    // setting up tree widget

    QRadioButton *buttonAmsterdam = new QRadioButton("", this);
    buttonAmsterdam->move(440, 640);

    QRadioButton *buttonBerlin = new QRadioButton("", this);
    buttonBerlin->move(605, 650);

    QRadioButton *buttonBrussel = new QRadioButton("", this);
    buttonBrussel->move(430, 685);

    QRadioButton *buttonBudapest = new QRadioButton("", this);
    buttonBudapest->move(730, 800);

    QRadioButton *buttonHamburg = new QRadioButton("", this);
    buttonHamburg->move(540, 610);

    QRadioButton *buttonLisbon = new QRadioButton("", this);
    buttonLisbon->move(50, 980);

    QRadioButton *buttonLondon = new QRadioButton("", this);
    buttonLondon->move(350, 648);

    QRadioButton *buttonMadrid = new QRadioButton("", this);
    buttonMadrid->move(200, 950);

    QRadioButton *buttonParis = new QRadioButton("", this);
    buttonParis->move(390, 735);

    QRadioButton *buttonPrague = new QRadioButton("", this);
    buttonPrague->move(625, 720);

    QRadioButton *buttonRome = new QRadioButton("", this);
    buttonRome->move(550, 950);

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

//            QTreeWidgetItem* cost = new QTreeWidgetItem();
//            QTreeWidgetItem* quantity = new QTreeWidgetItem();

//            food->addChild(cost);
//            food->addChild(quantity);
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
    //recursiveChecks(item);
}

void MainWindow::setPlan(QTreeWidgetItem* item, int col)
{
    if (item->checkState(0) == Qt::Checked) {
        if (myCities.GetTravelPlan().empty())
            myCities.setStartingCity(item->text(0).toStdString());
        myCities.AddCity(item->text(0).toStdString(), myCities.GetTravelPlan());
        for (auto & city: myCities.GetTravelPlan()) cout << city->name << "[" << city->distance << "]" << " --> ";
            cout << endl;
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


void MainWindow::on_actionCreate_New_Account_triggered()
{
    account acc;
    acc.setModal(true);
    acc.exec();
}

void MainWindow::paintEvent(QPaintEvent *e) {
    QWidget::paintEvent(e);
    QPainter painter(&pix);
    ui->map->setPixmap(pix);
    ui->map->show();
    QPen paintPen(Qt::red);
    paintPen.setWidth(3);
    painter.setPen(paintPen);

    if (myCities.GetTravelPlan().size() > 1) {
        for (int i = 0; i < myCities.GetTravelPlan().size() - 1; i++) {
            painter.drawLine(myCities.GetTravelPlan().at(i)->getCoordinate(),
                             myCities.GetTravelPlan().at(
                                     i + 1)->getCoordinate());
        }
    }
    update();
}

