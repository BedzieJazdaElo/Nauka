// Program z paragrafu 32_02


/*-------------------------------------------
				plik: Tinstrument.h
-------------------------------------------*/
#include <iostream>
using namespace std;
////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Tinstrument													// `1
{
    int cena;
public:
    virtual void wydaj_dzwiek()										// `2
    {
        cout << " Nieokreslony brzdek !\n";
    }
    // ...
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Ttrabka : public Tinstrument  									// `2
{
public:
    void wydaj_dzwiek()
    {
        cout << " Tra-ta-ta !\n";
    }
    // ...
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Tbeben : public Tinstrument  									// `2
{
public:
    void wydaj_dzwiek()
    {
        cout << " Bum-bum-bum !\n";
    }
    // ...
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Tfortepian : public Tinstrument 				 					// `2
{
public:
    void wydaj_dzwiek()
    {
        cout << " Plim-plim-plim !\n";
    }
    // ...
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////

// #include "Tinstrument.h"
//********************************************************************
void muzyk(Tinstrument & powierzony_instrument)	   					 // `16
{
    powierzony_instrument.wydaj_dzwiek();
}
//*****************************************************************
class Tczytelnikofon : public Tinstrument
{
public:
    void wydaj_dzwiek()
    {
        cout << " Jazzy-jazzy ! ";
    }
};
//*****************************************************************
int main()
{
    Tczytelnikofon cz;

    muzyk(cz);
}


