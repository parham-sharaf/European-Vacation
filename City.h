#pragma once
#include <vector>
#include <string>
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

    string name;
    vector<TradFood> tradFoodList;
    int distance;
};
