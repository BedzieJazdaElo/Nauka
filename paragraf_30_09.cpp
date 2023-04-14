// Program z paragrafu 30_09

#include <iostream>
#include <vector>
#include <cmath>						// dla: sqrt
#include <algorithm> 						// dla funkcji transform
#include <functional>						// dla funkcji std::function
using namespace std;
//////////////////////////////////////////////////////////////////////////////////////////////
// klasa obiektu wyjątku, który ewentualnie zostanie rzucony
class Twyjatek { 														// 1
public:
    string wiadomosc;
    int liczba;
public:
    Twyjatek (string txt, int wart): wiadomosc(txt), liczba(wart) { }
};
//////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
    vector<int> v = { 49, 87, 16, 89, -27, 324 }; 							// 2
    vector<double> pierwiastki;  											// 3
    pierwiastki.resize(v.size()); 				// przygotowanie miejsca na wynik 	// 4

    cout << "Wartosci, ktore kolejno pierwiastkujemy\n";
    try { 																// 5

        transform(
            v.begin(), v.end(), 											// 6
            pierwiastki.begin(),											// 7
            [ ] (int dana) throw(Twyjatek ) 								// 8
        {
            cout << "" << dana << ", " << flush;
            if(dana <0 )
                throw Twyjatek ("Niedozwolona wartosc ujemna", dana);		// 9
            return sqrt(dana);  										// 10
        }
        );

        cout << "\nSukces, wypelniony wektor rezultatow:" << endl;
        for(auto d : pierwiastki)
        {
            cout << d << ",  " << flush; 									// 11
        }
    } // koniec bloku try
    catch (Twyjatek ex) 												// 12
    {
        cout <<"!!!!!\nObliczenia przerwane, bo:\n\t"
             << ex.wiadomosc << " " << ex. liczba << endl;
    }

    cout << "\nDalszy ewentualny ciag programu..." << endl;
}
