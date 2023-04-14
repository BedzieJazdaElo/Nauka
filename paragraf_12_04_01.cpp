// Program z paragrafu 12_04_01


#include <iostream>
using namespace std;

char * producent(void);													// 1
char *w2; 				// nie trzeba inicjalizować						// 2
//****************************************************
int main()
{
    char * w1 = new char;												// 3
    w2 = new char;													// 4

    char *w3 = nullptr;													// 5
    w3 = producent();													// 6
    char * w4 = producent();											// 7
    //----------------------------
    *w1 = 'H'; 														// 8
    *w2 = 'M';
    *w3 = 'I';
    cout	<< "oto 3 znaki:" << *w1 << *w2 << *w3
            << "\noraz smiec w czwartym:" << *w4 << endl;						// 9

    delete w1;	 	// kasowanie obiektów 								// 10
    delete w2;
    delete w3;
    delete w4;
    // *w1 = 'F';		// byłaby tragedia, bo obiekt już nie istnieje!!!  		// 11
}
//****************************************************
char * producent(void) 													// 12
{
    char lokalny = 'M';													// 13

    char *wskaznik;
    cout << "Wlasnie produkuje obiekt \n";
    wskaznik = new char; 												// 14
    // ... 				tu możemy popracować z tym obiektem, a potem...
    return wskaznik;
}
