#include <iostream>
#include <sqlite3.h>
#include "spdlog/spdlog.h"
#include "ManageCities.h"

using namespace std;

int main(int argc, char** argv)
{
    spdlog::set_level(spdlog::level::trace);
    ManageCities myCities;
    for (auto& record: myCities.distanceList) {
        for (auto &r: record)
            cout << r << endl;
        cout << endl;
    }

    myCities.ReadData();

    myCities.AddCity("London", myCities.GetTravelPlan());
    for (auto & city: myCities.GetTravelPlan()) cout << city->name << "[" << city->distance << "]" << " --> ";
    cout << endl;
    myCities.AddCity("Amsterdam", myCities.GetTravelPlan());
    for (auto & city: myCities.GetTravelPlan()) cout << city->name << "[" << city->distance << "]" << " --> ";
    cout << endl;
    myCities.AddCity("Lisbon", myCities.GetTravelPlan());
    for (auto & city: myCities.GetTravelPlan()) cout << city->name << "[" << city->distance << "]" << " --> ";
    cout << endl;
    myCities.AddCity("Madrid", myCities.GetTravelPlan());
    for (auto & city: myCities.GetTravelPlan()) cout << city->name << "[" << city->distance << "]" << " --> ";
    cout << endl;
    myCities.AddCity("Paris", myCities.GetTravelPlan());
    for (auto & city: myCities.GetTravelPlan()) cout << city->name << "[" << city->distance << "]" << " --> ";
    cout << endl;
    myCities.AddCity("Budapest", myCities.GetTravelPlan());
    for (auto & city: myCities.GetTravelPlan()) cout << city->name << "[" << city->distance << "]" << " --> ";
    cout << endl;
    myCities.ShortestPath("Amsterdam");
    for (auto & city: myCities.GetTravelPlan()) cout << city->name << "[" << city->distance << "]" << " --> ";
    cout << endl;
}

