#include "Database.h"


Database::Database(const char* path)
{
    if (sqlite3_open(path, &db) != SQLITE_OK) {
        std::cerr << "Could not open database.\n";
        return;
    }
}

void Database::sql_stmt(const char* stmt)
{
    char *errmsg;
    int ret = sqlite3_exec(db, stmt, nullptr, nullptr, &errmsg);
    if (ret != SQLITE_OK) {
        std::cerr << "Error in select statement " << stmt << "[" << errmsg << "]\n";
    }
}

Records Database::select_stmt(const char* stmt)
{
    Records thisRecord;
    char *errmsg;
    int ret = sqlite3_exec(db, stmt, select_callback, &thisRecord, &errmsg);
    if (ret != SQLITE_OK) {
        std::cerr << "Error in select statement " << stmt << "[" << errmsg << "]\n";
    }
    else {
        std::cerr << thisRecord.size() << " results returned.\n";
    }

    return thisRecord;
}

int Database::select_callback(void *p_data, int num_fields, char **p_fields, char **p_col_names)
{
    auto* records = static_cast<Records*>(p_data);
    try {
        records->emplace_back(p_fields, p_fields + num_fields);
    }
    catch (...) {
        // abort select on failure, don't let exception propagate thru sqlite3 call-stack
        return 1;
    }
    return 0;
}