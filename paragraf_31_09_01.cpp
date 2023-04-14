// Program z paragrafu 31_09_01

#include <iostream>
using namespace std;
//////////////////////////////////////////////////////////////////////////////////////////////
class Tsamochod
{
protected:
    int a;
public:
    Tsamochod(int arg) : a(arg)
    {
        cout << "Konstruktor Tsamochodu\n";
    }
};
//////////////////////////////////////////////////////////////////////////////////////////////
class Tlodka
{
protected:
    int b;
public:
    Tlodka(int x) : b(x)
    {
        cout << "Konstruktor Tlodki \n";
    }
};
//////////////////////////////////////////////////////////////////////////////////////////////
class Tamfibia : public Tsamochod, public Tlodka 						// 1
{
public:
    Tamfibia() : Tsamochod(1991), Tlodka(4) 							// 2
    {
        cout << "Konstruktor Tamfibii \n";
    }

    void pisz_skladniki()
    {
        cout << "Oto odziedziczone skladniki\na = " << a << "\t b = " << b << endl;
    }
};
//*******************************************************
int main()
{
    Tamfibia aaa;
    aaa.pisz_skladniki();
}
