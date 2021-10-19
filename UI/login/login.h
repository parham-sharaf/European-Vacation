#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QMessageBox>
#include "SQLite/sqlite3/sqlite3.h"
#include <vector>
#include "../../DB/Database/Database.h"

namespace Ui {

    class login;
}

class login : public QDialog
{
Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();

    bool GetCred();

private slots:
    void on_loginButton_clicked();

private:

    Database usersDatabase{"C:/Users/4ktra/OneDrive/Desktop/College Work/CS 1D Homework/CS 1D Project 1/European Vacation Project/European-Vacation/DB/user-info.sqlite"};
    Records usernameList;
    Ui::login *ui;
    bool isAdmin;
};

#endif // LOGIN_H
