// Program z paragrafu 13_07c


#include <iostream>
using namespace std;
char* strcat(char *cel, const char *zrodlo);
//***********************************************************
int main()
{
    char co[ ] = { "urzadzen sterowych" };
    char komunikat[80] = { "Alarm: " };

    strcat(komunikat, co);
    cout << "po dopisaniu = " << komunikat << endl; 						// 1
    cout << (strcat(komunikat, ", o godz 17:12") );							// 2
}
//***********************************************************
char * strcat(char *cel, const char *zrodlo)									// 3
{
    char *poczatek = cel;
    while(*(cel++) ); 		// przesunięcie wskaźnika na koniec C-stringu 		// 4
    cel--;  				// teraz pokazuje o 1 znak za null, zatem cofamy		// 5

    while( (*(cel++) = *(zrodlo++)) ); 		// kopiowanie,  to już braliśmy przy strcpy 	// 6
    return poczatek;
}
