// Program z paragrafu 16_22

#include <iostream>
using namespace std;
//*******************************************************
class Tpunkt   														// 1
{
public:
    int x,y;
    constexpr    Tpunkt oddalenie(int dx, int dy)   							// 2
    {
        return {x+dx, y+dy};
    }

    constexpr  bool pozycja_jak(Tpunkt punkt)    const   						// 3
    {
        return (x == punkt.x && y == punkt.y)?  true : false;
    }
    void pozycjonuj(int n, int m) 											// 4
    {
        x = n;
        y = m;
    }
};
//*******************************************************
int main()
{
    constexpr Tpunkt    kotwica { 0, 0};   									// 5
    constexpr Tpunkt    skarb_galeon = kotwica.oddalenie( 62, 45);   			// 6
    constexpr Tpunkt    skarb_skrzynia_perel = skarb_galeon.oddalenie( 20, -12);		  // 7

    constexpr bool dwa_razem = skarb_skrzynia_perel.pozycja_jak(skarb_galeon);		// 8

    if(dwa_razem) cout <<  "Dwa skarby sa ukryte w tym samym miejscu\n";
    else cout << "Dwa skarby sa ukryte w roznych miejscach\n";

    Tpunkt   nurek = skarb_galeon.oddalenie(17, 7);    						// 9

    // poszukiwanie skarbów
    for(int x = 0 ; x < 100 ; ++x)
        for(int y = 0 ; y < 100 ; ++y)
        {
            nurek.pozycjonuj(x, y);   									// 10
            if(nurek.pozycja_jak(skarb_skrzynia_perel) )   					// 11
            {
                cout << "Znaleziona skrzynia perel w miejscu [" << x << ", " << y << "]\n";
            }
            if(skarb_galeon.pozycja_jak(nurek) )           						// 12
            {
                cout << "Znaleziony galeon w miejscu [" << x << ", " << y << "]\n";
            }
        }
}
