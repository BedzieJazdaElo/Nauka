// Program z paragrafu 29_03

#include <iostream>
using namespace std;
//////////////////////////////////////////////////////////////////////////////////////////////
struct Tmagazyn   												// 1
{
private:
    union {						// unia anonimowa 				// 2
        char 		litera;
        double 	liczba;
    };
public:
    enum Tco_w_unii { nic, mamy_litere, mamy_liczbe };  				// 3
    Tco_w_unii  	co_przechowujemy; 			// tzw. wyróżnik   		// 4
    //------------------------------------
    Tmagazyn() {													// 5
        co_przechowujemy = nic;
    }
    //------------------------------------
    void magazyn_ma() 											// 6
    {
        switch(co_przechowujemy)
        {
        case nic:
            cout << "Magazyn jest pusty" << endl;
            break;
        case mamy_litere:
            cout << "W magazynie jest litera " << litera << endl;
            break;
        case mamy_liczbe:
            cout << "W magazynie jest liczba " << liczba << endl;
            break;
        }
    }
    //------------------------------------
    void wstaw(char z)  {											// 7
        litera = z;
        co_przechowujemy = mamy_litere;
    }
    //------------------------------------
    void wstaw(double x)   { 										// 8
        liczba = x;
        co_przechowujemy = mamy_liczbe;
    }
};
//*******************************************************
int main()
{
    Tmagazyn   mag;
    mag.magazyn_ma();

    mag.wstaw('S');
    mag.magazyn_ma();
    mag.wstaw(6.28);
    mag.magazyn_ma();
}
