#include <string>
#include "../DB/Database/Database.h"
#include "../ManageCity/ManageCities.h"

using namespace std;
class Admin: public ManageCities
{
public:
    void AddNewCity(const string& cityName);
    void RemoveCity(const string& cityName);
    void ChangePrice(const string& cityName, const string& cityFood, double cost);
    void AddNewTradFood(const string& cityName, const string& cityFood, double cost);
    void RemoveTradFood(const string& cityName, const string& cityFood);

private:
    Database adminDatabase{"./DB/new-cities-table.sqlite"};
    Records newCityList;
    Records newDistanceList;
    Records newFoodList;

};