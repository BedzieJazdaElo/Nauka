// Program z paragrafu 37_10


#include <iostream>
using namespace std;
//////////////////////////////////////////////////////////////////////////////////////////////////
struct TwybranyA  												// 1
{
    int skl;
    using Tpozwolenie = int;   										// 2
    void zerowanie() {
        cout << " *** F. zerowanie z klasy TwybranyA" << endl;
    }
};
//////////////////////////////////////////////////////////////////////////////////////////////////
struct TwybranyB  												// 3
{
    double skl;
    using Tpozwolenie = double;   									// 4
    void zerowanie() {
        cout << "  *** F. zerowanie z klasy TwybranyB" << endl;
    }
};
//////////////////////////////////////////////////////////////////////////////////////////////////
struct Tzwykly 													// 5
{
    double skl;
    void zerowanie() {
        cout << "  *** F. zerowanie z klasy Tzwykly" << endl;
    }
};
////////////////////////////////////////// szablon tylko dla wyznaczonych typów ////////////////////////////////////////
template <typename T>
typename T::Tpozwolenie    maks(T a, T b) 							// 6
{
    cout << "Zadzialala f. SZABLONOWA maks" << endl;
    a.zerowanie();  		// a tu kompilator znalazłby błąd składni dla int.	// 7
    return (a.skl > b.skl)? a.skl :b.skl;		// ta klasa musi też mieć składnik skl
}
//********************************************************************
// Zwykła funkcja
long maks(long a, long b)			   // nie całkiem pasująca funkcja    	// 8
{
    cout << "Zadzialala ZWYKLA F. maks(long, long)" << endl;
    return (a > b) ? a : b;
}
//********************************************************************
int main()
{
    auto rez1 = maks(44, 88);    										// 9
    cout << "----> 1. Wiekszy dwoch int,  rez1 = "	<< rez1 << endl;
    auto rez2 = maks(3.4, 6.1);   										// 10
    cout << "----> 2. z argumentami double, rez2 = " << rez2 << endl;

    TwybranyA x { 5},  y {12};  										// 11
    auto rez3 = maks(x, y); 											// 12
    cout << "----> 3. z argumentami TwybranyA  rez3= " << rez3 << endl;

    TwybranyB 	p { 75.5},  	q {11.5};
    auto rez4 = maks(p, q);   										// 13
    cout << "----> 4. z argumentami TwybranyB rez4= " << rez4 << endl;

    Tzwykly  r { 75.5},  s {11.5};
    // auto rez5 = maks(r, s);   // nie ma odpowiedniej funkcji   			// 14
}
