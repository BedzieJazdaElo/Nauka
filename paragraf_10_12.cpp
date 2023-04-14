// Program z paragrafu 10_12

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;
void pokaz_wektor2D(vector<vector<int>> tabl, string opis);
void modyfikuj_wektor2D(vector<vector<int>> &tabl);
void pokaz_wektor1D(vector<int> tabl, string opis);
//***********************************************************
int main()
{
    // Definicja bez żadnych rozmiarów i inicjalizacji
    vector<vector<int> >  plansza;
    pokaz_wektor2D(plansza, "plansza (definiowana bez inicjalizacji)  ");
    // plansza[0][1] = 5 ;  				// błąd bo tablica "nie napompowana"

    // Definicja tablicy o rozmiarach wziętych z inicjalizacji
    vector<vector<int>>  arkusz {
        { 10, 20, 25} , 	  // dane dla rzędu 0
        { 44, 46, 48} 		   // dane dla rzędu 1
    } ;
    pokaz_wektor2D(arkusz, "arkusz liczb (z klamra inicjalizacyjna)" );

    // Rozmiary ze zwykłych zmiennych obiektów
    unsigned long int  liczba_rzedow = 3;
    unsigned long int liczba_kolumn = 5;

    // Definicja w jednej (długiej instrukcji) z "napompowaniem"
    vector<vector<int> >  tabliczka {
        liczba_rzedow,   				// ile elementów (czyli rzędów)
        vector<int>(liczba_kolumn) 		// czym te rzędy są (6 elementowymi wektorami )
    };
    tabliczka[1][3] = 222;
    tabliczka[0][3] = 111;
    pokaz_wektor2D(tabliczka, "tabliczka" );

    // Sami pompujemy balon pustej, zdefiniowany wcześniej tablicy
    vector<vector<int>> rozklad;
    rozklad.resize(liczba_rzedow);   						// napompowanie pionowe
    for(unsigned int rz = 0 ; rz < liczba_rzedow; ++rz)
    {
        rozklad[rz].resize(liczba_kolumn);  				// napompowanie konkretnego rzędu
    }
    // zrobione, możemy korzystać z tablicy
    rozklad[1][1] = 11;
    pokaz_wektor2D(rozklad, "Rozklad Jazdy");
    rozklad[1].resize(3);   // skrócenie rzędu 1 do długości 3 elementow
    pokaz_wektor2D(rozklad, "po skróceniu rzedu nr 1 rozklad jazdy - ");
    rozklad.resize(1);
    pokaz_wektor2D(rozklad, "po zmiejszaniu ilosci rzedow ");

    // Teraz pushback, pop_back -
    vector<vector<int> >  pole_bitwy;
    cout << "\nDodawanie rzedow lub kolumn -------------------------" << endl;
    for(unsigned int rz = 0 ; rz < liczba_rzedow ; ++rz)
    {
        // przygotowanie rzędu
        vector<int> dodawany_rzad;
        for(unsigned int k = 0 ; k < liczba_kolumn ; ++k)
            dodawany_rzad.push_back(100*rz + k); 		// wstawienie doń właściwych wartości
        // dodanie całego rzędu do tablicy bitw
        pole_bitwy.push_back( dodawany_rzad);
        pokaz_wektor2D(pole_bitwy, "Biezaca tresc pola bitwy morskiej");
    }
    pole_bitwy[1].push_back(750); 	// dodanie elementu do konca rzedu 0
    pole_bitwy.push_back(vector<int> { 11, 12, 13}  );  // dodanie nowego rzędu (do końca tablicy)
    pokaz_wektor2D(pole_bitwy, "pole_bitwy (po dwukrotnej zmianie rozmiarow)" );

    // skracanie rozmiarów za pomocą pop_back
    pole_bitwy[0].pop_back();    				// usuniecie ostatniego elementu z rzedu 0
    pokaz_wektor2D(pole_bitwy, "pole bitwy (po pop_back jednego elementu)");
    pole_bitwy.pop_back(); 	  					 // usunięcie ostatniego rzędu tej tablicy
    pokaz_wektor2D(pole_bitwy, "pole bitwy (po pop_back jednego rzedu)");

    cout << "========Funkcja mogaca modyfikowac wektor 2D " << endl;
    modyfikuj_wektor2D(pole_bitwy);
    pokaz_wektor2D(pole_bitwy, "Po modyfikacji tresc pola bitwy morskiej");

    // wysłanie rzędu do funkcji przyjmującej vector<int>
    pokaz_wektor1D(arkusz[1], "rzad nr 1 arkusza");
    pokaz_wektor1D(pole_bitwy[1], "rzad nr 1 pola bitwy");
} //***********************************************************
void pokaz_wektor2D(vector<vector<int>> tabl, string opis)
{
    cout << "\n"<< opis << " ma rzedow: "  << tabl.size()  << endl;
    for(unsigned int r = 0 ; r < tabl.size() ; ++r)
    {
        cout << "Rzad nr " << r << ", dlugosc " << 	tabl[r].size()   << " ---> |";
        for( unsigned int k = 0 ; k < tabl[r].size() ; ++k) 	 cout << setw(4) << tabl[r][k] << " | " ;
        cout << endl;
    }
}
//***********************************************************
void pokaz_wektor2Dx(vector<vector<int>> tabl, string opis)
{
    cout << "\n"<< opis << " ma rzedow: "  << tabl.size()  << endl;
    for(auto rzad : tabl)
    {
        cout << "Rzad o dlugosci " << 	rzad.size()   << " ---> |";
        for( auto elem : rzad)
            cout << setw(4) << elem << " | " ;
        cout << endl;
    }
}
//***********************************************************
void modyfikuj_wektor2D(vector<vector<int>> & tabl)
{
#define TRADYCYJNYM_FOR    false
#if TRADYCYJNYM_FOR									// kompilacja warunkowa
    cout << "Modyfikacja tradycyjnym for" << endl;
    for(unsigned int r = 0 ; r < tabl.size() ; ++r)
    {
        for( unsigned int k = 0 ; k < tabl[r].size() ; ++k) {
            tabl[r][k]  = - tabl[r][k] ;
        }
    }
#else
    cout << "Modyfikacja zakresowym for" << endl;
    for(auto &  rzad : tabl )
    {
        for(auto & elem : rzad ) {
            elem = -elem;
        }
    }
#endif
}
//***********************************************************
void pokaz_wektor1D(vector<int> tabl, string opis)
{
    cout << "\n"  <<  opis << " ma elementow: "  << tabl.size() << endl;
    int dlugosc_kreski = tabl.size() * 7;
    string kreska(dlugosc_kreski,  '*');
    cout << kreska << "\n|";
    for(auto elem : tabl)
        cout << setw(4) << elem << " | " ;
    cout << '\n' << kreska << endl;
}
