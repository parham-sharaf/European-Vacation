/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.1.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionCircle;
    QAction *actionRectangle;
    QAction *actionLine;
    QAction *actionPolyLine;
    QAction *actionEllipse;
    QAction *actionSquare;
    QAction *actionText;
    QAction *actionPolygon;
    QAction *actionLogin;
    QAction *actionCreate_New_Account;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QTreeWidget *citiesTreeWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QPushButton *submitPlan;
    QTreeWidget *planTreeWidget;
    QLabel *map;
    QStatusBar *statusbar;
    QMenuBar *menubar;
    QMenu *menuAccount;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(930, 636);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        actionCircle = new QAction(MainWindow);
        actionCircle->setObjectName(QString::fromUtf8("actionCircle"));
        actionRectangle = new QAction(MainWindow);
        actionRectangle->setObjectName(QString::fromUtf8("actionRectangle"));
        actionLine = new QAction(MainWindow);
        actionLine->setObjectName(QString::fromUtf8("actionLine"));
        actionPolyLine = new QAction(MainWindow);
        actionPolyLine->setObjectName(QString::fromUtf8("actionPolyLine"));
        actionEllipse = new QAction(MainWindow);
        actionEllipse->setObjectName(QString::fromUtf8("actionEllipse"));
        actionSquare = new QAction(MainWindow);
        actionSquare->setObjectName(QString::fromUtf8("actionSquare"));
        actionText = new QAction(MainWindow);
        actionText->setObjectName(QString::fromUtf8("actionText"));
        actionPolygon = new QAction(MainWindow);
        actionPolygon->setObjectName(QString::fromUtf8("actionPolygon"));
        actionLogin = new QAction(MainWindow);
        actionLogin->setObjectName(QString::fromUtf8("actionLogin"));
        actionCreate_New_Account = new QAction(MainWindow);
        actionCreate_New_Account->setObjectName(QString::fromUtf8("actionCreate_New_Account"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setEnabled(true);
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        citiesTreeWidget = new QTreeWidget(centralwidget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        citiesTreeWidget->setHeaderItem(__qtreewidgetitem);
        citiesTreeWidget->setObjectName(QString::fromUtf8("citiesTreeWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(citiesTreeWidget->sizePolicy().hasHeightForWidth());
        citiesTreeWidget->setSizePolicy(sizePolicy1);
        citiesTreeWidget->setMinimumSize(QSize(355, 260));

        gridLayout->addWidget(citiesTreeWidget, 3, 1, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy2);
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label);

        submitPlan = new QPushButton(centralwidget);
        submitPlan->setObjectName(QString::fromUtf8("submitPlan"));

        horizontalLayout_2->addWidget(submitPlan);


        gridLayout->addLayout(horizontalLayout_2, 2, 1, 1, 1);

        planTreeWidget = new QTreeWidget(centralwidget);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem();
        __qtreewidgetitem1->setText(0, QString::fromUtf8("1"));
        planTreeWidget->setHeaderItem(__qtreewidgetitem1);
        planTreeWidget->setObjectName(QString::fromUtf8("planTreeWidget"));
        sizePolicy1.setHeightForWidth(planTreeWidget->sizePolicy().hasHeightForWidth());
        planTreeWidget->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(planTreeWidget, 4, 1, 1, 1);

        map = new QLabel(centralwidget);
        map->setObjectName(QString::fromUtf8("map"));

        gridLayout->addWidget(map, 1, 0, 4, 1);

        MainWindow->setCentralWidget(centralwidget);
        map->raise();
        citiesTreeWidget->raise();
        planTreeWidget->raise();
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 930, 22));
        menuAccount = new QMenu(menubar);
        menuAccount->setObjectName(QString::fromUtf8("menuAccount"));
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menuAccount->menuAction());
        menuAccount->addAction(actionLogin);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionCircle->setText(QCoreApplication::translate("MainWindow", "Circle", nullptr));
        actionRectangle->setText(QCoreApplication::translate("MainWindow", "Rectangle", nullptr));
        actionLine->setText(QCoreApplication::translate("MainWindow", "Line", nullptr));
        actionPolyLine->setText(QCoreApplication::translate("MainWindow", "PolyLine", nullptr));
        actionEllipse->setText(QCoreApplication::translate("MainWindow", "Ellipse", nullptr));
        actionSquare->setText(QCoreApplication::translate("MainWindow", "Square", nullptr));
        actionText->setText(QCoreApplication::translate("MainWindow", "Text", nullptr));
        actionPolygon->setText(QCoreApplication::translate("MainWindow", "Polygon", nullptr));
        actionLogin->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        actionCreate_New_Account->setText(QCoreApplication::translate("MainWindow", "Create New Account", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Please mark which cities to travel to!", nullptr));
        submitPlan->setText(QCoreApplication::translate("MainWindow", "Submit Plan", nullptr));
        map->setText(QString());
        menuAccount->setTitle(QCoreApplication::translate("MainWindow", "Account", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
