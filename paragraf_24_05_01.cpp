// Program z paragrafu 24_05_01


#include <iostream>
#include <vector>
using namespace std;
//////////////////////////////////////////////////////////////////////////////////////////////
class K
{
    double re; 					// jakieś tam składniki-dane
    double im;
public:
    K() : re(0), im(0) { }				// jakieś tam konstruktory
    // ...
    // funkcje, których adresy będziemy umieszczać w tablicy  				// 1
    double 	fun0()			{
        cout << "f. zerowa" << endl;
        return 100;
    }
    double 	kolowanie()		{
        cout << "f. kolowanie" << endl;
        return 101;
    }
    double 	zaladunek()		{
        cout << "f. zaladunek" << endl;
        return 102;
    }
    double 	tankowanie()		{
        cout << "f. tankowanie" << endl;
        return 103;
    }

    // definicja tablicy wskaźników
    double (K::*tablica[4])();												// 2

    using Typfunskl = decltype(&K::kolowanie);  							// 3
    // definicja wektora wskaźników
    vector<Typfunskl>  wektor;  											// 4

    void wypelnienie_tablicy();
    void wypelnienie_wektora();

    void wywolaj_funkcje_nr(int nr) 										// 5
    {
        // Tak wywołuje się jedną z funkcji (tę, której adres jest zapamiętany na pozycji nr).
        cout << "z wewn. tablicy wskaznikow: \t";
        (this->*tablica[nr]) ();											// 6
        cout << "z wewn. wektora wskaznikow:\t";
        (this->*wektor[nr]) ();											// 7
    }
};
//////////////////////////////////////////////////////////////////////////////////////////////
void K::wypelnienie_tablicy()
{
    // Tak zapełnia się tablicę adresami funkcji.
    tablica[0] = &K::fun0;												// 8
    tablica[1] = &K::kolowanie;
    tablica[2] = &K::zaladunek;
    tablica[3] = &K::tankowanie;
}
//*******************************************************
void K::wypelnienie_wektora()
{
    // Tak zapełnia się wektor adresami funkcji.
    wektor.push_back(&K::fun0);										// 9
    wektor.push_back(&K::kolowanie);
    wektor.push_back(&K::zaladunek);
    wektor.push_back(&K::tankowanie);
}
//*******************************************************
int main()
{
    K orbiter;
    // ------------------
    cout << "Praca z tablica lub wektorem, ktore sa wewnatrz klasy" 	<< endl;

    orbiter.wypelnienie_tablicy();
    orbiter.wypelnienie_wektora();

    orbiter.wywolaj_funkcje_nr(3);	 		           						// 10
    // ------------------
    cout << "Inna ewentualnosc: tablica/wektor moze byc na zewnatrz klasy" << endl;

    // definicja zewnętrznego menu-tablicy
    double (K::*zmT[4])();		// albo inaczej 	K::Typfunskl	zmT[40];		// 11

    // ładujemy do niej treść (adresy funkcji składowych)
    zmT[0] = &K::fun0;													// 12
    zmT[1] = &K::kolowanie;
    zmT[2] = &K::zaladunek;
    zmT[3] = &K::tankowanie;
    // definicja zewnętrznego menu-wektora menu
    vector<K::Typfunskl>  zmV 											// 13
    = {	&K::fun0,  		&K::kolowanie,					// 14
        &K::zaladunek, 	&K::tankowanie
      };

    // wywołanie funkcji (tej, której adres jest zapamiętany pod indeksem 2)
    cout << "z zewn. menu tablicowego: \t";
    (orbiter.*zmT[2]) ();												// 15
    cout << "z zewn. menu wektorowego: \t";
    (orbiter.*zmV[2]) ();												// 16
}
