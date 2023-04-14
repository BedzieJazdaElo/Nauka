// Program z paragrafu 34_02_05


#include <iostream>
using namespace std;
#include <fstream>
#include <string>
//*******************************************************
int main()
{
    ifstream 	strum; 	  				// definicja strumienia do pracy z plikiem
    string	nazwa_pliku;
    //####################################################################
    // Niepowodzenie w otwieraniu pliku do czytania może ustawić flagę błędu ios::failbit
    // w razie, gdy plik nie istnieje. Strumień tkwi wówczas w stanie błędu.
    // Aby ponowić próbę otwarcia pliku, flagę tę trzeba najpierw skasować.
    //####################################################################
    bool sukces = false;
    while(!sukces)
    {
        cout << "Podaj nazwe pliku: ";
        cin >> nazwa_pliku;
        cout << endl;		  						// kosmetyka ekranu

        strum.open(nazwa_pliku, ios::in);			// próba otwarcia 		// 1
        // czy się udało?
        if(!strum)									// czyli inaczej: if(strum.fail())...
        {
            cout << "Blad otwarcia pliku: " << nazwa_pliku << endl;
            // Skoro próba otwarcia się nie udała, to strumień jest w stanie błędu!
            // musimy usunąć stan błędu strumienia
            strum.clear(strum.rdstate() & ~ios::failbit); 		// kasowanie flagi	// 2
            // strumień już jest w porządku. W kolejnym obiegu pętli...
            cout << "Ponawiamy probe...\n";
        } else {								// Udało się otworzyć plik,
            sukces = true;			 			// więc pętlę można zakończyć
            cout << "Plik poprawnie zostal otworzony do czytania\n"  <<  string(50, '#') << endl;
        }
    }	// koniec pętli while
    //####################################################################
    // Operacje czytania mogą wywołać ustawienie flagi błędu ios::eofbit w przypadku, gdy
    // dojdziemy do końca pliku i mimo to próbujemy czytać nadal. Aby dalej pracować
    // z tym strumieniem, musimy skasować tę flagę błędu
    // (a potem ewentualnie ustawić kursor czytania we właściwym miejscu).
    //####################################################################
    int numer;
    char znak;
    do
    {
        cout << "Podaj numer bajtu, ktory chcesz poznac: ";
        cin >> numer;
        // pozycjonujemy kursor czytania na tym bajcie
        strum.seekg(numer);											// 3
        znak = strum.get(); 											// 4
        if(strum.eof() )
        {
            sukces = false;
            cout << "Blad pozycjonowania, prawdopodobnie plik\n\t"
                 "jest krotszy niz " << numer << " bajtow\n";
            // strumień tkwi w stanie błędu ios::eofbit oraz równocześnie ios::failbit
            // więc trzeba te obie flagi błędu skasować
            strum.clear(strum.rdstate() & ~(ios::eofbit| ios::failbit) );  		// 5
            cout << "(Podaj mniejsza liczbe)\n";		// będzie ponowny obieg pętli
        } else {
            sukces = true;
            cout	<< "Ten bajt to hexadecymalnie: " << showbase << hex << (int) znak
                    << ", a jako znak ASCII: '"<< znak << "'\n"	<< string(50, '#')  <<  endl;
        }
    } while(!sukces);

    //####################################################################
    // Próba formatowanego wczytania liczby w sytuacji, gdy właśnie oczekuje
    // na wczytanie coś, co liczbą nie jest, wprowadzi strumień w stan błędu ios::failbit
    //####################################################################
    cout << "Proba wczytania nastepnych znakow jako cyfr liczby..." <<  endl;
    int liczba;
    // instrukcja wczytania liczby – zacznie czytać zaraz po
    // wczytanym poprzednio bajcie
    strum >> liczba;		  											// 6
    if(strum.fail() )									// Czy się udało?
    {   // nie!
        cout <<  "Blad failbit, bo najblizsze bajty\n\t nie moga byc wczytane jako liczba\n";
        // Aby to coś wówczas wczytać jako string, należy skasować ustawioną flagę błędu
        strum.clear(strum.rdstate() & ~ios::failbit);   						// 7
        // Strumień nadaje się do pracy, a to coś, co go
        // zatkało, nadal czeka na wczytanie
        string slowo;
        strum >> slowo;
        cout << "Jest to slowo: "<< slowo << endl;
    }
    else {							// Jeśli się udało
        cout << "Pomyslnie wczytana liczba: "<< liczba << endl;
    }
    // dalsza praca z plikiem...
}
