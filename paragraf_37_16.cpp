// Program z paragrafu 37_16

#include <iostream>
#include <vector>
#include <string>
using namespace std;
///////////////////////////////////////////////////// szablon klas (pierwotny) //////////////////////////////////////////////////
template <typename T>												// 1
class Takumulator {
    T depozyt;
public:
    Takumulator()   {
        zeruj_depozyt();     // 2
    }
    void zeruj_depozyt() {
        depozyt = 0;    // 3
    }
    void przyjmij(T co)													// 4
    {
        depozyt = depozyt + co;
    }
    T jaki_depozyt() {
        return depozyt;    // 5
    }
    T rozladunek();													// 6

};
//********************************************************************
template <typename T>
T Takumulator<T>::rozladunek()  										// 7
{
    T x = depozyt;
    zeruj_depozyt();
    return x;
}
//////////////////////////////////////////////////////////////////////////////////////////////////
//Użytkownik szablonu robi specjalizację (zupełną, kompletną) klasy szablonowej Takumulator
//////////////////////////////////////////////////////////////////////////////////////////////////
template< >		// specjalizacja kompletna								// 8
class Takumulator<char> {
    string depozyt;		 											// 9
public:
    void przyjmij(char nowy);  											// 10
    string jaki_depozyt() {
        return depozyt;
    }
    string  rozladunek()					  							// 11
    {
        string chwilowo = depozyt;
        depozyt.clear();
        return chwilowo;
    }
};
//********************************************************************
void Takumulator<char>::przyjmij(char nowy)								// 12
{
    depozyt += nowy;
}
//********************************************************************
int  main()
{
    Takumulator<float> kasa;											// 13
    // ––––––––––––––––––––––styczeń
    kasa.przyjmij(400.00);   												// 14
    cout << "W kasie jest teraz = " << kasa.jaki_depozyt() << endl;
    float przelew = 50.50;
    kasa.przyjmij(przelew);
    cout << "Utarg miesieczny w styczniu= " << kasa.rozladunek() << endl;		// 15
    // ––––––––––––––––––––––– luty
    kasa.przyjmij(320.00);
    cout << "Utarg miesieczny w lutym= " << kasa.rozladunek() << endl;

    Takumulator<char>  zestaw_znakow;  								// 16
    zestaw_znakow.przyjmij('A');
    zestaw_znakow.przyjmij('S');
    for(int i = 0 ; i < 20 ; ++i) zestaw_znakow.przyjmij('a'+ i);
    cout << "zestaw znakow =" << zestaw_znakow.jaki_depozyt() << endl;
}

