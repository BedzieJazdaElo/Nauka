// Program z paragrafu 17_24

#include <string>
#include <iostream>
using namespace std;
//-------------------------------------
int main()
{
    string miasto("Sajgon");
    cout << "Podaj nowa nazwe miasta " << miasto << ": "<< endl;
    getline(cin, miasto);
    cout << "Teraz jest: [" << miasto << "]" << endl;
}
