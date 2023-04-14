// Program z paragrafu 33_12_02

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
//////////////////////////////////////////////////////////////////////////////////////////////
class TnaszManip														// 1
{
    int arg;															// 2
public:
    TnaszManip(int argument) : arg(argument) 								// 3
    { }
    //-----------------------
    void dzialaj(ostream &os) 											// 4
    {
        os << setw(arg);
    }
};
//////////////////////////////////////////////////////////////////////////////////////////////
ostream & operator <<(ostream & strum, TnaszManip  man)					// 5
{
    man.dzialaj(strum); 												// 6
    return strum;
}
//*******************************************************
int main()
{
    string nazwa("Musee d'Orsay");

    cout << "#" << nazwa << "#\n";
    cout << "#" << TnaszManip(18) << nazwa << "#\n";   					// 7

}

