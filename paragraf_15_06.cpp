// Program z paragrafu 15_06

#include <iostream>
using namespace std;
//**********************************************************
void dzwiek(int a) 												// 1
{
    cout << a << " nuty \n";
}
//**********************************************************
void dzwiek(double h) 												// 2
{
    cout << "Dzwiek o czestotliwosci: " << h << " hercow \n";
}
//**********************************************************


// Zawiera on, jak widać, definicje dwóch funkcji o nazwie dzwiek.
// A oto inny plik, w którym korzystamy z tych funkcji:


#include <iostream>
using namespace std;
extern void dzwiek(int); 			// deklaracja o zasięgu pliku 		// 3
//**********************************************************
int main()
{
    dzwiek(1); 													// 4
    {   // <-- zakres lokalny   		// 5
        extern void dzwiek(double); 			// deklaracja lokalna  		// 6
        dzwiek(2);												 // 7
        dzwiek(3.14); 												 // 8
    } 															 // 9
    dzwiek(5); 													 // 10
    dzwiek(6.28); 													 // 11
}
