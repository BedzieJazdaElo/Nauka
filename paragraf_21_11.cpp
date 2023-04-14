// Program z paragrafu 21_11

// Uwaga, w książce ten program podzielony jest na kilka plików.
// Tutaj, w tej postaci jest w jednym dużym pliku który da się
// skompilować i uruchomić. Jeśli jednak wolałbyś podzielić
// go na te mniejsze pliki, to pamiętaj, że powinienieś wtedy także usunąć
// znaki komentarza rozpoczynające dyrektywy preprocesora
//    #include "Tprzyrzad.h"
// oraz
//    #include "Tekran_alfanumeryczny.h"
//


// Plik Tprzyrzad.h 		(poniżej jest "strażnik nagłówka")
#ifndef _Tprzyrzad_h_
#define  _Tprzyrzad_h_

#include <string>
class Tprzyrzad													// 8
{
    std::string 	nazwa;
    std::string 	jednostki;
    int 			pokazuje;
    int 			x, y;     	// gdzie jest na ekranie ten przyrząd
    static int 		ile_nieznanych;                       						// 9
public :
    // konstruktory
    Tprzyrzad (int,  int,  std::string,  std::string,  int wart = 0); 				// 10
    Tprzyrzad (void);

    // zwykłe funkcje składowe
    void zmien_wskazanie (int w);
    void narysuj (void);
};
#endif


// Plik: Tekran_alfanumeryczny.h   			(poniżej jest "strażnik nagłówka")
#ifndef _Tekran_alfanumeryczny_h_
#define  _Tekran_alfanumeryczny_h_

#include <string>
#include <iostream>
//********************************************************************
// Aby możliwe było narysowanie równych ramek, czcionka liter na ekranie
// powinna mieć stałą szerokość liter (taka jest na przykład czcionka "Courier").
////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Tekran_alfanumeryczny  										// 1
{
    std::string 	tresc;
    char 		znak_tla;
public:
    enum { szerokosc_ekranu = 63, wysokosc_jako_enum = 17 };  			// 2
    static constexpr  int wysokosc_ekranu = 17;  						// 3

    // konstruktor
    Tekran_alfanumeryczny(char znak = ' ')  							// 4
    {
        znak_tla = znak;
        wyczysc();
    }
    //--------------------
    void wyczysc()												// 5
    {
        tresc.clear() ;
        // wypełnienie całego "ekranu" samymi znakami tła
        std::string jedna_linijka(szerokosc_ekranu-1, znak_tla);
        jedna_linijka += '\n';
        for(int i = 0 ; i < wysokosc_ekranu ; ++i) 	tresc +=  jedna_linijka  ;
    }
    //--------------------
    void wyswietl()												// 6
    {
        std::cout << tresc << std::flush;
    }
    //--------------------
    // Funkcja składowa wpisująca w wybranym miejscu zadany tekst do treści ekranu
    void napisz(int kolumna, int rzad, std::string tekst)    					// 7
    {
        tresc.replace(		(szerokosc_ekranu * rzad) + kolumna,   tekst.length(), tekst);
    }
};
#endif   // koniec strażnika nagłówka


// Plik: Tprzyrzad.cpp

// #include "Tprzyrzad.h"
// #include "Tekran_alfanumeryczny.h"
using namespace std;
extern Tekran_alfanumeryczny     ekran; // deklaracja globalnego obiektu ekran 	11
// definicje konstruktorów
//********************************************************************
Tprzyrzad::Tprzyrzad(int xx, int yy, string nnn,  string jedn, int w)			// 12
{
    nazwa = nnn;
    jednostki = jedn;
    pokazuje = w;
    x = xx;
    y = yy;
    narysuj(); 													// 13
}
//********************************************************************
Tprzyrzad::Tprzyrzad(void)                       								// 14
{
    ++ile_nieznanych;    		// jeszcze jeden nieznany wyświetlacz
    jednostki = " ";

    // wypełnienie tablicy tekstem – "Wskaznik nr n"
    nazwa = "Wskaznik nr ";
    nazwa += to_string(ile_nieznanych);      							// 15

    // wymyślenie dla przyrządu jego pozycji na ekranie
    x = 33;
    y = 1+ (ile_nieznanych-1) * 4;         								// 16

    pokazuje = 0;          				// co ma on pokazywać
    narysuj();						// narysowanie go na "ekranie"
}
//********* dalsze funkcje składowe  ***************************************************************************
//********************************************************************
void Tprzyrzad::zmien_wskazanie(int w)
{
    pokazuje = w;
    narysuj();
}
//********************************************************************
void  Tprzyrzad:: narysuj() 											// 17
{
    // Funkcja odpowiadająca za narysowanie  na ekranie ramki z "wyświetlaczem cyfrowym"
    ekran.napisz(x, y,   " ________________________");				// 18
    ekran.napisz(x, y+1, "I                        I");
    ekran.napisz(x, y+2, "I                        I");
    ekran.napisz(x, y+3, "I________________________I");
    // Rysowanie wypełnionej spacjami ramki odbyło się najpierw.
    // Ta kolejność jest ważna, bo spacje ze stringów powyżej – zamazałyby teksty,
    //  które teraz napiszemy.
    ekran.napisz(x+4, y+1,  nazwa);
    ekran.napisz(x+7, y+2,  to_string(pokazuje) );
    ekran.napisz(x+14, y+2, jednostki );
    ekran.wyswietl();												// 19
}
//=====================================================
int Tprzyrzad::ile_nieznanych;										// 20
//====================================================

