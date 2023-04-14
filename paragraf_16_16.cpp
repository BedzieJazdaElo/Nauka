// Program z paragrafu 16_16

#include <string>
#include <iostream>
using namespace std;
///////////////////////////////////////////////////////////////
class Tgadula
{
    int 	licz;
    string tekst;
public:
    Tgadula(int k, string opis);		// konstruktor
    ~Tgadula();					// destruktor – deklaracja 			// 1
    // ––––––––––––––––––––––––– inne funkcje składowe
    int pokaz() 	{
        return licz;
    }
    void schowaj(int x) {
        licz = x;
    }
    void coto()
    {
        cout << tekst << " ma wartosc "<< licz << endl;
    }
};
///////////////////////////////////////////////////////////////
Tgadula::Tgadula(int k, string opis)		// konstruktor
{
    tekst = opis;
    licz = k;
    cout << "Konstruuje obiekt " << tekst << endl;
}
//*************************************************
Tgadula::~Tgadula()					// destruktor (definicja) 		// 2
{
    cout << "Pracuje destruktor (sprzata) " << tekst << endl;
}
//*************************************************
Tgadula a(1, "obiekt a (GLOBALNY)");								// 3
Tgadula b(2, "obiekt b (GLOBALNY)");
//*************************************************
int main()
{
    a.coto();
    b.coto(); 														// 4
    {   //  <----- ! 					// 5
        cout << "Poczatek lokalnego zakresu --------\n";
        Tgadula c(30, "obiekt c (lokalny)"); 							// 6
        Tgadula a(40, "obiekt a (lokalny)"); 		// zasłania ten globalny!
        cout << "\nCo teraz mamy :\n";
        a.coto(); 													// 7
        b.coto();
        c.coto();

        cout << "Do zaslonietego obiektu globalnego mozna sie jednak dostac\n";
        ::a.coto(); 												// 8
        cout << "Konczy sie lokalny zakres ---------\n";
    }															// 9
    cout << "Juz jestem poza blokiem \n";
    a.coto();														// 10
    b.coto();
    cout << "Sam uruchamiam destruktor obiektu a\n";
    a.~Tgadula(); 		 		  									// 11
    cout << "Koniec programu!!!!!!!!\n"; 	 							// 12
}

