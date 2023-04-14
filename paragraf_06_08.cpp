// Program z paragrafu 06_08

#include <iostream>
using namespace std;

void zer(int wart, int &ref);											// 1
//*********************************************1
int main()
{
    int 	a = 44, b = 77;
    cout << "Przed wywolaniem funkcji: zer a = " << a << ", b = " << b << endl;
    zer(a, b);														// 2
    cout << "Po powrocie z funkcji: zer a = " << a << ", b = " << b << endl;	// 3
}
//*********************************************1
void zer(int wart, int &ref)
{
    cout << "\tW funkcji zer przed zerowaniem \n"
         << "\twart = " << wart << ", ref = " << ref << endl; 				// 4
    wart = 0;
    ref = 0;														// 5
    cout << "\tW funkcji zer po zerowaniu \n"
         << "\twart = " << wart << ", ref = " << ref << endl; 				// 6
}																// 7
