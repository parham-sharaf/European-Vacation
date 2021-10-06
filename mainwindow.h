#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql/QSqlDatabase>
#include <QDebug>
#include <QFileInfo>
#include <QLineEdit>
#include "ManageCity/ManageCities.h"
#include <QTreeWidget>
#include <QTreeWidgetItem>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    int toggle = 0;

public slots:
    void itemChanged(QTreeWidgetItem*, int);
    void setPlan(QTreeWidgetItem*, int);

signals:

private slots:
    void on_submitPlan_clicked();

    void on_actionLogin_triggered();

    void on_actionCreate_New_Account_triggered();
private:
    Ui::MainWindow *ui;
    void printPlan(ManageCities toAdd);
    void updateChecks(QTreeWidgetItem* item, int column);
    void recursiveChecks(QTreeWidgetItem* parent);
    ManageCities myCities;



    QList<QTreeWidgetItem *> citiesTree;
//    QTreeWidgetItem *cities = new QTreeWidgetItem;

};
#endif // MAINWINDOW_H
