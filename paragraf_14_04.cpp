// Program z paragrafu 14_04

#include <iostream>
using namespace std;
#include <cstdlib>			// zawiera deklarację funkcji: exit
#include <cmath> 			// zawiera deklarację funkcji: sinus

void kurs();
void wiatraczek();
void wahadlo();
//*******************************************************
void zwloka_czasowa(int ile)
{
    for(int i = 0 ; i < ile *1000 ; ++i);
}
//*******************************************************
int main()
{
    void (*twf[3])() = {	&wahadlo, &wiatraczek,   &kurs }; 				// 1<$M[m_wskf_przykl3]>
    int co;
    while(1)  	{
        cout 	<< "---------------Menu -----------------\n"
                << "\t0 - wahadlo\n\t1 - wiatraczek \n\t2 - kurs\n\t9 - koniec programu\n\n"
                << "Podaj numer zadanej akcji: ";
        cin >> co; 												// 2
        switch(co)   {
        case 0:
        case 1:
        case 2:
            (*twf[co]) (); 		// lub prościej: twf[co] (); 		 // 3
            break;
        case 9:
            exit(1);			// koniec programu
        default:
            break;
        }
    }
}
//*******************************************************
void kurs()														// 4
{
    for(int i = 0 ; i < 100 ; ++i)   {
        cout << "kurs " << (232 + (i % 4))  << "...\r" << flush;
        zwloka_czasowa(50000);
    }
    cout <<"\nPokazywalem kurs...\n";
}
//*******************************************************
void wiatraczek() 													// 5
{
    char symbol[ ] = { '|', '/', '-', '\\' };
    for(int i = 0 ; i < 100 ; ++i)   {
        cout << " 	  " << symbol[i % 4] << "\r" << flush;
        zwloka_czasowa(10000);
    }
    cout <<"\nWiatraczek sie pokrecil...\n";
}
//*******************************************************
void wahadlo() 													// 6
{
    cout << '\n';
    char wzorek[25];
    for(int i = 0 ; i < 500 ; ++i)  	{
        for(int k = 0 ; k < 24 ; k++) wzorek[k] = ' ';		// przygotowanie tablicy spacji
        wzorek[24] = 0; 			// kończący C-string znak null (ma on kod ASCII  = 0)

        int pozycja = 12 * sin(i /20.0) + 12;
        wzorek[pozycja] = '*';		// wstawienie do jednego z elementów – znaczka '*'
        // poniżej: wydruk na ekranie, a potem powrót karetki do początku linijki
        cout << wzorek << '\r' << flush;
        zwloka_czasowa(5000);
    }
    cout <<"\n";
}
