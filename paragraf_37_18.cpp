// Program z paragrafu 37_18

#include <iostream>
using namespace std;
// ************************   szablon funkcji   ************************************
template <typename T>											// 1
bool czy_sie_nadaje()
{
    return false;   			// ogólnie mówiąc: nie
}
// ************************ specjalizacja użytkownika *****************************
template < >  														// 2
bool czy_sie_nadaje<int>()											// 3
{
    return true;
}
// @

// @
// ************************ specjalizacja użytkownika *****************************
template < >
bool czy_sie_nadaje<double>()   									// 4
{
    return false;
}
//////////////////////////////////////////////////////////////////////////////////////////////////
class obcy_typ    													// 5
{ };
//********************************************************************
int  main()
{
    cout << "Czy wedlug nas – do zliczania pikseli nadaje sie:" << endl;

    cout << "Typ int? : ";
    if(czy_sie_nadaje<int>() )    									// 6
        cout << "tak" << endl;
    else
        cout << "nie" << endl;

    cout << "Typ double? : ";
    if(czy_sie_nadaje<double>() )  									// 7
        cout << "tak" << endl;
    else
        cout << "nie" << endl;

    cout << "Typ nieujety w naszych specjalizacjach? ";
    if(czy_sie_nadaje<obcy_typ>() )   								// 8
        cout << "tak" << endl;
    else
        cout << "nie" << endl;
}
