// Program z paragrafu 37_12

#include <iostream>
#include <vector>
#include <list>
using namespace std;
//********************************************************************
struct Tregion
{
    int a, b, c, d;
    static int wspolny;
    void fun() {
        a = 60;
        b = 61;
        c = 62;
        d= 63;
        cout << "Wywolana funkcja  Tregion::fun()" << endl;
    }
};
//********************************************************************
template <typename W> struct moj_szablon {
    void f() {
        cout << "Funkcja mojego_szablonu " << endl;
    }
};
//********************************************************************
template <typename W> struct podobny_szablon {
    void f() {
        cout << "Funkcja podobnego_szablonu " << endl;
    }
};
/////////////////////////////////// Szablon z wieloma różnymi parametrami ////////////////////////////////////////////
template <	typename Typ,								// 1f(ormalny)
            int STALA,									// 2f
            char* ADR_OBJ,								// 3f
            Typ * WSK,									// 4f
            Typ & REF,									// 5f
            Tregion * WSKOBJ,							// 6f
            void (*ADR_FUN)(int, double),   					// 7f
            int * ADRES_DANEJ_STAT,  					// 8f
            int Tregion::*WSK_SKLADNIKA,  				// 9f

            template<typename W> class SZAB,								// 10f
            template<typename W, typename ALOC = std::allocator<W> >
            class POJEMNIK 		// 11f
            >
struct  ladownik     // tak tych parametrów używamy w ciele szablonu klasy
{
    Typ tablica[STALA];									// 1u i // 2u

    SZAB<Typ>    sz; 														// 10u
    POJEMNIK<Typ, std::allocator<Typ> >  wektor; 								// 11u
    POJEMNIK<Typ >  wektor2;												// 11u

    void fun_skl()
    {

        cout << "Przyjeta STALA = " << STALA << endl; 						// 2u
        *ADR_OBJ = 'z';   													// 3u
        cout << "Wartosc we wskazanym obiekcie " << *WSK << endl; 			// 4u
        cout << "Wartosc w obiekcie referowanym  " << REF << endl; 				// 5u
        cout << "Uzycie wskaznika do obiektu: ";
        WSKOBJ->fun();													// 6u
        cout << "Uzycie wskaznika do funkcji glob.: ";
        ADR_FUN(1, 3.14);												// 7u
        cout << "Statyczny skladnik klasy =" << *ADRES_DANEJ_STAT << endl; 			// 8u
        cout << "Uzycie wskaznika skladnika klasy: " << WSKOBJ->*WSK_SKLADNIKA   		// 9u
             << endl;

        sz.f();
        wektor.push_back(*WSK);
    }
    void f_poza_cialem();
};
///////////////////////// Tak definiuje się funkcję składową poza ciałem tego szablonu ////////////////////////
template <	typename Typ, int STALA, char* ADR_OBJ, Typ * WSK,
            Typ & REF,	 Tregion * WSKOBJ,
            void (*ADR_FUN)(int, double), int * ADRES_DANEJ_STAT,
            int Tregion::*WSK_SKLADNIKA,  template<typename W> class SZAB,
            template<typename W, typename ALOC = std::allocator<W> > class POJEMNIK
            >
void f_poza_cialem()
{
    //...
}
//********************************************************************
// Dodatki potrzebne poniżej do tworzenia egzemplarzy obiektów klas szablonowych
char 			znak = 'a';
char 			cyfra = '9';
int 				Tregion::wspolny = 100;
Tregion 			dolina, wzgorze;
constexpr int 		m = 128;
double 			pi = 3.14;
int 				zmienna = 40;
//********************************************************************
void funglobalna(int k, double x)
{
    cout << "Wywolana funkcja globalna(" << k << ", " << x << ")" << endl;
}
//********************************************************************
void trawersowanie(int k, double x)
{
    cout << "Wywolana funkcja globalna  trawersowanie(" << k << ", " << x << ")" << endl;
}
//********************************************************************
int main()
{
    // parametry aktualne klasy szablonowej
    ladownik<double,   			// nazwa typu 							// 1at
             5, 					// wartość całkowita 						// 2at
             &znak,  				// adres obiektu (globalnego) 				// 3at
             &pi,					// jw., ale typ jest parametrem pierwszym 			// 4at
             pi,					// odebrany jako referencja 				// 5at
             &	wzgorze, 			// adres obiektu (tym razem jakiejś klasy)  			// 6at
             funglobalna,			// lub &funglobalna, adres funkcji 			 // 7at
             &Tregion::wspolny,		// adres składnika statycznego klasy  			// 8at
             &Tregion::b,			// wskaźnik do skł. klasy ustaw na skł. b    			// 9at
             moj_szablon,													// 10at
             std::vector													// 11at
             >atlas;

    cout << "------------ z klasy szablonowej, obiektu: atlas" << endl;
    atlas.fun_skl();

    cout << "------------ z (innej) klasy szablonowej, obiektu: azory" << endl;
    ladownik<	int, 												// 1az
                m, 												// 2az
                &cyfra, 											// 3az
                &zmienna, 										// 4az
                zmienna, 										// 5az
                &dolina, 											// 6az
                &trawersowanie, 									// 7az
                &Tregion::wspolny,									// 8az
                &Tregion::c, 										// 9az
                podobny_szablon, 									// 10az
                std::list   											// 11az
                > azory;

    azory.fun_skl();
}
