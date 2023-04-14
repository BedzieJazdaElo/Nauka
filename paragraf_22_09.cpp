// Program z paragrafu 22_09


#include <iostream>
using namespace std;
void f(int & 	k)
{
    cout << "Odebrana referencja do lwartosci (obiektu) = " << k << endl;   // 1
}
void f(int &&	k)
{
    cout << "Odebrana referencja do rwartosci (CHWILOWEJ) = " 	<< k << endl;   // 2
}
//*******************************************************************
int main()
{
    int obj = 33; 														// 3
    f(obj);  															// 4

    f(50);      		// stała dosłowna 								 // 5
    f(50 + 2);     		// wyrażenie arytmetyczne
    f(obj + 3); 			// chwilowy wynik wyrażenia nie ma adresu

    f(int(50 + 5) );  		// obiekt chwilowy typu int  					// 6

    f(std::move (obj) );  												// 7
}

