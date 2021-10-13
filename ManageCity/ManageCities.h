#pragma once
#include <iostream>
#include <deque>
#include <vector>
#include <string>
#include "sqlite3.h"
#include <algorithm>
#include "City/City.h"
#include "../DB/Database/Database.h"

using namespace std;


class ManageCities
{
public:
    ManageCities();
    void ReadData();
    void AddCity(const string& name, deque<City*>& planner);
    void EraseCity(const string& name, deque<City*>& planner);
    void ShortestPath();
    deque<City*>& GetTravelPlan();
    vector<City*>& GetEuroCities();
    int GetTotalDistance(const deque<City*>& planner) const;
    void setStartingCity(const string& initial);
    Records& GetDistancesFromBerlin();

protected:
    Database cityDatabase{"./DB/cities-table.sqlite"};
    vector<City*> euroCities;
private:
    Records cityList;
    Records distanceList;
    Records foodList;
    Records distancesFromBerlin;
    deque<City*> travelPlan;
    string startingCity;
};
