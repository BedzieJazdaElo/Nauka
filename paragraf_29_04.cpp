// Program z paragrafu 29_04

#include <iostream>
using namespace std;
//////////////////////////////////////////////////////////////////////////////////////////////
struct   Ttygodnik   			// prosta klasa   						// 1
{
    int ile_stron;
    double cena;
public:
    void opis() { 	 												// 2
        cout << "tygodnik: " << ile_stron << " stron, cena " << cena <<endl;
    }
};
//////////////////////////////////////////////////////////////////////////////////////////////
union Umagazyn   												// 3
{
    char 		litera;
    Ttygodnik   	gazeta;

    void fun()  {
        cout << "rozmiar tej unii to:  " << sizeof(*this) << " bajtow"<< endl;
    }
    //-------------------------
    void wstaw_tygodnik(int stron, double zl) {  							 // 4
        gazeta.ile_stron = stron;
        gazeta.cena = zl;
    }
};
//*******************************************************
int main()
{
    Umagazyn   	przechowalnia; 									// 5
    przechowalnia.fun();

    przechowalnia.litera = 'S';
    cout << "Obecnie przechowywana litera to '" << przechowalnia.litera<<"'"<< endl;

    przechowalnia.gazeta.ile_stron = 16;  								// 6
    przechowalnia.gazeta.cena = 12.5;
    przechowalnia.gazeta.opis();

    przechowalnia.litera = 'M';
    cout << "Obecnie przechowywana litera to '" << przechowalnia.litera<<"'"<< endl;

    przechowalnia.wstaw_tygodnik(5 , 4.6);   							// 7
    przechowalnia.gazeta.opis();

    cout << "Definiujemy drugi taki obiekt Umagazyn" << endl;
    Umagazyn 	drugi =  przechowalnia;   							// 8
    cout << "Od nowosci w kopii jest ";
    drugi.gazeta.opis();

    przechowalnia.wstaw_tygodnik(80 , 25.0);
    cout << "Po zwyklym przypisaniu. ";
    drugi =  przechowalnia; // autom. generowany operator przypisania unii  	// 9
    drugi.gazeta.opis();
}
