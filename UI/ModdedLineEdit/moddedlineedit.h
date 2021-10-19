#ifndef MODDEDLINEEDIT_H
#define MODDEDLINEEDIT_H
#include <QLineEdit>
#include <iomanip>

class moddedLineEdit: public QLineEdit
{
Q_OBJECT

public:
    moddedLineEdit();

public slots:
    void updateAccessibleName();
};

#endif // MODDEDLINEEDIT_H
