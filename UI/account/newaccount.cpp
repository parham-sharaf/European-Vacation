#include "newaccount.h"
#include "ui_newaccount.h"

newAccount::newAccount(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::newAccount)
{
    ui->setupUi(this);
}

newAccount::~newAccount()
{
    delete ui;
}
