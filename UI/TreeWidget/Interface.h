#pragma once
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
};