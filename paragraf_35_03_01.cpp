// Program z paragrafu 35_03_01

#include <iostream>
#include <iomanip>
using namespace std;
#include <sstream> 					// bo używamy klasy stringstream
//*******************************************************
void co_kopiujemy(stringstream &strum) 									// 1
{
    auto skad = strum.tellg();
    auto dokad = strum.tellp();

    string schemat = string(int(dokad) - 1, ' ') + '^' +  string(skad - dokad -1, '-')  + 'o';
    cout << " " << schemat  << endl;
}
//*******************************************************
int main()
{
    stringstream pp;  													// 2

    int k =32;
    pp << hex << showbase << k << " ";   									// 3
    cout << "1) W strumieniu jest: " << pp.str() << endl;

    int k2 = 0;
    pp >> k2;															// 4
    cout << "2) Rezultat wczytania do k2 = " << k2 << endl; 					// 5

    auto seria_g = pp.tellg(); 											// 6
    for(int i = 0 ; i < 8 ; ++i)  												// 7
    {
        pp << setw(5) << 10.1 * i  << " ";
    }
    cout << "3) W strumieniu jest: \n[" << pp.str() << "]" << endl;

    // szukamy zakresu liczb, które chcemy wyciąć ------------------------
    double ostatnia_dobra = 20.2;										// 8
    double ostatnia_zla = 50.5;											// 9
    pp.seekg(seria_g); 												// 10
    for(double x ; pp >> x; ) 	 {											// 11
        if (x == ostatnia_dobra) {
            cout << "Znalezione " << x << endl;
            break;
        }
    }
    if(pp.eof() )  { 														// 12
        cout << "Blad: Nie ma  liczby " << ostatnia_dobra;
        return 2;
    }

    auto pocz_skrotu = pp.tellg();  		// jesteśmy po ostatniej dobrej liczbie 		// 13
    pp.seekp(pocz_skrotu); 												// 14

    for(double x ; pp >> x; )  {
        if (x == ostatnia_zla) {											// 15
            cout << "Znalezione " << x << endl;
            break;
        }
    }
    if(pp.eof() )  {
        cout << "Blad: Do konca nie ma juz liczby " << ostatnia_zla;
        return 2;
    }
    auto kon_skrotu = pp.tellg();   										// 16

    string schemat = string(pocz_skrotu, '-') +
                     string(kon_skrotu - pocz_skrotu, 'X') +
                     string(pp.str().size() - kon_skrotu,  '-');  				// 17
    cout << "[" << schemat << "]" << endl;  								// 18
    // czytać będziemy z tego miejsca do końca
    // a pisać będziemy tam, gdzie ustawiliśmy wcześniej wskaźnik pisania seekp
    for(char znak ; pp.get(znak) ; )  	// pętla czytająca znak (wg wskaźnika czytania) 	// 19
    {
        pp.put(znak);				// zapis znaku (wg wskaźnika pisania) 		// 20
        cout << "[" << pp.str() << "]" << endl;
        co_kopiujemy(pp);
    }
    // po zakończeniu tej operacji
    if(!pp)  		pp.clear(pp.rdstate() & ~(ios::failbit | ios::eofbit) );

    // ponieważ teraz na samym końcu są zbędne znaki, zasłonimy je
    int ile_skrocilem = kon_skrotu - pocz_skrotu; 							// 21
    string zaslona = string(ile_skrocilem, '_' );   								// 22
    pp << zaslona; 				// zasłaniamy stare znaki

    cout << "Po zakonczeniu kopiowania znakow \n";
    cout << "[" << pp.str() << "]" << endl;
}
