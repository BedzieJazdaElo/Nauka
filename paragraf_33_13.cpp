// Program z paragrafu 33_13

#include <iostream>
using namespace std;
//*******************************************************
int main()
{
    double x = 1175;
    ios::fmtflags   stare_flagi;
    cout << x << endl;

    cout <<"Zapamietanie flag formatowania\n";
    stare_flagi = cout.flags();										// 1

    cout.setf(ios::showpoint);
    cout << "Po ustawieniu flagi showpoint  " << x << endl;

    cout.setf(ios::scientific, ios::floatfield);
    cout << "Po ustawieniu flagi scientific "<< x << endl;

    cout.setf(ios::uppercase);
    cout << "Po ustawieniu flagi uppercase  "<< x << endl;

    cout.setf(ios::fixed, ios::floatfield);
    cout << "Po ustawieniu flagi fixed    "<< x << endl;

    cout <<"Powrot do starego sposobu formatowania\n";
    cout.flags(stare_flagi);    										// 2

    cout << x << endl;
}
