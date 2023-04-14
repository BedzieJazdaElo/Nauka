// Program z paragrafu 21_08

#include <string>
#include <iostream>
int fun(int m, int n) {
    return m*n;    // definicja zwykłej funkcji 			// 1
}
//////////////////////////////////////////////////////////////////////////////////////////////
class Tklasa
{
    const double 	stala;    												// 2
    int 			n;
    char 		c = '%';   												// 3
    std::string 	nazwa;  												// 4
    int & 		przezwisko;											// 5
public:
    //––––––––––––
    Tklasa(int pp, double dd, char znak, int& ref);  	// sama deklaracja		// 6
    //–––––––––––
    Tklasa(std::string tekst, double liczba, int & ref)  : 	stala {liczba},   n {12},
           c {'#'},   nazwa {tekst},
           przezwisko {ref}    		// 7
    { }    // na przykład puste ciało
    //–––––––––––
    Tklasa(int liczba, int & ref) :	stala {0.1 * fun(liczba, ref)  },  				// 8
           n {22 * fun(ref, 4)},   						// 9
           nazwa {"proba.txt"},
           przezwisko {ref}
    { }    // na przykład puste ciało
    //–––––––––––––
    void opisz() {
        std::cout << "skladniki obiektu: stala=" << stala << ", n=" << n
                  << ", c=[" << c << "], nazwa=[" << nazwa
                  << "], przezwisko=" << przezwisko << std::endl;
    }
};
//////////////////////////////////////////////////////////////////////////////////////////////
// ––––––––––––– definicja konstruktora
Tklasa::Tklasa(int pp, double dd, char znak, int& ref)  :
    stala {dd}, c {znak}, przezwisko(ref)   		 // 10
{
    n = pp;
}
//*******************************************************************
int main()
{
    int skrytka = 100;
    int poletko = 5;

    Tklasa    obiekt1 {10, 3.14, '@', skrytka};   								// 11
    obiekt1.opisz();
    Tklasa    obiekt2 {"plik.txt", 7.21, poletko};  								// 12
    obiekt2.opisz();
    Tklasa    obiekt3 {33, poletko};  										// 13
    obiekt3.opisz();
}
