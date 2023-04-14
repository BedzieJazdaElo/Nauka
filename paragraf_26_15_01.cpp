// Program z paragrafu 26_15_01


#include <iostream>
#include <vector>
using namespace std;
//*******************************************************
constexpr size_t operator"" _KB(unsigned long long kilobajtow) 				// 1
{
    return  kilobajtow * 1024;   		// przeliczenie na bajty
}
//*******************************************************
std::string  operator"" _sektor(char znak)        							      // 6
{
    return  (std::string("Wagon zatrzyma sie w sektorze ") += znak) ;
}
//*******************************************************
constexpr long double operator"" _pi(unsigned long long x)    					// 8
{
    return x * 3.14159265358979 ;
}
//*******************************************************
constexpr long double operator"" _pi(long double x)   						// 12
{
    return x * 3.14159265358979 ;
}
//*******************************************************
std::string operator"" _s(const char * tekst, size_t dlugosc)  					// 13
{
    return std::string {tekst, dlugosc};
}
//*******************************************************
int operator "" _komenda(const char* kom, size_t ile_znakow) 				// 16
{
    return system(kom);
}
//////////////////////////////////////////////////////////////////////////////////////////////
class Todleglosc    							// klasa literalna  			// 18
{
    long double  odl_w_km;
public:
    explicit   constexpr Todleglosc(long double ile = 0) : odl_w_km {ile}  { }  	// 19
    constexpr long double dystans() {
        return odl_w_km;	   // 20
    }
};
//////////////////////////////////////////////////////////////////////////////////////////////
constexpr Todleglosc   operator"" _km(unsigned long  long int ile)			// 24
{   // dla wartości całkowitych
    return Todleglosc(ile);
}
//*******************************************************
constexpr Todleglosc   operator"" _km(long double ile) 					// 25
{   // dla wartości ułamkowych
    return Todleglosc(ile);
}
//*******************************************************
constexpr Todleglosc     operator"" _Nm(long  double mil) 				// 28
{   // Nautical mile (mil morskich)
    return Todleglosc(mil * 1.852);    // bo 1 mila morska to 1.852 kilometra
}
//*******************************************************
constexpr Todleglosc operator+(Todleglosc a, Todleglosc b)				// 32
{
    return    Todleglosc (a.dystans() + b.dystans() ) ;
}
//*******************************************************
constexpr Todleglosc operator-(const Todleglosc obiekt)  				// 36
{
    return Todleglosc { -obiekt.dystans() };
}
//*******************************************************
int main()
{
    cout << "500 Kilobajtów to dokładnie " << 500_KB << " bajtow \n";  		// 2
    cout << "0xff Kilobajtów to = " <<   0xff_KB << " " << endl ; // to samo co: 255_KB
    // cout <<   3.5_KB;   // błąd   									// 3
    vector<char> bufor(20_KB);   			   						// 4
    cout << "Pojemnosc bufora = " << bufor.capacity() << endl;
    char bufor_tablicowy[5_KB]; 										// 5

    cout << 'A'_sektor << endl;     									// 7
    // stałe dosłowne będące krotnościami liczby <$[symbol>p<$]symbol>
    constexpr double r = 1;            	        								// 9
    constexpr double obwod_kola 	= 2_pi * r ;  						// 10
    constexpr double pole_kola 		= 1_pi * r * r ;
    constexpr double objetosc_kuli 	= 1.333333_pi  * r * r * r;  			// 11

    cout << "Obwod kola o promieniu " << r << " to " << obwod_kola << ", a pole = "
         << pole_kola << ", objetosc kuli = " << objetosc_kuli << endl;

    // Stała dosłowna na bazie C-stringu
    string skladany = "Trajektoria lotu "_s +
                      " powrotnego, kapsula: " + R"(s"z"e"s"c"i"a"n)";		// 14
    cout << skladany << endl;

    int ile_znakow = R"(s"z"e"s"c"i"a"n)"_s.size();   						// 15
    cout << "w surowym stringu jest znakow = " << ile_znakow << endl;

    cout << "Przed wydaniem komendy----------------" << endl;
    "ls -la"_komenda ;   		//  dla Windowsów:   "dir"_komenda 		// 17
    cout << "Po wydaniu komendy--------------------" << endl;

    //---- Stała zmieniająca się w obiekt klasy Todleglosc ---------------------
    Todleglosc  wyprawa; 											// 21
    wyprawa = 6_km;   											// 22
    wyprawa = 3.5_km; 											// 23
    wyprawa = 7.0_Nm;  											// 26
    cout << "dlugosc pierwszej wyprawy = " << wyprawa.dystans() << " km "<< endl;

    constexpr Todleglosc   zakopianka (100_km);   						// 29

    Todleglosc droga_ladowa = 38_km + 24.3_km;    					// 30
    Todleglosc droga_morska = 78.0_Nm + 4.3_Nm;

    auto druga_wyprawa = droga_ladowa + droga_morska + 5.0_Nm + 14.1_km;
    cout << "dlugosc drugiej wyprawy  = " << druga_wyprawa.dystans() << " km "<< endl;

    cout << "10 mil morskich to " << (10.0_Nm).dystans() << " kilometrow"<< endl;   		// 33

    constexpr  double ppp = -5_pi;    									// 34
    cout << ppp << endl;

    constexpr Todleglosc zawrocenie = -15_km  ;						// 35
    cout << "Ujemne zawrocenie = " << zawrocenie.dystans()  << endl;
}
