#pragma once
#include <iostream>
#include <deque>
#include <vector>
#include <string>
#include "sqlite3.h"
#include <algorithm>
#include <map>
#include "City/City.h"
#include "../DB/Database/Database.h"

class ManageCities
{
public:
    ManageCities();
    void ReadData();
    void AddCity(const string& name);
    void EraseCity(const string& name);
    void ShortestPath();
    deque<City*>& GetShortTravelPlan();
    map<string,City*> &GetTravelPlan();
    map<string,City*> GetEuroCities();
    int GetTotalDistance() const;
    void setStartingCity(const string& initial);
    Records& GetDistancesFromBerlin();
    void BaseCityPlan(const string& cityName, int numOfCities);

protected:
    Database cityDatabase{"./DB/cities-table.sqlite"};
    map<string, City*> euroCities;
private:
    Records cityList;
    Records distanceList;
    Records foodList;
    Records distancesFromBerlin;
    deque<City*> shortTravelPlan;
    map<string, City*> travelPlan;
    string startingCity;
};
