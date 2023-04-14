// Program z paragrafu 26_14

 #include <iostream>
using namespace std;
//////////////////////////////////////////////////////////////////////////////////////////////
class Twektorek {
public:
    double x, y, z;
    // --- konstruktor
    Twektorek(double a=0, double b=0, double c=0)		: x(a), y(b), z(c)
    { }
};
//////////////////////////////////////////////////////////////////////////////////////////////
// globalna funkcja operatorowa realizująca przeładowania << dla
// naszej klasy Twektorek
//*******************************************************
ostream &  operator<<(ostream & ekran, Twektorek &w)				// 1
{
    ekran << "wspolrzedne wektora: ";
    ekran << "(";
    ekran << w.x;													// 2

    ekran 	<< ", " << w.y 											// 3
            << ", " << w.z << ")";
    return ekran; 													// 4
}
//*******************************************************
int main()
{
    Twektorek	w(1, 2, 3);
    Twektorek	v;
    Twektorek	k(-10, -20, 100);

    cout << "Oto nasze wektory \nwektor w –";
    cout << w;			 										// 5

    cout << "\nwektor v –" << v << "\nwektor k –" << k << endl;

    cout << "Wywolanie jawne \n";
    operator<<( cout, w); 											// 6
}
