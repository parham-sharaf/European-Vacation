#include "login.h"
#include "ui_login.h"
#include <QMessageBox>

login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}

void login::on_loginButton_clicked()
{
    QString username = ui->username->text();
    QString password = ui->password->text();

    if (username == "Hiep Ton" && password == "1234") {
        QMessageBox msgBox;
        msgBox.setText("Account Connected");
        msgBox.exec();
    }
    else {
        QMessageBox msgBox;
        msgBox.setText("Account Not Found");
        msgBox.exec();
    }
}

