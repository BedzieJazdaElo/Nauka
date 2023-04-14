// Program z paragrafu 13_07b

#include <iostream>
using namespace std;
void przedzielacz_tabl(const char tab[ ]);
void przedzielacz_wsk(const char *w);
//***********************************************************
int main()
{
    char ostrzezenie[80] = { "Alarm trzeciego stopnia " };

    cout << "\n wersja tablicowa \n";
    przedzielacz_tabl(ostrzezenie); 									// 1

    cout << "\n wersja wskaznikowa \n";
    przedzielacz_wsk(ostrzezenie); 									// 2
}
//***********************************************************
void przedzielacz_tabl(const char tab[ ])								// 3
{
    int n = 0;
    while(tab[n])  	{
        cout << tab[n++] << "-";
    }
}
//***********************************************************
void przedzielacz_wsk(const char *w) 								// 4
{
    while(*w)   {
        cout << *(w++) << "-";
    }
}
