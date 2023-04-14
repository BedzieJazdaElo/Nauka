// Program z paragrafu 34_06_02


#include <iostream>
using namespace std;
#include <fstream>
#include <string>
//*******************************************************
int main()
{
    string tekst =  		"Coz, wedlug Ben-Alego,\n"
                            "czarnomistrza Krakowa\n"
                            "nie jest to nic wielkiego\n"
                            "dorozke zaczarowac.";
    // Otwieram istniejący plik i go zeruję, a jeśli go nie ma - tworzę go
    fstream strum("wiersz.tmp", ios::trunc | ios::in |  ios::out);
    if(!strum)
    {
        cout << "Blad otwarcia pliku " << endl;
        return -1;
    }
    strum << tekst;  				// Zapisaliśmy ten cały tekst do pliku,
    strum.seekp(25);				// Pozycjonowanie kursora pisania na literze nr 25
    strum << "ABCDE";
    strum.seekp(-6, ios::end); 		// Pozycjonowanie kursora pisania na znaku 6. od końca
    strum << "X";
}
