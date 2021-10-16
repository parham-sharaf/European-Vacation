#pragma once
#include <iostream>
#include <deque>
#include <vector>
#include <string>
#include "SQLite/sqlite3/sqlite3.h"
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
    map<string,City*> &GetEuroCities();
    int GetTotalDistance() const;
    void setStartingCity(const string& initial);
    Records& GetDistancesFromBerlin();
    void BaseCityPlan(const string& cityName, int numOfCities);

protected:
    Database cityDatabase{"C:/Users/4ktra/OneDrive/Desktop/College Work/CS 1D Homework/CS 1D Project 1/European Vacation Project/European-Vacation/DB/cities-table.sqlite"};
    static map<string, City*> euroCities;
private:
    Records cityList;
    Records distanceList;
    Records foodList;
    Records distancesFromBerlin;
    deque<City*> shortTravelPlan;
    map<string, City*> travelPlan;
    string startingCity;
};
