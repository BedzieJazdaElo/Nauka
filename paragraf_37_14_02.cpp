// Program z paragrafu 37_14_02

#include <iostream>
using namespace std;
//////////////////////////////////////////////////////////////////////////////////////////////////
struct zawierajaca
{
    template  <typename T>
    struct pomocnicza												// 1
    {
        T* wsk;
        void funkcja_pom();
    };
    // poniżej korzystamy z tego szablonu klasy
    pomocnicza<int>   			skl_szint;
    pomocnicza<double>   		skl_szdouble;

    void funkcja_zaw();	// zwykła funkcja składowa
};
//////////////////////////////////////////////////////////////////////////////////////////////////
template < typename T>
void zawierajaca::pomocnicza<T>::funkcja_pom()  						// 2
{
    cout << *wsk << endl;
}
//*******************************************************************
void zawierajaca::funkcja_zaw()
{
    cout << "Wartosc pokazywana skladnikiem skl_szint.wsk to:  " << *skl_szint.wsk
         << ",\n  a skladnikiem skl_szdouble.wsk to  " 	<< *skl_szdouble.wsk << endl;
}
//*******************************************************************
int main()
{
    int a {4};
    double pi { 3.14};

    zawierajaca obj; 												 // 3
    obj.skl_szint.wsk = &a;
    obj.skl_szdouble.wsk = &pi;
    obj.funkcja_zaw();
    cout << "Bezposrednie uruchomienie funkcji_pom dla obu skladnikow\n";
    obj.skl_szint.funkcja_pom();
    obj.skl_szdouble.funkcja_pom();
}
