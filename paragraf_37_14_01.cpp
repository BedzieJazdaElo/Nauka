// Program z paragrafu 37_14_01

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>				// dla manipulatora setw
using namespace std;
//////////////////////////////////////////////////////////////////////////////////////////////////
template <typename T >
class Tmemo {													// 1
    vector<T>  dane;												// 2
public:
    void wypisz(string txt ) {											// 3
        cout << txt;
        for (auto el  : dane) cout << "{" << el << "}, ";
        cout << endl;
    }
    vector<T> daj_wektor() const     	{
        return dane;    // 4
    }
    Tmemo() = default;  											// 5

    // 1) Szablon funkcji składowej przyjmij (z definicją w ciele szablonu klasy) ---------------------
    template <typename Inny_typ>
    void przyjmij(Inny_typ arg)  										// 6
    {
        T rob = arg;  												// 7
        string kreska(10, '_');
        cout << kreska << "[ " << setw(6) << arg << " ->" << rob
             << " ]" << kreska << endl;   								// 8
        dane.push_back(rob);										// 9
    }

    // 2) Konstruktor odbierający listę inicjalizatorów (dowolnego innego typu)
    template <typename Z>
    Tmemo(initializer_list<Z> il);										// 10

    // 3) Szablon konstruktora konwertującego
    template <typename Inny_typ>
    Tmemo(const Inny_typ &x);         									// 11
};
//////////////////////////////////////////////////////////////////////////////////////////////////
template <typename T> 											// 12
template <typename Z> 											// 13
Tmemo<T>::Tmemo(initializer_list<Z> il)   								// 14
{
    for (auto beg  : il)
        dane.push_back(beg);
}
//********************************************************************
template <typename T>
template <typename Inny_typ>
Tmemo<T>::Tmemo(const Inny_typ &obj)   							// 15
{
    for(auto elem : obj.daj_wektor() ) dane.push_back(elem);
    wypisz("konstruktor konwertujacy: ");
}
//********************************************************************
int main()
{
    Tmemo<int> punkty; 											// 16
    punkty.przyjmij(23); 			// int								// 17
    punkty.przyjmij('c'); 			// znak --> (jego kod ASCII to 99) 	// 18
    punkty.przyjmij(3.14); 			// double 						// 19
    punkty.wypisz("punkty: ");

    Tmemo<char>  znaki;  											// 20
    znaki.przyjmij('a');
    znaki.przyjmij(66); 	  			// liczba int 66 to kod ASCII znaku 'B'// //
    znaki.przyjmij(42.5);   			// liczba double (uwaga: 42 to kod ASCII znaku '*')
    znaki.wypisz("znaki: ");

    // Szablon konstruktorów z klamrową listą inicjalizatorów ================
    cout << "Inicjalizacja roznymi typami klamrowych list" << endl;

    Tmemo<int> ik ({ 10, 20, 30}); 	 								// 21
    ik.wypisz("ik: ");
    Tmemo<int> im( { 1.1, 2.5, 3.5});   								// 22
    im.wypisz("im: ");

    Tmemo<char> ch_n ( { 'k', 'l', 'm' });   								// 23
    Tmemo<char> ch_m( { 72.5, 73.9, 75.1});  							// 24

    // Szablon konstruktora konwertującego z innego typu Tmemo =============
    cout << "Zastosowanie konstruktora (konwertujacego)" << endl;
    Tmemo<double> dubler(znaki); 									// 25
    dubler.przyjmij(9.99);
    dubler.wypisz("dubler: ");

    cout << "Czy moze zadzialac konstruktor dla takiego samego typu  " << endl; // domniemany
    Tmemo<int> punkty_kopia (punkty);  								// 26

    cout << "Zadzialal domniemany k.k., a on nie wypisuje zawartosci" << endl;
    punkty_kopia.wypisz("punkty_kopia: ");  							// 27
}
