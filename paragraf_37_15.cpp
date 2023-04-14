// Program z paragrafu 37_15

#include <iostream>
using namespace std;

template <typename T> class Tpartner;   								// 1

template <typename T>
void f_osobista(T obj);												// 2

template <typename T> class Tszablon; 								// 3

template <typename T>
ostream &  operator<< (ostream&, Tszablon<T> & obj); 					// 4
//////////////////////////////////////////////// zwykła klasa deklaruje przyjaźń z... /////////////////////////////////////////////////
class Tzwykla {
    // 	 		Przyjaźń z klasami (szablonowymi) ------------------------------
    //  A   klasa deklaruje przyjaźń z jedną (1:1) specjalizacją szablonu klas Tpartner
    friend class Tpartner<Tzwykla>;  		// wymagana dekl. zapowiadająca szablonu Tpartner

    //  B  klasa deklaruje przyjaźń z KAŻDĄ (1:n) specjalizacją szablonu Tkolega
    template <typename T> friend class Tkolega;  			// nie trzeba dekl. zapow. szablonu

    //  C  znana nam od dawna deklaracja przyjaźni zwykłej klasy z inną zwykłą klasą
    friend class Tzwykla2;

    // 			Przyjaźń z funkcjami (szablonowymi) ---------------------------------
    //  D  klasa deklaruje przyjaźń z JEDNĄ (1:1) konkretną specjalizacją funkcji szablonowej
    friend  void  f_osobista  (Tszablon<Tzwykla> obj);

    //  D<<  szczególnie częsty przypadek takiej przyjaźni to...
    friend ostream &  operator<< (ostream&, Tszablon<Tzwykla> & obj);

    //  E  klasa deklaruje przyjaźń z KAŻDĄ (1:n) specjalizacją szablonu funkcji
    //															 funkcje_zaufane
    template<typename X>
    friend  void   funkcje_zaufane(Tszablon<Tzwykla> obiekt);

    //  F  klasa deklaruje przyjaźń ze zwykłą funkcją
    friend void   zwykla_funkcja_ktorej_wszyscy_ufaja(); 		// zwykły przypadek znany od dawna
};
//////////////////////////////////////////////////////////////////////////////////////////////////
// 			szablon klas  – deklaruje przyjaźń z...
//////////////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
class Tszablon {
    // ––––––––––––––––––– Przyjaźń z klasami ––––––––––––––––––––––
    //  G  przyjaźń z jedną (1:1) specjalizacją innego szablonu Tpartner.
    friend class Tpartner<T>;

    //  H  przyjaźń z KAŻDĄ (1:n) specjalizacją szablonu Tkolega
    template <typename X>   		// uwaga, konieczna inna nazwa parametru (inna niż T)
    friend class Tkolega;

    //  I  przyjaźń ze ściśle określoną zwykłą klasą: Tzwykła.
    friend class Tzwykla;

    // –––––––––––––––––––– Przyjaźń z funkcjami –––––––––––––––––
    //  J   przyjaźń z jedną (1:1) specjalizacją szablonu funkcji  f_osobista.
    friend   void   f_osobista  < > (Tszablon<T> obj);			// zauważ pusty ostry nawias

    //   J<<   szczególnie częsty przypadek takiej przyjaźni to przyjaźń z operatorem <<
    friend ostream &  operator<< < >(ostream&, Tszablon<T> & obj);

    //  K   przyjaźń z KAŻDĄ (1:n) specjalizacją szablonu funkcji: funkcje_zaufane
    template<typename X>
    friend void funkcje_zaufane(Tszablon<X> obiekt);

    //  L  przyjaźń z zawsze tą samą zwykłą funkcją
    friend   void   zwykla_funkcja_ktorej_wszyscy_ufaja();
};
//////////////////////////////////////////////////////////////////////////////////////////////////
// Szablon klas, z którego specjalizacjami przyjaźnią się na zasadzie 1:1
template <typename T>
struct Tpartner {
    // ...
    // [A] Klasa Tzwykła nadała prawa przyjaciela (jedynie) specjalizacji Tpartner<Tzwykla>

    // [G] Tszablon nadał temu szablonowi prawa przyjaciela, takie, że:
    // 	 każda specjalizacja Tszablon<T> przyjaźni się
    //		wyłącznie ze specjalizacją  Tpartner<T>
    // czyli np. Tszablon<char> przyjaźni się z Tpartner<char>,
    //     	   a Tszablon<int> z Tpartner<int>
};
//////////////////////////////////////////////////////////////////////////////////////////////////
// Szablon klas, z którego specjalizacjami przyjaźnią się na zasadzie 1:n
template <typename T>
struct Tkolega {
    // [B] Klasa Tzwykła nadała prawa przyjaciela każdej specjalizacji tego szablonu Tkolega

    // [H] Tszablon nadał temu szablonowi prawa przyjaciela, takie, że:
    // każda specjalizacja Tszablonu przyjaźni się z dowolną specjalizacją tego
    // szablonu Tkolega
};
//********************************************************************
//			 szablony FUNKCJI, które zostaną uznane za zaprzyjaźnione
//********************************************************************
template <class typ>
void f_osobista()
{
    // [D] Klasa Tzwykła nadała prawa przyjaciela (jedynie) specjalizacji f_osobista<Tzwykla>

    // [J] Tszablon nadał temu szablonowi funkcji prawa przyjaciela, takie, że:
    // każda specjalizacja Tszablon<T> przyjaźni się wyłącznie ze specjalizacją f_osobista<T>
    // np. Tszablon<char> przyjaźni się z f_osobista<char>,
    // a Tszablon<int> z f_osobista<int>
}
//********************************************************************
template <typename T>
ostream &  operator<< (ostream& strumien, Tszablon<T> & obj)
{
    // Dzięki [D<<] i [J<<]  prawa dostępu analogiczne jak w szablonie funkcji powyżej

    // możliwy dostęp do składnika prywatnego klasy szablonowej:  obj.skladnik_prywatny
    strumien << " Wypisanie danych ze specjalizacji Tszablonu, nawet prywatnych" << endl;
    return strumien;
}
//********************************************************************
template <class typ>
void funkcje_zaufane(Tszablon<typ> obj)
{
    // [E] Klasa Tzwykła nadała prawa przyjaciela każdej specjalizacji tego szablonu funkcji

    // [K] Tszablon nadał temu szablonowi prawa przyjaciela, takie, że:
    // każda specjalizacja Tszablonu przyjaźni się z dowolną specjalizacją tego szablonu funkcji
}
//********************************************************************
void zwykla_funkcja_ktorej_wszyscy_ufaja()
{
    // [F] Klasa Tzwykła nadała tej funkcji prawa przyjaciela
    // [L] Wszystkie specjalizacje Tszablonu klas przyjaźnią się z tą funkcją
}
//********************************************************************
int  main()
{
    // ...
}
