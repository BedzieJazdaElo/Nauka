// Program z paragrafu 37_16_02

 #include <iostream>
using namespace std;
////////////////////////////////////////////////////// szablon pierwotny /////////////////////////////////////////////////////////////////////////
template <typename T, int N>  										// 1
struct Tzaplon
{
    void fun_skl(T obj)
    {
        cout << "z pierwotnego szablonu, " << obj <<endl;
    }
};
///////////////////////////////////////////////////  specjalizacja częściowa powyższego szablonu //////////////////////////////
template <int N>  													// 2
struct Tzaplon<double, N>  											// 3
{
    void fun_skl(double obj);
};
//*********************** definicja jego funkcji składowej **************************
template <int N>
void Tzaplon<double, N>::fun_skl(double obj)  							// 4
{
    {
        cout << "z szablonu specjalizacji czesciowej, " << obj <<endl;
    }
}
//********************************************************************
int  main()
{
    Tzaplon<int, 6> a;
    a.fun_skl(10);

    Tzaplon<double, 22> c;  										// 5
    c.fun_skl(3.14);  												// 6
}

