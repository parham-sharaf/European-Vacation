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

    QMessageBox msgBox;
    msgBox.setWindowTitle("Account Information");

    if (username == "Hiep Ton" && password == "1234") {
        msgBox.setText("Account Connected");
        msgBox.setInformativeText("Click OK to continue");
        msgBox.setStyleSheet("QLabel{min-width:200 px; font-size: 12px;} QPushButton{ width:72px; font-size: 12px; }");
        msgBox.exec();
    }
    else {
        msgBox.setText("Account Not Found");
        msgBox.setInformativeText("Please try again");
        msgBox.setStyleSheet("QLabel{min-width:200 px; font-size: 12px;} QPushButton{ width:72px; font-size: 12px; }");
        msgBox.exec();
    }
}

