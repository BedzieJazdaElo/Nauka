// Program z paragrafu 35_01_01

#include <iostream>
using namespace std;
#include <iomanip> 				////  bo używamy manipulatora setw
#include <sstream> 				////  bo  używamy ostringstream  			// 1
void pomiar(string nazwa);	// 2
void odczyt(const char * nazwa); // 3
//*******************************************************
int main()
{
    int 		nr_silnika = 4;
    double 	temperat = 156.7123;
    ostringstream skomunikat ;  											// 4
    //// a teraz właściwe wypisanie
    skomunikat 	<< "Awaria silnika " << setw(2) << nr_silnika
                << ", temperatura oleju " << fixed << setprecision(2)
                << temperat << " stopni C \n";  							// 5
    if(!skomunikat)
        cout << "Jakis blad pracy strumienia"<< endl; 						// 6
    //// dopisujemy dalej
    skomunikat.fill('.');													// 7
    skomunikat.width(25);
    skomunikat << "Musisz cos zrobic !!!\n" ; 								// 8
    cout << 	"Aby sie przekonac czy w strumieniu\n jest "
         "rzeczywiscie zadany tekst\nwypisujemy jego tresc na ekranie\n";
    cout	<< "*******************************************\n"
            << skomunikat.str()   											// 9
            << "*******************************************\n";

    skomunikat.seekp(8, ios_base::beg);    								// 10
    skomunikat << "XYZ";
    cout << "W takim stringu mozna nawet pozycjonowac wskaznik pisania:\n"
         << skomunikat.str();   											// 11
    skomunikat.str("Nowa wstepna tresc niszczaca stara");   					// 12
    //// Uwaga, jeśli używasz kompilatora VC++ 6.0, to powyższe wywołanie funkcji
    // może w spowodować błąd w trakcie wykonywania destruktora tego obiektu
    cout << skomunikat.str() << endl;
    double pi = 3.1415;
    skomunikat << pi;
    skomunikat << ",  a  dwa pi = " << 2 * pi ;   								// 13
    cout << skomunikat.str() << endl;

    cout << "\nBudujemy inny string, potrzeba nam nazwe jakiegos pliku" << endl;
    int 	nr_zestawu = 167;
    int 	nr_dnia = 9;
    int 	nr_miesiaca = 5;
    int 	nr_roku = 2019;

    ostringstream   snazwa_pliku;						// 14
    snazwa_pliku	<< "Probka_"
                    << setfill('0') <<  setw(5) << nr_zestawu
                    << "_z_" << setw(2) << nr_dnia
                    << "_" << setw(2) << nr_miesiaca
                    << "_" << setw(4) << nr_roku
                    << ".dane" ;											// 15

    pomiar(snazwa_pliku.str());  											// 16
    odczyt(snazwa_pliku.str().c_str());									// 17
}
//*******************************************************
void pomiar(string nazwa)  												// 18
{
    cout << "Pomiar, a wynik zapisywany w pliku:\n " << nazwa << endl;
}
//*******************************************************
void odczyt(const char * nazwa)  										// 19
{
    cout << "Odczyt pomiaru, zapisanego w pliku:\n " << nazwa << endl;
}
