// Program z paragrafu 12_01_03

#include <iostream>
using namespace std;
//****************************************************
int main()
{
    int tablica[15];						// definicja tablicy
    int *wsk_a, *wsk_b, *wsk_c;

    wsk_a = &tablica[5];
    wsk_b = &tablica[10];
    wsk_c = &tablica[11];

    cout	<< "(wsk_b - wsk_a) = " << (wsk_b - wsk_a)
            << "\n(wsk_c - wsk_b) = " << (wsk_c - wsk_b)
            << "\n(wsk_a - wsk_c) = " << (wsk_a - wsk_c)
            << "\n(wsk_c - wsk_a) = " << (wsk_c - wsk_a);
}
