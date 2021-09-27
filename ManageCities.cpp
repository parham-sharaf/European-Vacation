#include "ManageCities.h"
#include "City.h"
sqlite3 *db;

ManageCities::ManageCities() {
    const char* path = "/home/parham/Personal/School/Saddleback/2021 Fall/CS 1D/European-Vacation/DB/cities-table.sqlite";
    if (sqlite3_open(path, &db) != SQLITE_OK) {
        std::cerr << "Could not open database.\n";
        return;
    }

    cityList = select_stmt("SELECT *\n"
                           "FROM city;");

    foodList = select_stmt("SELECT *\n"
                                "FROM food \n"
                                "ORDER BY city_name;");

    sqlite3_close(db);
}


void ManageCities::AddCity() {
    for (auto& group: cityList) {
        for (auto& cityName: group) {
            City *newCity = new City;
            newCity->name = cityName;
            euroCities.push_back(newCity);
        }
    }

    for (auto & city: euroCities) {
        for (auto & group: foodList) {
            if (group.at(2) == city->name) {
                TradFood thisTradFood;
                thisTradFood.foodName = group.at(0);
                thisTradFood.cost = std::stof(group.at(1));
                city->tradFoodList.push_back(thisTradFood);
                city->distance = 0;
            }
        }
    }
//    int counter = 0;
//    for (int i = 0; i < euroCities.size(); i++) {
//        for (int j = 0; j < foodList.at(counter).size(); j++) {
//            TradFood thisTradFood;
//            thisTradFood.foodName = foodList.at(j).at(0),
//            thisTradFood.cost = std::stof(foodList.at(j).at(1));
//            euroCities.at(i)->tradFoodList.push_back(thisTradFood);
//            euroCities.at(i)->distance = 0;
//        }
//        counter++;
//    }
}

int ManageCities::select_callback(void *p_data, int num_fields, char **p_fields, char **p_col_names)
{
    auto* records = static_cast<Records*>(p_data);
    try {
        records->emplace_back(p_fields, p_fields + num_fields);
    }
    catch (...) {
        // abort select on failure, don't let exception propogate thru sqlite3 call-stack
        return 1;
    }
    return 0;
}

//int (*select_callback)(void *NotUsed, int argc, char **argv, char **azColName)
Records ManageCities::select_stmt(const char* stmt) const
{
    Records thisRecord;
    char *errmsg;
    int ret = sqlite3_exec(db, stmt, select_callback, &thisRecord, &errmsg);
    if (ret != SQLITE_OK) {
        std::cerr << "Error in select statement " << stmt << "[" << errmsg << "]\n";
    }
    else {
        std::cerr << foodList.size() << " foodList returned.\n";
    }

    return thisRecord;
}

void ManageCities::sql_stmt(const char* stmt)
{
    char *errmsg;
    int ret = sqlite3_exec(db, stmt, nullptr, nullptr, &errmsg);
    if (ret != SQLITE_OK) {
        std::cerr << "Error in select statement " << stmt << "[" << errmsg << "]\n";
    }
}
