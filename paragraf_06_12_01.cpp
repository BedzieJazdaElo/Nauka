// Program z paragrafu 06_12_01

// @
#include <iostream>
using namespace std;
void funkcja(int a = 2, int  = 6);										// 1
int kwadrat(int x) {
    return x * x;    // 2
}
int globalny1 = 32; 												// 3
//*********************************************1
int main()
{
    funkcja(); 													// 4
    {   // <-- otwarcie lokalnego zakresu  							// 5
        cout << "--- Jestesmy w zakresie lokalnym\n";
        // wywołujemy jeszcze „po staremu”
        funkcja();                 										// 6
        int lokalny1 = 2;                  									// 7
        // void funkcja(int a = 3, int b);			// <-- błąd 			// 8
        // void funkcja(int a, int b = lokalny1);		//<-- błąd 			// 9

        void funkcja(int a, int  b = 8);									// 10
        // od tej pory „po staremu” wywołać już nie można
        //funkcja();							// <-- błąd! 			// 11
        funkcja(7);	   											// 12

        globalny1 = 4 + lokalny1;
        // argumentem może być skomplikowane wyrażenie...
        void funkcja(int a =kwadrat(globalny1), int);						// 13
        funkcja(); 												// 14
    }  															// 15
    cout << "---Jestesmy poza zakresem lokalnym\n";
    funkcja();   													// 16
}
//*********************************************1
void funkcja(int a, int b)
{
    cout << "Naprawde nastapilo wywolanie:  funkcja(" << a << ", " << b << ");" << endl;
}
