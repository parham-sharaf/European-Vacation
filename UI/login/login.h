#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include "sqlite3.h"
#include <string>
#include <iostream>
#include <vector>
#include "../../DB/Database/Database.h"
using namespace std;

namespace Ui {

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

    Database usersDatabase{"./DB/user-info.sqlite"};
    Records usernameList;
    Ui::login *ui;
};

#endif // LOGIN_H