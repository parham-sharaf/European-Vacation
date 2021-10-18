#include "City.h"

void City::addFood(TradFood newFood)
{
    tradFoodList.push_back(newFood);
}

void City::deleteFood(int indexToDelete)
{
    tradFoodList.erase(tradFoodList.begin() + indexToDelete, tradFoodList.begin() + indexToDelete + 1);
}

void City::setCoordinate(int x, int y) {
    cityCoord.setX(x);
    cityCoord.setY(y);
}

QPoint City::getCoordinate() {
    return cityCoord;
}
