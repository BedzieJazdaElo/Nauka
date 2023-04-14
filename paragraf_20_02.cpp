// Program z paragrafu 20_02

// W takiej postaci jak tu, składa się z jednego pliku, który da się
// skompilować i uruchomić.
// Możesz go jednak podzielić na kilka plików, (jak w książce) wtedy
// trzeba usunąć znaki komentrza stojące przed dyrektywami:  #include  "Tstopper.h"


// Plik Tstopper.h
//////////////////////////////////////////////////////////////////////////////////////////////////////////
class Tstopper														// 1
{
public:
    enum ladunek { neutralny, jeden_plus, dwa_plus};    						// 2

private:																// 3
// public:      // <-- umożliwiłoby tworzenie obiektów klasy Tpiksel z zewnątrz klasy Tstopper
    /////////////// definicja zagnieżdżonej klasy ////////////////////
    class Tpiksel 			  												// 4
    {
        int czas_implantacji;  											// 5
        double zet;  			// liczba protonów izotopu (Z)   				// 6

        //  możemy używać enum ladunek zdefinowanego w „zewnętrznej” klasie
        ladunek 	stan_ladunkowy; 										// 7

        static int    dopuszczalny_przedzial_czasowy;  						// 8

    public:
        Tpiksel()														// 9
        {
            czas_implantacji = 0;
            zet = 0;
            stan_ladunkowy = neutralny;   								// 10
            // zauważ, że powyżej nie trzeba było pisać: Tstopper::neutralny
        }
        //*************************************************
        bool czy_jestes_w_bramce_czasowej(int biezacy_czas)				// 11
        {
            if(biezacy_czas - czas_implantacji <= dopuszczalny_przedzial_czasowy)
                return true;
            else
                return false;
        }

        void 		zapisz (int c, double z, ladunek a);   						// 12
        Tpiksel 	odczytaj ( int* c, double* z, ladunek* a ); 					// 13
        static	void 	ustawienie_przedzialu(int interesujacy_czas);			// 14
    };
    //////////////////////// koniec definicji zagnieżdżonej klasy /////////////////////////////////
private:
    Tpiksel   plytka[100][100];	   	// tu korzystamy z obiektów tej klasy   		// 15

public:
    void ustaw_przedzial_poszukiwania(int przedzial)   						// 16
    {
        Tpiksel::ustawienie_przedzialu(przedzial);							// 17
    }
    void zdarzenie_implantacja_izotopu(	int x, int y,						// 18
                                        int biezacy_czas,
                                        double zet,
                                        ladunek stan_ladunkowy);

    void zdarzenie_rozpad_beta(int x, int y, int biezacy_czas); 				// 19

    Tpiksel odczytaj_dane_implantacji_z_piksela( int x, int y,   				// 20
            int* owczesny_czas,
            double* owczesny_zet,
            ladunek* owczesny_stan_ladunkowy);
};


// Plik Tstopper.cpp zawierający definicje funkcji składowych klasy Tstopper i zagnieżdżonej w niej klasy Tpiksel

