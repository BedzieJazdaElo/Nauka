// Program z paragrafu 17_21

#include <iostream>
#include <string>
using namespace std;
#include <cctype>      					// zawiera deklarację tolower
// deklaracja funkcji
string   zamien_na_male(string dany);
//*****************************************************************
int main()
{
    string h1("Hector Villa-Lobos");
    string h2("HECTOR VILLA-LOBOS");

    cout << "Dwa stringi \n[" << h1 << "] oraz [" << h2 << "]\n";
    cout << "Przy porownaniu wrazliwym na wielkosc liter..."  << endl;
    if(h1 != h2)      												// 1
        cout << " -> sa rozne " << endl;
    else
        cout << " -> sa identyczne " << endl;

    cout << "Przy porownaniu NIEwrazliwym na wielkosc liter..." << endl;

    if(zamien_na_male(h1) == zamien_na_male(h2)) 					// 2
        cout << " -> sa identyczne" << endl;
    else
        cout << " -> sa rozne" << endl;
}
//*****************************************************************
string zamien_na_male(string dany)  									// 3
{
    for(auto & znak : dany)   {
        znak = tolower(znak);  										// 4
    }
    return dany;
}
