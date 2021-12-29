#pragma once
#include <string>
#include "../Database/Database.h"
#include "../ManageCity/ManageCities.h"
using namespace std;

class Admin: public ManageCities
{
public:
    void AddNewCity(const string& cityName);
    void RemoveCity(const string& cityName);
    void ChangePrice(const string& cityName, const string& cityFood, double cost);
    void AddNewTradFood(const string& cityName, const string& cityFood, double cost);
    void RemoveTradFood(const string &cityName, const string &cityFood);
    vector<string> readNewCities();
    vector<string> readAvailableCities();
    vector<string> readFoodFromCity(string cityName);

private:
    Database adminDatabase{"/home/parham/Personal/School/Saddleback/2021 Fall/CS 1D/European-Vacation/DB/new-cities-table.sqlite"};
    Records newDistanceList;
    Records newFoodList;
    Records list;
};
