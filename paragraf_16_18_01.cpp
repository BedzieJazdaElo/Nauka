// Program z paragrafu 16_18_01


// 						Warunek // 1 brzmi: "gdy nie używamy adresu tego składnika"
#include <complex>
double kwadrat(const double promien);  	// deklaracja globalnej funkcji
///////////////////////////////////////////////////////////////
class Tplansza 														// 2
{
public:
//	static int zwykly = 5;						// źle, bo nie jest const 		// 3
    // typ całkowity i const
    static const int 			ile_pol = 120;  	// dobrze, bo typ całk. i const    	// 4
    static constexpr int 		niezawodnosc  = 1000;   		// dobrze 		// 5

    // typ double, ogólniej jest typu literalnego
// 	static  const double  		temperatura = 36.6;   			//  błąd    		// 6
    static  constexpr double  		cisnienie  = 2.5; 				// dobrze. 		// 7
// 	static  constexpr double  		pole_kola = 3.14 * kwadrat(5.0);	// zły inicjalizator 	// 8

    bool  pola_gry[ile_pol];   						// pola gry w chińczyka 		// 9

    // innym przykładem typu literalnego jest biblioteczny typ std::complex
    static constexpr std::complex<double>  zesp  { 0, -1};   					// 10

    // bez użycia static, podobny efekt, ale nadaje się tylko dla liczb całkowitych
    enum { max_pionow = 16, max_graczy = 4 }; 							// 11
    int gracz[max_graczy];  												// 12
};
/////////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
using namespace std;

//  Definicje składników statycznych poza klasą
// 	const int Tplansza::ile_pol; 		// można pominąć, gdy warunek // 1 spełniony.  	// 13
// 	constexpr int  Tplansza::niezawodnosc;    			// jak wyżej 			// 14
// 	constexpr double  Tplansza::cisnienie;  			// jak wyżej 			// 15
constexpr std::complex<double>  Tplansza::zesp;   	// jak wyżej			// 16
//*************************************************
void fun(const int * wsk) 		// argument tej funkcji przesyłany jest przez adres 	  // 17
{
    int wartosc = *wsk;
}
//*************************************************
double kwadrat(double promien)  			// zwykła funkcja				// 18
{
    return promien*promien;
}
//*************************************************
int main()
{
    int a = Tplansza::ile_pol; 	// tu używamy tylko wartości tego składnika   		// 19

    cout << "Niezawodnosc = " << Tplansza::niezawodnosc 					// 20
         << " godzin pracy, Tplansza::cisnienie = " << Tplansza::cisnienie << endl;

    // Jeśli usuniesz poniższe znaki komentarza, to definicje // 13 i // 14 stają się konieczne!
    // fun (&Tplansza::ile_pol); 											// 21
    // fun (&Tplansza::niezawodnosc);

    complex<double> kopia_zesp = Tplansza::zesp;   						// 22
    const complex<double> *wskzesp = & Tplansza::zesp;   	// Uwaga! 		// 23

    cout << "Za pomocą enum:  Tplansza::max_pionow  "
         << Tplansza::max_pionow 										// 24
         << ", a Tplansza::max_graczy " <<  Tplansza::max_graczy << endl;

    // fun(& Tplansza::max_pionow); 						// błąd  			// 25
}

