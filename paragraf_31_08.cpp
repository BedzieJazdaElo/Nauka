// Program z paragrafu 31_08

#include <iostream>
using namespace std;
//////////////////////////////////////////////////////////////////////////////////////////////
class Tpojazd 					// klasa podstawowa					// 1
{
protected:
    int 					liczba_kol;    									// 2
    double *				tabl_gps;   									// 3
    static constexpr int 	ile_wspolrzednych = 2;  						 // 4
public:
    Tpojazd(int ile)   :	liczba_kol(ile),										// 5
        tabl_gps(new double[ile_wspolrzednych])
    { }

    // Mechanizm kopiowania obiektów tej klasy realizują:
    Tpojazd(const Tpojazd &);   					// konstruktor kopiujący
    Tpojazd & operator=(const Tpojazd & wz);	 	// kopiujący operator przypisania

    // Mechanizm przenoszenia realizują:
    Tpojazd(Tpojazd &&); 						// konstruktor przenoszący
    Tpojazd & operator=(Tpojazd && odzysk); 		// przenoszący operator przypisania

    // dla upewniania się, czy poprawnie skopiowano tablice współrzędnych
    void zmien_pozycje(double x, double y)  								// 6
    {
        tabl_gps[0] = x;
        tabl_gps[1] = y;
    }
};
//////////////////////////////////////////////////////////////////////////////////////////////
Tpojazd::Tpojazd(const Tpojazd & wzor)   		// konstruktor kopiujący 		// 7
{
    liczba_kol = wzor.liczba_kol;
    tabl_gps = new double[ile_wspolrzednych];
    for(int nr = 0 ; nr < ile_wspolrzednych ; ++nr)  tabl_gps[nr] = wzor.tabl_gps[nr];
}
//*******************************************************
Tpojazd::Tpojazd(Tpojazd && zlom) 			// konstruktor przenoszący 		// 8
{
    liczba_kol = zlom.liczba_kol;
    tabl_gps = zlom.tabl_gps; 											// 9
    zlom.tabl_gps = nullptr;
}
//*******************************************************
Tpojazd & Tpojazd::operator=(const Tpojazd & wz) 		// kopiujący operator= 		// 10
{
    if(this != &wz) 		// czy adres obecnego obiektu jest inny niż adres wzorca?
    {
        delete [ ] tabl_gps;

        liczba_kol = wz.liczba_kol;
        tabl_gps = new double[ile_wspolrzednych];
        for(int nr = 0 ; nr < ile_wspolrzednych ; ++nr)   tabl_gps[nr] = wz.tabl_gps[nr];
    }
    return *this; 														// 11
}
//*******************************************************
Tpojazd & Tpojazd::operator=(Tpojazd && zlom)   // przenoszący operator=   		// 12
{
    cout << "Dziala przenoszacy operator= Tpojazdu" << endl;
    if(this != &zlom)
    {
        delete [ ] tabl_gps;

        liczba_kol = zlom.liczba_kol;
        tabl_gps = zlom.tabl_gps;
        zlom.tabl_gps = nullptr;
    }
    return *this;
}
// Klasa pochodna ###########################################################################
                          class Tautomobil : public Tpojazd 										// 13
{
    int 		stan_licznika;
    string 	kolor_karoserii;
public:
    Tautomobil(int kola, string kolor, int licznik) : Tpojazd(kola)
    {
        stan_licznika = licznik;
        kolor_karoserii = kolor;
    }
    // Mechanizm kopiowania obiektów realizują poniższe funkcje
    Tautomobil(const Tautomobil &);
    Tautomobil & operator=(const Tautomobil &ww);
    // Mechanizm przenoszenia realizują
    Tautomobil(Tautomobil &&);
    Tautomobil & operator=(Tautomobil &&ww);

