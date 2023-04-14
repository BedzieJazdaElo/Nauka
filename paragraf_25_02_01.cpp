// Program z paragrafu 25_02_01


 #include <iostream>
using namespace std;
//////////////////////////////////////////////////////////////////////////////////////////////
class Tzespolona
{
    double rzeczyw;
    double urojon;
public:
    // To byłby konstruktor konwertujący, gdyby nie słowo explicit...
    explicit Tzespolona(double r = 0, double i = 0) :  rzeczyw(r), urojon(i)		// 1
    {    }
    friend void pokaz(const Tzespolona z); 								// 2
};
//////////////////////////////////////////////////////////////////////////////////////////////
void pokaz(const Tzespolona z)
{
    cout << "Liczba zespolona: [" << z.rzeczyw << ", " << z.urojon << "] \n";
}
//*******************************************************
int main()
{
    Tzespolona a;														// 3
    Tzespolona b(2.4); 												// 4
    Tzespolona bk { 2.5 };												// 5
//	Tzespolona c	= 2.55;			// <-- niejawne wywołanie konstruktora 		  // 6

    Tzespolona d	= Tzespolona(2.6); 									// 7
    Tzespolona *wsk_e  = new Tzespolona(2.7); 							// 8
    Tzespolona f	= (Tzespolona)2.8; 									// 9
    Tzespolona g	= static_cast<Tzespolona>(2.9); 							// 10

    //––––––––––––––
    pokaz(a);
    pokaz(b);
    pokaz(bk);
//	pokaz(c);  	// (to jest konsekwencja wcześniejszej „niemożliwości”)		  // 11
    pokaz(d);
    pokaz(*wsk_e);
    pokaz(f);
    pokaz(g);
//	pokaz(3.0);   				// <-- przy explicit niemożliwe 	 			 	// 12
    delete wsk_e;				// dla zasady zwalniamy pamięć...
}
