// Program z paragrafu 27_07_01

#include <iostream>
#include <vector>
using namespace std;
//////////////////////////////////////////////////////////////////////////////////////////////
class Trojka
{
public:
    double	x, y, z;
    // ––––––––––––––– konstruktor ––––
    Trojka(double a, double b, double c)	:	x(a), y(b), z(c)					// 1
    { }
    // ––––––––––––––– kilka zwykłych funkcji składowych
    void podwojenie()
    {
        x *= 2;
        y *= 2;
        z *= 2;
    }
    // ––––––––––––––
    void wypisz()
    {
        cout << "x= "<< x << ", y= "<< y <<", z= "<< z << endl;
    }
};
//////////////////////////////////////////////////////////////////////////////////////////////
class Tsprytny_wskaznik
{
    Trojka *wsk;														// 2
    vector<Trojka *>  pamietnik;											// 3
public:
    // ––––––––––––– operator przypisania ––––
    void operator=(Trojka* w)											// 4
    {
        wsk = w;
    }
    // ––––––––––––– konstruktor (także domniemany!)
    Tsprytny_wskaznik(Trojka * adr = nullptr)  : wsk(adr)						// 5
    {   }

    // ––––––––––––– przeładowanie operatora ->
    Trojka * operator->();
    void raport(long unsigned int ile_ostatnich);
};
//*******************************************************
Trojka * Tsprytny_wskaznik::operator->()									// 6
{
    pamietnik.push_back(wsk);		// sprytna akcja: wpisujemy do akt!		// 7
    return wsk;					// zwykła akcja
}
//*******************************************************
void Tsprytny_wskaznik::raport(unsigned long ile_ostatnich)					// 8
{
    int ile_wypisac = min(ile_ostatnich, pamietnik.size() ); // ile można w tym wypadku	// 9

    cout << "Ostatnie " << ile_wypisac << " (z " << pamietnik.size()
         << ") przypadkow uzycia odbylo sie dla obiektow o adresach:\n";
    int ostatni_indeks = pamietnik.size() -1;
    // wypisujemy od końca
    for(int i = 0 ; i < ile_wypisac   ; ++i)
    {
        cout << i << ") "	<< pamietnik[ostatni_indeks - i];					// 10
        cout << (( (i+1) % 4)? ", " : "\n") << flush;							// 11
    }
    cout << endl;
}
//*******************************************************
int main()
{
    double m;
    Trojka w1(1, 1, 1);

    Trojka				*zwykly_wsk;									// 12
    Tsprytny_wskaznik		zreczny_wsk;									// 13
    zwykly_wsk	= &w1;
    zreczny_wsk	= &w1;												// 14

    cout << "Przypisanie do m za pomoca zwyklego wskaznika \n";
    m = zwykly_wsk->x;
    cout << "m = " << m << endl;

    cout << "Przypisanie do m za pomoca zrecznego wskaznika \n";
    m = zreczny_wsk->x;												// 15
    cout << "m = " << m << endl;

    Trojka	w2(2, 2, 2),	w3(3, 3, 3),	w4(44, 10, 1);   // def. trzech obiektów
    cout << "Prace na Trojkach za pomoca zrecznego wskaznika" << endl;
    zreczny_wsk = &w2;
    zreczny_wsk->podwojenie();			 							// 16
    zreczny_wsk->wypisz();
    zreczny_wsk.raport(5);

    zreczny_wsk = &w3;
    zreczny_wsk->podwojenie();
    zreczny_wsk->wypisz();
    zreczny_wsk.raport(8);

    zreczny_wsk = &w4;
    zreczny_wsk->podwojenie();
    zreczny_wsk->wypisz();

    zreczny_wsk = &w3;
    zreczny_wsk->wypisz();
    for(int nr = 0 ; nr < 12 ; ++nr) 	{
        zreczny_wsk->podwojenie();
    }
    zreczny_wsk->wypisz();
    zreczny_wsk.raport(8);				 								// 17
}
