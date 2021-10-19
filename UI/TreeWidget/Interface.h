#pragma once

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

//#include "ManageCity/ManageCities.h"
//#include "ManageCity/City/City.h"
//#include "UI/login/login.h"
#include "../../Admin/Admin.h"
#include "../Map/Map.h"

#include <QWidget>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QLineEdit>
#include "../../ManageCity/ManageCities.h"
#include "../../mainwindow.h"
#include "../ModdedLineEdit/moddedlineedit.h"
#include "../../ui_mainwindow.h"

class Interface {
public:
    explicit Interface(QObject *parent = 0);
    void createTravelerTree(Ui::MainWindow *ui, ManageCities &myCities) const;
    void createAdminTree(Ui::MainWindow *ui, Admin newAdmin, const ManageCities &myCities);
    void submitPlanTree(Ui::MainWindow *ui, ManageCities &myCities);

private:
//    Ui::MainWindow *ui;
};
