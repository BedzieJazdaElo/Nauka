// Program z paragrafu 11_03

#include <iostream>
using namespace std;
//*******************************************************
int main()
{
    int zmienna = 8, drugi = 4;											// 1
    int *wskaznik;														// 2
    wskaznik = &zmienna;												// 3
    // prosty wypis na ekranie;				   	   						// 4
    cout << "zmienna = " << zmienna
         << "\n a odczytana przez wskaznik = " << *wskaznik << endl;

    zmienna = 10; 													// 5
    cout << "zmienna = "<< zmienna
         << "\n a odczytana przez wskaznik = " << *wskaznik << endl;

    *wskaznik = 200;													// 6
    cout << "zmienna = " << zmienna
         << "\n a odczytana przez wskaznik = " << *wskaznik << endl;

    wskaznik = &drugi;													// 7
    cout << "zmienna = "<< zmienna
         << "\n a odczytana przez wskaznik = " << *wskaznik << endl;
}
