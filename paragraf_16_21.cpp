// Program z paragrafu 16_21


#include <string>
#include <iostream>
#include <vector>
using namespace std;
//*******************************************************
class Twynik_skoku {     											// 1
public:
    double dlugosc;
    string nazwisko;
};
//*******************************************************
int main ()
{
    Twynik_skoku   zawodnikA;  										 // 2
    zawodnikA.dlugosc = 115.5;    									// 3
    zawodnikA.nazwisko = "Mateusz Szanta";

    Twynik_skoku    zawodnikB { 112.0, "Olaf Dziurski"};   				// 4
    Twynik_skoku    zawodnikC = { 117.2, "Gen Krawczyk"};   			// 5
    Twynik_skoku    zawodnikD = { 100 };   							// 6

    vector<Twynik_skoku> zestawienie;     							// 7
    zestawienie.push_back(zawodnikA);
    zestawienie.push_back(zawodnikB);
    zestawienie.push_back(zawodnikC);
    zestawienie.push_back(zawodnikD);
    for(auto x : zestawienie)
    {
        cout << x.nazwisko << " skoczyl na odleglosc: " << x.dlugosc << endl;
    }
}

