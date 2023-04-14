// Program z paragrafu 06_16_01

 #include <iostream>
using namespace std;

int liczba;														// 1
void fff(void);
//*********************************************
int main()
{
    int n;
    liczba = 10;													// 2
    n = 4;
    cout << "Wartosci: liczba = " << liczba << " n = " << n;
    fff();															// 3
}
//*********************************************
void fff(void)
{
    int x; 														// 4
    x = 5;
    liczba--; 														// 5
    // n = 4;			// błąd!	 									// 6

    cout << " sumka = " << (x + liczba);
}
//*********************************************
