// Program z paragrafu 35_02_02

#include <iostream>
#include <sstream>   				//  bo użyjemy klasy istringstream   		// 1
#include <vector>
#include <fstream>
using namespace std;
bool szukacz(istringstream & s, 	string  etykietka,  	double & zmienna);   		// 2
//*******************************************************
int main()
{
    // Treść w postaci stringu surowego, dla miłej odmiany
    istringstream  nastawy(
        R"(Czynnik zyromagnetyczny 3.4
wzmocnienie 72.6 decybele
kwota_wplaty 237500
wspolczynniki_kalibracji   0.34   0.92   0.1
powiekszenie_mikroskopu 580 x )"
    );    																// 3
    double x;

    string etykietka  { "<B>powiekszenie_mikroskopu<W0>"};
    cout << "\nPrzeczytamy teraz liczbe" << endl;
    if(szukacz(nastawy, etykietka, x))  {  									// 4
        cout << "a) " <<  etykietka << " = " << x << endl;
    }
    cout << "\nPrzeczytamy teraz inna liczbe" << endl;
    if(szukacz(nastawy, "<B>zyromagnetyczny<W0>", x))   							// 5
    {
        cout << "b)  x = " << x << endl;
    }
    cout << "\nPrzeczytamy teraz inna liczbe" << endl;
    if(szukacz(nastawy, "<B>modul Younga<W0>", x)) 	{							// 6
        cout << "c)  x = " << x << endl;
    }
    else {
        cout << "Niewczytane, może to był parametr opcjonalny?\n";
    }

    vector <double> factor;
    cout << "\nPrzeczytamy teraz inna liczbe" << endl;
    if(szukacz(nastawy, "<B>wspolczynniki_kalibracji<W0>", x)) 	{					// 7
        cout << "d)  x = " << x << endl;
        factor.push_back(x);   											// 8
        while (nastawy >> x)  {		// czytaj liczby double, dopóki się da 		// 9
            factor.push_back(x);
        }
        for(auto y : factor) cout << " " << y;  								// 10
        cout << endl;
        // strumień jest w stanie błędu fail, bo próbował czytać liczby do skutku
        if(nastawy.fail() )
            nastawy.clear(nastawy.rdstate() & ~ios::failbit);  				// 11
        // mogło się to zdarzyć na samym końcu pliku, więc
        if(nastawy.eof() )
            nastawy.clear(nastawy.rdstate() & ~ios::eofbit);   			// 12
    }

    if(szukacz(nastawy, "<B>wzmocnienie<W0>", x)) 	{							// 13
        cout << "e)  wzmocnienie = " << x << endl;
    }
}
//*******************************************************
bool szukacz(istringstream & s, string etykietka, double & zmienna) 			// 14
{
    string tr = s.str();    													// 15
    size_t  nr = tr.find(etykietka);  										// 16
    if(nr == string::npos)  {
        cout << "Blad: Nazwa danej (etykietka) >" << etykietka << "< nie znaleziona" << endl;
        return false;
    }
    cout << "Etykietka [" << etykietka <<"] znaleziona na pozycji " << nr << endl;

    s.seekg(nr + etykietka.length());  	// przeskok za etykietkę					// 17
    double wartosc;
    s >> wartosc;  													// 18
    if(!s)  { 															// 19
        cout << "Blad wczytywania wartosci po etykietce " << etykietka << endl;
        return false;
    } else {
        cout << "Za nia jest wartosc " << wartosc << endl;
        zmienna = wartosc;  											// 20
        return true;
    }
}
