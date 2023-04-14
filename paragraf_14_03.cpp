// Program z paragrafu 14_03


#include <iostream>
#include <vector>
using namespace std;

//*************************************************
// Dwie przykładowe funkcje orzekające
//*************************************************

bool   czy_nieparzyste_Fcja(int liczba) 								// 1
{
    return (liczba % 2);
}

//*************************************************
bool  czy_wieksze_niz_9_Fcja(int liczba) 								// 2
{
    return (liczba > 9);
}

//*************************************************
using Typwskf =  decltype( &czy_nieparzyste_Fcja);   					// 3

//*************************************************
// Algorytm zliczający

// int przelicz_elementy(vector<int> pojemnik, Typwskf orzecznik ) 			// 4
int przelicz_elementy(vector<int> pojemnik, bool (*orzecznik)(int i) ) 		// 5
{
    int licznik_spelniajacych = 0;
    for(int element : pojemnik)    				// zakresowe for
    {
        if( orzecznik(element) ) {		// wywołanie: wsk_funkcji(int) 	// 6
            licznik_spelniajacych++;
        }
    }
    return licznik_spelniajacych;
}

//*************************************************
int main()
{
    vector<int> v { 4, 2, 13, 11, 5, 24, 7 }; 								// 7
    cout << "Korzystajac z funkcji (orzekających) sprawdzamy, ze\n";
    int ile = przelicz_elementy(v, &czy_nieparzyste_Fcja); 				// 8
    cout << "a) Nieparzystych liczb jest " << ile << endl;

    ile = przelicz_elementy(v, &czy_wieksze_niz_9_Fcja); 				// 9
    cout << "b) Wartosci > 9 jest " << ile << endl;
}
