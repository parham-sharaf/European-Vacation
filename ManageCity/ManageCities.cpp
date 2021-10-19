#include "ManageCities.h"
#include "City/City.h"
#include <iterator>

map<string, City*> ManageCities::euroCities;

ManageCities::ManageCities() {
//    sqlite3_close(db);
}

void ManageCities::ReadData() {
    euroCities.clear();
    cityList = cityDatabase.select_stmt("SELECT *\n"
                                        "FROM city;");

    foodList = cityDatabase.select_stmt("SELECT *\n"
                                        "FROM food \n"
                                        "ORDER BY city_name;");

    distancesFromBerlin = cityDatabase.select_stmt("SELECT ending_city,kilometers from distance"
                                      " WHERE starting_city IS 'Berlin' ORDER BY kilometers;");

    for (auto & group: cityList) {
        City *newCity = new City;
        newCity->name = group.at(0);
        euroCities.insert(pair<string, City*>(group.at(0), newCity));
    }

    for (auto & group: foodList) {
        TradFood thisTradFood;
        thisTradFood.foodName = group.at(0);
        thisTradFood.cost = std::stof(group.at(1));
        euroCities.find(group.at(2))->second->tradFoodList.push_back(thisTradFood);
    }
}

void ManageCities::AddCity(const string& name) {
    auto newCity = euroCities.find(name);
    newCity->second->distance = 0;
    travelPlan.insert(pair<string, City*> (newCity->first, newCity->second));
}

void ManageCities::EraseCity(const string &name) {
    auto removeCity = travelPlan.find(name);
    travelPlan.erase(removeCity);
}

deque<City *> &ManageCities::GetShortTravelPlan() {
    return shortTravelPlan;
}


map<string,City*> &ManageCities::GetTravelPlan(){
    return travelPlan;
}

const map<string,City*> &ManageCities::GetEuroCities() const {
    return euroCities;
}

Records& ManageCities::GetDistancesFromBerlin() {
    return distancesFromBerlin;
}

void ManageCities::ShortestPath() {
    bool found;

    travelPlan[startingCity]->distance = 0;
    shortTravelPlan.push_back(travelPlan[startingCity]);
    travelPlan.erase(travelPlan.find(startingCity));

    string sql = "SELECT ending_city,kilometers from distance WHERE"
                 " starting_city IS '" + startingCity +
                 "' ORDER BY kilometers;";
    distanceList = cityDatabase.select_stmt(sql.c_str());

    auto group = distanceList.begin();
    while (!travelPlan.empty()) {
        found = false;
        group = distanceList.begin();
        while (!found && group != distanceList.end()) {
            auto target = travelPlan.find(group->at(0));
            if (target != travelPlan.end()) {
                found = true;
                target->second->distance = stoi(group->at(1));
                shortTravelPlan.push_back(target->second);
                sql = "SELECT ending_city,kilometers from distance WHERE starting_city IS '" +
                        group->at(0) + "' ORDER BY kilometers;";
                distanceList = cityDatabase.select_stmt(sql.c_str());
                travelPlan.erase(target);
            }
            group++;
        }
    }
}

int ManageCities::GetTotalDistance() const{
    int sum = 0;
    for (auto & city: shortTravelPlan) {
        sum += city->distance;
    }
    return sum;
}

void ManageCities::setStartingCity(const string& initial) {
    this->startingCity = initial;
}

void ManageCities::BaseCityPlan(const string& cityName, int numOfCities) {
    if (numOfCities > euroCities.size()) numOfCities = euroCities.size();
    travelPlan.clear();
    shortTravelPlan.clear();
    startingCity = cityName;
    int i = 0;
    string relativePoint = cityName;
    string sql;
    AddCity(relativePoint);

    while (i < numOfCities) {
        sql = "SELECT ending_city,kilometers from distance WHERE starting_city IS '" + relativePoint + "' ORDER BY kilometers LIMIT " + to_string(i + 1) + ";";
        distanceList = cityDatabase.select_stmt(sql.c_str());
        for (int j = 0; j < i; j++) {
            if (travelPlan.find(distanceList.at(j).at(0)) == travelPlan.end()) {
                relativePoint = distanceList.at(j).at(0);
                j = i;
            }
        }
        cout << relativePoint << endl;
        AddCity(relativePoint);
        i++;
    }
    cout << endl;

    ShortestPath();
}

