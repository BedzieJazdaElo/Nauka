// Program z paragrafu 16_07

#include <iostream>
#include <string>
#include <vector>
using namespace std;
///////////////////////////////////////////////////////////////////
class Tklasa {
public:
    string 		imie {"nieznane imie"};   							 // 1
    double 		*wskaznik { nullptr }; 								// 2
    int  			tablicaA[5]  { 100, 200, 300 };  						// 3
    vector<char> 	symbole { 'a','b','c'   };   								// 4

    enum stan { pauza = 40, stop = 55, play = 66, przewijanie = 77 };  		// 5
    stan  		odtwarzacz { stop };  								// 6
};
//***********************************************
int main()
{
    Tklasa ob;

    cout << "Wstepna zawartosc kazdego nowego obiektu klasy Tklasa to:\n"
         <<"ob.imie= " << ob.imie
         << ", ob.wskaznik = " << ob.wskaznik    						// 7
         << ", odtwarzacz jest w stanie = " << ob.odtwarzacz    			// 8
         << endl;
    cout << "Tresc tablicyA: ";
    for(int k  : ob.tablicaA) cout << k << ", "; 								// 9

    cout << "Tresc wektora symbole: ";
    for(auto s  : ob.symbole) cout << s << ", "; 							// 10
}
