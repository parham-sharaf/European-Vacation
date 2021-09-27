#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <sqlite3.h>
#include "spdlog/spdlog.h"
#include "City.h"
using namespace std;

using Record = std::vector<std::string>;
using Records = std::vector<Record>;

class ManageCities
{
public:


    ManageCities();
    void AddCity();
    // static int AddCityCallback(void *NotUsed, int argc, char **argv, char **azColName);

//private:
    static int select_callback(void *p_data, int num_fields, char **p_fields, char **p_col_names);
    Records select_stmt(const char* stmt) const;
    static void sql_stmt(const char* stmt);
    Records cityList;
    Records foodList;
    vector<City*> euroCities;
};