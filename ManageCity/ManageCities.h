#pragma once
#include <deque>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include "City/City.h"
#include "../Database/Database.h"

class ManageCities
{
public:
    void ReadData();
    void AddCity(const string& name);
    void EraseCity(const string& name);
    void ShortestPath();
    deque<City*>& GetShortTravelPlan();
    map<string,City*> &GetTravelPlan();
    [[nodiscard]] const map<string,City*> &GetEuroCities() const;
    int GetTotalDistance() const;
    void setStartingCity(const string& initial);
    Records& GetDistancesFromBerlin();
    void BaseCityPlan(const string& cityName, int numOfCities);

protected:
    Database cityDatabase{"./DB/cities-table.sqlite"};
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
