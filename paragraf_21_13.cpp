// Program z paragrafu 21_13


#include <iostream>
using namespace std;

using  typ_pix = unsigned char;  // czyli zakres wartości jasności piksela to 0 – 255 	// 1
////////////////////////////////////////////////////////////////////////////////////////////////////////
class Tkolor 															// 2
{
    typ_pix	czerw;     // zwykłe składniki klasy nigdy nie są deklarowane constexpr  	// 3
    typ_pix	ziel; 		// ale mogą być const (nie muszą)
    typ_pix	nieb;
public:

    constexpr   Tkolor(typ_pix cz, typ_pix zi, typ_pix ni)  :    					// 4
        czerw(cz),	ziel(zi),	 nieb(ni)
{   /* puste ciało */
    }

    Tkolor() : ziel(0)  		// zwykły konstruktor   							// 5
    {
        czerw = 0;
        nieb = 0;
    }

    constexpr unsigned int     id()                 								// 6
    {
        return (czerw << 16) + (ziel << 8) + nieb;     						// 7
    }

    constexpr int     ile_pikseli_swieci()    									// 8
    {
        return	(czerw ? 1 : 0) +   		// czy czerw jest niezerowy?  tak = 1, nie = 0
        (ziel ? 1 : 0) +
        (nieb ? 1 : 0);
    }
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// To są stałe dosłowne klasy Tkolor.
constexpr Tkolor 		wzorcowy_czerwony {255, 0, 0};     					// 9
constexpr Tkolor 		wzorcowy_niebieski {0, 0, 255};
constexpr Tkolor 		wzorcowy_pomaranczowy {255, 180, 0};

// To nie jest stała dosłowna (obiekt constexpr), to po prostu zwykły (zmienny) obiekt globalny.
Tkolor blady_pomarancz {255, 180, 150};   								// 10

// constexpr  Tkolor kolor_karoserii;  				 // błąd 					// 11
Tkolor kolor_tapicerki;  												// 12

typ_pix  zmienna = 150;
// constexpr Tkolor cudowny {zmienna, 180, 0};  							// 13
//*******************************************************************
int main()
{
    constexpr Tkolor 	wzorcowy_fioletowy {255, 0, 255};     					// 14
    constexpr Tkolor 	wzorcowy_zolty {255, 255, 0};

    cout	<< "wzorcowy_fioletowy  id= 0x" << hex <<wzorcowy_fioletowy.id() 		// 15
            << "\nwzorcowy_czerwony  id= 0x" <<wzorcowy_czerwony.id()
            << "\nwzorcowy_niebieski  id= 0x"  <<wzorcowy_niebieski.id()
            << dec << endl;

    Tkolor kolor_wybrany {0, 0, 255}; 	  // intensywności np. odczytane z ekranu 		// 16
    cout	<< "W wybranym kolorze swiecacych pikseli jest:  "
            << kolor_wybrany.ile_pikseli_swieci() << endl;   						// 17

    // Gdy funkcja id zwraca wyrażenie constexpr, to może stać przy etykiecie case.
    switch(kolor_wybrany.id() ) 											// 18
    {
    case  wzorcowy_czerwony.id() :   										// 19
        cout << "Rozpoznany:  kolor czerwony" << endl;
        break;
    case  wzorcowy_niebieski.id() : 										// 20
        cout << "Rozpoznany:  kolor niebieski" << endl;
        break;

    //  case blady_pomarancz.id():   										// 21
    // 	cout << "to jest kolor blady pomaranczowy" << endl;
    // 	break;

    default:
        cout << "Nie mam takiego zapamietanego we wzorniku kolorow" << endl;
        break;
    }  // koniec switch

    // Jeszcze inne zastosowanie – wolno użyć do określenia szerokości pola bitowego
    struct robocze_slowo_stanu {   										// 22
int pole_bitowe 	:
        wzorcowy_pomaranczowy.ile_pikseli_swieci();
        // 	int drugie_pole 	:   blady_pomarancz.ile_pikseli_swieci(); 			// 23
    };

    // Wyrażenia constexpr można użyć dla wartości na liście wyliczeniowej.
    enum kolor_plomiena { 	pierwszy = wzorcowy_czerwony.id(),
                            drugi = wzorcowy_pomaranczowy.id(),   		// 24
                            trzeci = wzorcowy_zolty.id(),
                            // obiektu nie-constexpr nie można tu użyć
                            //  	czwarty = blady_pomarancz.id()   			// 25
                        };
}
