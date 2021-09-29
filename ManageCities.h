#pragma once
#include <iostream>
#include <deque>
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
    void ReadData();
    void AddCity(const string& name);
    void EraseCity(const string& name);


    //private:
    static int select_callback(void *p_data, int num_fields, char **p_fields, char **p_col_names);
    static Records select_stmt(const char* stmt) ;
    static void sql_stmt(const char* stmt);
    Records cityList;
    Records distanceList;
    Records foodList;
    vector<City*> euroCities;
    deque<City*> travelPlan;
};