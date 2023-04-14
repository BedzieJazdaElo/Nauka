// Program z paragrafu 09_02


#include <iostream>
using namespace std;
void wczytaj_dane();
//*********************************************************
int main()
{
    constexpr int 	ile_pomiarow = 4;
    long 		widmo[ile_pomiarow][2048] { };   								// 1

    //  tajemnicza funkcja, która wczyta z dysku cztery zestawy wyników pomiarowych
    //  i dane te umieści w tablicy widmo
    wczytaj_dane();

    cout	<< "Jaki przedzial widm ma byc sumowany?\nPodaj dwie liczby (oddzielone spacją): ";
    int 	pocz;
    int 	koniec;
    cin >> pocz >> koniec;

    for(int nr_widma = 0 ; nr_widma < ile_pomiarow ; ++nr_widma) // pętla po 4 próbkach  		// 2
    {
        long suma = 0;
        for(int i = pocz ; i <= koniec ; ++i)   	//  pętla sumująca dane jednej próbki  		// 3
        {
            suma += widmo[nr_widma][i]; 									// 4
        }
        cout << "\nW widmie "<< nr_widma << " miedzy kanalami "	<< pocz
             << " a " << koniec	<< " jest " << suma << " zliczen";					// 5
    }	// koniec pętli po 4 próbkach
}
//*********************************************************
void wczytaj_dane()
{
    // ... wczytywanie danych z dysku
}
