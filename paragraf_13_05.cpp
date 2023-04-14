// Program z paragrafu 13_05
#include <iostream>
using namespace std;
//***********************************************************
int main()
{
    // ....
    double zmienna = 0;
    const double stala = 3.14;

    double *wsk_do_zmiennej = &zmienna; 								 // 1
    const double *wsk_do_stalej = &stala;  								// 2
    const double *wsk2_do_stalej;

    cout << "Na poczatku, stala = " << stala << endl;

    wsk2_do_stalej = wsk_do_zmiennej; 									// 3

    // wsk_do_zmiennej = wsk_do_stalej;  					// błąd			// 4
    wsk_do_zmiennej = const_cast<double *>(wsk_do_stalej); 			// 5

    *wsk_do_zmiennej = -333;
    cout << "Potem -----> stala = " << stala << endl;

    // stały (nieruchomy) wskaźnik do zmiennej
    // usuwamy stałość stałej, a nadajemy stałość (nieruchomość) wskaźnika

    double * const 	st_wsk_do_zmiennej =
        const_cast<double * const> (wsk_do_stalej); 		 // 6

    wsk_do_zmiennej = st_wsk_do_zmiennej;								 // 7
    // ...
    int * wskint;
    wskint =	reinterpret_cast<int*>(const_cast<double*>(wsk_do_stalej)); 		// 8
    //...
}
