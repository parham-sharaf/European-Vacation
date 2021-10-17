#include "Interface.h"

void Interface::createTravelerTree(Ui::MainWindow *ui, ManageCities &myCities) const {
    ui->citiesTreeWidget->setHeaderLabels(QStringList() << "Cities & their Foods" << "Cost($)" << "Distance to Berlin (km)");
    ui->citiesTreeWidget->header()->setDefaultAlignment(Qt::AlignCenter);

    for (auto & city : myCities.GetEuroCities())
    {
        for (auto & dot: Map::euroMap)
            if (dot->GetLocation() == city.first) {
                dot->setAvailability(true);
            }

        auto* cities = new QTreeWidgetItem;
        cities->setText(0, QString::fromStdString(city.first));
        for (auto & foodItem: city.second->tradFoodList)
        {
            auto* food = new QTreeWidgetItem;
            auto* food_costLineEdit = new QLineEdit;

            food->setText(0, QString::fromStdString(foodItem.foodName));
            food_costLineEdit->setText(QString::number(foodItem.cost, 'f', 2));
            food_costLineEdit->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Minimum);

            //check for admin perms here
            food_costLineEdit->setDisabled(true);
            food_costLineEdit->setStyleSheet("QLineEdit {color : black; border: 1px solid black;}");
            food_costLineEdit->setAlignment(Qt::AlignHCenter);

            cities->addChild(food);

            ui->citiesTreeWidget->setItemWidget(food, 1, food_costLineEdit);

        }
        cities->setData(0, Qt::CheckStateRole, Qt::Unchecked);
        cities->setFlags(cities->flags() | Qt::ItemIsUserCheckable);
        ui->citiesTreeWidget->insertTopLevelItem(0, cities);

        for (auto & i : myCities.GetDistancesFromBerlin())
        {
            if (i.at(0) == cities->text(0).toStdString())
            {
                QLineEdit* distFromBerlin = new QLineEdit();
                distFromBerlin->setText(QString::fromStdString(i.at(1)));
                distFromBerlin->setAlignment(Qt::AlignHCenter);
                distFromBerlin->setStyleSheet("border: 1px solid black;");
                distFromBerlin->setReadOnly(true);

                ui->citiesTreeWidget->setItemWidget(cities, 2, distFromBerlin);
            }
        }
    }
    ui->citiesTreeWidget->setColumnWidth(0, 193);
    ui->citiesTreeWidget->setColumnWidth(1, 50);
    ui->citiesTreeWidget->setColumnWidth(2, 100);
}

void Interface::submitPlanTree(Ui::MainWindow *ui, ManageCities &myCities) {
    if (ui->citiesFromLondon_LineEdit->isEnabled())
    {
        myCities.BaseCityPlan("London", ui->citiesFromLondon_LineEdit->text().toInt());
        for (auto & city: myCities.GetTravelPlan()) cout << city.first << "[" << city.second->distance << "]" << " --> ";
        cout << endl;
    }
    else
    {
        myCities.setStartingCity(Map::getStartingCity());
        myCities.ShortestPath();
        for (auto & city: myCities.GetTravelPlan()) cout << city.first << "[" << city.second->distance << "]" << " --> ";
        cout << endl;
    }
    ui->totalDistanceTraveled_LineEdit->setText(QString::number(myCities.GetTotalDistance()));

    // setting up Tree Widget
    ui->planTreeWidget->clear();
    ui->updatepurchases_pushButton->setStyleSheet("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1,   stop:0 rgba(60, 186, 162, 255), stop:1 rgba(98, 211, 162, 255));");
    ui->totalspent_LineEdit->setText("0.00");
    ui->updatepurchases_pushButton->setDisabled(false);

    ui->planTreeWidget->setHeaderLabels(QStringList() << "Cities & their Foods" << "Cost($)" << "Quantity to Buy");
    ui->planTreeWidget->setColumnCount(3);
    ui->planTreeWidget->header()->setDefaultAlignment(Qt::AlignCenter);

    int orderInTrip = 1;
    for (auto & city: myCities.GetShortTravelPlan())
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

            QMainWindow::connect(food_costLineEdit, SIGNAL(textChanged(const QString &)), food_costLineEdit, SLOT(updateAccessibleName()));
            food->setText(0, QString::fromStdString(foodItem.foodName));
            food_costLineEdit->setText(QString::number(foodItem.cost, 'f', 2));
            food_costLineEdit->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Minimum);

            //check for admin perms here
            food_costLineEdit->setDisabled(true);
            food_costLineEdit->setStyleSheet("QLineEdit {color : black; border: 1px solid black}");
            food_costLineEdit->setStyleSheet("QLineEdit {color : black; }");
            food_costLineEdit->setAlignment(Qt::AlignHCenter);

            quantity_foodLineEdit->setText(QString::number(0));
            quantity_foodLineEdit->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Minimum);
            quantity_foodLineEdit->setAlignment(Qt::AlignHCenter);
            quantity_foodLineEdit->setStyleSheet("QLineEdit {color : black; border: 1px solid black}");

            newCity->addChild(food);
            ui->planTreeWidget->setItemWidget(food, 1, food_costLineEdit);
            ui->planTreeWidget->setItemWidget(food, 2, quantity_foodLineEdit);

            // testing set accessible name
            ui->planTreeWidget->itemWidget(food, 2)->setAccessibleName("0");
            QMainWindow::connect(quantity_foodLineEdit, SIGNAL(textChanged(const QString &)), quantity_foodLineEdit, SLOT(updateAccessibleName()));
        }
    }
    ui->planTreeWidget->setColumnWidth(0, 193);
    ui->planTreeWidget->setColumnWidth(1, 50);
    ui->planTreeWidget->setColumnWidth(2, 100);
}

void Interface::createAdminTree(Ui::MainWindow *ui, Admin newAdmin, const ManageCities &myCities) {
    for (auto& group : newAdmin.readNewCities()) {
        if (myCities.GetEuroCities().find(group) == myCities.GetEuroCities().end())
            ui->newCityComboBox->addItem(QString::fromStdString(group));
    }

    //Setting "Add City" button functionality

    //=====================CHANGE TRADITIONAL FOODS PRICE=====================
    //Setting the combo box for the available cities
    for (auto& group : newAdmin.readAvailableCities()) ui->cityComboBox->addItem(QString::fromStdString(group));

    //Setting the combo box for the traditional foods for the specified city
    for (auto& group : newAdmin.readFoodFromCity(ui->cityComboBox->currentText().toStdString())) ui->tradFoodComboBox->addItem(QString::fromStdString(group));

    //Setting "Change Traditional Food Price" button functionality

    //=====================ADD TRADITIONAL FOODS=====================
    //Setting the combo box for the available cities
    for (auto& group : newAdmin.readAvailableCities()) ui->addFoodCityComboBox->addItem(QString::fromStdString(group));

    //Setting "Add Traditional Food" button functionality

    //=====================DELETE TRADITIONAL FOODS=====================
    //Setting the combo box for the available cities
    for (auto& group : newAdmin.readAvailableCities()) ui->delFoodCityComboBox->addItem(QString::fromStdString(group));

    //Setting the combo box for the traditional foods for the specified city
    for (auto& group : newAdmin.readFoodFromCity(ui->cityComboBox->currentText().toStdString())) ui->delTradFoodComboBox->addItem(QString::fromStdString(group));
}

Interface::Interface(QObject *parent) {

}
