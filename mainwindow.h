#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql/QSqlDatabase>
#include <QDebug>
#include <QFileInfo>
#include "ManageCity/ManageCities.h"
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

private slots:
    void on_pushButton_clicked();

    void on_actionLogin_triggered();

    void on_actionCreate_New_Account_triggered();

private:
    Ui::MainWindow *ui;
    void printPlan(ManageCities toAdd);

    QList<QTreeWidgetItem *> citiesTree;
//    QTreeWidgetItem *cities = new QTreeWidgetItem;

};
#endif // MAINWINDOW_H
