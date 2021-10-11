#include "City.h"
#include <iostream>

void City::addFood(TradFood newFood)
{
    tradFoodList.push_back(newFood);
    cout << "Added new food: " << newFood.foodName << " " << newFood.cost;
}

void City::deleteFood(int indexToDelete)
{
    tradFoodList.erase(tradFoodList.begin() + indexToDelete, tradFoodList.begin() + indexToDelete + 1);
}
