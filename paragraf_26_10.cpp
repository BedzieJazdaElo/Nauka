// Program z paragrafu 26_10

#include <iostream>
#include <vector>
using namespace std;
#include <string>
#include <ctime>     								// deklaracja funkcji time
void zwloka(int sekund); 							// sama deklaracja
//////////////////////////////////////////////////////////////////////////////////////////////
class Tekran_alfanum													// 1
{
    string 	tresc;
    char 	tlo_ekranu;
    enum 	{ wys_ekranu = 24, szer_ekranu = 63 };
public:
    Tekran_alfanum() : tlo_ekranu(' ')										// 2
    {
        tresc.resize(wys_ekranu * szer_ekranu, tlo_ekranu);
    }
    //--------------------
    void zamaluj_obszar(int lewy, int gora, int prawy, int dol, char tlo_okna);
    //--------------------
    void wyswietl()													// 3
    {
        cout << tresc << flush;
    }
    //--------------------
    void wymaz_wszystko()												// 4
    {
        zamaluj_obszar(0,0, szer_ekranu, wys_ekranu, tlo_ekranu);
    }
    //-------------------
    // funkcja składowa wpisująca w miejscu x, y zadany tekst
    void napisz(int kolumna, int rzad, string tekst)							// 5
    {
        tresc.replace(szer_ekranu * rzad + kolumna, tekst.length(), tekst);
    }
};
//////////////////////////////////////////////////////////////////////////////////////////////
void Tekran_alfanum::zamaluj_obszar(	int lewy, int gora,
                                        int prawy, int dol, char tlo_okna)		// 6
{
    // wypełnienie zadanego fragmentu ekranu „kolorem” tła okna
    int dlugosc = prawy - lewy;
    for(int y = gora ; y < dol ; y++)
    {
        tresc.replace(y * szer_ekranu + lewy, dlugosc, dlugosc, tlo_okna);
    }

    // dla pewności wstawienie znaków przejścia do nowej linii ekranowej
    // w odpowiednich miejscach stringu
    for(int i = 0 ; i < wys_ekranu ; ++i)
    {
        tresc[(i+1) * szer_ekranu - 1] = '\n';
    }
}
//*******************************************************
Tekran_alfanum monitor; 			// definicja globalnego obiektu 			// 7
//*******************************************************
class Tpulpit;        				// deklaracja zapowiadająca
//////////////////////////////////////////////////////////////////////////////////////////////
class Tokno   														// 8
{
    int 		x, y, wys, szer;     	// geometria okienka
    char 	kolor;       	       	// kolor okienka
    string 	tytul;         		// opis okienka
public:
    Tokno(int xx, int yy, int ss, int ww, char kk, string tt)
        :	x(xx), y(yy), wys(ww), szer(ss), kolor(kk), tytul(tt)
    { }
    // dodanie okienka w operacji  pulpit = pulpit + okienko
    Tpulpit operator +(Tokno & m2);
    void narysuj_sie();
};
//////////////////////////////////////////////////////////////////////////////////////////////
// definicje funkcji składowych klasy Tokno //*******************************************************
void Tokno::narysuj_sie() 												// 9
{
    // zamaluj kolorem tła
    monitor.zamaluj_obszar(x, y, x + szer, y + wys, kolor);					// a)
    // narysowanie ramki – dwie linie poziome -------------
    string linijka(szer, '-');
    monitor.napisz(x, y,		linijka);				// górny brzeg 		b)
    monitor.napisz(x, y + wys,   	linijka);				// dolny brzeg
    // cd. rysowania ramki – dwie linie pionowe ------------
    for(int i = 0; i < wys+1; ++i)
    {
        monitor.napisz(x, y + i, "|");					// lewy brzeg	 		c)
        monitor.napisz(x + szer, y+i, "|");				// prawy brzeg
    }
    // napisanie tytułu okna na środku pierwszej linijki
    monitor.napisz(x + (szer - (tytul.size())) / 2, y, tytul);	// 					d)
    monitor.wyswietl();													// 10
}
//////////////////////////////////////////////////////////////////////////////////////////////
// definicja klasy odpowiadającej za ustawianie okien na ekranie względem siebie, wyjmowanie
// niektórych na wierzch itd.
// Tu jest cały „program naukowy” tego przykładu.
//////////////////////////////////////////////////////////////////////////////////////////////
class Tpulpit 														// 11
{
    vector<Tokno*> vec_okien;
public:
    Tpulpit()									// konstruktor
    { }
    void odswiez(); 							// narysowanie obecnego stanu ekranu
    void mazanie();     							// mazanie treści całego ekranu
    // ------------ przeładowane operatory
    void operator+=(Tokno * adr_ok);   			// dodawanie okienka
    void operator-=(Tokno * adr_ok);         		// usuwanie okienka
    void operator!=(Tokno * adr_ok);    			// wyjmowanie na sam wierzch
};
//*******************************************************
// definicje funkcji składowych klasy Tpulpit
//*******************************************************
void Tpulpit::odswiez()   	            										// 12
{
    for(auto okno : vec_okien) 	okno-> narysuj_sie();
}
//*******************************************************
void Tpulpit::mazanie()												// 13
{
    monitor.wymaz_wszystko();
}
//*******************************************************
// dodawanie okna
void Tpulpit::operator +=(Tokno * adr_ok) 									// 14
{
    vec_okien.push_back(adr_ok);
    odswiez();
}
//*******************************************************
// usuwanie okna z pulpitu (czyli z wektora wskaźników do okien)
void Tpulpit::operator -=(Tokno * adr_okna)	 							// 15
{
    // odszukanie w tablicy wskaźnika do tego okna
    for(unsigned int nr_usun= 0 ; nr_usun < vec_okien .size() ; ++nr_usun)
    {
        if(vec_okien[nr_usun] == adr_okna)
        {
            vec_okien.erase(vec_okien.begin() + nr_usun);
            break;
        }
    }
    mazanie(); 					// najpierw musimy zmazać cały pulpit
    odswiez();
}
//*******************************************************
/* wydobycie na sam wierzch zadanego okienka */
void Tpulpit::operator!=(Tokno * adr_okna)     								// 16
{
    // polega na postawieniu go na samym końcu wektora
    // w tym celu najprościej usunąć je z wektora i natychmiast dodać
    *this -= adr_okna;        				// czyli pulpit –= okno
    *this += adr_okna;      				// czyli pulpit += okno
    odswiez();
}
//*******************************************************
int main()
{
    Tpulpit pulpit; 									// definicja obiektu pulpit
    Tokno 	gra(15, 7, 21, 6, '$', "Gra w chinczyka"); 	// definicja kilku okien
    Tokno 	kalkulator(2, 3, 14, 6, '@', "Kalkulator");
    Tokno 	edytor(7, 5, 18, 6, ':', "Edytor");
    // umieszczenie tych okien na pulpicie
    pulpit += &gra;     		 											// 17
    pulpit += &kalkulator;
    pulpit += &edytor;													// 18
    zwloka(1);

    Tokno zegar(4, 9,18, 6, '%', "Zegar"); 	// wymyślamy jeszcze jedno okno
    pulpit += &zegar;    	// dodanie go do obecnego pulpitu 				// 19
    zwloka(1);

    pulpit != &kalkulator; 	// wyjęcie kalkulatora na sam wierzch			// 20
    zwloka(1);

    pulpit != &gra; 		// teraz wyjęcie na wierzch gry					// 21
    zwloka(1);

    pulpit -= &kalkulator; 	// usunięcie jednego z okien 					// 22
    zwloka(1);
}
//*******************************************************
// Dodatkowo zdefiniowałem funkcję zwłoka, która powoduje w programie
// zwłokę czasową wynoszącą zadaną liczbę sekund
//*******************************************************
void zwloka(int sekund)
{
    time_t 		poprzedni_czas = time(NULL);
    while(time(NULL) - poprzedni_czas < sekund)  // dopóki (bieżący czas – poprzedni) < 1 sek
    {  }    		// ciało puste
}

