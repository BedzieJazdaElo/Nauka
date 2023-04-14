// Program z paragrafu 30_01_04

#include <iostream>
#include <vector>
#include <algorithm> 				// zawiera deklarację funkcji count_if
using namespace std;
//*******************************************************
// Funkcje orzekające
//*******************************************************
bool czy_nieparzyste_Fcja(int liczba)
{
    return (liczba % 2);
}
//*******************************************************
bool czy_wieksze_niz_9_Fcja(int liczba)
{
    return (liczba > 9);
}
//*******************************************************
// Dwie klasy obiektów funkcyjnych
//*******************************************************
class Tfunktor_czy_nieparzyste
{
public:
    bool operator() (int liczba)	{
        return liczba % 2;
    }
};
//*******************************************************
class Tfunktor_wieksze_niz											// 1
{
    int porown;			// wartość progowa
public:
    // konstruktor
    Tfunktor_wieksze_niz(int p) : porown(p)
    {  }
    bool operator() (int liczba)  const  {
        return liczba > porown;
    }
};
//*******************************************************
int main()
{
    vector<int>  v { 4, 2, 13, 11, 5, 24, 7   };
    cout << "\nKorzystamy z funkcji bibliotecznej count_if" << endl;
    // ponieważ przeszukiwać będziemy cały pojemnik, przygotujmy sobie iteratory
    auto pocz = v.begin();  											// 2
    auto kon = v.end();

    int ile = count_if(pocz, kon, czy_nieparzyste_Fcja);				// 3
    cout << "Fun. orzekajaca: nieparzystych liczb jest " << ile << endl;

    ile = count_if(pocz, kon, czy_wieksze_niz_9_Fcja );				// 4
    cout << "Fun. orzekajaca: liczb > 9 jest " << ile << endl;

    cout << "\nInny sposob przeslania kryterium – obiektem funkcyjnym\n";

    ile = count_if(pocz, kon, Tfunktor_czy_nieparzyste() );				// 5
    cout << "Obj. funkcyjny: nieparzystych liczb jest " << ile << endl;

    ile = count_if(pocz, kon, Tfunktor_wieksze_niz(9) );				// 6
    cout << "Obj. funkcyjny: liczb > 9 jest " << ile << endl;

    ile = count_if(pocz, kon, Tfunktor_wieksze_niz(5) );				// 7
    cout << "Obj. funkcyjny: liczb > 5 jest " << ile << endl;
}
