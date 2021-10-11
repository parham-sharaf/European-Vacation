#pragma once
#include <iostream>
#include <sqlite3.h>
#include <vector>
#include <string>

using namespace std;

using Record = std::vector<std::string>;
using Records = std::vector<Record>;

static sqlite3 *db;

class Database {
public:
    explicit Database(const char* path);
protected:
    static Records select_stmt(const char* stmt) ;

private:
    static int select_callback(void *p_data, int num_fields, char **p_fields, char **p_col_names);
    static void sql_stmt(const char* stmt);
};

