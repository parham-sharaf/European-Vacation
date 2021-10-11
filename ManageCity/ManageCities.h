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

using Record = std::vector<std::string>;
using Records = std::vector<Record>;

class ManageCities: public Database
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

private:

    Records cityList;
    Records distanceList;
    Records foodList;

    vector<City*> euroCities;
    deque<City*> travelPlan;

    string startingCity;
};
