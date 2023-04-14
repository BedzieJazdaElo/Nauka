// Program z paragrafu 21_03_04

#include <iostream>
using namespace std;
//////////////////////////////////////////////////////////////////////////////////////////////
class Kl
{
public:
    int		a;
    float 	b;
    char 	c;
    // ------------------------------- konstruktor
    Kl(int i, float x, char z)  {
        a = i;
        b = x;
        c = z;
    }
};
//////////////////////////////////////////////////////////////////////////////////////////////
void wypis(Kl);
//*******************************************************************
int main()
{
    Kl	obiektA(1, 3.14, 'x');
    Kl	obiektB(2, 1.41, 's');

    wypis(obiektA);
    wypis(obiektB);
    wypis( Kl(3, 7.77, 'l') );    // 1
}
//*******************************************************************
void wypis(Kl sk)
{
    cout << " a= " << sk.a << "    b= " << sk.b << "    c= " << sk.c << endl;
}
