// Program z paragrafu 21_10_01

#include <iostream>
#include <initializer_list>    											// 1
#include <vector>
using namespace std;
void zwykla_funkcja(initializer_list<double> zestaw);
void zestaw_napisow(initializer_list<string> zestaw, int liczba);
initializer_list<double> zrob_nowa_liste(bool);
//*******************************************************************
int main()
{
    initializer_list<double>    faktory   { 10.5,  2,  5.4,  4  };  				// 2
    cout << "Petla zakresowe for : ";
    for( auto d : faktory)  		  // inaczej:  for( double d : faktory)  		// 3
    {
        cout << d << "  ";
    }
    cout << endl;

    cout << "Petla zwykle for, wskaznikowo : ";
    const double *    wsk_skoczek  {
        faktory.begin()
    };   					// 4
    for(  ;  wsk_skoczek != faktory.end() ; ++wsk_skoczek) 				// 5
    {
        cout <<  *wsk_skoczek << "  ";    								// 6
    }
    cout << endl;
    // ciąg dalszy tekstu programu nastąpi później
// @

    // ciąg dalszy programu
    // Lista inicjalizatorów nie ma operatora [ ]. Ale można zrobić taki trik:
    cout << "Petla zwykle for, ze składnia tablicowa [ ] (na dwa sposoby) \n";
    const double  *  wsk_pocz	 {
        faktory.begin()
    };    						// 7
    for(unsigned int i = 0  ; i < faktory.size() ; ++i)  									// 8
    {
        cout << "[" << i << "]= "	<< wsk_pocz[i]   							// 9
             << "  "<< faktory.begin()[i]									// 10
             << " / ";
    }
    cout << endl;

    //----------------------------------------
    cout << "Liste i wskazniki mozna zdefiniowac latwiej z uzyciem 'auto' " << endl;
    auto liczby  = {6.0,   2.2,   3.14,   76.642};  								// 11
    auto wsk_liczb  = liczby.begin();  										// 12
    for(  ; wsk_liczb != liczby.end()  ; ++wsk_liczb)
    {
        cout << "*wsk_liczb="  << * wsk_liczb  << ", "<< flush;  				// 13
    }
    cout << endl;
    for(auto x : liczby) cout << x << " / ";    									// 14
    cout << endl;
    //------------------------------------------
    cout << "--- Lista inicjalizatorow zdefiniowana \"na kolanie\" -------" << endl;
    for(auto x :   {
                5, 248, 2
            } )											// 15
    {
        cout << "Obieg petli dla wartosci x =  "  << x << endl;
    }
    // cdn.

    // cd.
    zwykla_funkcja(   { 3.7, 1.5, 8, 4}   );   									// 16
    cout << "Wyslanie pustej listy" << endl;
    zwykla_funkcja( { } );   												// 17
    zestaw_napisow( { "ABC", "NAN", "XYZ"}, 512 );   						// 18

    double a = 10, b = 25, c = 6, d= -100;
    auto lista = { a, b, c, d };   											// 19
    zwykla_funkcja(lista);  												// 20
    d = 200;  					// podmieniamy wartość					// 21
    zwykla_funkcja(lista);    												// 22

    auto lista_kopia = lista;    											// 23
    zwykla_funkcja(lista_kopia);

    cout << "Funkcja zwracajaca liste: ";
    for(double dd : zrob_nowa_liste(true)  )   								// 24
    {
        cout << dd << " ; " << flush;
    }
    cout << "\ninny wariant: ";
    auto lis = zrob_nowa_liste(false);   									// 25
    for(auto dd : lis) cout << dd << " ; " ;
}
//*******************************************************************
void zwykla_funkcja(std::initializer_list<double> zestaw) 	// można, ale lepiej vector  	// 26
{
    cout << "zwykla_funkcja: przyslana sekwencja liczb to:" << endl;
    double suma = 0;
    for( auto d : zestaw) 												// 27
    {
        suma += d;  													// 28
        cout << d << " / " << flush;
    }
    cout << "   Ich suma = " << suma << endl;

    vector<double> wekt;
    for( auto d : zestaw)
    {
        wekt.push_back(d);   											// 29
    }
    // ...
}
//*******************************************************************
void zestaw_napisow(initializer_list<string> zestaw, int liczba) 				// 30
{
    cout << "zestaw_napisow: przyslana sekwencja NAPISOW  to:" << endl;
    for( auto d : zestaw)
        cout << d << " / " << flush;
    cout << "\na takze liczba: " << liczba << endl;
}
//*******************************************************************
initializer_list<double>   zrob_nowa_liste(bool pierwsza)   					// 31
{
    if(pierwsza)
        return { 3.2, 11.5, 0.5, 33 };
    else
        return { 100.5, 111.5, 133 };
}
