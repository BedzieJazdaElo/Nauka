// Program z paragrafu 12_02_03

#include <iostream>
using namespace std;
// deklaracje funkcji												 // 1
void pokazywacz(const int *wsk, int ile);
void zmieniacz(int *wsk, int ile);

//****************************************************
int main()
{
    int tablica[4] = { 110,120,130,140};

    pokazywacz(tablica, 4);											// 2
    zmieniacz(tablica, 4);
    pokazywacz(tablica, 4);
    cout << "Dla potwierdzenia tablica[3] = " << tablica[3];
}

//****************************************************
void pokazywacz(const int *wsk, int ile)								// 3
{
    cout << "Dziala pokazywacz " << endl;
    for(int i = 0 ; i < ile ; ++i, ++wsk)
    {
        // *wsk += 22;					// błąd!    					// 4
        cout << "element nr "<< i << " ma wartosc " << *wsk << endl;		// 5
    }
}

//****************************************************
void zmieniacz(int *wsk, int ile)										// 6
{
    cout << "Dziala zmieniacz " << endl;
    for(int i = 0 ; i < ile ; ++i, ++wsk)
    {
        *wsk += 500;					// wolno nam! 	 				// 7
        cout << "element nr " << i << " ma wartosc " << *wsk << endl;
    }
}
