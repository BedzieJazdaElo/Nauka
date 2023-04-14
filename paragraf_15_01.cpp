// Program z paragrafu 15_01

#include <iostream>
using namespace std;

void wypisz(int liczba);					 							// 1
void wypisz(char znak1, double x, const char *tekst );
void wypisz(int liczba, char znak); 									// 2
void wypisz(char znak, int liczba); 									// 3
//**********************************************************
int main()
{
    wypisz(12345);												// 4
    wypisz(8, 'X');
    wypisz('D', 89.5, " stopni Celsjusza ");
    wypisz('M', 22);
}
//**********************************************************
void wypisz(int liczba)
{
    cout << "Liczba typu int: " << liczba << endl;
}
//**********************************************************
void wypisz(char znak1, double x, const char *tekst )
{
    cout << "Blok " << znak1 << ": " << x << tekst << endl;
}
//**********************************************************
void wypisz(int liczba, char znak)
{
    cout << znak << ") " << liczba << endl;
}
//**********************************************************
void wypisz(char znak, int liczba)
{
    cout << liczba << " razy wystapil stan " << znak << endl;
}
