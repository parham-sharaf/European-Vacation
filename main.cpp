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

    myCities.AddCity();
    for (auto& city: myCities.euroCities) {
        cout << "-- " << city->name << endl;
        for (auto& food: city->tradFoodList) {
            cout << food.foodName << "  " << food.cost << endl;
        }
        cout << city->distance << endl;
        cout << endl;
    }
}

