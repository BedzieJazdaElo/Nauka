// Program z paragrafu 27_03

#define JEST_KONSTR_PRZENOSZACY 				true					// 1
#define JEST_PRZENOSZACY_OPER_PRZYPISANIA 		true					// 2

#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <ctime> 			  // deklaracja funkcji time()
//////////////////////////////////////////////////////////////////////////////////////////////
class Tpersona															// 3
{
    string *		adr_nazwiska;
    double *		tabl_czasow_prob;
    int			ile_prob;
    enum { max_elem = 10 };
public:
    Tpersona(string n);								// konstruktor
    Tpersona(const Tpersona &wzor);				// konstruktor kopiujący 			// 4
#if JEST_KONSTR_PRZENOSZACY
    Tpersona(Tpersona &&wzor);					// konstruktor przenoszący			 // 5
#endif
    ~Tpersona();									// destruktor
    void info(const string);
    void dodaj_czas_proby(double wart);

    // deklaracja kopiującego operatora przypisania
    Tpersona &  operator=(const Tpersona &wzor);								// 6

    // deklaracja przenoszącego operatora przypisania
#if JEST_PRZENOSZACY_OPER_PRZYPISANIA		// kompilacja warunkowa
    Tpersona &  operator=(Tpersona &&wzor);									// 7
#endif

    void swap(Tpersona & czerwony)											// 8
    {
        Tpersona  plast = std::move(*this); 									// 9
        *this = std::move(czerwony);											// 10
        czerwony = std::move(plast);											// 11
    }
};
//////////////////////////////////////////////////////////////////////////////////////////////
Tpersona::Tpersona(string nazwisko)
{
    adr_nazwiska = new string(nazwisko);
    tabl_czasow_prob = new double[max_elem];
    ile_prob = 0;
}
//*******************************************************
Tpersona::Tpersona(const Tpersona &wzor)
{
    ile_prob = wzor.ile_prob;						// proste przepisanie wartości

    adr_nazwiska = new string;						// utworzenie obiektu klasy string
    *adr_nazwiska = *(wzor.adr_nazwiska);			// skopiowanie zawartości ze wzorca

    tabl_czasow_prob = new double[max_elem];			// utworzenie tablicy

    for(int i = 0 ; i < max_elem ; ++i)
    {   // przepisanie zawartości z obiektu wzorcowego
        tabl_czasow_prob[i] = wzor.tabl_czasow_prob[i];
    }
}
//*******************************************************
#if JEST_KONSTR_PRZENOSZACY						// kompilacja warunkowa
Tpersona::Tpersona( Tpersona &&inny)										// 12
{
    ile_prob = inny.ile_prob;								// proste przepisanie wartości

    adr_nazwiska = inny.adr_nazwiska;					// przeniesienie zawartości ze wzorca
    inny.adr_nazwiska = nullptr;

    tabl_czasow_prob = inny.tabl_czasow_prob;
    inny.tabl_czasow_prob = nullptr;
}
#endif				// JEST_KONSTR_PRZENOSZACY   koniec kompilacji warunkowej
//*******************************************************
Tpersona::~Tpersona()
{
    delete [ ] tabl_czasow_prob;
    delete adr_nazwiska;
}
//*******************************************************
void Tpersona::info(const string txt)
{
    cout << " " << txt << " "	<< *adr_nazwiska << ", czasy prob: ";
    for(int i = 0 ; i < ile_prob ; ++i)
    {
        cout << tabl_czasow_prob[i] << "h, ";
    }
    cout << endl;
}
//*******************************************************
void Tpersona::dodaj_czas_proby(double wart)
{
    if(ile_prob < max_elem)
    {
        tabl_czasow_prob[ile_prob++] = wart;
    }
}
//*******************************************************
// kopiujący operator przypisania (czyli działający na zasadzie kopiowania obiektu)
Tpersona & Tpersona::operator=(const Tpersona &wzor)							// 13
{
    if(&wzor != this)			// ##  Część 1) Sprawdzenie, czy to nie kopiowanie siebie samego
    {   // ## Część 2) „Destruktorowa” #######
        delete [ ] tabl_czasow_prob;
        delete adr_nazwiska;
        // ## Część 3) „Konstruktorowa (konst. kopiujący)” ######
        ile_prob = wzor.ile_prob;						// proste przepisanie wartości

        adr_nazwiska = new string;						//  utworzenie obiektu klasy string
        *adr_nazwiska = *(wzor.adr_nazwiska);			//  skopiowanie zawartości ze wzorca

        tabl_czasow_prob = new double[max_elem];		// utworzenie tablicy
        for(int i = 0 ; i < max_elem ; ++i)
        {   // skopiowanie zawartości z obiektu wzorcowego
            tabl_czasow_prob[i] = wzor.tabl_czasow_prob[i];
        }
    }
    return *this;							// „druga pieczeń na tym samym ogniu”
}
//*******************************************************
// przenoszący operator przypisania
//*******************************************************
#if JEST_PRZENOSZACY_OPER_PRZYPISANIA		// kompilacja warunkowa
Tpersona & Tpersona::operator=(Tpersona && inny)								// 14
{
    if(&inny != this)	 // ## Część 1) Sprawdzenie, czy to nie kopiowanie siebie samego 		// 15
    {
        // ## Część 2) „Destruktorowa” ########################## 			// 16
        delete [ ] tabl_czasow_prob; 			// zwolnienie dotychczas posiadanych zasobów
        delete adr_nazwiska;

        // ## Część 3) Kopiująca składniki (i podkradająca adresy) ## 			// 17
        ile_prob = inny.ile_prob;						// proste przepisanie wartości składnika
        adr_nazwiska = inny.adr_nazwiska;			// przepisanie adresu zasobu
        tabl_czasow_prob = inny.tabl_czasow_prob;	// przepisanie adresu tablicy

        // ## Część 4) Zerowanie adresów zasobów u innego obiektu ##			// 18
        inny.adr_nazwiska = nullptr;					// zerowanie adresu obiektu kl. string
        inny.tabl_czasow_prob = nullptr;				// zerowanie adresu tablicy double
    }
    return *this;		// „druga pieczeń na tym samym ogniu”					// 19
}
#endif											// koniec kompilacji warunkowej
//*******************************************************
int main()
{
    time_t 	czas_startu = time(nullptr); 										// 20

    vector<Tpersona> spis; 												// 21
    for(int i = 0 ; i < 30000  ; ++i)
    {
        string nazwa = "Chrobry_" + to_string(i);
        spis.insert(spis.begin(), Tpersona(nazwa)  );
    }
    int trwalo = time(nullptr) - czas_startu; 									// 22
    cout	<< "*  Wstawianie wizytowek na poczatek wektora trwalo: " << trwalo << " s"    << endl;

    czas_startu = time(nullptr);   // zaczynamy nowy pomiar czasu
    Tpersona bialy("Woda"); 												// 23
    Tpersona czerwony("Sok");

    for(auto x = 1 ; x < 100000000 ; x ++)
    {
        bialy.swap(czerwony); 												// 24
    }

    cout<< "*  Wielokrotne swap zajelo: " << (time(nullptr) - czas_startu) 			// 25
        << " s "  << endl;

    cout << "JEST_KONSTR_PRZENOSZACY?  "        							// 26
         << (JEST_KONSTR_PRZENOSZACY  ? "tak" : "nie")
         << "\nJEST_PRZENOSZACY_OPER_PRZYPISANIA?  "
         << (JEST_PRZENOSZACY_OPER_PRZYPISANIA ? "tak" : "nie")<<endl;
}

