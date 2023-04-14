// Program z paragrafu 31_02_01

#include <iostream>
using namespace std;
//////////////////////////////////////////////////////////////////////////////////////////////
class Tryba 									// klasa podstawowa
{
private:
    int a;
protected:
    int prots;
public:
    int pubs;
    //––– publiczne funkcje składowe
    void wstaw(int m ) {
        a = m;
    }
    int czytaj() {
        return a;
    }
};
//////////////////////////////////////////////////////////////////////////////////////////////
class Trekin : public Tryba 						 // klasa pochodna
{
    double x;
public:
    void funk();
};
//*******************************************************
void Trekin::funk()
{
    x = 15.6;														// 1
    //  a = 6; 				// <-- tak się nie da, ale...					// 2
    wstaw(6); 													// 3
    cout << "\n wyjety funkcja 'czytaj' skladnik a = " << czytaj(); 			// 4

    prots = 77;						 							// 5
    pubs = 100;
    cout << "\n bezposrednio odczytany skladnik protected = " << prots
         << "\n bezposrednio odczytany skladnik public = " << pubs;
}
//*******************************************************
int main()
{
    Trekin wacek;
    wacek.funk();
}
