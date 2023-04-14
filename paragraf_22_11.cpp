// Program z paragrafu 22_11


#include <iostream>
using namespace std;
//*******************************************************************
void f(int & 	k)														// 1
{
    cout << "Odebrana referencja do lwartosci (obiektu) = " << k << endl;
}
//*******************************************************************
void f(int &&	k) 														// 2
{
    cout << "Odebrana referencja do rwartosci (CHWILOWEJ) = " 	<< k << endl;
}
//*******************************************************************
void poslaniec( int && arg)  	 										// 3
{
    cout << "   Funkcja g przekazuje ten argument dalej" << endl;
    f(arg);  															// 4

    cout << "  Zeby arg (o adresie: 0x" << hex
         << reinterpret_cast<long> (&arg) << dec 							// 5
         << ") \n znowu był traktowany jako rwartosc - rzutujemy std::move\n";
    f(std::move(arg) ); 													// 6
}
//*******************************************************************
int main()
{
    int obj = 33;
    f(obj);  															// 7
    f(50+2);     		// wyrażenie arytmetyczne  						// 8
    cout << "Po rzutowaniu obiektu (lwartosci) na rwartosc " << endl;
    f(std::move (obj) );  												// 9

    poslaniec(50+2);   		// argument jest rwartością 					// 10
}
