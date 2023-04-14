// Program z paragrafu 12_04_06

#include <iostream>
using namespace std;
int main()
{
    int ile; 								// zauważ, że to NIE jest obiekt stały! 		// 1
    cout << "Podaj rozmiar? ";
    cin >> ile;

    int (*tablica)[7][4] = 	new int[ile][7][4];  	// rezerwacja tablicy wielowymiarowej  		// 2
    tablica[2][4][3] = 1000;					// tak tego używamy
    cout << tablica[2][4][3] << endl;
    delete [ ] tablica;						// a tak likwidujemy

    // Prezent od twórców C++11 – rezerwację identycznej tablicy możemy zapisać łatwiej
    auto * tab = new int[ile][7][4];    											// 3

    // Celowo popełniamy błąd, aby uzyskać bardzo pouczającą informację
    // tab = 5.5;     Error: Cannot convert –double– to –int (*)[7][4]– in assignment 		// 4

    tab[2][3][4] = 1000;						// tak tego używamy
    delete [ ] tab;							// a tak likwidujemy
}
