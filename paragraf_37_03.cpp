// Program z paragrafu 37_03


#include <iostream>
using namespace std;

template <typename T>
T maksimum(T a, T b)
{
    return (a > b) ? a : b;
}
//********************************************************************
int  main()
{
    int 	a = 44, 		b = 88;
    double x = 12.6 , 	y = 67.8;
    unsigned long la = 99987654L , lb = 456;
    cout << "wiekszy int: "	<< maksimum(a, b) << endl;						// 1
    cout << "wiekszy double: " << maksimum(x, y) << endl;					// 2
    cout << "wiekszy int: " << maksimum<int>(x, y) << endl;  					// 3

    cout << "wiekszy long: " << maksimum(la, lb) << endl;
    cout << "wiekszy znak (kod ASCII): "  << maksimum('A', 'Z' ) << endl;

    char (*wskfun)(char, char);  			// definicja wskaźnika do funkcji 		// 4
    wskfun = &maksimum;				// tu kompilator zrobi specjalizację dla char 	// 5
    cout << "wiekszy kod ASCII ma: "  << wskfun('k', 'm') << endl;  				// 6
}
