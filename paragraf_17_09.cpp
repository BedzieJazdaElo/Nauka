// Program z paragrafu 17_09

#include <iostream>
#include  <stdexcept> 	// deklaracje wyjątków: invalid_argument, out_of_range 		// 1
#include <string>
#include <iomanip>
using namespace std;
int main()
{
    try {
        size_t  idx = -1;
        int liczba = 	stoi("987.123", &idx);   								// 2
        cout << "liczba = " << liczba << ", indeks = " << idx << endl;

        double x = 	stod("987.123", &idx);   								// 3
        cout << "x = " << x << ", indeks = " << idx << endl;

        long v = stol("101091", &idx, 2);  									// 4
        cout << "dwojkowo  v = " << v << " idx = " << idx << endl;

        v = stol("101091", &idx, 16); 										// 5
        cout << "szesnastkowo v = " << v << " idx = " << idx << endl;

        v = stol("0x101091", &idx, 16);  									// 6
        cout << "szesnastkowo v = " << v << " idx = " << idx << endl;

        // sytuacje błędne
        x = stod("wyraz"); 		// "Blad funkcji stod: Niepoprawny argument" 		// 7
        liczba = stoi("9999999999999999999999"); 						// 8
        // "Blad funkcji stoi: wartosc poza zakresem pracy"
    }
    catch(std::invalid_argument & e)
    {
        cout << "Blad funkcji " << e.what() << ": Niepoprawny argument"<< endl;
    }
    catch(std::out_of_range  & e)
    {
        cout << "Blad funkcji " << e.what() << ": wartosc poza zakresem pracy" << endl;
    }
}
