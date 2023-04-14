// Program z paragrafu 34_03

#include <iostream>
using namespace std;
#include <fstream>
#include <string>
//*******************************************************
int main()
{
    string plikA;
    string plikB;
    // ----------------------------------------------------------------------------------
    cout << "Podaj nazwe pliku wejsciowego : ";
    cin >> plikA;
    ifstream  czyt(plikA );   											// 1
    if(!czyt) {
        cout << "Nie moge otworzyc takiego pliku ";
        return 1;
    }
    // ----------------------------------------------------------------------------------
    cout << "Podaj nazwe pliku wyjsciowego : ";
    cin >> plikB;
    ofstream pisz(plikB); 											// 2
    if(!pisz)  {
        cout << "Nie moge otworzyc takiego pliku ";
        return 1;
    }
    // -------------------- akcja przepisywania ------------------------------------
    char c;
    while(czyt.get(c))  												// 3
    {
        if(!pisz.put(c) )   											// 4
        {
            cout << "Blad pisania! \n";
            break;
        }
    }
    // ------------ koniec, sprawdzam powód zakończenia  --------------------
    if(!czyt.eof() )   {												// 5
        cout << "Blad czytania\n";
    }
}
