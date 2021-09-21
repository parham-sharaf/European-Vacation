#include <iostream>
#include <sqlite3.h>
#include <fstream>
#include "spdlog/spdlog.h"

using namespace std;
void ReadDB(const char* path);
void OpenDB(const char* path, sqlite3* DB);

static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
    int i;
    for(i=0; i<argc; i++){
        cout << azColName[i] << ": " << argv[i] << endl;
    }
    cout << endl;
    return 0;
}

int main(int argc, char** argv)
{
    spdlog::set_level(spdlog::level::trace);
    sqlite3 *DB = nullptr;
    const char* path = "/home/parham/Personal/School/Saddleback/2021 Fall/CS 1D/European-Vacation/DB/cities-table.sqlite";
    ReadDB(path);
    sqlite3_close(DB);
}


void ReadDB(const char* path)
{
    sqlite3* DB;
    int exit = 0;

    int rc;
    string data("CALLBACK FUNCTION");
    string sql("SELECT * FROM food;");
    exit = sqlite3_open(path, &DB);
    if (exit) {
        spdlog::error("Error open DB {0}", sqlite3_errmsg(DB));
        return;
    }
    else {
        spdlog::info("Opened Database Successfully!");
    }

    rc = sqlite3_exec(DB, sql.c_str(), callback, (void*)data.c_str(), nullptr);

    if (rc != SQLITE_OK)
        spdlog::error("Error SELECT");
    else {
        spdlog::info("Operation OK!");
    }
}