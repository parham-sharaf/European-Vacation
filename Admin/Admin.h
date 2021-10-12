#include <string>
#include "../DB/Database/Database.h"
#include "../ManageCity/ManageCities.h"

using namespace std;
class Admin: ManageCities
{
public:
    void AddNewCity(const string& cityName);
    void RemoveCity(const string& cityName);

private:
    Database adminDatabase{"./DB/new-cities-table.sqlite"};
    Records newCityList;
    Records newDistanceList;
    Records newFoodList;

};