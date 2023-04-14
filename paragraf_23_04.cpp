// Program z paragrafu 23_04

#include <iostream>
#include <string>
#include <vector>
using namespace std;
////////////////////////////////////////////////////////////////////////////////////////////////////////
class Tstacja_agreg				// klasa – prosty agregat  					// 1
{
public:
    double 	km;
    int 		glebokosc;
    char		nazwa[40];
    char		przesiadki[80];
};
//*******************************************************
class Tstacja_kolejki				// klasa – coś więcej niż agregat				// 2
{
    double km;
    int glebokosc;
    string nazwa;
    string przesiadki;
public:
    Tstacja_kolejki(double kk, int gg, string nn, string pp = "") 						// 3
        : km(kk), glebokosc(gg), nazwa(nn), przesiadki(pp)
    {   }

    Tstacja_kolejki() : 						// konstruktor domniemany			 // 4
        km(0), glebokosc(0), nazwa("Niewpisana jeszcze"), przesiadki ("")
    {   }
    void gdzie_jestesmy();
};
//*******************************************************
void Tstacja_kolejki::gdzie_jestesmy()
{
    cout << "Stacja: " << nazwa << endl;
    if(przesiadki.empty() == false)	cout << "\tPrzesiadki: " << przesiadki << endl;
}
//*************************************************28]>
int main()
{
    Tstacja_agreg	  moja_stacja = Tstacja_agreg { 14.3, -6, "Yorckstrasse", "S1 Wansee" };   	// 5

    cout << "### Wektor elementów będących agregatami ###"<< endl;

    vector<Tstacja_agreg>  stacyjka = 										 // 6
    {   // <-- // 7
        Tstacja_agreg{ 0, 4, "ZOO", "S3, U1, U9" },			// dane dla stacyjki[0]
        Tstacja_agreg{ 1.7, 4, "Tiergarten"},				// dane dla stacyjki[1]   		// 8
        Tstacja_agreg{ 3, 3, "Bellevue", "" },				// dane dla stacyjki[2]
        Tstacja_agreg{  },								// dane dla stacyjki[3] 		// 9
        { }											// dane dla stacyjki[4]		// 10
    }; // <-- // 7

    // praca z takim wektorem
    for(unsigned int i = 0; i < stacyjka.size() ; ++i)  										// 11
    {
        cout << "Stacja: " << stacyjka[i].nazwa << endl;
        if(stacyjka[i].przesiadki[0]) 	// czy w tablicy przesiadki coś jest?
        {
            cout << "\tPrzesiadki:" << stacyjka[i].przesiadki << endl;
        }
    }

    cout << "### Wektor elementów NIEbędących agregatami ###"<< endl;

    vector<Tstacja_kolejki>  przystanek  =	   									// 12
    {   // <-- // 13
        Tstacja_kolejki (5, 0, "Teatr Bagatela", "Tramwaje 2,4,8,13,14"),  			// 14
        Tstacja_kolejki { }, 				// zadziała konstruktor domniemany 		// 15
        { },							// zadziała konstruktor domniemany 		// 16
        { Tstacja_kolejki (6, 0, "Basztowa LOT", "Tramwaje 2,4,7,14,") }
    };	// <-- // 13

    for(unsigned int i = 0 ; i < przystanek.size() ; ++i)
        przystanek[i].gdzie_jestesmy();

    cout << "Wektor mozna przebiec za pomoca petli zakresowe for\n";
    for(auto & p : przystanek)
        p.gdzie_jestesmy();

    // Nie ma sensu tworzyć wektora operatorem new, bo on sam tworzy
    // swoją wewnętrzną tablicę właśnie tym operatorem.
}
