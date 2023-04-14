// Program z paragrafu 12_02_02

 #include <iostream>
using namespace std;
//****************************************************
void funkcja_wska(int *wsk, int rozmiar);
void funkcja_tabl(int tab[ ], int rozmiar);
void funkcja_wsk2(int *wsk, int rozmiar);
//****************************************************
int main()
{
    int tafla[4] = { 5,10,15,20 };
    funkcja_tabl(tafla, 4); 											// 1
    funkcja_wska(tafla, 4); 											// 2
    funkcja_wsk2(tafla, 4); 											// 3
}
//****************************************************
void funkcja_tabl(int tab[ ], int rozmiar) 								// 4
{
    cout << "\nWewnatrz funkcji funkcja_tabl \n";
    for (int i = 0 ; i < rozmiar ; ++i)
        cout << tab[i] << "\t";
}
//****************************************************
void funkcja_wska(int *wsk, int rozmiar) 								// 5
{
    cout << "\nWewnatrz funkcji funkcja_wska \n";
    for (int i = 0 ; i < rozmiar ; ++i)
        cout << *(wsk++) << "\t";
}
//****************************************************
void funkcja_wsk2(int *wsk, int rozmiar)								// 6
{
    cout << "\nWewnatrz funkcji funkcja_wsk2 \n";
    for (int i = 0 ; i < rozmiar ; ++i)
        cout << wsk[i] << "\t";
}
