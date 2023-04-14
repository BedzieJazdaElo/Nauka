// Program z paragrafu 09_05

#include <iostream>
using namespace std;
void wypisz(char sz[ ][15], int rozm_y, int rozm_x);
//*********************************************************
int main()
{
    constexpr int 	liczba_polek = 3;   	 			 // ile półek ma szafa 	// 1
    constexpr int 	liczba_przegrodek = 15;
    char szafka[liczba_polek][liczba_przegrodek] { };   					// 2

    char znak = '!';
    for(int p = 0 ; p < liczba_polek ; ++p)
        for(int g = 0 ; g < liczba_przegrodek ; ++g)
        {
            szafka[p][g] =  znak++;									// 3
        }

    wypisz(szafka, liczba_polek, liczba_przegrodek);    					// 4
}
//*********************************************************
void wypisz(char sz[ ][15], int rozm_y, int rozm_x)   						// 5
{
    cout << "_______________________________\n";
    for(int y = 0 ; y < rozm_y ; ++y) {
        for(int x = 0 ; x < rozm_x ; ++x)
        {
            cout << "|"<< sz[y][x]; 									  // 6
        }
        cout << "|" << endl;
    }
    cout << "-------------------------------\n";
}

