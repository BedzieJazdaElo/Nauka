// Program z paragrafu 17_26

#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s1("synteza_");
    string s2("czasteczki");

    string suma = std::move(s1) + std::move(s2);  							// 1

    cout << "Tresc obiektu suma =[" << suma << "]\n";
    cout << "Tresc obiektu s1 =[" << s1 << "]\n";  							// 2
    cout << "Tresc obiektu s2 =[" << s2 << "]\n";
}
