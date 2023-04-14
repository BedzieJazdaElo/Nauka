// Program z paragrafu 22_08

// Uwaga: Co prawda ten program spowoduje błąd naruszenia pamięci, ale i tak
// na samym początku wydruku zobaczymy interesujące 5 linijek naszego tekstu


#include <iostream>
#include <cstring> 				// dla funkcji strlen, memcpy
#include <vector>
using namespace std;
////////////////////////////////////////////////////////////////////////////////////////////////////////
class Twizytowka
{
public:
    char * wsk_nazwiska { nullptr }; 										// 1
    int dl_tablicy { 0 }; 												// 2

    int rok_urodzenia { 0 }; 											// 3

    explicit Twizytowka(const char * nazw , int rok) 						// 4
    {
        dl_tablicy = strlen(nazw) +1;
        wsk_nazwiska = new char[ dl_tablicy];

        memcpy(wsk_nazwiska, nazw, dl_tablicy);
        rok_urodzenia = rok;
    }
    //------------------
    ~Twizytowka() 													// 5
    {
        if(!wsk_nazwiska ) return;
        delete [ ] wsk_nazwiska;
    }
    //------------------
#if 0 // poniższa funkcja chwilowo nie istnieje... (Kompilacja warunkowa)
    Twizytowka( const Twizytowka & inny)
    {
        cout << "dziala: Konstrukor Kopiujacy\n";
        dl_tablicy = inny.dl_tablicy;
        wsk_nazwiska = new char[dl_tablicy];
        memcpy(wsk_nazwiska, inny.wsk_nazwiska, dl_tablicy);

        rok_urodzenia = inny.rok_urodzenia;
    };
#endif 					// ---------------------- koniec kompilacji warunkowej

    void przedstaw_sie() 												// 6
    {
        cout << wsk_nazwiska << ", ur. " << rok_urodzenia 	<< endl;
    }
    void zmiana_1_litery_nazwiska(char znak, int rok) 						// 7
    {
        if(dl_tablicy > 1) wsk_nazwiska[0] = znak;
        rok_urodzenia = rok;
    }
};
////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
    Twizytowka fizyk( "Einstein", 1879);									// 8
    Twizytowka kolega { fizyk }; 										// 9

    cout << "Po utworzeniu blizniaczego obiektu oba zawieraja nazwiska\n";
    cout << "fizyk: ";
    fizyk.przedstaw_sie(); 												// 10
    cout << "kolega: ";
    kolega.przedstaw_sie();

    // mój kolega ma inne nazwisko: Minstein
    kolega.zmiana_1_litery_nazwiska('M', 2002);							// 11
    cout << "\nPo zmianie nazwiska kolegi brzmi ono: ";
    kolega.przedstaw_sie(); 												// 12
    cout << "Tymczasem niemodyfikowany fizyk nazywa sie: ";
    fizyk.przedstaw_sie(); 												// 13
}
