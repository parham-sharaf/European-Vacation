#include <string>
#include "../DB/Database/Database.h"

class Admin: public Database
{
public:
    AddNewCity(const string& cityName);

};