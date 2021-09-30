#include "ManageCities.h"
#include "City.h"
#include <iterator>
sqlite3 *db;

//int (*select_callback)(void *NotUsed, int argc, char **argv, char **azColName)
Records ManageCities::select_stmt(const char* stmt)
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

ManageCities::ManageCities() {
    const char* path = "/home/parham/Personal/School/Saddleback/2021 Fall/CS 1D/European-Vacation/DB/cities-table.sqlite";
    if (sqlite3_open(path, &db) != SQLITE_OK) {
        std::cerr << "Could not open database.\n";
        return;
    }

    distanceList = select_stmt("SELECT ending_city,kilometers from distance WHERE starting_city IS 'London' ORDER BY kilometers;");
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

void ManageCities::AddCity(const string& name, deque<City*>& planner) {
    __gnu_cxx::__normal_iterator<City **, vector<City *>> newCity;
    if (planner.empty()) {
        spdlog::trace("Travel plan is empty. Adding the first city...");
        newCity = find_if(euroCities.begin(), euroCities.end(), [name](City* target) -> bool {
            return (target->name == name);
        });
        (*newCity)->distance = 0;
    }
    else {
//        spdlog::trace("Travel plan is not empty. Currently at the top: {0}", travelPlan.top());
        string sql = "SELECT * FROM distance WHERE starting_city IS '" +
                planner.back()->name + "' AND ending_city IS '" + name + "';";

        distanceList = select_stmt(sql.c_str());
        newCity = find_if(euroCities.begin(), euroCities.end(), [name](City* target) -> bool {
            return (target->name == name);
        });
        (*newCity)->distance = std::stoi(distanceList.at(0).at(2));
    }
    planner.push_back(*newCity);
}

void ManageCities::EraseCity(const string &name, deque<City*>& planner) {
    if (planner.back()->name == name) {
        planner.erase(planner.end());
    }
    else if (planner.front()->name == name) {
        planner.erase(planner.begin());
        planner.at(0)->distance = 0;
    }
    else {
        for (auto city = planner.begin(); city != planner.end(); city++) {
            if ((*city)->name == name) {
                string sql = "SELECT * FROM distance WHERE starting_city IS '" +
                        (*(city - 1))->name + "' AND ending_city IS '" + (*(city + 1))->name + "';";
                distanceList = select_stmt(sql.c_str());
                (*(city + 1))->distance = std::stoi(distanceList.at(0).at(2));
                planner.erase(city);
            }
        }
    }
}

deque<City*>& ManageCities::GetTravelPlan() {
    return travelPlan;
}

void ManageCities::ShortestPath(const string& startingPoint) {
    deque<City *> newPlanner = travelPlan;
    string sql;

    travelPlan.clear();
    AddCity(startingPoint, travelPlan);
    EraseCity(startingPoint, newPlanner);

    sql = "SELECT ending_city,kilometers from distance WHERE starting_city IS '" + travelPlan.back()->name + "' ORDER BY kilometers;";
    distanceList = select_stmt(sql.c_str());

    for (auto & group: distanceList) {
        for (auto city = newPlanner.begin(); city != newPlanner.end(); city++) {
            cout << "group at 0:" << group.at(0) << endl;
            cout << "city name: " << (*city)->name << endl;
            cout << endl;

            if (group.at(0) == (*city)->name) {
                cout << "got a match" << endl << endl;
                AddCity((*city)->name, travelPlan);
                EraseCity((*city)->name, newPlanner);
                sql = "SELECT ending_city,kilometers from distance WHERE starting_city IS '" +
                      travelPlan.back()->name + "' ORDER BY kilometers;";
                distanceList = select_stmt(sql.c_str());
            }
        }

//        }
//        cout << group.at(0) << endl;
//        AddCity((*newCity)->name, travelPlan);
//        EraseCity((*newCity)->name, newPlanner);
//        break;
    }


//    for (auto city = newPlanner.begin(); city != newPlanner.end(); city++) {
//        if ((*city)->name == group.at(0)) {
//                AddCity(group.at(0), travelPlan);
//                EraseCity(group.at(0), newPlanner);
//            cout << (*city)->name << endl;
//            sql = "SELECT ending_city,kilometers from distance WHERE starting_city IS '" + (*city)->name + "' ORDER BY kilometers;";
//            distanceList = select_stmt(sql.c_str());
//        }
//    }
}


