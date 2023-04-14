// Program z paragrafu 27_02_01

#include <iostream>
using namespace std;
#include <string>
//////////////////////////////////////////////////////////////////////////////////////////////
class Tpersona													// 1
{
    string 	* adr_nazwiska;										// 2
    double 	* tabl_czasow_prob;									// 3
    int		ile_prob;				// ile prób muzycznych odbył		// 4
    enum { max_elem = 10 };										// 5
public:
    Tpersona(string n);									// konstruktor
    Tpersona(const Tpersona &wzor);					// konstruktor kopiujący
    ~Tpersona();										// destruktor
    Tpersona &  operator=(const Tpersona &wzor);			// kopiujący operator przypisania
    void info(const string);
    void dodaj_czas_proby(double wart);
};
//////////////////////////////////////////////////////////////////////////////////////////////
Tpersona::Tpersona(string nazwisko) 								// 6
{
    adr_nazwiska = new string(nazwisko);
    tabl_czasow_prob = new double[max_elem];
    ile_prob = 0;
    cout << " (Pracuje konstruktor zwykly dla: "	<< nazwisko << ")" << endl;
}
//*******************************************************
Tpersona::Tpersona(const Tpersona &wzor)							// 7
{
    ile_prob = wzor.ile_prob;							// proste przepisanie wartości
    adr_nazwiska = new string;							// utworzenie obiektu klasy string
    *adr_nazwiska = *(wzor.adr_nazwiska);				// skopiowanie zawartości ze wzorca

    tabl_czasow_prob = new double[max_elem];			// utworzenie tablicy
    for(int i = 0 ; i < max_elem ; ++i)
    {   // przepisanie zawartości z obiektu wzorcowego
        tabl_czasow_prob[i] = wzor.tabl_czasow_prob[i];
    }
    // -----------------------------------------------------------------------------
    cout << " (Pracuje konstruktor kopiujacy, kopiowanie z obiektu: "
         << *(wzor.adr_nazwiska) << ")" << endl;
}
//*******************************************************
Tpersona::~Tpersona()												// 8
{
    delete [ ]	tabl_czasow_prob;
    delete	adr_nazwiska;
}
//*******************************************************
void Tpersona::info(const string txt) 									// 9
{
    cout << " " << txt << " " << *adr_nazwiska << ", czasy prob: ";
    for(int i = 0 ; i < ile_prob ; ++i)
    {
        cout << tabl_czasow_prob[i] << "h, ";
    }
    cout << endl;
}
//*******************************************************
void Tpersona::dodaj_czas_proby(double wart) 						// 10
{
    if(ile_prob < max_elem)
    {
        tabl_czasow_prob[ile_prob++] = wart;
    }
}
//*******************************************************
// kopiujący operator przypisania (czyli działający na zasadzie kopiowania obiektu)
//*******************************************************
Tpersona & Tpersona::operator=(const Tpersona &wzor)					// 11
{
    // ## Część 1) Sprawdzenie, czy to nie kopiowanie siebie samego ###	// 12
    if(&wzor != this) {
        // ## Część 2) „Destruktorowa” #########################	// 13
        delete [ ]	tabl_czasow_prob;
        delete	adr_nazwiska;

        // ## Część 3) „Konstruktorowa (konst. kopiujący)” #########	 // 14
        ile_prob = wzor.ile_prob;						// proste przepisanie wartości

        adr_nazwiska = new string;						// utworzenie obiektu klasy string
        *adr_nazwiska = *(wzor.adr_nazwiska);			// skopiowanie treści stringu wzorca

        tabl_czasow_prob = new double[max_elem];		// utworzenie tablicy
        for(int i = 0 ; i < max_elem ; ++i)
        {   // kopiowanie zawartości tablicy z obiektu wzorcowego
            tabl_czasow_prob[i] = wzor.tabl_czasow_prob[i];
        }
    }
    cout << " (Pracuje operator=, czyli operator przypisania)\n";
    return *this;		// „druga pieczeń na tym samym ogniu”			// 15
}
//*******************************************************
int main()
{
    cout << "Definicje 'pianista' i 'skrzypek' \n";

    Tpersona pianista("Dino" );  										// 16
    Tpersona skrzypek("Xavier");

    // kolejne dni prób ---------------
    pianista.dodaj_czas_proby(5.5);
    skrzypek.dodaj_czas_proby(6.0);
    pianista.dodaj_czas_proby(4);
    skrzypek.dodaj_czas_proby(5);
    // koniec prób --------------------
    cout << "\nDefinicja 'dyrygent': \n";

    Tpersona dyrygent = pianista; 			// (konstruktor kopiujący!)  	// 17

    cout << "\nOto tresc w obiektach\n";
    pianista.info("\tPianista:"); 	 		 							// 18
    skrzypek.info("\tSkrzypek:");
    dyrygent.info("\tDyrygent to:");

    cout << "\nZabawy z przypisywaniem ---\n";
    dyrygent = skrzypek;  											// 19
    dyrygent.info("\tDyrygent:");
    cout << "Zmiana dyrygenta\n";
    dyrygent = pianista;
    dyrygent.info("\tDyrygent:");

    cout << "'Kaskadowe' przypisanie ----------\n";
    dyrygent = skrzypek = pianista; 									// 20

    pianista.info("\tPianista:");				// sprawdzamy, co to dało
    skrzypek.info("\tSkrzypek:");
    dyrygent.info("\tDyrygent:");
}
