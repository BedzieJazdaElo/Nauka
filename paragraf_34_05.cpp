// Program z paragrafu 34_05

 #include <iostream>
using namespace std;
#include <fstream>
#include <string>

void czytaj_40_liczb_int(ifstream & s);
void wypisz_biezace_ustawienie(ifstream &s);
//*******************************************************
int main()
{
    ifstream 	strum; 	   				// definicja strumienia do pracy z plikiem
    string	nazwa_pliku("t.tmp");
    strum.open(nazwa_pliku, ios::in);		   								// 1
    // czy się udało?
    if(!strum)							// czyli inaczej: if(  strum.fail()  )
    {
        cout << "Blad otwarcia pliku: " << nazwa_pliku << endl;
        return -1;
    }
    wypisz_biezace_ustawienie(strum); 									// 2
    cout << "Zmiana powodow rzucenia wyjatku" << endl;
    strum.exceptions(ios::failbit | ios::badbit);  								// 3
    wypisz_biezace_ustawienie(strum);									// 4
    try
    {
        czytaj_40_liczb_int(strum); 										// 5
    }
    catch(ios::failure const & kapsula)
    {
        cout << " ios::failure. Nie udalo sie, informuje: " 	<< kapsula.what() << endl; 		// 6
    }
}
//*******************************************************
void czytaj_40_liczb_int(ifstream & s)
{
    for(int i = 0; i < 40; ++i)
    {
        int wartosc;
        s >> wartosc;  												// 7
        cout << "(" << wartosc << ")";
    }
}
//*******************************************************
void wypisz_biezace_ustawienie(ifstream &s)  								// 8
{
    cout << "Wyjatek bedzie rzucony, gdy ustawione sa flagi:\n";
    ios::io_state    rzuc_gdy = s.exceptions();   								// 9
    cout << "ios::failbit - ";
    if(rzuc_gdy & ios::failbit)
        cout << "TAK\n";
    else
        cout << "nie\n";

    cout << "ios::eofbit - ";
    if(rzuc_gdy & ios::eofbit)
        cout << "TAK\n";
    else
        cout << "nie\n";

    cout << "ios::badbit - ";
    if(rzuc_gdy & ios::badbit)
        cout << "TAK\n";
    else
        cout << "nie\n";
}
