// Program z paragrafu 37_17

#include <iostream>
#include <vector>
#include <string>
using namespace std;
///////////////////////////////////////////////////////// szablon klas (pierwotny) //////////////////////////////////////////////
template <typename T>											// 1
class Takumulator {
    T depozyt;
public:
    Takumulator()   		{
        zeruj_depozyt();
    }
    void zeruj_depozyt()	{
        depozyt = 0;    // 2
    }
    void przyjmij(T co)		{
        depozyt = depozyt + co;
    }
    T jaki_depozyt() 		{
        return depozyt;
    }
    T rozladunek() {
        T x = depozyt;
        zeruj_depozyt();
        return x;
    }
};
//////////////////////////////////////////////////////////////////////////////////////////////////
// Specjalizacja użytkownika dla typu string wymaga poprawienia tylko
// jednej funkcji składowej szablonu pierwotnego
template < >
void Takumulator<std::string>::zeruj_depozyt()							// 3
{
    depozyt.clear();
}
//********************************************************************
int  main()
{
    Takumulator<string> wyspianski;  								// 4

    wyspianski.przyjmij("Przeciez juz dawno sie wyzbylem\n");
    wyspianski.przyjmij("Marzen o utraconym raju\n");

    string  zapisek_ranny = wyspianski.rozladunek();	 				// 5
    cout << "*** Rano Wyspianski zapisal:***\n"   << zapisek_ranny  ;

    // -- wieczorem  -----------
    wyspianski.przyjmij("Zyje, by zwalo sie ze zylem\n");					// 6
    wyspianski.przyjmij("Nad jakas rzeka, w jakims kraju.\n");

    string zapisek_wieczorny = wyspianski.rozladunek();
    cout << "*** Wieczorem Wyspianski zapisal ***\n"  	<< zapisek_wieczorny << endl;
}
