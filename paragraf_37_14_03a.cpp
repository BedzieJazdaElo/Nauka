// Program z paragrafu 37_14_03a

#include <iostream>
using namespace std;
//////////////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
class lancuch {													// 1
    struct ogniwo {				// klasa pomocnicza   				// 2
        T * wskobj;												// 3
        ogniwo * poprzednik;
        ogniwo * nastepca;
        // ------------ konstruktor
        ogniwo() : wskobj(nullptr), poprzednik(nullptr), nastepca(nullptr)
        {  }
        void funkcja_skladowa(); 									// 4
    };
    // z tego zagnieżdżonego typu od razu korzystamy, definiując trzy wskaźniki
    ogniwo *pierwsze_ogn;  										// 5
    ogniwo *ostatnie_ogn;
public:
    ogniwo *wybrane_ogn;
    lancuch() : pierwsze_ogn(nullptr), ostatnie_ogn(nullptr), wybrane_ogn(nullptr)
    { }
    // ...
};
// @

// @
//////////////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
void lancuch<T>::ogniwo::funkcja_skladowa()							// 6
{
    cout << "Funkcja skladowa " << endl;
}
// @

// @
//********************************************************************
int main()
{
    lancuch<char>  symbole;
    // ...
    symbole.wybrane_ogn->funkcja_skladowa();
    cout << "Koniec programu " << endl;
}
