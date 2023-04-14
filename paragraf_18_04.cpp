// Program z paragrafu 18_04

// @
#include <iostream>
#include <string>
using namespace std;
//---------------------------
class Tpunkt;			 		// deklaracja zapowiadająca 			// 1
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Tkwadrat
{
    int x, y;
    int bok;
    string nazwa;
public:
    Tkwadrat(int a, int b, int dd, string opis);
    // ...może coś jeszcze...

    int sedzia (Tpunkt & p); 											// 2
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Tpunkt
{
    int x, y;
    string nazwa;
public:
    Tpunkt(int a, int b, string opis);
    void ruch(int n, int m) {
        x += n;
        y += m;
    }
    // ...może coś jeszcze...

    friend int Tkwadrat::sedzia(Tpunkt & p); 							// 3
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Tpunkt::Tpunkt(int a, int b,string opis) 					// konstruktor
{
    x = a;
    y = b;
    nazwa = opis;
}
//**************************************************************************
Tkwadrat::Tkwadrat(int a, int b, int dd, string opis)			// konstruktor
{
    x = a;
    y = b;
    bok = dd;
    nazwa = opis;
}
//**************************************************************************
int Tkwadrat::sedzia (Tpunkt & pt) 									// 4
{
    if(	(pt.x >= x) && (pt.x <= (x + bok) ) 								// 5
            &&
            (pt.y >= y) && (pt.y <= (y + bok) )
      )
    {
        cout << pt.nazwa << " lezy na tle " << nazwa << endl;
        return 1;
    } else {
        cout << "AUT! " << pt.nazwa << " jest na zewnatrz " << nazwa << endl;
        return 0;
    }
}
//**************************************************************************
int main()
{
    Tkwadrat	bo(10,10, 40, "boiska");
    Tpunkt	pi( 20, 20, "pilka");
    bo.sedzia(pi);					 								// 6
}
