// Program z paragrafu 30_04

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//////////////////////////////////////////////////////////////////////////////////////////////
class Tfraport 				  										// 1
{
    int skl_a = 2;														// 2
    int skl_b = 1;														// 3
    int skl_c = 0;														// 4
public:
    void f_skladowa();													// 5
    static void f_skl_statyczna();
};
//////////////////////////////////////////////////////////////////////////////////////////////
void Tfraport::f_skladowa() 				 								// 6
{
    vector<int> wek { 1,2,7,4,5, -1, 0 };
    auto p = wek.begin();
    auto k = wek.end();

    int rezultat;

    cout << "Wartosc skl_a = " << skl_a << endl; 							// 7

    // tak się nie da!
    // rezultat = count_if (p, k,  [skl_a] (int j) { return(j< skl_a );}   ); 		// błąd		// 8

    cout << "=== Liczenie z przechwyceniem wskaznika this – [this]"<< endl;
    rezultat = count_if	(p, k,
    [this] (int j) {
        skl_c++; 									// 9
        return (j < (skl_a + this->skl_b) );
    }  											// 10
                        );

    cout << "Cialo lambdy skorzystalo ze skladnikow-danych na dwa sposoby\n"
         << "\tRezultat liczenia  = " << rezultat
         << "\nNa dowod, ze dostep byl przez referencje - obecna wartosc skl_c = "
         << skl_c << endl;												// 11

    cout << "=== Liczenie z przechwyceniem [=] " << endl;
    rezultat = count_if	(p, k,
    [=] (int j) {
        return (j < (2*skl_a + this->skl_b) );		// 12
    }
                        );
    cout << "Drugie liczenie: w wektorze liczb mniejszych niz " << 2*skl_a+ skl_b
         << " jest = " << rezultat << endl;
}
//*******************************************************
void Tfraport::f_skl_statyczna()
{
    //auto lambda2 = [this] (int j) { return true j < (2*skl_a + this->skl_b);};		// 13
    //auto lambda3 = [=] (int j) { return true j < (2*skl_a + this->skl_b);};			// 14
}
//*******************************************************
int main()
{
    Tfraport d;
    d.f_skladowa();
}
