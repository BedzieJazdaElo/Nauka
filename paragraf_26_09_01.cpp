// Program z paragrafu 26_09_01

#include <iostream>
using namespace std;
//////////////////////////////////////////////////////////////////////////////////////////////
class Twektorek
{
public:
    double x, y, z;
    // --- konstruktor
    Twektorek(double xp = 0, double yp = 0, double zp = 0 )
        :  x(xp), y(yp), z(zp) 				// 1
    {   /* ciało puste */
    }

    // ...inne funkcje składowe
};
//////////////////////////////////////////////////////////////////////////////////////////////
Twektorek operator*(Twektorek kopia, double liczba)	// definicja operatora		// 2
{
    Twektorek rezultat;

    rezultat.x = kopia.x * liczba;
    rezultat.y = kopia.y * liczba;
    rezultat.z = kopia.z * liczba;
    return rezultat;
}
//*******************************************************
void pokaz(Twektorek www);				// deklaracja funkcji pomocniczej
//*******************************************************
int main()
{
    Twektorek		a(1, 1, 1);
    Twektorek 		b(-15, -100, +1);
    Twektorek		wynik;

    wynik = a * 6.66; 													// 3
    pokaz(wynik);

    wynik = b *  -1.0;
    pokaz(wynik);
}
//*******************************************************
void pokaz(Twektorek www)
{
    cout	<< " x = " << www.x
            << " y = " << www.y
            << " z = " << www.z << endl;
}

