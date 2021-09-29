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
    for (auto & city: myCities.travelPlan) cout << city->name << "[" << city->distance << "]" << " --> ";
    cout << endl;
    myCities.AddCity("Amsterdam");
    for (auto & city: myCities.travelPlan) cout << city->name << "[" << city->distance << "]" << " --> ";
    cout << endl;
    myCities.AddCity("Lisbon");
    for (auto & city: myCities.travelPlan) cout << city->name << "[" << city->distance << "]" << " --> ";
    cout << endl;
    myCities.AddCity("Madrid");
    for (auto & city: myCities.travelPlan) cout << city->name << "[" << city->distance << "]" << " --> ";
    cout << endl;
    myCities.AddCity("Paris");
    for (auto & city: myCities.travelPlan) cout << city->name << "[" << city->distance << "]" << " --> ";
    cout << endl;
    myCities.EraseCity("London");
    for (auto & city: myCities.travelPlan) cout << city->name << "[" << city->distance << "]" << " --> ";
    cout << endl;
    myCities.AddCity("Budapest");
    for (auto & city: myCities.travelPlan) cout << city->name << "[" << city->distance << "]" << " --> ";
    cout << endl;
//    myCities.AddCity("Paris");
//    for (auto & city: myCities.travelPlan) cout << city->name << "[" << city->distance << "]" << " --> ";
//    cout << endl;
    std::sort(myCities.travelPlan.begin(), myCities.travelPlan.end(), [](City* a, City* b) {
        return a->distance < b->distance;
    });
    for (auto & city: myCities.travelPlan) cout << city->name << "[" << city->distance << "]" << " --> ";
    cout << endl;

}

