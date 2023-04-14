// Program z paragrafu 08_05

#include <iostream>
using namespace std;

enum class Tetap {
    nic, scenopis, proba_czytana, 						// 1
    proba_kamerowa, nagranie,
    montaz, postsynchron
};
void stan_realizacji(Tetap s[  ], int ile, int dzien_zdjeciowy);
//************************************************************
int main()
{
    const int liczba_scen = 10;
    Tetap scena[liczba_scen] =   {	Tetap::scenopis, Tetap::proba_czytana,
                                    Tetap::proba_kamerowa
                                 };				// 2

    int dzien_realizacji = 1;

    scena[2] = Tetap::nagranie; 											// 3
    scena[5] = Tetap::montaz;
    scena[9] = Tetap::nagranie;
    scena[4] = Tetap::proba_kamerowa;
    stan_realizacji(scena, liczba_scen, dzien_realizacji);						// 4

    // -------------- następnego dnia praca posunęła się dalej ---------------
    dzien_realizacji++;

    scena[1] = Tetap::proba_kamerowa;
    scena[5] = Tetap::postsynchron;
    scena[0] = Tetap::scenopis;
    scena[8] = Tetap::scenopis;
    stan_realizacji(scena, liczba_scen, dzien_realizacji);
}
//************************************************************
void stan_realizacji(Tetap s[ ], int ile, int dzien )  							// 5
{
    cout << dzien << ". dzien realizacji filmu reklamowego\n" << "Stan realizacji: \n";
    for(int i = 0 ; i < ile ; ++i)
    {
        cout << "Scena nr " << i << ", ";
        int zaawansowanie = static_cast<int> (s[i]); 						// 6
        for(int k = 0 ; k < zaawansowanie ; ++k) 							// 7
        {
            cout << "#";
        }
        cout << endl;
    }
}

