// Program z paragrafu 21_09

#include <string>
#include <iostream>
using namespace std;
//////////////////////////////////////////////////////////////////////////////////////////////
class Tprzedzial														// 1
{
    const int 	brzeg_dolny;  		 		// dolna krawędź przedziału 		// 2
    int 		brzeg_gorny;				// górna krawędź przedziału		// 3
    string 	nazwa_pliku;

    int liczba_spacji  {0};   	// to tylko kosmetyka: wcięcia tekstu ekranowego 		// 4
public:
    // najbardziej pracowity, ale zwykły konstruktor
    Tprzedzial(int k1, int k2, string nazwa) :   								// 5
        brzeg_dolny { (k1< k2)? k1 : k2 },		// 6
    nazwa_pliku {nazwa}
    {
        cout << uskok() << "Pracuje cialo k-tora   Tprzedzial(int, int, string)" << endl;
        brzeg_gorny = (k1 < k2) ? k2 : k1; 								// 7
        // instrukcje zapisujące informację do pliku o nazwie: nazwa_pliku
        // ...
    }
    //---------------------------------------------------
    Tprzedzial() : Tprzedzial {0, 4096, "dane.txt"} 							// 8
    {
        cout << uskok() <<  "Pracuje cialo k-tora   Tprzedzial()" << endl;
    }
    //---------------------------------------------------
    Tprzedzial(string napis, int brzeg) : Tprzedzial { 300, brzeg, napis}			// 9
    {
        cout << uskok() << "Pracuje cialo k-tora   Tprzedzial(string, int)" << endl;
    }
    //---------------------------------------------------
    Tprzedzial(int nr) : Tprzedzial { "bramka" + to_string(nr) + ".txt", 0 }			// 10
    {
        cout << uskok()  << "Pracuje cialo k-tora   Tprzedzial(int)" << endl;
    }
    //---------------------------------------------------
    void opisz(string txt) {
        cout << txt << ".  Brzegi: dolny=" <<  brzeg_dolny << ", gorny=" << brzeg_gorny
             << "; Plik '" << nazwa_pliku << "'\n" << endl;
    }
    // inne funkcje składowe
    string  uskok() {
        return string(liczba_spacji++, ' ');      // kosmetyka 		// 11
    }
};
//////////////////////////////////////////////////////////////////////////////////////////////
//*******************************************************************
int main()
{
    Tprzedzial 	p0 { 530, 500, "linia511.txt" }; 							// 12
    p0.opisz("OBIEKT p0");												// 13

    Tprzedzial 	p1;   												// 14
    p1.opisz("OBIEKT p1");

    Tprzedzial 	p2 { "szeroka.txt", 10 };    								// 15
    p2.opisz("OBIEKT p2");

    Tprzedzial 	p3 { 73 };  											// 16
    p3.opisz("OBIEKT p3");
}

