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

//    sqlite3_close(db);
}


void ManageCities::ReadData() {
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
}

void ManageCities::AddCity(const string& name) {

    if (travelPlan.empty()) {
        spdlog::trace("Travel plan is empty. Adding the first city...");
        for (auto &city: euroCities) {
            if (city->name == name) {
                city->distance = 0;
                travelPlan.push(city);
                break;
            }
        }
    }
    else {
//        spdlog::trace("Travel plan is not empty. Currently at the top: {0}", travelPlan.top());
        string sql = "SELECT * FROM distance WHERE starting_city IS '" + travelPlan.top()->name + "' AND ending_city IS '" + name + "';";

        distanceList = select_stmt(sql.c_str());
        for (auto &city: euroCities) {
            cout << distanceList.at(0).at(2) << endl;
            if (city->name == name) {
                city->distance = std::stoi(distanceList.at(0).at(2));
                travelPlan.push(city);
                break;
            }
        }
    }
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
        std::cerr << thisRecord.size() << " results returned.\n";
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