    friend ostream &   operator<<(ostream & ekran, const Tautomobil & obj); 		// 14
};
//////////////////////////////////////////////////////////////////////////////////////////////
//    definicja konstruktora kopiującego dla klasy pochodnej
Tautomobil::Tautomobil(const Tautomobil & wzorzec)	: Tpojazd(wzorzec) 		// 15
{
    stan_licznika = 0;
    kolor_karoserii = wzorzec.kolor_karoserii;
}
//*******************************************************
//    definicja konstruktora PRZENOSZĄCEGO dla klasy pochodnej
Tautomobil::Tautomobil(Tautomobil && odzysk)  							// 16
    : Tpojazd(std::move(odzysk) ) 		// 17
{
    stan_licznika = 0;
    kolor_karoserii = odzysk.kolor_karoserii;
}
//*******************************************************
//   definicja kopiującego operatora przypisania dla klasy pochodnej
//*******************************************************
Tautomobil & Tautomobil::operator=(const Tautomobil &wzor) 				// 18
{
    if(this != &wzor) 													// 19
    {
        Tpojazd::operator=(wzor);   // wywołanie zasłoniętego z klasy podstawowej 	// 20
        // dalej tylko dokańczamy robotę
        kolor_karoserii = wzor.kolor_karoserii; 								// 21
        stan_licznika = wzor.stan_licznika + 2;
    }
    return *this;
}
//*******************************************************
//   definicja PRZENOSZĄCEGO operatora przypisania klasy pochodnej
Tautomobil & Tautomobil::operator=(Tautomobil &&wzorcowy) 				// 22
{
    if(this != &wzorcowy)
    {
        //   wywołanie jawne zasłoniętego operatora z klasy podstawowej
        Tpojazd::operator=( std::move(wzorcowy) );   // UWAGA: patrz wyjaśnienia 	// 23

        // dalej tylko dokańczamy robotę
        kolor_karoserii = wzorcowy.kolor_karoserii;
        stan_licznika = wzorcowy.stan_licznika + 2;
    }
    return *this;
}
//*******************************************************
// 							 Aby się oswoić z przeładowaniem operatora <<
ostream & operator<<(ostream & ekran, const Tautomobil & obj) 				// 24
{
    ekran 	<< "\tkol " << obj.liczba_kol << ", przebieg " << obj.stan_licznika
            << ", kolor " << obj.kolor_karoserii;

    if(obj.tabl_gps) { 			// jeśli jest tablica, to ją wypisujemy
        ekran << ", GPS[" << obj.tabl_gps[0] << ", " << obj.tabl_gps[1] << "]" << endl;
    } else {
        ekran << "\n\tUwaga: obiekt ma wymontowana tablice GPS!" << endl;
    }
    return ekran;
}
//*******************************************************
int main()
{
    Tautomobil mojfiacik(4, "bialy", 30000);
    mojfiacik.zmien_pozycje(10.0, 25.1);    								// 25

    Tautomobil taksowka { mojfiacik }; 			// konstruktor kopiujący		// 26
    Tautomobil sluzbowy = mojfiacik; 			// konstruktor kopiujący		// 27
    taksowka.zmien_pozycje(7.3, 5.8);

    cout << "Lista istniejacych automobili \n"
         << "'mojfiacik'  " << mojfiacik		 								// 28
         << "'taksowka' " << taksowka;

    Tautomobil dziwak(3, "bialy", 5000);
    cout << "Jeszcze jeden o nazwie 'dziwak':\n" << dziwak;

    dziwak = mojfiacik; 				// kopiujący operator przypisania		// 29
    mojfiacik.zmien_pozycje(12,12); 										// 30

    cout << "'dziwak' po przypisaniu:\n"<< dziwak<< "a mojfiacik odjechal: "<< mojfiacik; 	// 31

    const Tautomobil muzealny(4, "czerwony", 25000);						// 32
    Tautomobil filmowy { muzealny};        	// konstruktor kopiujący 			// 33

    dziwak = muzealny;    				// znowu przypisanie (kopiujące) 		// 34

    filmowy.zmien_pozycje(3,3);
    dziwak.zmien_pozycje(4,4);
    cout << "Czy przypisanie 'od' obiektu const dziala?\n"
         << "'muzealny': " << muzealny << "'filmowy': " << filmowy << "'dziwak' po... " << dziwak;

    cout << "\n### Proby pracy z mechanizmem przenoszenia ###############\n";

    Tautomobil  autko(std::move(dziwak) );  // konstruktor przenoszący  		// 35

    cout << "\nZrobione konstruktorem przenoszacym=======\n"
         << "  'autko': " << autko
         << "  ogolocony  'dziwak': " << dziwak; 								// 36

    dziwak = mojfiacik;  												// 37
    dziwak.zmien_pozycje(4, 3);
    cout << "// dziwak//  = " << dziwak << "// mojfiacik//  = " << mojfiacik << endl;

    dziwak = std::move(mojfiacik);   										// 38
    cout << "Po przypisaniu przenoszacym==========\n"
         << "// dziwak//  = " << dziwak << "// mojfiacik//  = " << mojfiacik << endl;

    dziwak = std::move(muzealny);        //  przypisanie (jednak bez przenoszenia!)		// 39
    cout << "Po przypisaniu jakim? \n"
         << "// dziwak//  = " << dziwak << "// muzealny//  = " << muzealny << endl;
}
