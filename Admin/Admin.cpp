#include "Admin.h"
#include "../ManageCity/ManageCities.h"


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
    for (auto & group: newDistanceList) {
        sql = "INSERT or IGNORE INTO distance VALUES ('" + group.at(0) + "', '" + cityName + "', " + group.at(1) + ");";
        cityDatabase.select_stmt(sql.c_str());
    }
    ReadData();
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
