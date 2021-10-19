#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <iostream>
#include <iomanip>
#include <vector>

#include <QMainWindow>
#include <QtGui>
#include <QtCore>
#include <QDebug>
#include <QFileInfo>
#include <QLineEdit>
#include <QList>
#include <QString>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QPainter>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPixmap>

#include "ManageCity/ManageCities.h"
#include "ManageCity/City/City.h"
#include "UI/login/login.h"
#include "Admin/Admin.h"
#include "UI/Map/Map.h"

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Ui::MainWindow *ui;

protected:

public slots:
    void itemChanged(QTreeWidgetItem*, int);
    void updateSpent();
    void setPlan(QTreeWidgetItem*, int);
    void adminNewCity();
    void adminChangePrice();
    void adminAddFood();
    void adminDelFood();
    void updateChangePriceFoodsComboBox();
    void updateDelFoodsComboBox();

signals:

private slots:
    void on_actionLogin_triggered();
    void on_updatepurchases_pushButton_clicked();
    void on_submitPlan_clicked();
    void on_clearPlan_clicked();
    void on_citiesFromLondon_LineEdit_textEdited(const QString &arg1);
    void on_adminSubmit_clicked();

private:
    QPixmap pix;
    QGraphicsScene *scene;
    QTreeWidgetItem* cities;
    QList<QTreeWidgetItem *> citiesTree;
    ManageCities myCities;
    Admin newAdmin;
    bool repurchase = false;
    int itemsChecked = 0;
    double price;
    string city;
    string food;

};
#endif // MAINWINDOW_H
