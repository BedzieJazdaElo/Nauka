// Program z paragrafu 23_03_02


#include <iostream>
using namespace std;
#include <string>
//*******************************************************
class Tstacja_kolejki
{
    double km; 		 				// na którym kilometrze trasy
    int glebokosc;					// ile metrów pod ziemią
    string nazwa; 					// nazwa stacji
    string przesiadki; 				// na co można się przesiąść
public:
    Tstacja_kolejki(double kk, int gg, string nn, string pp = ""); // konstruktor 		// 1
    Tstacja_kolejki();				// ---------- konstruktor domniemany
    void gdzie_jestesmy(); 			// ---------- zwykła funkcja składowa
};
//*******************************************************
Tstacja_kolejki::Tstacja_kolejki(double kk, int gg, string nn, string pp)			// 2
    :   km(kk), glebokosc(gg), nazwa(nn), przesiadki(pp)
{   }
//*************************************************
Tstacja_kolejki::Tstacja_kolejki() : km(0), glebokosc(0)	// konstruktor domniemany	 // 3
{
    nazwa = "Niewpisana jeszcze";
    przesiadki = "";
}
//*************************************************
void Tstacja_kolejki::gdzie_jestesmy() 				   							// 4
{
    cout << "Stacja: " << nazwa << endl;
    if(przesiadki.size())
    {
        cout << "\tPrzesiadki: " << przesiadki << endl;
    }
}
//*************************************************
int main()
{
    Tstacja_kolejki  ostatnia =   Tstacja_kolejki (22, 0, "Wansee", "118 Bus"); 		// 5
    ostatnia.gdzie_jestesmy();
    cout << "********************\n";

    constexpr  int ile_stacji = 6;
    Tstacja_kolejki przystanek[ile_stacji] = 	  								// 6
    {
        Tstacja_kolejki (0, 5, "Friedrichstrasse", "Linia U6"),
        Tstacja_kolejki (),
        Tstacja_kolejki (5.7, 4, "Tiergarten"),
        Tstacja_kolejki (8, 4, "ZOO", "Linie U1 i U9")
    };

    for(int i = 0 ; i < ile_stacji ; ++i)
    {
        przystanek[i].gdzie_jestesmy();
    }
    // inicjalizacja tablicy wytworzonej operatorem new -----------------------------
    cout << "Linia krakowska -----------------------" << endl;

    Tstacja_kolejki * wskprzyst = new Tstacja_kolejki[5]
    {
        { Tstacja_kolejki (5, 0, "Teatr Bagatela", "Tramwaje 2,4,8,13,14,18,24,64,69") } ,
        { Tstacja_kolejki (6, 0, "Basztowa LOT", "Tramwaje 2,4,7,14,18,24,64,69") },
        { Tstacja_kolejki (6.5, 0, "Dworzec Kolejowy", "Tramwaje 2,4,7,14,20,24,52,62,64,69,70") }
    };

    for(int nr = 0 ; nr < 5; ++nr) wskprzyst[nr].gdzie_jestesmy();
    delete [ ] wskprzyst;
}

