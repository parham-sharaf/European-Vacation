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
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
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
    QGraphicsView *graphicsView;
    QTabWidget *tabWidget;
    QWidget *traveller;
    QVBoxLayout *verticalLayout;
    QPushButton *submitPlan;
    QPushButton *clearPlan;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *citiesFromLondon_LineEdit;
    QTreeWidget *citiesTreeWidget;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_4;
    QLabel *label_2;
    QLineEdit *totalDistanceTraveled_LineEdit;
    QLineEdit *totalspent_LineEdit;
    QLabel *label_3;
    QPushButton *updatepurchases_pushButton;
    QTreeWidget *planTreeWidget;
    QWidget *admin;
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
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

        gridLayout->addWidget(graphicsView, 0, 0, 1, 1);

        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        traveller = new QWidget();
        traveller->setObjectName(QString::fromUtf8("traveller"));
        verticalLayout = new QVBoxLayout(traveller);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        submitPlan = new QPushButton(traveller);
        submitPlan->setObjectName(QString::fromUtf8("submitPlan"));
        QFont font;
        font.setFamilies({QString::fromUtf8("Waree")});
        font.setPointSize(12);
        submitPlan->setFont(font);
        submitPlan->setAutoFillBackground(false);
        submitPlan->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1,   stop:0 rgba(60, 186, 162, 255), stop:1 rgba(98, 211, 162, 255))"));

        verticalLayout->addWidget(submitPlan);

        clearPlan = new QPushButton(traveller);
        clearPlan->setObjectName(QString::fromUtf8("clearPlan"));
        clearPlan->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1,   stop:0 #f8c485, stop:1 #f1acc8)"));

        verticalLayout->addWidget(clearPlan);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(traveller);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(label);

        citiesFromLondon_LineEdit = new QLineEdit(traveller);
        citiesFromLondon_LineEdit->setObjectName(QString::fromUtf8("citiesFromLondon_LineEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(citiesFromLondon_LineEdit->sizePolicy().hasHeightForWidth());
        citiesFromLondon_LineEdit->setSizePolicy(sizePolicy1);
        citiesFromLondon_LineEdit->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(citiesFromLondon_LineEdit);


        verticalLayout->addLayout(horizontalLayout);

        citiesTreeWidget = new QTreeWidget(traveller);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        citiesTreeWidget->setHeaderItem(__qtreewidgetitem);
        citiesTreeWidget->setObjectName(QString::fromUtf8("citiesTreeWidget"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(citiesTreeWidget->sizePolicy().hasHeightForWidth());
        citiesTreeWidget->setSizePolicy(sizePolicy2);
        citiesTreeWidget->setMinimumSize(QSize(400, 0));
        citiesTreeWidget->setAutoFillBackground(true);
        citiesTreeWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 243, 222);\n"
"QHeaderView::section { background-color: rgb(255, 243, 222); };"));

        verticalLayout->addWidget(citiesTreeWidget);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        label_2 = new QLabel(traveller);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);

        gridLayout_4->addWidget(label_2, 1, 0, 1, 1);

        totalDistanceTraveled_LineEdit = new QLineEdit(traveller);
        totalDistanceTraveled_LineEdit->setObjectName(QString::fromUtf8("totalDistanceTraveled_LineEdit"));
        sizePolicy1.setHeightForWidth(totalDistanceTraveled_LineEdit->sizePolicy().hasHeightForWidth());
        totalDistanceTraveled_LineEdit->setSizePolicy(sizePolicy1);

        gridLayout_4->addWidget(totalDistanceTraveled_LineEdit, 0, 1, 1, 1);

        totalspent_LineEdit = new QLineEdit(traveller);
        totalspent_LineEdit->setObjectName(QString::fromUtf8("totalspent_LineEdit"));
        sizePolicy1.setHeightForWidth(totalspent_LineEdit->sizePolicy().hasHeightForWidth());
        totalspent_LineEdit->setSizePolicy(sizePolicy1);
        totalspent_LineEdit->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(totalspent_LineEdit, 1, 1, 1, 1);

        label_3 = new QLabel(traveller);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_4->addWidget(label_3, 0, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout_4, 0, 2, 1, 1);

        updatepurchases_pushButton = new QPushButton(traveller);
        updatepurchases_pushButton->setObjectName(QString::fromUtf8("updatepurchases_pushButton"));
        updatepurchases_pushButton->setStyleSheet(QString::fromUtf8(""));

        gridLayout_3->addWidget(updatepurchases_pushButton, 0, 0, 1, 1);


        verticalLayout->addLayout(gridLayout_3);

        planTreeWidget = new QTreeWidget(traveller);
        planTreeWidget->headerItem()->setText(0, QString());
        planTreeWidget->setObjectName(QString::fromUtf8("planTreeWidget"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(planTreeWidget->sizePolicy().hasHeightForWidth());
        planTreeWidget->setSizePolicy(sizePolicy3);
        planTreeWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 243, 222);\n"
"QHeaderView::section { background-color: rgb(255, 243, 222); };"));

        verticalLayout->addWidget(planTreeWidget);

        tabWidget->addTab(traveller, QString());
        admin = new QWidget();
        admin->setObjectName(QString::fromUtf8("admin"));
        tabWidget->addTab(admin, QString());

        gridLayout->addWidget(tabWidget, 0, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 930, 26));
        menuAccount = new QMenu(menubar);
        menuAccount->setObjectName(QString::fromUtf8("menuAccount"));
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menuAccount->menuAction());
        menuAccount->addAction(actionLogin);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


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
        submitPlan->setText(QCoreApplication::translate("MainWindow", "Submit Plan", nullptr));
        clearPlan->setText(QCoreApplication::translate("MainWindow", "Reset Plan", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "# of Cities to Travel to from London:", nullptr));
        citiesFromLondon_LineEdit->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Total Spent (USD)", nullptr));
        totalspent_LineEdit->setText(QString());
        label_3->setText(QCoreApplication::translate("MainWindow", "Distance Traveled (km)", nullptr));
        updatepurchases_pushButton->setText(QCoreApplication::translate("MainWindow", "Update Purchases", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(traveller), QCoreApplication::translate("MainWindow", "Traveller", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(admin), QCoreApplication::translate("MainWindow", "Maintenance", nullptr));
        menuAccount->setTitle(QCoreApplication::translate("MainWindow", "Account", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
