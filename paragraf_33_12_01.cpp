// Program z paragrafu 33_12_01

#include <iostream>
using namespace std;
#include <iomanip>
#include <cmath>  					 // dla liczby pi
//*******************************************************
ostream & tem(ostream & strum)
{
    strum << setprecision(1) << showpos << fixed << setw(12);
    return strum;
}
//*******************************************************
ostream & wys(ostream & strum)
{
    strum << noshowpos << setw(10);
    return strum;
}
//*******************************************************
ostream & ges(ostream & strum)
{
    strum << scientific << setprecision(4) << setw(16);
    return strum;
}
//*******************************************************
int main()
{
    double	t = 20.47,
            g = 0.09273;
    int		w = 3000;

    cout 	<< "\n  Temperatura = " << tem << t
            << "\n  Wysokosc   = " << wys << w
            << "\n  Gestosc     = " << ges << g 		<< endl;

    const double pi = 2 * asin(1);  			// tak można wyliczyć liczbę pi
    cout 	<< "Uzytkownik niszczy obecne ustawienia... "
            << fixed << setprecision(18) << pi << endl;

    cout 	<< "\n  Temperatura = " << tem << 2*t
            << "\n  Wysokosc   = " << wys << 2*w
            << "\n  Gestosc   = " << ges << 2*g		<< endl;
}
