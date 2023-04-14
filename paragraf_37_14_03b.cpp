// Program z paragrafu 37_14_03b

#include <iostream>
using namespace std;
//////////////////////////////////////////////////////////////////////////////////////////////////
// szablon klas pomocniczych -------------------
template <typename T>
struct ogn {
    T * wskobj;
    ogn * poprzednik;
    ogn * nastepca;
    // ------------ konstruktor
    ogn() : wskobj(nullptr), nastepca(nullptr)
    { }
};
//////////////////////////////////////////////////////////////////////////////////////////////////
template <typename T, int ILE>
class lan
{
    ogn<T> *pierwsze_ogn;
    ogn<T> *ostatnie_ogn;
    ogn<T> *wybrane_ogn;

    ogn<T>  ciag[ILE];
public:
    lan() : pierwsze_ogn(nullptr), ostatnie_ogn(nullptr), wybrane_ogn(nullptr)
    { }
    void dodaj(T x) {  }
    // ...
};
//********************************************************************
int main()
{
    lan<double, 10> lancuszek;
    lancuszek.dodaj(1.23);
}
