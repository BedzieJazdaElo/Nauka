// Program z paragrafu 17_03

 #include <iostream>
#include <iomanip>   													// 1
#include <string>
using namespace std;
//*****************************************************************
void pokaz(string opis, string wlasciwy)  									// 2
{
    cout << "Tresc obiektu " << setw(15)  									// 3
         << opis << ": [" << wlasciwy << "]\n";
}
//*****************************************************************
int main()
{
    string napisA; 														// 4
    string napisB1("Jakis tekst"); 										// 5

    char tablica[20] = { "Natenczas Wojski" };
    string napisB2(tablica); 												// 6

    string wiadomosc(&tablica[5]);										// 7

    string ostrzezenie("Awaria studni", 8);									// 8

    string gwiazdki(25, '*');												// 9

    string litery({'a', 'b', 'c'});  											// 10

    string jedna(1, 'a'); 													// 11
    string sama({'a'});  				// C++11 								// 12

    string inny = "ABCDEFGH";
    string nowy(inny, 4, 2);  												// 13
    //====== Dla sprawdzenia ===========
    pokaz("napisA", napisA);
    pokaz("napisB1", napisB1);
    pokaz("napisB2", napisB2);
    pokaz("wiadomosc", wiadomosc);
    pokaz("ostrzezenie", ostrzezenie);
    pokaz("gwiazdki", gwiazdki);
    pokaz("nowy", nowy);
}
