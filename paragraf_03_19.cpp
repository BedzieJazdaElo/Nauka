// Program z paragrafu 03_19

#include <iostream>
using namespace std;
int main()
{
    double szerokosc;
    decltype(szerokosc)  wysokosc;   								// `1

    unsigned int  obj = 5;           									// `2
    using  typ_roboczy = decltype(obj);  							// `3

    typ_roboczy  zmienna1;										// `4
    typ_roboczy  zmienna2;

    // ale nawet do typów złożonych
    typ_roboczy 	*wskaznik;   									// `5
    typ_roboczy 	tablica[10]; 									// `6
}
