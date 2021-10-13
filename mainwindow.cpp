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
#include "moddedlineedit.h"
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

    ui->citiesTreeWidget->setHeaderLabels(QStringList() << "Cities & their Foods" << "Cost($)" << "Distance to Berlin (km)");
    ui->citiesTreeWidget->header()->setDefaultAlignment(Qt::AlignCenter);

    myCities.ReadData();

    // testing buying 5 stroopwaffles from amsterdam
    myCities.GetEuroCities().at(0)->tradFoodList.at(0).purchase(5);

    // INPUTTING ITEMS INTO TREE WIDGET
    ui->updatepurchases_pushButton->setDisabled(true);
    ui->totalDistanceTraveled_LineEdit->setReadOnly(true);
    ui->totalDistanceTraveled_LineEdit->setAlignment(Qt::AlignHCenter);
    ui->totalspent_LineEdit->setReadOnly(true);

    for (auto & city : myCities.GetEuroCities())
    {
        auto* cities = new QTreeWidgetItem;
        cities->setText(0, QString::fromStdString(city->name));
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

