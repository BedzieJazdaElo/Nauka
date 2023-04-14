// Program z paragrafu 22_12

#include <iostream>
#include <cstring>   				// dla funkcji strlen, memcpy
#include <vector>
using namespace std;
////////////////////////////////////////////////////////////////////////////////////////////////////////
class Twizytowka 													// 1
{
public:
    char * wsk_nazwiska { nullptr };
    int dl_tablicy { 0 };

    int rok_urodzenia { 0 };

    explicit Twizytowka(const char * nazw, int rok) 						// 2
    {
        dl_tablicy = strlen(nazw) +1;
        wsk_nazwiska = new char[ dl_tablicy];

        memcpy(wsk_nazwiska, nazw, dl_tablicy);
        rok_urodzenia = rok;
    }
    //------------------
    ~Twizytowka() 												// 3
    {
        if(!wsk_nazwiska ) return;
        delete [] wsk_nazwiska;
    }
    //------------------
    Twizytowka( const Twizytowka & inny) 							// 4
    {
        dl_tablicy = inny.dl_tablicy;
        wsk_nazwiska = new char[dl_tablicy];
        memcpy(wsk_nazwiska, inny.wsk_nazwiska, dl_tablicy);

        rok_urodzenia = inny.rok_urodzenia;

        cout << "Konstrukor Kopiujacy utworzył: ";
        przedstaw_sie();
    };
    //------------------
    // konstruktor przenoszący 										// 5
    Twizytowka( Twizytowka && inny)								// 6
    {
        // kopiujemy składniki
        wsk_nazwiska = inny.wsk_nazwiska; 							// 7
        dl_tablicy =inny.dl_tablicy;
        rok_urodzenia = inny.rok_urodzenia;

        // zacieramy ślady po przejęciu tablicy
        inny.wsk_nazwiska = nullptr; 								// 8
        inny.dl_tablicy = 0;											// 9

        // inny.rok_urodzenia = 0; 	// szkoda czasu 					// 10

        cout << "Konstruktor PRZENOSZACY: ";						 // 11
        przedstaw_sie();
    }
    //----------------------------
    void przedstaw_sie() 											// 12
    {
        cout << wsk_nazwiska << ", ur. " << rok_urodzenia << endl;
    }
};
////////////////////////////////////////////////////////////////////////////////////////////////////////
Twizytowka  daj_rwartosc(int ktory) 									// 13
{
    Twizytowka a("Adam", 1980);
    Twizytowka k("Kazia", 1931);
    Twizytowka z("Zenek", 2001);

    if(ktory == 1)
        return a;
    else if(ktory == 2)
        return k;
    else
        return z;
}
//*******************************************************************
int main()
{
    for(int i = 0 ; i < 3 ; ++i)
    {
        Twizytowka wybraniec = daj_rwartosc(i); 						// 14
        cout << "w main: ";
        wybraniec.przedstaw_sie(); 									// 15
    }
}

