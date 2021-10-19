#pragma once
#include <string>
#include "../DB/Database/Database.h"
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
    Database adminDatabase{"C:/Users/4ktra/OneDrive/Desktop/College Work/CS 1D Homework/CS 1D Project 1/European Vacation Project/European-Vacation/DB/new-cities-table.sqlite"};
//    Database cityDatabase{"./DB/new-cities-table.sqlite"};
//    Records newCityList;
    Records newDistanceList;
    Records newFoodList;
    Records list;
};
