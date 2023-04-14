// Program z paragrafu 13_08

#include <iostream>
using namespace std;
#include <cstdlib> 				// <--deklaracja funkcji bibliotecznej:  atof
//***********************************************************
int main(int argc, char * argv[ ])
{
    cout << "Wydruk parametrow wywolania:\n";

    for(int i = 0 ; i < argc ; ++i) {
        cout << "Parametr nr "<< i << " to C-string: " << argv[i] << endl;
    }

    float x;
    x = atof(argv[2]);		//  funkcja  atof  zamienia C-string na wartość liczbową
    x = x + 4;				// na dowód, że się udało – robimy operację arytmetyczną
    cout << "wartosc liczbowa x = " << x << endl;
}
