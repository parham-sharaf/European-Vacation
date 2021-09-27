#pragma once
#include <vector>
#include <string>
using namespace std;

struct TradFood {
    string foodName;
    double cost;
};

class City
{
public:
//    City();

    string name;
    vector<TradFood> tradFoodList;
    int distance;
};