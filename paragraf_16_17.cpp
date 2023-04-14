// Program z paragrafu 16_17

#include <iostream>
using namespace std;
///////////////////////////////////////////////////////////////
class Tsilnik {    														// 1
private:
    string	nazwa;
    int		biezaca_moc;
    int		moc_dopuszczalna;
public:
    static	int	licznik_silnikow;										// 2
    static 	int	sumaryczna_moc;			// wszystkich silników // 3
private:
    static	int 	niezawodnosc; 										// 4

public:    // funkcje składowe-------------------------------------------
    Tsilnik(string naz, int moc) 				// konstruktor  				// 5
    {
        ++licznik_silnikow; 												// 6
        nazwa = naz;
        moc_dopuszczalna = moc;
        biezaca_moc = 0;
    }
    ~Tsilnik() 						// destruktor   					// 7
    {
        stop();
        --licznik_silnikow;   											// 8
    }
    //––––––––––––––––––––––––––––––––––––––––––––
    void cala_naprzod() 												// 9
    {
        biezaca_moc = moc_dopuszczalna;
        sumaryczna_moc += biezaca_moc;
        cout << "Silnik "<< nazwa  << ": cala naprzod " << endl;
    }
    //––––––––––––––––––––––––––––––––––––––––––––
    void stop()														// 10
    {
        sumaryczna_moc -= biezaca_moc;
        biezaca_moc = 0;
        cout << "Silnik "<< nazwa << ": stop " << endl;
    }
    //––––––––––––––––––––––––––––––––––––––––––––
    int ile_godz_wytrzyma() 											// 11
    {
        return niezawodnosc + 5033;
    }
};
///////////////////////////////////////////////////////////////
// DEFINICJE  składników statycznych klasy Tsilnik
int 		Tsilnik::licznik_silnikow = 0; 										// 12
int 		Tsilnik::sumaryczna_moc;  										// 13
int  		Tsilnik::niezawodnosc = 130000; 	// prywatny!   					// 14

void trudne_manewry(); 				// deklaracja funkcji globalnej
//*************************************************
int main()
{
    cout << "Stocznia, silnikow jest teraz = "<< Tsilnik::licznik_silnikow << endl;		// 15

    cout << "Zamierzamy kupic te silniki. Ile godzin wytrzymuja? "
         // << Tsilnik::niezawodnosc						//  <-- <->błąd, bo prywatny 	// 16
         << endl;

    Tsilnik lewy("Lewy", 1200);                 									// 17
    Tsilnik prawy("Prawy", 1400);

    cout << "Po definicji kilku silnikow (i zwodowaniu statku) \n";
    // odczytywanie informacji zapisanych w danej statycznej (public)
    cout << "Dwa sposoby uzyskania informacji ze skl. statyczego\n"
         << "   1) Klasa Tsilnik::licznik_silnikow = " << Tsilnik::licznik_silnikow    		// 18
         << ",\n   2a) lewy.licznik_silnikow = " << lewy.licznik_silnikow  		// 19
         << ",\n   2b) prawy.licznik_silnikow = " << prawy.licznik_silnikow << endl;

    cout << "Na razie pracuja z moca sumaryczna = "
         << Tsilnik::sumaryczna_moc       								// 20
         << ", inaczej: " << lewy.sumaryczna_moc   							// 21
         << endl;

    lewy.cala_naprzod();
    prawy.cala_naprzod();
    cout << "Po opuszczeniu portu moc = " << prawy.sumaryczna_moc << endl;    		// 22

    // praca ze statycznym składnikiem prywatnym --------------
    cout << "Ile wytrzymuja silniki tej firmy? ";
    // cout  << Tsilnik::niezawodnosc  		//  <-- <->błąd, bo prywatny  		// 23
    cout << lewy.ile_godz_wytrzyma() << " h" << endl;

    trudne_manewry();  												// 24

    cout << "Na otwartym morzu. Silnikow: " << Tsilnik::licznik_silnikow   		// 25
         << ", obecnie sum. moc: " << Tsilnik::sumaryczna_moc
         << endl;
    // i tak dalej trwa rejs...
    cout << "Gdy rejs sie skonczyl" << endl;
}
//*************************************************
void trudne_manewry()
{
    cout << "---Rafa koralowa. Tu musimy doinstalowac maly silnik" << endl;
    Tsilnik man("manewrowy", 400);   									// 26

    man.cala_naprzod();
    cout << "---Teraz lacznie silnikow= "  << Tsilnik::licznik_silnikow
         << " z sum. moc = "   << man.sumaryczna_moc << endl;

// tu silnik man zostanie zlikwidowany
}
