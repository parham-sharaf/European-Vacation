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
#include "ManageCity/ManageCities.h"
#include "ManageCity/City/City.h"
#include "UI/login/login.h"
#include "Admin/Admin.h"
#include "UI/Map/map.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    double totalSpentOnTrip = 0;

protected:

public slots:
    void itemChanged(QTreeWidgetItem*, int);
    void updateSpent();
    void setPlan(QTreeWidgetItem*, int);
    void on_submitPlan_clicked();

signals:

private slots:

    void on_actionLogin_triggered();
    void on_updatepurchases_pushButton_clicked();

private:
    void updateChecks(QTreeWidgetItem* item, int column);
    Ui::MainWindow *ui;
    QPixmap pix;
    QGraphicsScene *scene;
    ManageCities myCities;
    vector<Map*> euroMap;
    bool repurchase = false;

    void recursiveChecks(QTreeWidgetItem* parent);
    QList<QTreeWidgetItem *> citiesTree;
};
#endif // MAINWINDOW_H