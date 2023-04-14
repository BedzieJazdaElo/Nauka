// Program z paragrafu 19_06


#ifndef HELPER_H
#define HELPER_H
/***************************************************************************************************************
        helper.h
***************************************************************************************************************/
#include <string>
namespace pomocnik_stringowy   										// `1
{
	//  Funkcja wczytująca wartość następującą bezpośrednio po zadanym słowie kluczowym
	double    wczytaj_parametr(std::string  tresc_pliku, std::string slowo);   // 		`2

	// Funkcja szukająca zadanego słowa kluczowego
	size_t    znajdz_slowo_kluczowe(std::string  tresc_pliku, std::string  slowo) ;  		// `3

	// Dwie pomocnicze klasy dla oznajmiania dwóch sytuacji wyjątkowych
	struct Twyj_sl_klucz  												// `4
	{
		std::string wiadomosc;
	} ;
	struct Twyj_blad_wart  												// `5
	{
		std::string wiadomosc;
	} ;

	// wczytanie np. jakiejś najnowszej opcji, która może jeszcze nie istnieć w starym
	// zestawie parametrów
	double    wczytaj_parametr_opcjonalny(	std::string zrodlo, std::string slowo,
										double wartosc);				// `6
}   // koniec zakresu przestrzeni nazw
//********************************************************************
// przydatny (bo krótszy) alias nazwy tej przestrzeni nazw
namespace PS = pomocnik_stringowy;   									// `7
#endif   // koniec strażnika nagłówka

// Plik Thelper.cpp

/***************************************************************************************************************
                          helper.cpp
***************************************************************************************************************/
// #include "Thelper.h"   // zlikwidować komentarz, jeśli rzeczywiściej jest to w osobnym pliku
#include <algorithm>  // deklaracje typu wyjątków std::invalid_argument, std::out_of_range
#include <iostream>
using namespace std;
//********************************************************************
double pomocnik_stringowy::wczytaj_parametr(string tresc_pliku, string slowo)   		// `8
{
    size_t     pos = znajdz_slowo_kluczowe(tresc_pliku, slowo); 				// `9
    // po sukcesie wczytamy daną stojącą zaraz za znalezionym słowem kluczowym
    string pomocniczy = tresc_pliku.substr(pos);   							// `10
    try {  																// `11
        double wartosc = stod(pomocniczy);
        return wartosc ;					 // zwraca poprawnie wczytaną wartość 		`12
    }
    catch(std::invalid_argument) 			// wyjątek rzucany przez funkcję stod   		`13
    {
        Twyj_blad_wart kapsula;  											// `14
        kapsula.wiadomosc =    											// `15
            "Blad wczytania wartosci liczbowej po slowie kluczowym: " + slowo;
        throw kapsula ;
    }
    catch(std::out_of_range) {			// wyjątek rzucany przez funkcję stod  		`16
        Twyj_blad_wart kapsula;
        kapsula.wiadomosc = "Blad: wartosc po slowie kluczowym \""
                            + slowo
                            + "\"jest za duza jak na typ double" ;
        throw kapsula ;
    }
}
//********************************************************************
size_t    pomocnik_stringowy::znajdz_slowo_kluczowe(string tresc_pliku, string slowo)
{
    size_t      pozycja = tresc_pliku.find(slowo);  								// `17
    if(pozycja != string::npos) 		// znalezione    						`18
    {
        // zwracamy pozycję pierwszego znaku ZA słowem kluczowym
        return pozycja + slowo.size();    										// `19
    }
    else {
        Twyj_sl_klucz    kapsula;   											// `20
        kapsula.wiadomosc = "Nie ma slowa kluczowego \'" + slowo + "\' w podanym tekscie." ;
        throw kapsula; 													// `21
    }
}
//********************************************************************
namespace pomocnik_stringowy   										// `22
{
//------------------------
double  wczytaj_parametr_opcjonalny(string zrodlo, string slowo, double wartosc)  		// `23
{
    double p = 0;
    try {
        p = wczytaj_parametr(zrodlo, slowo);
    }
    catch(Twyj_sl_klucz & k)												// `24
    {
        p = wartosc;
        cout << "W pliku/stringu  nie ma (opcjonalnego) slowa kluczowego '" << slowo
        	  << "'\n wiec przyjmuje dla niego wartosc domniemana: " << p << endl;
    }
    return p;
}	// koniec funkcji
//---------------------------
}   // koniec zakresu pomocnik_stringowy



// Plik main.cpp, w którym korzystamy
// z powyższych funkcji – mogących rzucić wyjątki

// #include "Thelper.h"   // zlikwidować komentarz, jeśli rzeczywiściej jest to w osobnym pliku
#include <iostream>
using namespace std;

// Oto treść pliku  reprezentowana przez surowy string  		`25
string parametry_txt = R"(Poczatek pliku z danymi
                           linijka z jakimis informacjami ogolnymi
                           beta  				45.3
                           alfa     			23
                           delta   			1024
                           omega  			88.2
                           jota    			44.4
                           flaga_operacji 		1
                           PI				3.1416
                           )";
//********************************************************************
int main()
{
    	// Z treści stringu parametry_txt , (jakby z pliku dyskowego) chcemy przeczytać
	// wartości odpowiadające konkretnie nazwanym parametrom
    	double omega = 0;
    	double beta = 0;
	double nowy_par = 0 ;

    	try { 			//------------------------										`26
    	    omega = pomocnik_stringowy::wczytaj_parametr(parametry_txt, "omega"); 		// `27
    	    cout << "Poprawnie wczytany parametr omega = " << omega << endl;

    	    beta = PS::wczytaj_parametr(parametry_txt, "beta");					// `28
    	    cout << "Poprawnie wczytany parametr beta = " << beta << endl;
    	}			//------------------------
    	catch(PS::Twyj_sl_klucz & k) 	//------------------------						`29
   	{
        	cout <<  k.wiadomosc <<  endl; 									// `30
        	cout << "Porada: dodaj to slowo kluczowe (oraz wartosc) do tresci "
			" stringu 'parametry_txt' " << endl;  							// `31
		return 1; 		// zakończmy program    							`32
    	}
    	catch(PS::Twyj_blad_wart &k)    	//------------------------						`33
    	{
      		cout  <<  k.wiadomosc <<  endl;  									// `34
        	cout << "Porada: Popraw zapis liczby po tym slowie kluczowym w tresci "
				"stringu 'parametry_txt' "<< endl; 							// `35
        	throw; 														// `36
    	}
    	catch(...)   					//------------------------						`37
    	{
    		cout << "Przechwycony nierozpoznany wyjatek. Konczymy program" << endl;
        	throw ; // oddajemy ten wyjatek systemowi operacyjnemu
	}

	cout << "Proba przeczytania parametru, ktorego moze nie byc..." << endl;
	nowy_par = PS::wczytaj_parametr_opcjonalny(parametry_txt, "nowy_par", 22);
	cout << "Ustalony nowy_par = " << nowy_par  << endl;

	// ...Dalsza część programu korzystająca z tych parametrów
}
