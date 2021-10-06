#pragma once
#include <iostream>
#include <deque>
#include <vector>
#include <string>
#include <sqlite3.h>
#include <algorithm>
//#include "spdlog/spdlog.h"
#include "City/City.h"
#include <QWidget>
#include <QPainter>

using namespace std;

using Record = std::vector<std::string>;
using Records = std::vector<Record>;

class ManageCities : public QWidget
{
public:
    ManageCities();
    void ReadData();
    void AddCity(const string& name, deque<City*>& planner);
    void EraseCity(const string& name, deque<City*>& planner);
    void ShortestPath();
    deque<City*>& GetTravelPlan();
    vector<City*>& GetEuroCities();
    int GetTotalDistance(const deque<City*>& planner) const;
    void setStartingCity(const string& initial);
    void paintEvent(QPaintEvent *event) override;

private:

    Records cityList;
    Records distanceList;
    Records foodList;

    static int select_callback(void *p_data, int num_fields, char **p_fields, char **p_col_names);
    static Records select_stmt(const char* stmt) ;
    static void sql_stmt(const char* stmt);

    vector<City*> euroCities;
    deque<City*> travelPlan;

    string startingCity;
};
