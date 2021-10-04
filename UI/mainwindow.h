#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql/QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QFileInfo>
#include <QSqlQueryModel>
#include <QSql>
#include <QLineEdit>
#include "ManageCities.h"
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
signals:

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase mydb;
    void printPlan(ManageCities toAdd);
    void updateChecks(QTreeWidgetItem* item, int column);
    void recursiveChecks(QTreeWidgetItem* parent);

    QList<QTreeWidgetItem *> citiesTree;
//    QTreeWidgetItem *cities = new QTreeWidgetItem;

};
#endif // MAINWINDOW_H
