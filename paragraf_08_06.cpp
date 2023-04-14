// Program z paragrafu 08_06


#include <iostream>
using namespace std;

//************************************************************
int main()
{
    char 	napis1[ ] = { "Nocny lot"};
    char 	napis2[ ] = { 	'N', 'o', 'c', 'n', 'y', ' ', 'l', 'o', 't' };
    cout << "rozmiar tablicy pierwszej: " << sizeof(napis1) << endl;
    cout << "rozmiar tablicy drugiej: " << sizeof(napis2) << endl;
}
