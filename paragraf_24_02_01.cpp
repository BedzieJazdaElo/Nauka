// Program z paragrafu 24_02_01


#include <iostream>
#include <string>
using namespace std;
//////////////////////////////////////////////////////////////////////////////////////////////
class  Tzdarzenie													// 1
{
public:
    int 	polka_sygnalu_mw41_lewy;
    int 	polka_sygnalu_mw41_prawy;
    int 	polka_sygnalu_mw41_gora;
    int 	polka_sygnalu_mw41_dol;

    int 	polka_sygnalu_mw42_lewy;
    int 	polka_sygnalu_mw42_prawy;
    int 	polka_sygnalu_mw42_gora;
    int 	polka_sygnalu_mw42_dol;

    int 	p;  // składnik typu int, o krótkiej nazwie
};
//////////////////////////////////////////////////////////////////////////////////////////////
Tzdarzenie *biezace_zdarzenie; 										// 2
using Twsk = decltype(&Tzdarzenie::p); 								// 3
//////////////////////////////////////////////////////////////////////////////////////////////
class Tkomora_drutowa 											// 4
{
    string nazwa;
    int Tzdarzenie::*wL; 				// 5
    int Tzdarzenie::*wP;				// 6
    Twsk 		wG; 					// 7
    Twsk 		wD; 					// 8

    // ...
public:
    Tkomora_drutowa(string nnn,	 								// 9
                    int Tzdarzenie::*wsk_lewy,
                    int Tzdarzenie::*wsk_prawy,
                    Twsk			wsk_gora,
                    Twsk			wsk_dol)
        : nazwa(nnn),
          wL(wsk_lewy), wP(wsk_prawy),
          wG(wsk_gora), wD(wsk_dol)
    {
    }
    //----------------------------------------------------------------------------------------
    void analizuj()													// 10
    {
        cout << "  " << nazwa << ": moja elektroda lewa = "
             << biezace_zdarzenie ->* wL						// 11
             << ", prawa = " << biezace_zdarzenie ->* wP 			// 12
             << endl;
    }
};
//////////////////////////////////////////////////////////////////////////////////////////////
void dokonaj_pomiaru();
//*******************************************************
int main()
{
    // definicje dwóch urządzeń pomiarowych
    Tkomora_drutowa  	mw41("mw41",							// 13
                             &Tzdarzenie::polka_sygnalu_mw41_lewy,
                             &Tzdarzenie::polka_sygnalu_mw41_prawy,
                             &Tzdarzenie::polka_sygnalu_mw41_gora,
                             &Tzdarzenie::polka_sygnalu_mw41_dol);

    Tkomora_drutowa  	mw42("mw42",							// 14
                             &Tzdarzenie::polka_sygnalu_mw42_lewy,
                             &Tzdarzenie::polka_sygnalu_mw42_prawy,
                             &Tzdarzenie::polka_sygnalu_mw42_gora,
                             &Tzdarzenie::polka_sygnalu_mw42_dol);

    // Rozpoczynamy pomiary.
    for(int i = 0 ; i < 50 ; ++i) 										// 15
    {
        cout << "Pomiar nr " << i << endl;
        dokonaj_pomiaru();	  									// 16
        mw41.analizuj(); 											// 17
        mw42.analizuj();
    }
    delete biezace_zdarzenie; 										// 18
}
//*******************************************************
void dokonaj_pomiaru() 											// 19
{
    if(biezace_zdarzenie)   {
        delete biezace_zdarzenie;    // 20
    }

    biezace_zdarzenie = new Tzdarzenie; 								// 21

    // Dalej już jest wielkie oszustwo.
    // imitacja odczytu wyników z układów elektronicznych
    static int m;													// 22
    m += 100;
    // Rozłożenie „wyników pomiaru” na odpowiednich półkach
    biezace_zdarzenie->polka_sygnalu_mw41_lewy		= m + 1; 		// 23
    biezace_zdarzenie->polka_sygnalu_mw41_prawy		= m + 5;
    biezace_zdarzenie->polka_sygnalu_mw41_gora		= m + 6;
    biezace_zdarzenie->polka_sygnalu_mw41_dol			= m + 7;

    biezace_zdarzenie->polka_sygnalu_mw42_lewy		= m + 8;
    biezace_zdarzenie->polka_sygnalu_mw42_prawy		= m + 9;
    biezace_zdarzenie->polka_sygnalu_mw42_gora		= m + 10;
    biezace_zdarzenie->polka_sygnalu_mw42_dol			= m + 11;
}
