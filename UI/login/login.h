#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include "sqlite3.h"
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

    Database usersDatabase{"./DB/user-info.sqlite"};
    Records usernameList;
    Ui::login *ui;
    bool isAdmin;
};

#endif // LOGIN_H