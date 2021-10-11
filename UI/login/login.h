#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include "sqlite3.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;

namespace Ui {
    using Record = std::vector<std::string>;
    using Records = std::vector<Record>;
    class login;
}

class login : public QDialog
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();

private slots:
            void on_loginButton_clicked();

private:
    static int select_callback(void *p_data, int num_fields, char **p_fields, char **p_col_names);
    static Ui::Records select_stmt(const char* stmt) ;
    static void sql_stmt(const char* stmt);
    Ui::Records usernameList;
    Ui::login *ui;
};

#endif // LOGIN_H