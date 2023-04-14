// Program z paragrafu 17_08

#include <iostream>
#include <string>
using namespace std;
int main()
{
    for(int liczba = 8 ; liczba < 13 ; liczba ++) {
        string nazwa_pliku("urzadzenie_");								// 1
        if(liczba<10) nazwa_pliku += "0";									// 2

        nazwa_pliku += to_string(liczba);									// 3
        nazwa_pliku += ".parametry";
        cout 	<< "plik = " << nazwa_pliku << endl;
    }
}
