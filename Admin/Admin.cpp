#include "Admin.h"

void Admin::AddNewCity(const string& cityName) {
    string sql;
    sql = "INSERT or IGNORE INTO city VALUES('" + cityName + "', 0, 0);";
    cityDatabase.select_stmt(sql.c_str());

    sql = "SELECT ending_city,kilometers FROM new_distance WHERE starting_city IS '" + cityName + "';";
    newDistanceList = adminDatabase.select_stmt(sql.c_str());
    for (auto & group: newDistanceList) {
        sql = "INSERT or IGNORE INTO distance VALUES ('" + cityName + "', '" + group.at(0) + "', " + group.at(1) + ");";
        cityDatabase.select_stmt(sql.c_str());
    }

    sql = "SELECT food_name,cost FROM new_food WHERE city_name IS '" + cityName + "';";
    newFoodList = adminDatabase.select_stmt(sql.c_str());
    for (auto & group: newFoodList) {
        sql = "INSERT or IGNORE INTO food VALUES('" + group.at(0) + "', " + to_string(std::stof(group.at(1))) + ", '" + cityName + "');";
        cityDatabase.select_stmt(sql.c_str());
    }

    sql = "SELECT starting_city,kilometers FROM new_distance WHERE ending_city IS '" + cityName + "';";
    newDistanceList = adminDatabase.select_stmt(sql.c_str());
    for (auto & group: newDistanceList) {
        sql = "INSERT or IGNORE INTO distance VALUES ('" + group.at(0) + "', '" + cityName + "', " + group.at(1) + ");";
        cityDatabase.select_stmt(sql.c_str());
    }
}

void Admin::RemoveCity(const string& cityName) {
    string sql;
    sql = "DELETE FROM city WHERE city_name IS '" + cityName + "';";
    cityDatabase.select_stmt(sql.c_str());
    sql = "DELETE FROM distance WHERE starting_city IS '" + cityName + "';";
    cityDatabase.select_stmt(sql.c_str());
    sql = "DELETE FROM food WHERE city_name IS '" + cityName + "';";
    cityDatabase.select_stmt(sql.c_str());
}

void Admin::ChangePrice(const string& cityName, const string& cityFood,
                        double cost) {
    for (auto food: euroCities.find(cityName)->second->tradFoodList)
        if (food.foodName == cityFood)
            food.cost = cost;
    string sql = "UPDATE food SET cost = " + to_string(cost) +
            " WHERE city_name IS '" + cityName + "' AND food_name IS '" + cityFood + "';";
    cityDatabase.select_stmt(sql.c_str());
}

void Admin::AddNewTradFood(const string &cityName, const string &cityFood,
                           double cost) {
    TradFood newTradFood;
    newTradFood.foodName = cityFood;
    newTradFood.cost = cost;
    euroCities.find(cityName)->second->tradFoodList.push_back(newTradFood);
    string sql = "INSERT INTO food VALUES('" + cityFood + "', " +
            to_string(cost).erase(to_string(cost).
            find_last_not_of('0') + 1, string::npos) + ", '" + cityName + "');";
    cityDatabase.select_stmt(sql.c_str());
}

void Admin::RemoveTradFood(const string &cityName, const string &cityFood) {
    for (int i = 0; i < euroCities.find(cityName)->second->tradFoodList.size(); i++)
        if (euroCities.find(cityName)->second->tradFoodList.at(i).foodName == cityFood)
            euroCities.find(cityName)->second->tradFoodList.erase(
                    euroCities.find(cityName)->second->tradFoodList.begin() + i);
    string sql = "DELETE FROM food WHERE city_name IS '" + cityName + "' AND food_name IS '" + cityFood +  "';";
    cityDatabase.select_stmt(sql.c_str());
}

vector<string> Admin::readNewCities() {
    string sql = "SELECT city_name FROM new_city;";
    vector<string> newCities;

    list = adminDatabase.select_stmt(sql.c_str());

    for (auto& group: list) newCities.push_back(group.at(0));

    return newCities;
}

vector<string> Admin::readAvailableCities() {
    string sql = "SELECT city_name FROM city;";
    vector<string> cities;

    list = cityDatabase.select_stmt(sql.c_str());

    for (auto& group: list) cities.push_back(group.at(0));

    return cities;
}

vector<string> Admin::readFoodFromCity(string cityName) {
    string sql = "SELECT food_name FROM food WHERE city_name IS '" + cityName + "';";
    vector<string> foods;

    list = cityDatabase.select_stmt(sql.c_str());

    for (auto& group: list) foods.push_back(group.at(0));

    return foods;
}