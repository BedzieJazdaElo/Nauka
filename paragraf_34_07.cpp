// Program z paragrafu 34_07


#include <iostream>
#include <fstream>
#include <cstdlib> 							// dla exit()
#include <string>
using namespace std;
//////////////////////////////////////////////////////////////////////////////////////////////
class Tduza_tablica												// 1
{
    string 	nazwa_pliku;       					// nazwa pliku dyskowego
    fstream 	plik;
    const int 	rozmiar;
    int *		linijka;		 					// linijka w zapasie pamięci
    long		dlug_linijki;
    int		nr_obecnego; 						// nr wiersza, nad którym pracujemy
public:
    Tduza_tablica(string nazwa, int wym, int wypelniacz = 0);
    ~Tduza_tablica();
    int * operator[ ](int wiersz);
private:
    void error();
};
//*******************************************************
Tduza_tablica::Tduza_tablica(string nazwa,	int wym, 	int wypelniacz)
    :  nazwa_pliku(nazwa), rozmiar(wym) 					// 2
{
    plik.open(nazwa,   ios::trunc | ios::in | ios::out | ios::binary);			// 3
    if(!plik)   {
        cout << "Blad otwarcia pliku " << nazwa_pliku << endl;
        error();
    }
    linijka = new int[rozmiar];										// 4
    dlug_linijki = rozmiar * sizeof(int);
    // ------------------------- wstępne wypełnienie
    for (int i = 0; i < rozmiar; ++i)
        linijka[i] = wypelniacz;

    // -----------------------zapis tego do pliku
    for (int k = 0;  (k < rozmiar) && plik.good(); k++)
        plik.write( (char*)linijka, dlug_linijki );							// 5
    if(!plik)  {
        cout << "Blad podczas wypelniania tablicy" << endl;
        error();
    }
    nr_obecnego = 0;
}
//*******************************************************
Tduza_tablica::~Tduza_tablica()										// 6
{
    // skoro koniec, to musimy odesłać na dysk wiersz, który jest jeszcze w tablicy linijka
    if(! plik.seekp(nr_obecnego * dlug_linijki))    {
        cout << "Blad pozycjonowania wskaznika pisania\n";
        error();
    }
    // zapisanie tamże ---------
    if(!plik.write( (char*)linijka , dlug_linijki) )  {
        cout << "Blad przy odsylaniu\n";
        error();
    }
    plik.close(); 		 								// zamknięcie pliku
    delete [ ] linijka; 									// zwolnienie rezerwacji
}
//*******************************************************
// przeładowanie operatora [ ]
//*******************************************************
int * Tduza_tablica::operator[ ](int nr_wiersza_chcianego)
{   // 7
    //===========================================
    // może dany fragment tablicy jest pod ręką?
    //===========================================
    if(nr_wiersza_chcianego == nr_obecnego)	return linijka; 	// Tak? To nic nie trzeba robić!
    // jeśli nie, to najpierw odsyłamy obecny wiersz
    // obliczenie, gdzie go posłać
    if(! plik.seekp(nr_obecnego * dlug_linijki))  {
        cout << "Blad pozycjonowania wskaznika pisania\n";
        error();
    }
    // zapisanie tam -------------------------
    if(!plik.write( (char*)linijka , dlug_linijki) )  {
        cout << "Blad przy odsylaniu\n";
        error();
    }
    // ===================================
    // sprowadzamy potrzebny wiersz
    // ===================================
    // obliczenie, gdzie on w pliku jest
    if(! plik.seekg(nr_wiersza_chcianego * dlug_linijki))  {
        cout << "Blad pozycjonowania wskaznika czytania"
             << nr_wiersza_chcianego * dlug_linijki  << endl;
        error();
    }

    // przeczytanie tego fragmentu ------------------------
    if(!plik.read( (char*) linijka, dlug_linijki) )  {
        cout << "Blad czytania wiersza " 	<< nr_wiersza_chcianego << endl;
        error();
    }
    nr_obecnego = nr_wiersza_chcianego;		// uaktualnienie notatek
    return linijka;								// zwracamy wskaźnik do tablicy roboczej
}
//*******************************************************
void Tduza_tablica::error()
{
    if(plik.eof()) cout << "Koniec pliku ";
    if(plik.fail())
        cout 	<< " -FAIL strumienia do pliku : " << nazwa_pliku << endl;
    exit(1);
}
//*******************************************************
int main()														// 8
{
    int i, k;
    const int wymiar = 50;

    Tduza_tablica t("macierz.tmp", wymiar);							// 9

    // wpisanie jakichś danych do tablicy t
    for(i = 0; i < wymiar; ++i)
        for(k = 0; k < wymiar; k++)
            t[i][k] = i * 100 + k;										// 10

    cout << "Element t [24][7] ma wartosc = " << t [24][7] << endl;			// 11
    // -------------------------------------------
    cout << "Przykladowo zrobimy transpozycje " <<endl;

    Tduza_tablica	m("macierz1.tmp", wymiar);							// 12
    for(i = 0; i < wymiar; ++i)
        for(k = 0; k < wymiar; k++)
            m[i][k] = t[k][i];											// 13

    cout << "transpozycja skonczona, oto rezultat\n"
         "Przykladowo elementy t[7][31] = " << t[7][31]
         << ", \tt[31][7] = " << t[31][7] << endl;

    cout << "  Natomiast elementy m[7][31] = " << m[7][31]
         << ", \tm[31][7] = " << m[31][7] << endl;
}

