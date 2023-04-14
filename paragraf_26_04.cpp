// Program z paragrafu 26_04


#include <iostream>
using namespace std;
constexpr   int 	rozmiar = 1024;										// 1
//////////////////////////////////////////////////////////////////////////////////////////////
class Twidmo
{
public:
    int kanal[rozmiar]; 													// 2
    Twidmo(int wart = 0); 				// konstruktor
    Twidmo operator+(int ); 				// przeładowany operator
};
//*******************************************************
Twidmo::Twidmo(int wart) 												// 3
{
    for(int i = 0 ; i < rozmiar ; ++i)    kanal[i] = wart;
}
//*******************************************************
Twidmo Twidmo::operator+(int liczba)
{
    Twidmo rezultat;
    for(int i = 0 ; i < rozmiar ; ++i)	rezultat.kanal[i] = kanal[i] + liczba; 		// 4
    return rezultat;
}
//*******************************************************
int main()
{
    Twidmo kobalt(5);													// 5
    Twidmo nowe; 													// 6
    nowe = kobalt + 100; 												// 7
    cout << "Przykladowo patrzymy na kanal 44. \nWidmo 'kobalt' ma tam: "
         << kobalt.kanal[44]
         << "\na w widmie 'nowe' jest tam: " << nowe.kanal[44] << endl;
    nowe = nowe + 700;												// 8
    cout <<"A teraz w kanale 44 obiektu 'nowe' jest: " << nowe.kanal[44] << endl;
}

