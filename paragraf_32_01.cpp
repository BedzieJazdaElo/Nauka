// Program z paragrafu 32_01

/*-------------------------------------------
				plik: Tinstrument.h
-------------------------------------------*/
#include <iostream>
using namespace std;
//////////////////////////////////////////////////////////////////////////////////////////////
class Tinstrument													// 1
{
    int cena;
public:
    virtual void wydaj_dzwiek()										// 2
    {
        cout << " Nieokreslony brzdek!\n";
    }
    // ...
};
//////////////////////////////////////////////////////////////////////////////////////////////
class Ttrabka : public Tinstrument  									// 2
{
public:
    void wydaj_dzwiek()
    {
        cout << " Tra-ta-ta!\n";
    }
    // ...
};
//////////////////////////////////////////////////////////////////////////////////////////////
class Tbeben : public Tinstrument  									// 2
{
public:
    void wydaj_dzwiek()
    {
        cout << " Bum-bum-bum!\n";
    }
    // ...
};
//////////////////////////////////////////////////////////////////////////////////////////////
class Tfortepian : public Tinstrument 				 					// 2
{
public:
    void wydaj_dzwiek()
    {
        cout << " Plim-plim-plim!\n";
    }
    // ...
};


// Ta linijka poniżej jest niepotrzebna, jeśli kompilujemy w postaci
// jednego wspólnego pliku

//  #include "Tinstrument.h"
/*-------------------------------------------
				plik: Tinstrument.cpp
-------------------------------------------*/
void muzyk(Tinstrument & powierzony_instrument);
//*******************************************************
int main()
{
    Tinstrument 	jakis_instrument;									// 3
    Ttrabka	 	zlota_trabka;
    Tfortepian	steinway_giseli;
    Tbeben	 	moj_werbel;

    cout << 	"Zwykle wywolania funkcji skladowych\n"
         "na rzecz obiektow - jak dotad nic szczegolnego\n";

    jakis_instrument.wydaj_dzwiek(); 									// 4
    zlota_trabka.wydaj_dzwiek();
    steinway_giseli.wydaj_dzwiek();
    moj_werbel.wydaj_dzwiek();

    cout << 	"Wywolanie funkcji na rzecz obiektu \n"
         "pokazywanego wskaznikiem instrumentu\n";

    Tinstrument *wskinstr; 											// 5
   // ustawienie wskaźnika
       wskinstr = & jakis_instrument;									// 6
       wskinstr-> wydaj_dzwiek(); 										// 7

       cout << "Rewelacja okazuje sie przy pokazaniu wskaznikiem\ndo instrumentow"
       " na obiekty klas pochodnych\n od klasy Tinstrument! \n";

       wskinstr = &zlota_trabka;										// 8
       wskinstr-> wydaj_dzwiek();										// 9

       wskinstr = &steinway_giseli;
       wskinstr-> wydaj_dzwiek();

       wskinstr = &moj_werbel;
       wskinstr-> wydaj_dzwiek();

       cout << "Podobne zachowanie jest takze \nw stosunku do referencji \n";

       muzyk(jakis_instrument); 										// 10
       muzyk(zlota_trabka); 		 			   						// 11
       muzyk(steinway_giseli); 		 		   						// 12
       muzyk(moj_werbel);

       cout << "Orkiestra instrumentow zagra koncert" << endl;
       Tinstrument* orkiestra[10] =										// 13
    { &zlota_trabka, &moj_werbel, &steinway_giseli, &moj_werbel, &zlota_trabka, };

    for(int nr = 0 ; nr < 5; ++nr)   										// 14
    orkiestra[nr]->wydaj_dzwiek();   								// 15
}
//*******************************************************
void muzyk(Tinstrument & powierzony_instrument)	   					 // 16
{
    powierzony_instrument.wydaj_dzwiek();
}

