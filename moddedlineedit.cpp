#include "moddedlineedit.h"

moddedLineEdit::moddedLineEdit()
{

}

void moddedLineEdit::updateAccessibleName()
{
    setAccessibleName(this->text());
}
