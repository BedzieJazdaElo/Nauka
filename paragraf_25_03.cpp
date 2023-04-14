// Program z paragrafu 25_03

 #include <iostream>
using namespace std;
#include <string>
#include <iomanip>   			// dla setw
class Tnumer; 													// 1
//////////////////////////////////////////////////////////////////////////////////////////////
class Tzespolona
{
    double rzeczyw; 	  											// 2
    double urojon;
public:
    // dwa konstruktory konwertujące
    Tzespolona(double r = 0, double i = 0)  :  rzeczyw(r),urojon(i)
    { }
    Tzespolona(Tnumer ob); 		   									// 3

    operator double() {
        return rzeczyw;    // 4
    }
    operator Tnumer();												// 5
    void pokaz()
    {
        cout << "\tLiczba zespolona: (" << rzeczyw << ", " << urojon << ") \n";
    }
    friend  Tzespolona  dodaj(Tzespolona a, Tzespolona b);
};
//////////////////////////////////////////////////////////////////////////////////////////////
class Tnumer
{
    double n;
    string opis; 				   											// 6
    friend Tzespolona::Tzespolona(Tnumer);
    friend void plakietka(Tnumer);
public:
    Tnumer(double k, string t = "opis domniemany")
        :   n(k), opis(t)					// 7
    { }
    operator double() {
        return n;    // 8
    }
};
//////////////////////////////////////////////////////////////////////////////////////////////
Tzespolona::Tzespolona(Tnumer ob) : rzeczyw(ob.n), urojon(0)
{   /* puste ciało, bo wszystko zrobione za pomocą listy inicjalizacyjnej */
}
//*******************************************************
Tzespolona::operator Tnumer()										// 9
{
    // pomagamy sobie, wywołując konstruktor (ale już nie konwertujący,
    // bo wywoływany z 2 argumentami)
    return Tnumer(rzeczyw, "powstal z zespolonej");
}
//*******************************************************
void pole_kwadratu(double bok);				// deklaracje funkcji globalnych
void plakietka(Tnumer nnn);
Tzespolona dodaj(Tzespolona a, Tzespolona b);
//*******************************************************
int main()
{
    // definicje trzech obiektów
    double 		x = 3.21;
    Tnumer 		nr(44, "a imie jego");
    Tzespolona   	z(6, -2);

    // wywołania funkcji pole_kwadratu(double) --------------------------------	 // 10
    pole_kwadratu(x); 			  			// niepotrzebna żadna konwersja
    // poniższe wywołania nie są dopasowane, ale mimo to możliwe,
    // bo kompilator samoczynnie zastosuje nasze konwersje
    pole_kwadratu(nr); 	   				// operator konwersji Tnumer --> double
    pole_kwadratu(z); 	   				// operator konwersji Tzespolona --> double
    // ------------------------------------------------
    Tzespolona	z2(4, 5); 	 			// definicje dwóch roboczych obiektów
    Tzespolona wynik;

    // wywołania funkcji dodaj(Tzespolona, Tzespolona) ---------------------- 	// 11
    wynik = dodaj(z, z2); 		 			// niepotrzebna żadna konwersja
    wynik.pokaz();
    // poniższe wywołania nie są dopasowane, ale mimo to możliwe,
    // bo kompilator samoczynnie zastosuje nasze konwersje
    wynik = dodaj(z, x);				// konstr. konwertujący double --> Tzespolona
    wynik.pokaz();
    wynik = dodaj(z, nr);				// konstr. konwertujący Tnumer --> Tzespolona
    wynik.pokaz();
    // ---------------------------------------------------------------------------------------
    // wywołania funkcji plakietka(Tnumer); 							// 12
    plakietka(nr);
    // poniższe wywołania nie są dopasowane, ale mimo to możliwe,
    // bo kompilator samoczynnie zastosuje nasze konwersje
    plakietka(x); 		 			// konstr. konwertujący double --> Tnumer
    plakietka(z); 		 			// operator konwersji Tzespolona --> Tnumer 	// 13
}
//*******************************************************
Tzespolona dodaj(Tzespolona a, Tzespolona b)
{
    Tzespolona chwilowy(a.rzeczyw + b.rzeczyw,  a.urojon + b.urojon);
    return chwilowy;
}
//*******************************************************
void plakietka(Tnumer nnn)											// 14
{
    string kreska(30, '*');
    string lewybrzeg {"***  "};
    string prawybrzeg {"  ***"};
    cout << kreska << endl;
    cout << lewybrzeg << setw(20) << nnn.opis << prawybrzeg << endl;
    cout << lewybrzeg  << setw(20) << nnn.n << prawybrzeg << endl;
    cout << kreska << endl;
}
//*******************************************************
void pole_kwadratu(double bok)										// 15
{
    cout << "Pole kwadratu o boku " << bok << " wynosi " << (bok * bok) << endl;
}
//*******************************************************
