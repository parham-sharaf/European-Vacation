#include <iostream>
#include <sqlite3.h>
#include "spdlog/spdlog.h"
#include "ManageCities.h"

using namespace std;

int main(int argc, char** argv)
{
    spdlog::set_level(spdlog::level::trace);
    ManageCities myCities;
//    for (auto& record: myCities.foodList) {
//        for (auto &r: record)
//            cout << r << endl;
//        cout << endl;
//    }

    myCities.ReadData();
//    for (auto& city: myCities.euroCities) {
//        cout << "-- " << city->name << endl;
//        for (auto& food: city->tradFoodList) {
//            cout << food.foodName << "  " << food.cost << endl;
//        }
//        cout << city->distance << endl;
//        cout << endl;
//    }
    myCities.AddCity("London");
    spdlog::trace("Added London");
    spdlog::debug("Name: {0}", myCities.travelPlan.top()->name);
    for (auto& food: myCities.travelPlan.top()->tradFoodList) {
        spdlog::debug("Foods: {0}, {1:.2f}", food.foodName, food.cost);
    }
    spdlog::debug("Distance: {0}", myCities.travelPlan.top()->distance);
    cout << endl;

    myCities.AddCity("Amsterdam");
    spdlog::trace("Added Amsterdam");
    spdlog::debug("Name: {0}", myCities.travelPlan.top()->name);
    for (auto& food: myCities.travelPlan.top()->tradFoodList) {
        spdlog::debug("Foods: {0}, {1:.2f}", food.foodName, food.cost);
    }
    spdlog::debug("Distance: {0}", myCities.travelPlan.top()->distance);

}

