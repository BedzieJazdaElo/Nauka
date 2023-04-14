// Program z paragrafu 34_02_04

 #include <iostream>
#include <fstream>
#include <string>
using namespace std;
//////////////////////////////////////////////////////////////////////////////////////////////
class Tslowo_na_e
{
public:
    string wyraz;
};
//////////////////////////////////////////////////////////////////////////////////////////////
istream & 	operator >>(istream & str, Tslowo_na_e & w) 				// 1
{
    str >> w.wyraz;
    if(w.wyraz[0] != 'e')
    {
        str.setstate(ios::failbit);									// 2a
        // str.clear(str.rdstate() | ios::failbit );							// 2b
    }
    return str;
}
//*******************************************************
int main()
{
    Tslowo_na_e   pierwsze, drugie, trzecie;
    while(1)
    {
        cout << "Podaj trzy slowa na litere 'e': \n";
        cin >> pierwsze >> drugie >> trzecie; 	 						// 3
        if(!cin)   {
            cout << "\nZle! Od poczatku. ";
            cin.clear(cin.rdstate() & ~ios::failbit);					// 4
        }
        else break; 							// jeśli poprawnie
    }
}
