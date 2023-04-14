// Program z paragrafu 21_08_01



#include <iostream>
#include <memory>
using namespace std;
//////////////////////////////////////////////////////////////////////////////////////////////
class K   														// 1
{
    unique_ptr<double> 	wsktab = nullptr;
    long 				rozmiar;
public:

K(long ile)   try :
        wsktab(new double[ile]),   rozmiar(ile)  				// 2
    {    	}
    catch(exception & e)   											// 3
    {
        cerr << "  Wyjatek typu " << e.what()   							// 4
             <<" z listy inicjalizacyjnej K::K\n  - przy new double[" << ile << "]" << endl;
        // teraz wyjątek jest rzucony ponownie dalej, tak jakby tu była instrukcja throw;
    }
};
//////////////////////////////////////////////////////////////////////////////////////////////
class Pa : public K   												// 5
{
public:
Pa(long ile)  try :
        K(ile)     										// 6
    {      }
    catch(exception & x)  											// 7
    {
        cout	<< "  Wyjatek typu " << x.what() << " z listy incjalizacyjnej Pa::Pa " << endl;
        // teraz wyjątek jest rzucony ponownie dalej, tak jakby tu była instrukcja throw;
    }
};
//////////////////////////////////////////////////////////////////////////////////////////////
int main(void)
{
    cout << "Definiowanie  obiektow  klasy K-----------" << endl;
    try {
        K obj1 { 10000000000L };     									// 8
    }
    catch(...)    													// 9
    {
        cout << "(1) W main zlapany wyjatek od definicji obiektu klasy K \n" << endl;
    }
    //--------------------------------
    cout << "Definiowanie  obiektu  klasy pochodnej Pa-----------" << endl;
    try {    														// 10
        Pa obj2(999999999999L);  									// 11
    }
    catch(...)  													// 12
    {
        cout << "(2) W main zlapany wyjatek od obiektu klasy Pa " << endl;
    }
}

