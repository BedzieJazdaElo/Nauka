// Program z paragrafu 16_08_02

#include <iostream>
#include <string>													// 1
using namespace std;
///////////////////////////////////// definicja klasy  /////////////////////////////////////////////////////////////////////////////////
class Tosoba
{
    string nazwisko; 												// 2
    int 	wiek;
public: 															// 3
    void zapamietaj(string napis, int lata); 								// 4
    //------------
    void wypisz() 													// 5
    {
        cout << "\t" << nazwisko << ", lat: " << wiek << endl;
    }
};
///////////////////////// koniec definicji klasy /////////////////////////////////////////////////////////////////////////////////////
void Tosoba::zapamietaj(string napis, int lata)							// 6
{
    nazwisko = napis;
    wiek = lata;
}
//*************************************************************
int main()
{
    Tosoba 	student1,
            student2,
            profesor,
            pilot;

    cout << "Dla informacji podaje, ze jeden obiekt klasy Tosoba\n ma rozmiar: "
         << sizeof(Tosoba) 											// 7
         << " bajtow. To samo inaczej: "
         << sizeof(student1) << endl;

    profesor.zapamietaj("Albert Einstein", 55); 							// 8
    student1.zapamietaj("Ruediger Schubart", 26);
    student2.zapamietaj("Claudia Bach", 25);
    pilot.zapamietaj("Neil Armstrong", 37);

    cout << "Po wpisaniu informacji do obiektow. Sprawdzamy: \n";
    cout << "dane z obiektu profesor\n";
    profesor.wypisz();

    cout << "dane z obiektu student1\n";
    student1.wypisz();

    cout << "dane z obiektu student2\n";
    student2.wypisz(); 												// 9

    cout << "dane z obiektu pilot\n";
    pilot.wypisz();

    cout << "Podaj swoje nazwisko (tylko nazwisko): ";
    string magazynek;
    cin >> magazynek;												// 10

    cout << "Podaj swoj wiek: ";
    int ile;
    cin >> ile;
    pilot.zapamietaj(magazynek, ile);		  	   						// 11

    cout << "Oto dane, ktore teraz sa zapamietane w obiektach profesor i pilot \n";
    profesor.wypisz();
    pilot.wypisz(); 				 	    								// 12
}
