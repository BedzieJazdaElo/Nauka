// Program z paragrafu 31_10


#include <iostream>
#include <string>
using namespace std;
//////////////////////////////////////////////////////////////////////////////////////////////
struct Tnapis : public std::string
{
    using string::string; 	// <->deklaracja, dzięki której „dziedziczymy” konstruktory   	// 1
    // Funkcja składowa naszego pomysłu---------
    void  dopisz(string schemat, int liczba)   								// 2
    {
        string dopisek;
        size_t    gdzie_procent = schemat.find("%1");  						// 3
        if(gdzie_procent == npos) {
            dopisek = schemat;   										// 4
            dopisek += " Error - brak symboli: %1";   						// 5
        } else {
            dopisek = schemat.substr(0, gdzie_procent);  // pierwsza część tekstu 		// 6
            dopisek += to_string(liczba); 									// 7
            dopisek += schemat.substr(gdzie_procent + 2);   // dalsza część  		// 8
        }
        *this += dopisek; 			// lub 	string::append(dopisek);		// 9
        return;
    }
};
//*******************************************************
int main()
{
    Tnapis ostrzezenie;   	// konstr. domniemany generowany jest automatycznie 	// 10
    for(int i = 3; i > 0 ; --i)
    {
        ostrzezenie.clear(); 											// 11
        ostrzezenie += "UWAGA"; 										// 12
        ostrzezenie.assign("UWAGA");

        ostrzezenie.dopisz(" odpalenie silnikow za %1 min", i );   				// 13
        cout << "[" << ostrzezenie << "]" << endl;
    }
    // te definicje poniżej są niemożliwe bez dziedziczenia konstruktorów z klasy std::string
    Tnapis 	protokol("Analiza gruntu. ");  									// 14
    Tnapis 	szlaczek(5, '#'); 											// 15
    protokol += szlaczek;

    int nr_proc = 14;
    protokol.dopisz (" wedlug procedury [%1Y] ", nr_proc);
    protokol += szlaczek;
    protokol += "\n";
    for(int id : {
                153, 84, 725
            }  ) 											// 16
    {
        protokol.dopisz("  Probka o numerze identyfikacyjnym  %1, zbadana \n", id);
    }
    cout << protokol;

    // zupełnie inny konstruktor klasy std::string o (jednym) argumencie initializer_list<char>
    Tnapis   litania  {'z', 'i', 'u' }; 											// 17
    cout << litania << endl;
}