// #include "Tprzyrzad.h"												// 1
// #include "Tekran_alfanumeryczny.h"
using namespace std;
Tekran_alfanumeryczny ekran('.');
void zwloka(int sekund);
////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Tpanel														// 2
{
    int 		poz_x;
    const int 		poz_y;

    Tprzyrzad 	predkosciomierz;
    int *			wsk1;

    Tprzyrzad 	drugi;
    int *			wsk2;

public :
// konstruktor----------------------------------------
    Tpanel(    string nazw,                 									// 3
               int x, int y,
               int * zrodlo_sygnalu1,
               int * zrodlo_sygnalu2,
               string opis2, string jedn2);
// destruktor-----------------------------------------
    ~Tpanel();
// zwykła funkcja składowa
    void aktualizuj();
};
//////////////////////////////////////////////////////////////// koniec def klasy Tpanel ////////////////////////////////////////////////
// -----definicja konstruktora------------------------------------------
Tpanel::Tpanel(string nazw, int x, int y,              						// 4
               int * zrodlo_sygnalu1,
               int * zrodlo_sygnalu2,
               string opis2, string jedn2)
    : 	poz_x(x),           				// <$[symbol><@172><$]symbol> tu się zaczyna lista inicjalizacyjna
        poz_y(y),
        predkosciomierz (x, y+3, "Predkosc", "km/h"),
        drugi (x, y+7, opis2, jedn2)
{
    wsk1  = zrodlo_sygnalu1,                         							// 5
    wsk2 =  zrodlo_sygnalu2;
    ekran.napisz(poz_x, poz_y, nazw);
}
//********************************************************************
Tpanel::~Tpanel()                                          							// 6
{
    ekran.napisz(poz_x, poz_y, "  - ZLOMOWANY -   ");
}
//********************************************************************
void Tpanel:: aktualizuj()
{
    predkosciomierz.zmien_wskazanie(*wsk1);							// 7
    drugi.zmien_wskazanie(*wsk2);
}
#include <ctime>
//********************************************************************
int main()
{
    int	predkosc = 0;
    int	azymut = 270;
    ekran.wyczysc();    				// skasowanie dotychczasowej treści ekranu

    // definicja obiektu klasy Tpanel                            					8
    Tpanel kabina("Panel pilota", 1,2, &predkosc, &azymut, "Kurs ", "stopni");
    for(int i = 0 ; i < 50 ; ++i)     // imitujemy zmianę w czasie lotu
    {
        predkosc = 60 + i;
        azymut = 270 + i%3;   			// panel te zmienne właśnie pokazuje
        kabina.aktualizuj();                           							// 9
        zwloka(1);
    }
    // --- bawimy się dalej -------------------------------------------------------------
    int paliwo = 500;

    // definiujemy drugi panel   										10
    Tpanel maszynownia(	"Panel mechanika", 35,2, &predkosc,
                        &paliwo, "Paliwa w zbiorniku", "litrow");
    for(int m = 0; m < 100 ; ++m)		// imitujemy zmianę w czasie lotu
    {
        predkosc = 60 + m;
        azymut = 270 + m%3;
        paliwo--;

        kabina.aktualizuj();
        maszynownia.aktualizuj();
        zwloka(1);
    }
}
//********************************************************************
// Funkcja, która powoduje w programie zwłokę czasową o długości zadanej liczby sekund
//********************************************************************
void zwloka(int sekund)
{
    time_t   poczatkowy_czas   = time(nullptr);
    // ta pętla wykonuje się dopóki nie minie zadana liczba sekund
    while(time(nullptr) - poczatkowy_czas  <  sekund)
    { }   											// ciało puste
}
