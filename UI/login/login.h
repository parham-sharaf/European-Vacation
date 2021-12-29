#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QMessageBox>
#include <vector>
#include "../../Database/Database.h"

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
    Database usersDatabase{"/home/parham/Personal/School/Saddleback/2021 Fall/CS 1D/European-Vacation/DB/user-info.sqlite"};
    Records usernameList;
    Ui::login *ui;
    bool isAdmin;
};

#endif // LOGIN_H
