// Program z paragrafu 29_05

#include <iostream>
#include <string>
#include <vector>
using namespace std;
// @

// @
//////////////////////////////////////////////////////////////////////////////////////////////
struct Tszuflada {   														// 1
    union   {   															// 2
        std::vector<double>   	zestaw;
        std::string   			tekst;
    };

    enum Typ_wariantu { tryb_wektorowy, tryb_tekstowy }; 						// 3
    Typ_wariantu 		wyroznik; 											// 4
public:
    Tszuflada();
    ~Tszuflada();
    void co_teraz_w_unii();
    Tszuflada& operator= ( const vector<double> & wartosc );
    Tszuflada& operator= ( const string &napis );
};
// @

// @
//*******************************************************
Tszuflada::Tszuflada() { 													// 5
    new (&zestaw) std::vector<double>; 			// zakładamy obiekt klasy vector
    wyroznik = tryb_wektorowy;
}
// @

// @
//*******************************************************
Tszuflada::~Tszuflada() 													// 6
{
    if(wyroznik == tryb_tekstowy) {
        tekst.~string();  						// likwidujemy string
        cout << "destrukcja stringu " << endl;
    } else {									// czyli jeśli obecnie tryb_wektorowy
        zestaw.~vector<double>(); 				// to likwidujemy wektor
        cout << "destrukcja vectora " << endl;
    }
}
// @

// @
//*******************************************************
void Tszuflada::co_teraz_w_unii() 											// 7
{
    switch(wyroznik)
    {
    case tryb_wektorowy:
        cout << "W unii jest wektor liczb: ";
        for(auto n : zestaw) cout << n  << ", ";
        cout << endl;
        break;
    case tryb_tekstowy:
        cout << "W unii jest tekst: " << tekst << endl;
        break;
    }
}
// @

// @
//*******************************************************
Tszuflada& Tszuflada::operator=(const std::string & napis)   						// 8
{
    if(wyroznik == tryb_tekstowy) {	// czyli jeśli już jesteśmy w trybie tekstowym...
        tekst = napis; 				// ...to wystarczy przypisać tekst				// 9
    }
    else if (wyroznik == tryb_wektorowy)	// jeśli zaś wcześniej był wektor...
    {
        zestaw.~vector<double>(); 			// likwidujemy wektor				// 10
        new (&tekst)  std::string(napis); 		// budujemy obiekt typu string			// 11
        wyroznik = tryb_tekstowy;
    }
    return *this;
}
// @

// @
//*******************************************************
Tszuflada& Tszuflada::operator=(const vector<double> & wek)  					// 12
{
    if(wyroznik == tryb_wektorowy) {		// jeśli już jest właściwy tryb wektorowy
        zestaw = wek;					// to wystarczy skopiować treść przysłanego	 	// 13
    }
    else if(wyroznik == tryb_tekstowy)	// jeśli zaś tryb się nie zgadza
    {
        tekst.~string(); 		// likwidujemy dotychczasowy obiekt typu string 			// 14
        new (&zestaw) vector<double>(wek); // i budujemy obiekt klasy vector			// 15
        wyroznik = tryb_wektorowy;
    }
    return *this;
}
// @

// @
//*******************************************************
int main()
{
    Tszuflada	 u;	 													// 16
    u.co_teraz_w_unii();

    u.zestaw.push_back(3.3);
    u.zestaw.push_back(2.2);
    u.co_teraz_w_unii();

    u = "Stal dwor szlachecki, z drzewa, lecz podmurowany"; 						// 17
    u.co_teraz_w_unii();													// 18
    cout << "Pracujemy... " << u.tekst.substr(5, 24) << endl;	// przykład korzystania		// 19
    // wpisanie do unii innego typu treści (wektora liczb)
    u = vector<double> { 0, 0.1,0.2,0.3}; 					// operatorem przypisania		// 20
    u.zestaw[2]= 44.4; 									// ewentualne korzystanie		// 21
    u.co_teraz_w_unii();

    // przypisanie także wektora, ale z innym zestawem liczb
    u = vector<double> { 99.1, 98.2, 97.3, 96.4, 95.5}; 		// operatorem przypisania 		// 22
    u.co_teraz_w_unii();

    // zmiana trybu z powrotem na tekstowy
    u = "Krotkie były Sedziego z synowcem witania"; 							// 23
    u.co_teraz_w_unii();
    u = "Slusznie Wozny powiadal, ze w zamkowej sieni";						// 24
    u.co_teraz_w_unii();
}
