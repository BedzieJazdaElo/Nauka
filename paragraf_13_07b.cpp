// Program z paragrafu 13_07b

#include <iostream>
using namespace std;

char * strcpy(char *cel, const char *zrodlo);

//***********************************************************
int main()
{
    char poziom[ ] = { "Poziom szumu w normie" };
    char komunikat[80];

    strcpy(komunikat, poziom);											// 1
    cout << poziom << endl;
    cout << komunikat << endl;
}
//***********************************************************
char * strcpy(char *cel, const char *zrodlo) 								// 2
{
    char *poczatek = cel;												// 3

    while(*(cel++) = *(zrodlo++)); 										// 4
    return poczatek;													// 5
}
