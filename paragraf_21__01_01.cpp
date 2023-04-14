// Program z paragrafu 21_01_01


// Uwaga, w książce ten program podzielony jest na kilka plików.
// Tutaj, w tej postaci jest w jednym dużym pliku który da się
// skompilować i uruchomić. Jeśli jednak wolałbyś podzielić
// go na te mniejsze pliki, to pamiętaj, że powinienieś wtedy także usunąć
// znaki komentarza rozpoczynające dyrektywy preprocesora
//    #include "Tprzyrzad.h"
// oraz
//    #include "Tekran_alfanumeryczny.h"
//

// Plik nagłówkowy: Tekran_alfanumeryczny.h

// Plik: Tekran_alfanumeryczny.h   			(poniżej jest "strażnik nagłówka")
#ifndef _Tekran_alfanumeryczny_h_
#define  _Tekran_alfanumeryczny_h_

#include <string>
#include <iostream>
//********************************************************************
// Aby możliwe było narysowanie równych ramek, czcionka liter na ekranie
// powinna mieć stałą szerokość liter (taka jest na przykład czcionka "Courier").
////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Tekran_alfanumeryczny  										// `1
{
	std::string 	tresc;
	char 		znak_tla;
public:
	enum { szerokosc_ekranu = 63, wysokosc_jako_enum = 17 };  			// `2
	static constexpr  int wysokosc_ekranu = 17;  						// `3

	// konstruktor
	Tekran_alfanumeryczny(char znak = ' ')  							// `4
	{
		znak_tla = znak;
		wyczysc();
	}
	//--------------------
	void wyczysc()												// `5
	{
		tresc.clear() ;
		// wypełnienie całego "ekranu" samymi znakami tła
		std::string jedna_linijka(szerokosc_ekranu-1, znak_tla);
		jedna_linijka += '\n';
		for(int i = 0 ; i < wysokosc_ekranu ; ++i) 	tresc +=  jedna_linijka  ;
	}
	//--------------------
	void wyswietl()												// `6
	{
		std::cout << tresc << std::flush;
	}
	//--------------------
	// Funkcja składowa wpisująca w wybranym miejscu zadany tekst do treści ekranu
	void napisz(int kolumna, int rzad, std::string tekst)    					// `7
	{
		tresc.replace(		(szerokosc_ekranu * rzad) + kolumna,   tekst.length(), tekst);
	}
};
#endif   // koniec strażnika nagłówka



// Plik Tprzyrzad.h 		(poniżej jest "strażnik nagłówka")
#ifndef _Tprzyrzad_h_
#define  _Tprzyrzad_h_

#include <string>
class Tprzyrzad													// `8
{
	std::string 	nazwa;
	std::string 	jednostki;
	int 			pokazuje;
	int 			x, y;     	// gdzie jest na ekranie ten przyrząd
	static int 		ile_nieznanych;                       						// `9
public :
	// konstruktory
	Tprzyrzad (int,  int,  std::string,  std::string,  int wart = 0); 				// `10
	Tprzyrzad (void);

	// zwykłe funkcje składowe
	void zmien_wskazanie (int w);
	void narysuj (void);
};
#endif   // koniec strażnika nagłówka

// Plik: Tprzyrzad.cpp

//#include "Tprzyrzad.h"
//#include "Tekran_alfanumeryczny.h"
using namespace std;
extern Tekran_alfanumeryczny     ekran; // deklaracja globalnego obiektu ekran 	`11
// definicje konstruktorów
//********************************************************************
Tprzyrzad::Tprzyrzad(int xx, int yy, string nnn,  string jedn, int w)			// `12
{
	nazwa = nnn;
	jednostki = jedn;
	pokazuje = w;
	x = xx;
	y = yy;
	narysuj(); 													// `13
}
//********************************************************************
Tprzyrzad::Tprzyrzad(void)                       								// `14
{
	++ile_nieznanych;    		// jeszcze jeden nieznany wyświetlacz
	jednostki = " ";

	// wypełnienie tablicy tekstem – "Wskaznik nr n"
	nazwa = "Wskaznik nr ";
	nazwa += to_string(ile_nieznanych);      							// `15

	// wymyślenie dla przyrządu jego pozycji na ekranie
	x = 33;
	y = 1+ (ile_nieznanych-1) * 4;         								// `16

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
void  Tprzyrzad:: narysuj() 											// `17
{
	// Funkcja odpowiadająca za narysowanie  na ekranie ramki z "wyświetlaczem cyfrowym"
	ekran.napisz(x, y,   " ________________________");				// `18
	ekran.napisz(x, y+1, "I                        I");
	ekran.napisz(x, y+2, "I                        I");
	ekran.napisz(x, y+3, "I________________________I");
	// Rysowanie wypełnionej spacjami ramki odbyło się najpierw.
	// Ta kolejność jest ważna, bo spacje ze stringów powyżej – zamazałyby teksty,
	//  które teraz napiszemy.
	ekran.napisz(x+4, y+1,  nazwa);
	ekran.napisz(x+7, y+2,  to_string(pokazuje) );
	ekran.napisz(x+14, y+2, jednostki );
	ekran.wyswietl();												// `19
}
//=====================================================
int Tprzyrzad::ile_nieznanych;										// `20
//=====================================================

// Główny plik programu – ilustrujący użycie konstruktorów

// Główny plik programu (zawierający funkcję main)
#include <ctime>                    	//dla bibliotecznej funkcji : time
#include <string>
#include <iostream>
using namespace std;
//#include "Tprzyrzad.h"
// #include "Tekran_alfanumeryczny.h"
Tekran_alfanumeryczny     ekran('.');     	// definicja globalnego obiektu	`21
void zwloka(int sekund);   // deklaracja funkcji pomocniczej
//********************************************************************
int main()
{
	ekran.wyczysc();   												// `22
	// definicje obiektów  -----------------------------------------------------------
	Tprzyrzad	Pred(2, 1, "Predkosc", "wezlow", 110);					// `23
	Tprzyrzad	Vari {2, 7, "Wznoszenie", "stopy/sec"};					// `24
	Tprzyrzad 	A;     											// `25
	Tprzyrzad  	B{ } ;											// `26
	volatile 		Tprzyrzad C;           								// `27
	const Tprzyrzad 	Udzw(2, 11, "Udzwig maksymalny", "ton", 15000 );	// `28

	// symulacja normalnego ciągłego wyświetlania ----
	for(int i = 0 ; i < 30 ; i++)											// `29
	{
		Vari.zmien_wskazanie(i);
		Pred.zmien_wskazanie(110+i);
		A.zmien_wskazanie(-i);
		B.zmien_wskazanie(i % 4);
		// C.zmien_wskazanie(i % 3);     		// obiekt volatile 			`30
		// Udzw.zmien_wskazanie(270);       	// obiekt const   			`31
		zwloka(1);   												// `32
	}
}
//********************************************************************
// Dodatkowo zdefiniowałem funkcję zwloka, która powoduje w programie
// zwłokę czasową o długości zadanej liczby sekund
//********************************************************************
void zwloka(int sekund)   											// `33
{
	time_t 	poczatkowy_czas = time(nullptr);
	// poniższa pętla wykonuje się dopóki nie minie zadana liczba sekund
	while(time(nullptr) - poczatkowy_czas < sekund);   // ciało puste !
}
//********************************************************************
