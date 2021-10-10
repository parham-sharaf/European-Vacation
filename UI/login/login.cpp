#include "login.h"
#include "ui_login.h"
#include <QMessageBox>

sqlite3 *usersDB;

login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    const char* path = "C:/Users/4ktra/OneDrive/Desktop/CS 1D Homework/CS 1D Project 1/European Vacation Project/European-Vacation/DB/user-info.sqlite";
    if (sqlite3_open(path, &usersDB) != SQLITE_OK) {
        std::cerr << "Could not open database.\n";
        return;
    }

    ui->setupUi(this);
    this->setWindowTitle("Log In");

    usernameList = select_stmt("SELECT * FROM users;");
}

login::~login()
{
    delete ui;
}

void login::sql_stmt(const char* stmt)
{
    char *errmsg;
    int ret = sqlite3_exec(usersDB, stmt, nullptr, nullptr, &errmsg);
    if (ret != SQLITE_OK) {
        std::cerr << "Error in select statement " << stmt << "[" << errmsg << "]\n";
    }
}

Ui::Records login::select_stmt(const char* stmt)
{
    Ui::Records thisRecord;
    char *errmsg;
    int ret = sqlite3_exec(usersDB, stmt, select_callback, &thisRecord, &errmsg);
    if (ret != SQLITE_OK) {
        std::cerr << "Error in select statement " << stmt << "[" << errmsg << "]\n";
    }
    else {
        std::cerr << thisRecord.size() << " results returned.\n";
    }

    return thisRecord;
}

int login::select_callback(void *p_data, int num_fields, char **p_fields, char **p_col_names)
{
    auto* records = static_cast<Ui::Records*>(p_data);
    try {
        records->emplace_back(p_fields, p_fields + num_fields);
    }
    catch (...) {
        // abort select on failure, don't let exception propogate thru sqlite3 call-stack
        return 1;
    }
    return 0;
}

void login::on_loginButton_clicked()
{
    bool isLoginCorrect = false;
    QString username = ui->username->text();
    QString password = ui->password->text();

    QMessageBox msgBox(this);
    msgBox.setWindowTitle("Account Information");

    for (auto& group: usernameList) {
        if ( QString::fromStdString(group.at(0)) == username &&
             QString::fromStdString(group.at(1)) == password) {
            isLoginCorrect = true;
            break;
        }
    }

    if (isLoginCorrect) {
        QAbstractButton *close = msgBox.addButton(tr("OK"), QMessageBox::AcceptRole);

        msgBox.setText("<center>Account Connected</center>");
        msgBox.setInformativeText("<center>Click OK to continue</center>");
        msgBox.setIcon(QMessageBox::Information);
        msgBox.setStyleSheet("QLabel{font-size: 12px;} QPushButton{width:72px; font-size: 12px;}");
        msgBox.exec();

        if (msgBox.clickedButton() == close) {
            QDialog::reject();
            std::cerr << "Login Dialog Closed\n";
        }
    }
    else {
        msgBox.setText("<center>Account Not Found</center>");
        msgBox.setInformativeText("<center>Please try again</center>");
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setStyleSheet("QLabel{font-size: 12px;} QPushButton{width:72px; font-size: 12px;}");
        msgBox.exec();
    }
}

