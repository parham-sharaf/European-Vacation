#pragma once
#include <iostream>
#include "SQLite/sqlite3/sqlite3.h"
#include <vector>
#include <string>

//using namespace std;

using Record = std::vector<std::string>;
using Records = std::vector<Record>;


class Database {
public:
    explicit Database(const char* path);
    Records select_stmt(const char* stmt) ;

private:
    Database();
    static int select_callback(void *p_data, int num_fields, char **p_fields, char **p_col_names);
    void sql_stmt(const char* stmt);
    sqlite3 *db;
};

