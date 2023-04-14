// Program z paragrafu 27_06

 #include <iostream>
using namespace std;
//////////////////////////////////////////////////////////////////////////////////////////////
class Tfiltr															// 1
{
    char dol;															// 2
    char gora;
public:
    char operator() (char litera)											// 3
    {
        if(litera >= dol && litera <= gora)   return litera;
        else  return '.';
    }
    //––––––––––––––––––––––––––––––––
    Tfiltr(char d, char g)  												// 4
    {
        ustaw_zakres(d, g);
    }
    //––––––––––––––––––––––––––––––––
    void ustaw_zakres(char d, char g)									// 5
    {
        dol = d;
        gora = g;
    }
};
//////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
    Tfiltr filtr_bialy ('k', 'r'); 												// 6
    cout << "Dzialanie filtru bialego  : ";
    for(char x = 'a' ; x < 'z' ; ++x)	cout << filtr_bialy(x); 						// 7
    cout << endl;

    Tfiltr filtr_zielony(' ', 'j'); 												 // 8
    cout << "Dzialanie filtru zielonego: ";
    for(char x = 'a' ; x < 'z' ; ++x)	cout << filtr_zielony(x); 					// 9
    cout << endl;


    string tekst {"wladyslaw warnenczyk @ w 1444 ginie pod warna"}; 			// 10
    string rez_z;
    string rez_b;

    for(auto znak : tekst) 												// 11
    {
        rez_z +=														// 12
            filtr_zielony(znak);									// 13

        if(znak == '@')													// 14
        {
            filtr_bialy.ustaw_zakres(' ', 'z'); 								// 15
        }
        rez_b+= filtr_bialy(znak);
    }
    cout << "Rezultat filtrowania tekstu przez filtry\n"
         << " oryginal: " << tekst
         << "\n zielony : " << rez_z
         << "\n bialy   : " << rez_b << endl;
}

