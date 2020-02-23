#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double windChill(double Temperature, double Speed)
{
    double wind = 0;
    wind = 35.74 + (0.621 * Temperature) - (35.75 * pow(Speed, 0.16)) + (0.4275 * Temperature * pow(Speed, 0.16));
    wind = round(wind);
    return wind;
}

int main()
{
cout<<"\t\t\t\tTemperature(F)\n";
cout<<"Wind(mph)\n";
    for (int rows = 40; rows >= -45; rows = rows - 5)
    {
        cout << setw(6) << rows;
    }

    for (int columns = 5; columns <= 60; columns = columns + 5)
    {
        cout <<endl << columns;
        for (int rows = 40; rows >= -45; rows = rows - 5)
        {
            cout << setw(6) << windChill(rows, columns);
        }
    }

    
    return 0;
}
