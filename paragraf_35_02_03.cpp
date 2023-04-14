// Program z paragrafu 35_02_03


#include <iostream>
using namespace std;
#include <sstream>  					//  bo używamy istringstream
//*******************************************************
void info()
{
    cout <<
         "INFO: Program nalezy wywolac z 3 argumentami:   [liczba]  [wybor]   [arg3]\n"
         "	  gdy [wybor] ma wartosc '-port',  to [arg3] jest numerem portu\n"
         "	  gdy [wybor] ma wartosc '-file',  to [arg3] jest nazwa pliku\n";
}
//*******************************************************
int main(int argc, char* argv[ ])  											 // 1
{
    cout << "Program " << argv[0] << "\nma argumentow: " << argc -1 << endl;
    if(argc < 4)  {
        cout << "Blad: za malo argumentow wywolania programu\n";
        info();
        return 5;
    }
    cout << "Oto argumenty przyslane do programu\n";
    for(int i = 0 ; i < argc ; ++i)
        cout << "argv[" << i << "]   " << argv[i] << endl;						// 2
    //----
    string 	  wszystkie_parametry;
    for(int i = 1 ; i < argc ; ++i)  {											// 3
        wszystkie_parametry += argv[i];
        wszystkie_parametry += "  "; 		// żeby się nie posklejały
    }

    istringstream sp(wszystkie_parametry);   								// 4
    sp.exceptions(ios::failbit); 											// 5
    string kto { "argument pierwszy" };  // żeby wiadomo było, kto spowodował błąd 	// 6
    double x;
    bool dane_z_pliku = false;
    bool dane_z_portu = false;
    int nr_portu {};
    string nazwa_pliku;
    string co; 					// na parametr wyboru (źródła danych)

    try {
        kto = "argument pierwszy";
        sp >> x; 														// 7
        cout << "Liczba bedaca pierwszym argumentem: " << x << endl;

        kto = "argument drugi";
        sp >> co; 													// 8

        kto = "argument trzeci";
        if(co == "-port" )  {												// 9
            dane_z_portu = true;
            sp >> nr_portu; 											// 10
        }  else if(co == "-file" )  {										// 11
            dane_z_pliku = true;
            sp >> nazwa_pliku;   										// 12
        }  else {
            cout << "Nierozpoznany parametr [wybor]" << argv[2] << endl;
            info();
            return 6;
        }
    } catch(ios::failure const&kapsula)
    {
        cout << "Blad // fail//  w czasie dekodowania przyjmowania argumentow\n"
             "spowodowal " + kto << endl; 							// 13
        info();
        return 7;
    }
    cout << "Przyjete parametry pracy\n\tOgolny czynnik x = " << x << endl;
    if(dane_z_pliku) {
        cout << "\tDane do analizy z pliku: " << nazwa_pliku;
    }
    if(dane_z_portu) {
        cout << "\tDane do analizy z portu nr: " << nr_portu;
    }
}
