#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <QPoint>
using namespace std;


struct TradFood {
    string foodName;
    double cost;
    int amountBought;
    double amountSpent;

    void purchase(int amt)
    {
        amountBought = amt;
        amountSpent = amountBought * cost;
    };
};

class City
{
public:
//    City();
    void addFood(TradFood newFood);
    void deleteFood(int indexToDelete);
    void setCoordinate(int x, int y);
    QPoint getCoordinate();

    string name;
    vector<TradFood> tradFoodList;
    int distance;
    QPoint cityCoord;

};
