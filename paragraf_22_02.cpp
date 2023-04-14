// Program z paragrafu 22_02

#include <iostream>
#include <string>
using namespace std;
////////////////////////////////////////////////////////////////////////////////////////////////////////
class Tkalibracja
{
    double a;						// współczynniki kalibracji
    double b;
    string nazwa; 					// nazwa dla naszej kontroli 			// 1
public:
    // ------------------konstruktor
    Tkalibracja(double wsp_a, double wsp_b, string txt);

    // ----------------konstruktor kopiujący
    Tkalibracja(Tkalibracja & wzor); 			 								// 2
    // ---------------inne funkcje składowe
    double energia (int kanal) {
        return( (a * kanal) + b );
    }
    string opis() {
        return( nazwa);    // 3
    }
};
////////////////////////////////////////////////////////////////////////////////////////////////////////
Tkalibracja::Tkalibracja(double wsp_a, double wsp_b, string txt)
    : a(wsp_a), b(wsp_b) 							// 4
{
    nazwa = txt;
}
//*******************************************************************
Tkalibracja::Tkalibracja(Tkalibracja & wzorzec) 							// 5
{
    a = wzorzec.a;
    b = wzorzec.b;
    // zamiast: nazwa = wzorzec.nazwa;
    nazwa = "-- To ja, konstruktor kopiujacy!!! --"; 						// 6
}
//*******************************************************************
void fun_pierwsza(Tkalibracja odebrana);
Tkalibracja fun_druga(void);
//*******************************************************************
int main()
{
    Tkalibracja kobalt(1.07, 2.4, "ORYGINALNA KOBALTOWA ");

    // różne warianty tego samego
    Tkalibracja 	europ {kobalt};										// 7
    // Tkalibracja 	europ = Tkalibracja(kobalt);
    // Tkalibracja 	europ = kobalt;

    cout << "Oktory kanal widma chodzi? : ";
    int kanal;
    cin >> kanal; 																	// 8

    cout << "\nWedlug kalibracji kobalt, \nopisanej jako "
         << kobalt.opis() << "\nkanalowi nr " << kanal						// 9
         << " odpowiada energia " << kobalt.energia(kanal) << endl;

    cout << "\nWedlug kalibracji europ, \nopisanej jako "
         << europ.opis() << "\nkanalowi nr " << kanal 						// 10
         << " odpowiada energia " << europ.energia(kanal) << endl;

    cout <<"\nDo funkcji pierwszej wysylam kalibracje "	<< kobalt.opis() << endl;

    fun_pierwsza(kobalt); 														// 11

    cout << "\nTeraz wywolam funkcje druga, a jej rezultat podstawie do innej kalibracji \n";

    cout << "Obiekt chwilowy zwrocony jako rezultat funkcji \nma opis ";
    cout << ( fun_druga() ).opis() << endl; 									// 12
}
//*******************************************************************
void fun_pierwsza(Tkalibracja odebrana)
{
    cout << "Natomiast w funkcji pierwszej odebralem te kalibracje\n\topisana jako "
         << odebrana.opis() << endl;										// 13
}
//*******************************************************************
Tkalibracja fun_druga(void) 													// 14
{
    Tkalibracja wewn(2, 1, "WEWNETRZNA"); 								// 15

    cout << "W funkcji fun_druga definiuje kalibracje i ma \nona opis: "
         << wewn.opis() << endl;
    return wewn; 																	// 16
}
