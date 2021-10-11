#ifndef NEWACCOUNT_H
#define NEWACCOUNT_H

#include <QDialog>

namespace Ui {
class newAccount;
}

class newAccount : public QDialog
{
    Q_OBJECT

public:
    explicit newAccount(QWidget *parent = nullptr);
    ~newAccount();

private:
    Ui::newAccount *ui;
};

#endif // NEWACCOUNT_H
