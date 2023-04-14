// Program z paragrafu 33_07_02

#include <iostream>
#include <string>
using namespace std;
//////////////////////////////////////////////////////////////////////////////////////////////
class TSamochod
{
public:
    int rok_produkcji;
    virtual void rzecznik (ostream & strum);
};
//////////////////////////////////////////////////////////////////////////////////////////////
class TMercedes : public TSamochod
{
public:
    string model;
    void rzecznik(ostream & strum)    override;
};
//*******************************************************
// realizacja operatora << dla klasy podstawowej
//*******************************************************
ostream &   operator<<(ostream &  strum, TSamochod &x)					// 1
{
    x.rzecznik(strum);													// 2
    return strum;
}
//*******************************************************
// realizacje funkcji wirtualnych
//*******************************************************
void TSamochod::rzecznik(ostream &   strum)
{
    strum << rok_produkcji;
}
//*******************************************************
void TMercedes::rzecznik(ostream &   strum)
{
    TSamochod::rzecznik(strum);
    strum << " " << model;  				// wypis tej dodatkowej  informacji
}
//*******************************************************
int main()
{
    TSamochod a, b;
    a.rok_produkcji = 2015;
    b.rok_produkcji = 2017;

    TMercedes m;
    m.rok_produkcji = 2016;
    m.model = "sportowy";

    cout << a << endl;
    cout << b << endl;
    cout << m << endl;
}
