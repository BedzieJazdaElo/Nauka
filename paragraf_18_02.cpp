// Program z paragrafu 18_02

#include <iostream>
#include <string>
using namespace std;
//--------------------------
class Tkwadrat;		 				// deklaracja zapowiadająca 	 // 1
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Tpunkt
{
    int x, y;
    string nazwa;
public:
    Tpunkt(int a, int b, string opis);
    void ruch(int n, int m)
    {
        x += n;
        y += m;
    }
    // ...może coś jeszcze...

    friend int sedzia(Tpunkt & p, Tkwadrat & k); 						// 2
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Tkwadrat
{
    int x, y;
    int bok;
    string nazwa;
public:
    Tkwadrat(int a, int b, int dd, string opis);
    // ...może coś jeszcze...

    friend int sedzia (Tpunkt & p, Tkwadrat & k); 						// 3
};
// @

// @
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
Tpunkt::Tpunkt(int a, int b, string opis)					// konstruktor
{
    x = a;
    y = b;
    nazwa = opis;
}
// @

// @
//**************************************************************************
Tkwadrat::Tkwadrat(int a, int b, int dd, string opis) 			// konstruktor
{   x = a;
    y = b;
    bok = dd;
    nazwa = opis;
}
// @

// @
//**************************************************************************
// Z tą funkcją przyjaźnią się obie klasy.
int sedzia (Tpunkt & pt, Tkwadrat & kw) 								// 4
{
    if(  	(pt.x >= kw.x) && (pt.x <= (kw.x + kw.bok) )
            &&
            (pt.y >= kw.y) && (pt.y <= (kw.y + kw.bok) )
      )
    {
        cout << pt.nazwa << " lezy na tle " << kw.nazwa << endl;
        return 1;
    } else {
        cout << "AUT! " << pt.nazwa << " jest na zewnatrz " << kw.nazwa << endl;
        return 0;
    }
}
//**************************************************************************
int main()
{
    Tkwadrat		bo(10, 10, 40, "boiska");
    Tpunkt		pi(20, 20, "pilka");

    sedzia(pi, bo );												// 5
    cout << "kopiemy pilke!\n";
    while(sedzia(pi, bo))
    {
        pi.ruch(20,20);
    }
}

