// Program z paragrafu 37_16_03

 #include <iostream>
#include <vector>
using namespace std;
///////////////////////////////////////////////////// szablon klas (pierwotny) ///////////////////////////////////////////////////
template <typename T>												// 1
class Takumulator {
    T depozyt;
public:
    Takumulator()   		{
        zeruj_depozyt();
    }
    void zeruj_depozyt() 	{
        depozyt = 0;
    }
    void przyjmij(T co)		{
        depozyt = depozyt + co;
    }
    T jaki_depozyt() 		{
        return depozyt;
    }
    T rozladunek() {
        T x = depozyt;
        zeruj_depozyt();
        return x;
    }
};
//////////////////////////////////////////////////////////////////////////////////////////////////
// Użytkownik szablonu robi specjalizację (tzw. częściową) klasy szablonowej Takumulator
template <typename T>												// 2
class Takumulator<T*> {   // to oznacza, że interesują nas tylko wskaźniki typu T*  	// 3
    vector<T*> adr_kratek;  											// 4
public:
    void przyjmij(T* gdzie)												// 5
    {
        adr_kratek.push_back(gdzie);
    }
    //––––––––––––––––––
    T biezaca_suma ()													// 6
    {
        T suma {};
        for(auto wsk : adr_kratek) suma += *wsk;
        return suma;
    }
    void pokaz_skladniki() 												// 7
    {
        for(auto elem : adr_kratek) cout << *elem << " , ";
    }
    T rozladunek();													// 8
};
//********************************************************************
template <typename T>
T Takumulator<T*>::rozladunek()
{
    auto suma = biezaca_suma();
    adr_kratek.clear(); 				// zerowanie wektora adresów
    return suma;
}
//********************************************************************
int main()
{
    // Ilustracja zastosowania specjalizacji częściowej (dla wskaźników) ––––––––––
    vector<double> kratka {22, 40, 20.2, 30, 10, 44.4, 55.5, 66.6, 77.7, 88.8};  		// 9

    Takumulator<double*> sumator;  										// 10
    sumator.przyjmij( &kratka[5] ); // zapamiętanie adresu danej kratki		// 11
    sumator.przyjmij( &kratka[6] );
    sumator.przyjmij( &kratka[8] );

    cout << "1) Obecna suma wybranych kratek = " << sumator.biezaca_suma() << endl; // 12

    kratka[6] *= 3;  	// czyli kratka[6] ma teraz wartość 165.5				 // 13
    cout << "3) Obecna suma = " << sumator.biezaca_suma() << endl; 			// 14

    cout << "Skladniki sumy: ";
    sumator.pokaz_skladniki();
    cout << "Koncowe sumowanie = " << sumator.rozladunek() << endl;  		// 15
    cout << "4) Obecna suma = " << sumator.biezaca_suma() << endl;  		// 16
}
