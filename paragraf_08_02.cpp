// Program z paragrafu 08_02

#include <iostream>
using namespace std;
//******************************************************
int main()
{
    int 	t[4];
    for(int i = 0 ; i < 4 ; ++i) {
        t[i] = 100 * i; 	// wpisanie wartości do elementu
    }
    cout << "Wydruk tresci tablicy: \n";
    for(int i = 0 ; i < 4 ; ++i)   {
        cout << "Element nr: " << i 	<< " ma wartosc " << t[i] << endl;
    }
}