// #include "Tstopper.h"
#include <iostream>
using namespace std;
// definicja składnika statycznego (słowa static tu się już nie powtarza)
int Tstopper::Tpiksel::dopuszczalny_przedzial_czasowy; 	  					// 21
//*******************************************************************
// Funkcje składowe zagnieżdżonej klasy Tpiksel
//*******************************************************************
void Tstopper::Tpiksel::zapisz (int c, double z, ladunek a)  					// 22
{
    czas_implantacji = c;
    zet = z;
    stan_ladunkowy = a;
}
//*******************************************************************
Tstopper::Tpiksel Tstopper::Tpiksel::odczytaj (int* c, double* z, ladunek* a ) 		// 23
{
    *c = czas_implantacji;
    *z = zet;
    *a = stan_ladunkowy;
    return *this;
}
//*******************************************************************
void Tstopper::Tpiksel::ustawienie_przedzialu(int interesujacy_czas) 			// 24
{
    dopuszczalny_przedzial_czasowy = interesujacy_czas;
}
//*******************************************************************
// Funkcje składowe klasy Tstopper //*******************************************************************
void Tstopper::zdarzenie_implantacja_izotopu(int x, int y, 						// 25
        int biezacy_czas,
        double zet,
        ladunek stan_ladunkowy)
{
    cout << "––>|   Implantacja izotopu w pikselu [" << x << ", " << y << "]" << endl;

    // zapamiętujemy liczbę atomową (Z) i stan ładunkowy tego jonu
    plytka[x][y].zapisz (biezacy_czas, zet, stan_ladunkowy); 					// 26
}
//*******************************************************************
void Tstopper::zdarzenie_rozpad_beta(int x, int y, int biezacy_czas)   			// 27
{
    cout << "<––*––> Rozpad beta zarejestrowany w pikselu [" << x << ", " << y << "]" << endl;

    // najpierw sprawdzamy, czy zapisana w danym pikselu implantacja nie jest zbyt stara
    if(plytka[x][y].czy_jestes_w_bramce_czasowej(biezacy_czas))   			// 28
    {
        // dobrze, stało się to w dopuszczalnym czasie
        double zet = 0;
        ladunek stan_ladunkowy = neutralny;
        int owczesny_czas = 0;

        plytka[x][y].odczytaj(&owczesny_czas, &zet, &stan_ladunkowy);
        int czas_od_implantacji = biezacy_czas - owczesny_czas;

        cout << 	"   Z informacji zapamietanej w tym pikselu widzimy, ze\n"
             "   to rozpadl sie izotop Z = " << zet;

        if(stan_ladunkowy == neutralny) 			cout << " (bez ladunku)";
        else if(stan_ladunkowy == jeden_plus) 	cout << " (pojedynczo zjonizowany)";
        else if(stan_ladunkowy == dwa_plus) 	cout << " (podwojnie zjonizowany)";

        cout << "\n   po czasie " << czas_od_implantacji << " milisekund " << endl;
    } else {
        cout << 	"   Uznajemy, ze nie mozemy ocenic, z jakiego izotopu pochodzi "
             "ten rozpad beta,\n"
             "   bo informacja o implantacji w tym pikselu jest starsza niz\n"
             "   zadany 'przedzial poszukiwania'" << endl;
    }
}
//*******************************************************************
Tstopper::Tpiksel		// <F"Symbol"C3,5,0,0,0,0,153><@172><F255C255> typ rezultatu tej funkcji to obiekt typu Tpiksel  		// 29
Tstopper::odczytaj_dane_implantacji_z_piksela(int x,
        int y,
        int* owczesny_czas,
        double* owczesny_zet,
        ladunek* owczesny_stan_ladunkowy)
{
    plytka[x][y].odczytaj (owczesny_czas, owczesny_zet, owczesny_stan_ladunkowy);
    return plytka[x][y];
}
//Plik z funkcją main (imitujący właściwy program)


// @
// #include "Tstopper.h"    												// 30
#include <iostream>
using namespace std;
//*******************************************************************
int main ( )
{
    Tstopper stopperA; 													// 31
    stopperA.ustaw_przedzial_poszukiwania(200);   						// 32

    cout << "Uruchamiamy pomiar..." << endl;
    // W trakcie pomiaru otrzymujemy dane o implantacjach i rozpadach
    // i dane te sukcesywnie wysyłamy do stoppera, wywołując jedną z jego dwóch,
    // przygotowanych w tym celu funkcji.

    stopperA.zdarzenie_implantacja_izotopu(10, 10,  20000, 48.5, Tstopper::neutralny); // 33
    stopperA.zdarzenie_implantacja_izotopu(14, 35,  20010, 44.3, Tstopper::dwa_plus);

    stopperA.zdarzenie_implantacja_izotopu(60, 40,  20020, 50.7, Tstopper::jeden_plus);
    stopperA.zdarzenie_implantacja_izotopu(35, 50,  20030, 46.4, Tstopper::dwa_plus);

    stopperA.zdarzenie_rozpad_beta(60, 40, 20055); 						// 34
    stopperA.zdarzenie_rozpad_beta(10, 10, 20150);

    stopperA.zdarzenie_implantacja_izotopu(10, 10,  20200, 46.0, Tstopper::neutralny);
    stopperA.zdarzenie_rozpad_beta(14, 35,  20250);
    // ...i tak dalej

    //------------------------------------------------------------
    // Próba, czy można odebrać wartość funkcji będącą obiektem typu
    // zagnieżdżonej klasy Tpiksel
    int odtworzony_czas;  			 // obiekty przygotowane do odebrania informacji
    double odtworzone_zet;
    Tstopper::ladunek    	odtworzony_stan_ladunkowy;

    // Tstopper::Tpiksel p =
    stopperA.odczytaj_dane_implantacji_z_piksela ( 35, 50,    			// 35
            &odtworzony_czas,
            &odtworzone_zet,
            &odtworzony_stan_ladunkowy);

    cout << "\nTEST: W pikselu 35, 50 jest zapisana wartosc zet = "
         << odtworzone_zet << endl;
}
