#include "ManageCities.h"
#include "City/City.h"
#include <iterator>
static sqlite3 *db;

ManageCities::ManageCities() {
//    sqlite3_close(db);
}

void ManageCities::ReadData() {
    distanceList = cityDatabase.select_stmt("SELECT ending_city,kilometers from distance"
                                            " WHERE starting_city IS 'London' ORDER BY kilometers;");
    cityList = cityDatabase.select_stmt("SELECT *\n"
                                        "FROM city;");

    foodList = cityDatabase.select_stmt("SELECT *\n"
                                        "FROM food \n"
                                        "ORDER BY city_name;");

    for (auto& group: cityList) {
        City *newCity = new City;
        newCity->name = group.at(0);
        newCity->setCoordinate(std::stoi(group.at(1)), std::stoi(group.at(2)));
        euroCities.push_back(newCity);
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

//    for (auto & city : euroCities) {
//        cout << "city name: " << city->name << endl;
//        cout << "distance: " << city->distance << endl;
//        for (auto & group: city->tradFoodList) {
//            cout << "food name " << group.foodName << "\tfood cost " << group.cost << endl;
//        }
//        cout << endl << endl;
//    }
}

void ManageCities::AddCity(const string& name, deque<City*>& planner) {
    __gnu_cxx::__normal_iterator<City **, vector<City *>> newCity;
    if (planner.empty()) {
        newCity = find_if(euroCities.begin(), euroCities.end(), [name](City* target) -> bool {
            return (target->name == name);
        });
        (*newCity)->distance = 0;
    }
    else {
        string sql = "SELECT kilometers FROM distance WHERE starting_city IS '" +
                planner.back()->name + "' AND ending_city IS '" + name + "';";

        distanceList = cityDatabase.select_stmt(sql.c_str());
        newCity = find_if(euroCities.begin(), euroCities.end(), [name](City* target) -> bool {
            return (target->name == name);
        });
        (*newCity)->distance = std::stoi(distanceList.at(0).at(0));
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
        setStartingCity(planner.at(0)->name);
    }
    else {
        for (auto city = planner.begin(); city != planner.end(); city++) {
            if ((*city)->name == name) {
                string sql = "SELECT * FROM distance WHERE starting_city IS '" +
                        (*(city - 1))->name + "' AND ending_city IS '" + (*(city + 1))->name + "';";
                distanceList = cityDatabase.select_stmt(sql.c_str());
                (*(city + 1))->distance = std::stoi(distanceList.at(0).at(2));
                planner.erase(city);
            }
        }
    }
}

deque<City*>& ManageCities::GetTravelPlan(){
    return travelPlan;
}

vector<City*>& ManageCities::GetEuroCities() {
    return euroCities;
}

void ManageCities::ShortestPath() {
    deque<City *> newPlanner = travelPlan;
    string sql;

    travelPlan.clear();
    AddCity(startingCity, travelPlan);
    EraseCity(startingCity, newPlanner);

    sql = "SELECT ending_city,kilometers from distance WHERE starting_city IS '" + travelPlan.back()->name + "' ORDER BY kilometers;";
    distanceList = cityDatabase.select_stmt(sql.c_str());

    auto group = distanceList.begin();
    while (group != distanceList.end()) {
        for (auto city: newPlanner) {
            if (group->at(0) == city->name) {
                AddCity(city->name, travelPlan);
                EraseCity(city->name, newPlanner);
                sql = "SELECT ending_city,kilometers from distance WHERE starting_city IS '" +
                      travelPlan.back()->name + "' ORDER BY kilometers;";
                distanceList = cityDatabase.select_stmt(sql.c_str());
                group = distanceList.begin();
                continue;
            }
            city++;
        }
        group++;
    }
    if (!newPlanner.empty()) AddCity(newPlanner.back()->name, travelPlan);
}

int ManageCities::GetTotalDistance(const deque<City*>& planner) const{
    int sum = 0;
    for (auto & city: planner) {
        sum += city->distance;
    }
    return sum;
}

void ManageCities::setStartingCity(const string& initial) {
    this->startingCity = initial;
}

