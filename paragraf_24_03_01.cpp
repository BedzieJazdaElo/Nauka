// Program z paragrafu 24_03_01

#include <iostream>
using namespace std;
//////////////////////////////////////////////////////////////////////////////////////////////
class K					// korektor dopplerowski  					// 1
{
public:															// 2
    // dwa sposoby  oszacowania prędkości jonu --------------------------------
    double 	tryb_przyblizony(int x) {	  							// 3
        cout << "przyblizone" << endl;
        return 0.4 / x;
    }
    double 	tryb_dokladny (int x) {									// 4
        cout << "dokladne" << endl;
        return 0.456777 / x;
    }

    // trzy sposoby oszacowania trajektorii lotu --------------------------------
    double 	sposob_Samita(double a, double b) { 					// 5
        cout << "sposobem Samita" << endl;
        return 0.314 + a + b;
    }
    double 	sposob_Franka(double a, double b) {						// 6
        cout << "sposobem Franka" << endl;
        return 0.414  + a + b;
    }
    double 	sposob_Pietera(double a, double b) {						// 7
        cout << "sposobem Pietera" << endl;
        return 0.514  + a + b;
    }

    double licz_poprawke(	double energia,							// 8
                            double (K::*wskf_predkosc)(int),				// 9
                            double (K::*wskf_tor)(double, double)); 		// 10

    using Szac_t = decltype(&K::tryb_przyblizony);   					// 11
    using Trajekt_t = decltype(&K::sposob_Pietera);   					// 12

    // Poniższa deklaracja musi być w komentarzu, bo inaczej kompilator pomyśli, że
    // nieumiejętnie próbujemy przeładowania, a przecież te
    // argumenty są tożsame z tymi powyżej, choć zapis wygląda inaczej.
    // 	double licz_poprawke(	double energia,						// 13
    // 	  				 	Szac_t    wskf_predkosc,				// 14
    // 						Trajekt_t  wskf_tor); 					// 15
};
//////////////////////////////////////////////////////////////////////////////////////////////
// definicja funkcji składowej
double  K::licz_poprawke(	double energia,							// 16
                            Szac_t    wskf_predkosc,					 		  // 17
                            Trajekt_t  wskf_tor) 	   // 18
{
    cout << "Procedura obliczania poprawki...\n\tSzacowanie predkosci: ";
    // -------------------------------------------------------
    // szacowanie prędkości za pomocą funkcji, którą wybrał użytkownik
    int zmierzona_predkosc = 6; 				// z jakiegoś pomiaru 		// 19
    double beta =
        (this->*wskf_predkosc)(zmierzona_predkosc);		// 20

    cout << "\tSzacowanie trajektorii: ";
    //-------------------------------------------------------
    // śledzenie trajektorii jonu wylatującego według innego
    // sposobu, wybranego przez użytkownika
    double wspx = 0.12;   // np. dane z komór drutowych? 				// 21
    double wspy = 0.64;
    // dla uproszczenia tylko dwa argumenty
    double cosinus_kata =
        (this->*wskf_tor)(wspx, wspy); 					// 22

    // imitacja właściwych obliczeń
    double eneria_skorygowana = energia * (1- (beta * cosinus_kata)); 	// 23
    return eneria_skorygowana; 										// 24
}
//*******************************************************
K doppler; 														// 25
//*******************************************************
int main()
{
    cout << "Obliczanie poprawki dopplerowskiej" << endl;
    cout << "Podaj wartosc energii zmierzonej? : ";
    double Em = 0;
    cin >> Em;
    double Ep = 0; 			// zmienna na rezultat (energię poprawioną)
    // pierwszy wariant ----------------------------------------------------------------------
    Ep=  doppler.licz_poprawke(	Em,
                                &K::tryb_przyblizony,
                                &K::sposob_Samita);//   			// 26
    cout << "A) Po poprawce prawdziwa wartosc = " << Ep << endl;

    // drugi wariant --------------------------------------------------------------------------
    Ep= doppler.licz_poprawke(	Em,
                                &K::tryb_dokladny,
                                &K::sposob_Pietera);  					// 27
    cout << "B) Po poprawce prawdziwa wartosc = " << Ep << endl;

    // trzeci wariant -------------------------------------------------------------------------
    Ep= doppler.licz_poprawke(	Em,
                                &K::tryb_dokladny,
                                &K::sposob_Franka);  					// 28
    cout << "C) Po poprawce prawdziwa wartosc = " << Ep << endl;
}
