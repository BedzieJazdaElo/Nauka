// Program z paragrafu 30_01

#include <iostream>
#include <vector>
using namespace std;
//*******************************************************
// Dla sposobu I. Dwie przykładowe funkcje orzekające
//*******************************************************
bool czy_nieparzyste_Fcja(int liczba) 										// 1
{
    return (liczba % 2);
}
//*******************************************************
bool czy_wieksze_niz_9_Fcja(int liczba) 									// 2
{
    return (liczba > 9);
}
//*******************************************************
// Algorytm zliczający mogący korzystać z obu powyższych funkcji orzekających
//*******************************************************
int algorytm_zliczajacy(vector<int> pojemnik, bool (*orzecznik)(int i)) 			// 3
{
    int licznik_spelniajacych = 0;
    for(int element : pojemnik)
    {
        if( orzecznik(element) ) {		// <-- wywołanie: wskaźnik_funkcji(arg)		// 4
            licznik_spelniajacych++;
        }
    }
    return licznik_spelniajacych;
}
//*******************************************************
//*******************************************************
//  Dla sposobu II.  Dwie klasy obiektów funkcyjnych
//*******************************************************
struct Tfunktor_czy_nieparzyste 											// 5
{
    bool operator() (int liczba) {											// 6
        return liczba % 2;
    }
};
//*******************************************************
struct Tfunktor_wieksze_niz												// 7
{
    // konstruktor
    Tfunktor_wieksze_niz(int p) : porown(p) {}								// 8

    bool operator() (int liczba) {
        return liczba > porown;
    }
    int porown;			// wartość progu								// 9
};
//*******************************************************
// Algorytm zliczający – konieczny teraz w dwóch wersjach
//*******************************************************
int algorytm_zliczajacy(vector<int> pojemnik, Tfunktor_czy_nieparzyste  orzecznik)		// 10
{
    int licznik_spelniajacych = 0;
    for(int element : pojemnik)
    {
        if(orzecznik(element) ) 		// <--  wywołanie: obiekt.operator()(arg)		// 11
            licznik_spelniajacych++;
    }
    return licznik_spelniajacych;
}
//*******************************************************
int algorytm_zliczajacy(vector<int> pojemnik, Tfunktor_wieksze_niz   orzecznik)		// 12
{
    int licznik_spelniajacych = 0;
    for(int element : pojemnik)
    {
        if(orzecznik(element) )
            licznik_spelniajacych++;
    }
    return licznik_spelniajacych;
}
//*******************************************************
int main()
{
    vector<int>  v { 4, 2, 13, 11, 5, 24, 7 }; 									// 13

    cout << "Korzystajac z funkcji (orzekających), sprawdzamy, ze w wektorze v\n";
    int ile = algorytm_zliczajacy(v, czy_nieparzyste_Fcja);					// 14
    cout << "Nieparzystych liczb jest " << ile << endl;

    ile = algorytm_zliczajacy(v, czy_wieksze_niz_9_Fcja);					// 15
    cout << "Wartosci > 9 jest " << ile << endl;

    cout << "Inny sposob przeslania kryterium – obiektem funkcyjnym\n";

    ile = algorytm_zliczajacy(v, Tfunktor_czy_nieparzyste() );				// 16
    cout << "Obj. funkcyjny: Nieparzystych liczb jest " << ile << endl;

    ile = algorytm_zliczajacy(v, Tfunktor_wieksze_niz(9) );					// 17
    cout << "Obj. funkcyjny: Wartosci > " << 9 << " jest " << ile << endl;

    for(int k = 3; k < 6 ; k++)
    {
        ile = algorytm_zliczajacy(v, Tfunktor_wieksze_niz(k) );			// 18
        cout << "\tObj. funkcyjny: Wartosci > " << k << " jest " << ile<< endl;
    }
}

