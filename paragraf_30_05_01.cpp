// Program z paragrafu 30_05_01


#include <iostream>
#include <vector>
#include <algorithm>   					// dla funkcji for_each
using namespace std;
//*******************************************************
int main()
{
    auto wypisz =														// 1
    [ ] (double s) {
        cout << "Lambda 'wypisz': s = " << s << endl;
    };  	// 2

    wypisz(8.7);   			// testujemy sobie wywołanie lambdy 		// 3
    wypisz(2000.5); 													// 4

    vector<int>  v { 4, 2, 13, 24 };
    cout << "Wyslanie tego wyrazenia lambda do algorytmu for_each"<< endl;
    for_each( v.begin(), v.end(), wypisz);  									// 5
}
