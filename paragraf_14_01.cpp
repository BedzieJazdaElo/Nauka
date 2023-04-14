// Program z paragrafu 14_01

#include <iostream>
using namespace std;
int pierwsza();
int druga(); 														// 1

//*******************************************************
int main()
{
    int i;
    int (*wskaz_fun)(); 												// 2
    auto * wskaz_funB = &pierwsza;									// 3

    cout << "Na ktora funkcje ma pokazac wskaznik?\npierwsza -\t1 \nczy druga - \t2 \n"
         "   napisz numer: ";
    cin >> i; 														// 4
    switch(i) {
    case 1:
        wskaz_fun = &pierwsza;								// 5
        break;
    case 2:
        wskaz_fun = &druga;
        break;
    default:
        wskaz_fun = nullptr; 									// 6
        break;
    }
    cout << "Wedlug rozkazu! \n";
    if(wskaz_fun)   {						// jeśli adres niezerowy		// 7
        (*wskaz_fun)(); 											// 8
    }
}
//*******************************************************
int pierwsza()
{
    cout << "wykonuje sie funkcja pierwsza! \n";
    return 9;
}

//*******************************************************
int druga()
{
    cout << "wykonuje sie funkcja druga!\n";
    return 106;
}
