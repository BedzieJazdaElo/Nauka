// Program z paragrafu 08_06_b

#include <iostream>
using namespace std;
#include <cstring>
//************************************************************
int main()
{
    char tekst[ ] = { "Uwaga, tarcza zostala przepalona!"};
    char komunikat[120];

    strcpy(komunikat, tekst);
    cout << komunikat << endl;

    strncpy(komunikat, "1234567890abcdef", 9 ); 						// 1
    cout << komunikat;

    strcpy(komunikat, "--A ku-ku --!" );
    cout << "\nNa koniec: " << komunikat << endl;
}
