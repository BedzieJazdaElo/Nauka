// program z paragrafu 36.9

#include <iostream>
using namespace std;

#include <iomanip>
#include <fstream>
#include <string>

#include <cctype>          // dla tolower();

// Zmiany zamiast tablicy jest wektor adresów bloków
#include <vector>
void wyczysc_ekran(); // deklaracja funkcji przygotowującej ekran
void error(string informacja);

enum typy_blokow { nic = 0, id_mlynek = 1,
                   id_express,
                   id_blok_napiecia,
                   id_scaler,
                   id_jednostka_logiczna,
                   id_matryca_opoznien
                 };
/********************************************************************/
constexpr  int ile_kaset = 5;
constexpr int ile_slotow = 20;
//////////////////////////////////////////////////////////////////////
class Tblok
{
public:
    // funkcje składowe
    virtual void dialog() = 0;               // pure virtual
    virtual void zapisz_nastawy_w_pliku(ofstream &plik_wej)= 0;
    virtual void odczytaj_nastawy_z_pliku(ifstream &plik_wyj)= 0;  // !!
    virtual string kto_jestes();
    virtual ~Tblok();
};
//////////////////////////////////////////////////////////////////////
inline string Tblok::kto_jestes()  //!!
{
    return "bez nazwy";
}
/*-----------------------------------*/
inline Tblok::~Tblok()          // wirtualny destruktor
{
    cout << "destruktor z klasy Tblok ! " << endl;
}

/*********************************************************************/
class Tkaseta
{
    vector<Tblok *> slot;      // tablica wskaźnikow
    int wybrany_slot;                       	// nr wlaśnie wybrango slotu

public:
    // funkcje skladowe
    Tkaseta ();    	   	            // konstruktor
    void narysuj_sie(int nr_kasety);         	      // rysowanie kasety
    void zapisz_bloki(ofstream & plik_wej);                  // zapis blokow kasety
    void czytaj_nastawy_blokow(ifstream & plik_wyj);    	 	     // odczyt bloków
    void edycja();                 	  // bedzie regulacja
    int podaj_wybrany_slot();        	  	 	    // aktywny slot
    void wybierz_slot(int n);   	          // sklepik ?
    void skasuj();                       // wyrzucanie bloku
    void wstaw();         	     	  // wstawianie bloku

    void stworca(int nr);                // pomocnicza funkcja
};
/********************************************************************/
Tkaseta::Tkaseta () 	     // konstruktor
{
    cout << "konstruktor kasety " << endl;
    for(int i = 0; i  < ile_slotow; i++)
    {
        slot.push_back(nullptr);
    }
    wybrany_slot = 0;
}
/********************************************************************/
void Tkaseta::narysuj_sie(int nr_kasety)
{
    int ile_znakow_na_slot = 4;
    wyczysc_ekran();

    cout << "Kaseta nr " << nr_kasety << endl;
    // budujemy i narysujemy kreskę poziomą
    string margines { "   " };
    string krawedz_kasety { margines + "+" };
    krawedz_kasety += string(ile_znakow_na_slot *ile_slotow - 1, '-') + "+";

    // wykrzyknik przy wybranym slocie
    krawedz_kasety[margines.size() + (ile_znakow_na_slot * wybrany_slot) + 2] = '!';
    cout << krawedz_kasety << endl;
    //--------- rysowanie dalszych linii kasety --------------------------------------
    unsigned int wysokosc_bloku = 10;

    for(unsigned int wys = 0; wys < wysokosc_bloku; wys++)
    {
        cout << margines << "| "; // lewy brzeg kasety
        for(int i = 0; i < ile_slotow; i++)
        {
            char znak_opisu = ' ';
            if(slot[i]) // jeśli coś w slocie jest
            {
                string opis = slot[i]->kto_jestes();
                if(wys < opis.size() ) {
                    znak_opisu = opis[wys] ;
                }
            }
            cout << znak_opisu 	<< " | " ; // przegródka między slotami
        }
        cout << endl;

    }
    // napisanie dolnego brzegu kasety
    cout << krawedz_kasety << endl;   // dolna

    // wypisanie numerków slotów pod kasetą
    cout << margines ;
    for(int k=0; k < ile_slotow; k++)
    {
        cout << setw(ile_znakow_na_slot) << internal << k;   // numeracja slotow
    }
    cout << endl;
}
/*-----------------------------------*/
void Tkaseta::czytaj_nastawy_blokow(ifstream &plik_wej)                // tu jest polimorfizm
{
    slot[wybrany_slot] -> odczytaj_nastawy_z_pliku(plik_wej);
}
/*-----------------------------------*/
void Tkaseta::edycja()
{
    if(slot[wybrany_slot])
    {
        slot[wybrany_slot] -> dialog();
    }
}
/*-----------------------------------*/
int Tkaseta::podaj_wybrany_slot() {
    return wybrany_slot;
}
/*-----------------------------------*/
void Tkaseta::wybierz_slot(int n) {
    wybrany_slot = n;
}
/*-----------------------------------*/
void Tkaseta::skasuj()
{
    if(slot[wybrany_slot])
    {
        delete slot[wybrany_slot];
        slot[wybrany_slot] = 0;   // !!
    }
}
//////////////////////////////////////////////////////////////////////
class Twieza
{
    Tkaseta   k[ile_kaset];          // piec obiektow klasy kaseta
    int aktywna_kaseta;       	             // nr aktywnej kasety
public:
    // funkcje skladowe
    Twieza();
    void wybierz_kasete(int nr);
    void wybor_slotu(int nr);
    int ktory_slot();
    int ktora_kaseta();
    void zapisz_wszystko_na_dysku();
    void odczytaj_konfig_z_dysku();
    void regulacja();
    void narysuj();
    void usun();
    void dodaj();
};
/********************************************************************/
Twieza::Twieza()
{
    aktywna_kaseta = 0;      // konstruktor ??
    cout << "konstruktor wiezy" << endl;
    odczytaj_konfig_z_dysku();
}
/*-----------------------------------*/
void Twieza::wybierz_kasete(int nr)
{
    aktywna_kaseta = nr;   // aktywowanie jednej z kaset
}
/*-----------------------------------*/
void Twieza::wybor_slotu(int nr)
{
    k[aktywna_kaseta].wybierz_slot(nr);   // aktywowanie jednego ze slotow
}
/*-----------------------------------*/
int Twieza::ktory_slot()
{
    return (k[aktywna_kaseta].podaj_wybrany_slot());
}
/*-----------------------------------*/
int Twieza::ktora_kaseta() {
    return aktywna_kaseta;
}
/*-----------------------------------*/
void Twieza::regulacja()
{
    k[aktywna_kaseta].edycja();
}
/*-----------------------------------*/
void Twieza::narysuj()
{
    k[aktywna_kaseta].narysuj_sie(aktywna_kaseta);
}
/*-----------------------------------*/
void Twieza::usun()
{
    k[aktywna_kaseta].skasuj();
}
/*-----------------------------------*/
void Twieza::dodaj()
{
    k[aktywna_kaseta].wstaw();
}
/*--------------------------------------------------------------------*/
void Tkaseta::zapisz_bloki(ofstream & plik_wyj)
{
    for(int i = 0; i < ile_slotow; ++i)
    {
        if(slot[i]) {
            plik_wyj << "\tslot\t" << i << endl;
            // nr indentyfikacyjny juz konkretnie w bloku
            slot[i]->zapisz_nastawy_w_pliku(plik_wyj);
        }
    }
}
/********************************************************************/
void Twieza::zapisz_wszystko_na_dysku()
{

    // otwarcie pliku
    ofstream plik_wyj("konfiguracja.sav", ios::out);

    // zapis tresci poszczegolnych kaset
    for(int i = 0; i < ile_kaset; i++)
    {
        plik_wyj << "kaseta  " << i <<endl;
        k[i].zapisz_bloki(plik_wyj);
        if(!plik_wyj)  // !! kolejnosc inna
        {
            error("Blad w trakcie zapisu " + to_string(i) + " kasety" );
        }
    }

    // zamknięcie pliku
    plik_wyj.close();

}
//////////////////////////////////////////////////////////////////////
class Tmenu
{

    Twieza *wieza;
public:
    Tmenu(Twieza *x);
    void narysuj_menu();
    int wybor_opcji();
};
/********************************************************************/
Tmenu::Tmenu(Twieza *x)
{
    wieza =  x;
    narysuj_menu();
}
/********************************************************************/
void Tmenu::narysuj_menu()
{
    cout <<
         "\n\n Obecnie wybrana jest : kaseta    nr "
         << wieza->ktora_kaseta() <<
         " slot nr ";
    cout << wieza->ktory_slot()
         <<
         "\n\n"
         "                	k - wybierz inna kasete\n"
         "         	       s - wybierz inny slot\n"
         " Opcje akcji \n"
         "      r - rozmawiaj\n"
         "      w - wstaw blok do tego slotu\n"
         "      u - usun blok z do tego slotu\n"
         "      z - zapis wszystkiego na dysk\n"
         "      o - odczyt z dysku\n"
         "      x - zakoncz prace programu"<< endl;

}
/*********************************************************************/
int Tmenu::wybor_opcji()
{
    char opcja;
    int i;

    cin >> opcja;
    switch(tolower(opcja))
    {
    case 'k' :
        cout<< "Ktora kaseta ? : ";
        cin >> i;
        if(i >= 0  && i < 5)
        {
            wieza->wybierz_kasete(i);
        }
        else
        {
            error("numer kasety moze byc z zakresu 0 - 4 " );
        }
        break;
    case 's' :
        cout<< "Ktory slot? : ";
        cin >> i;
        if(i >= 0  && i < 20)
        {
            wieza->wybor_slotu(i);
        }
        else
        {
            error("numer slotu moze byc z zakresu 0 - 19" );
        }
        break;
    case 'r' :
        wieza->regulacja();
        break;
    case 'z' :
        wieza->zapisz_wszystko_na_dysku();
        break;
    case 'o' :
        wieza->odczytaj_konfig_z_dysku();
        break;
    case 'u' :
        wieza->usun();
        break;
    case 'w' :
        wieza->dodaj();
        break;
    case 'x' :
        return 0;
    default:
        break;
    } // end switch
    return 1; // wszystko oprocz x
}
//////////////////////////////////////////////////////////////////////
/////////// klasy konkretnych realizacji blokow //////////////////////
//////////////////////////////////////////////////////////////////////
class Tmlynek : public Tblok
{
    int grubosc;

    // funkcje skladowe
    void miel();
public:
    // funkcje skladowe
    Tmlynek() {
        grubosc = 5;
    }
    void dialog();
    void zapisz_nastawy_w_pliku(ofstream &plik_wyj);
    void odczytaj_nastawy_z_pliku(ifstream &plik_wej);
    string kto_jestes();
    ~Tmlynek() {
        cout << "destruktor mlynka" << endl;
    }
};
/**********************************************************************/
void Tmlynek::zapisz_nastawy_w_pliku(ofstream &plik_wyj)
{
    cout << kto_jestes() << " sie zapisuje" << endl;
    plik_wyj << id_mlynek << endl;
}
/*-----------------------------------*/
void Tmlynek::odczytaj_nastawy_z_pliku(ifstream & /*plik_wej*/)
{
    cout << kto_jestes() << " sie odtwarza" << endl;
}
/*-----------------------------------*/
string Tmlynek::kto_jestes()
{
    return "mlynek";
}
/*-----------------------------------*/
void Tmlynek::dialog()
{
    char co;

    cout << kto_jestes() << " rozmawia " << endl;
    while(1) {
        wyczysc_ekran();
        \

        cout << "JESTEM MLYNEK\nmiele z gruboscia: " << grubosc;
        cout << "\nopcje mlynka -\n"
             "     g - zmiana grubosc mielenia\n"
             "     m - zmiel wsypana kawe\n"
             "     x - koniec rozmowy\nCo robic ? : ";
        cin >> co;
        switch(tolower(co)) {
        case 'g' :
            cout <<  "dotychczasowa grubosc mielenia byla: " << grubosc
                 <<  "\nPodaj nowy parametr grubosci [1-10] : ";
            cin >> grubosc;
            break;
        case 'm' :
            cout << " m-m-m-m-m \n Juz zmielone !\n";
            break;
        case 'x' :
            return;
        default:
            break;
        }
    }
}
//////////////////////////////////////////////////////////////////////
class Texpress : public Tblok
{
public:
    // funkcje skladowe
    void dialog()
    {
        cout << kto_jestes()
             << " Otwiera swoje okno dialogowe i rozmawia...\n"
             << "wcisnij Enter " << endl;
        cin.ignore(2) ;
    }
    /*-----------------------------------*/
    void zapisz_nastawy_w_pliku(ofstream & plik_wyj)
    {
        cout << kto_jestes() << " sie zapisuje" << endl;
        plik_wyj << id_express << endl;
    }
    /*-----------------------------------*/
    void odczytaj_nastawy_z_pliku(ifstream & plik_wej)
    {
        cout << kto_jestes() << " sie odtwarza" << endl;
    }
    /*-----------------------------------*/
    string kto_jestes() {
        return "express";
    }

    // wirtualny destruktor
    ~Texpress()
    {
        cout << "destruktor ekspresu " << endl;
    }

};
//////////////////////////////////////////////////////////////////////
class Twys_napiecie : public Tblok
{
    int zrodlo, wartosc;
public:
    // funkcje skladowe
    // konstruktor
    Twys_napiecie() : zrodlo(0), wartosc(0) {};
    void dialog();
    /*-----------------------------------*/
    void zapisz_nastawy_w_pliku(ofstream &plik_wyj)
    {
        cout << kto_jestes() << " sie zapisuje" << endl;
        plik_wyj << id_blok_napiecia << endl;
    }
    /*-----------------------------------*/
    void odczytaj_nastawy_z_pliku(ifstream & /*plik_wej*/)
    {
        cout << kto_jestes() << " sie odtwarza" << endl;
    }
    /*-----------------------------------*/
    string kto_jestes() {
        return "wys napiecia";
    }
    /*-----------------------------------*/

    ~Twys_napiecie() {
        cout << "destruktor w.n." << endl;
    }
};
/**********************************************************************/
void Twys_napiecie::dialog()
{
    char co;

    cout << kto_jestes() << " rozmawia " << endl;
    while(1)
    {
        wyczysc_ekran();
        cout << "      *** Blok Wysokiego Napiecia ***\n"
             " obsluguje 256 zrodel wysokiego napiecia\n\n"
             "\n\n\n"
             " Biezaco wybrane zrodlo nr "
             << zrodlo << "  ma napiecie " << wartosc << "\n\n\n"
             "\nopcje bloku -\n"
             "     n - wybierz inny numer zrodla \n"
             "     u - ustaw wartosc jego napiecia\n"
             "     x - zakoncz rozmowe\nCo robic ? : ";
        cin >> co;
        switch(tolower(co))
        {
        case 'n' :
            cout <<  "Podaj numer zrodla [1-24] : ";
            cin >> zrodlo;
            wartosc = 99; // na siłę!
            break;
        case 'u' :
            cout << " Podaj zadana wartosc napiecia :";
            cin >> wartosc;
            // wykonanie
            break;
        case 'x' :
            return;
        default:
            break;
        }
    }
}

//////////////////////////////////////////////////////////////////////
class Tjednostka_logiczna  : public Tblok
{
public:
    // funkcje skladowe
    void dialog()
    {
        cout << kto_jestes()
             << " otwiera swoje okno dialogowe i rozmawia...\n"
             << "wcisnij 2 razy Enter " << endl;
        cin.ignore(2) ;
    }
    /*-----------------------------------*/
    void zapisz_nastawy_w_pliku(ofstream & plik_wyj)
    {
        cout << kto_jestes() << " sie zapisuje" << endl;
        plik_wyj << id_jednostka_logiczna << endl;
    }
    /*-----------------------------------*/
    void odczytaj_nastawy_z_pliku(ifstream &plik_wej)
    {
        cout << kto_jestes() << " sie odtwarza" << endl;
    }
    /*-----------------------------------*/
    string kto_jestes() {
        return "logic";
    }
    /*-----------------------------------*/
    ~Tjednostka_logiczna()
    {
        cout << "destruktor jednostki_logiczna" << endl;
    }
};
//////////////////////////////////////////////////////////////////////
class Tmatryca_opoznien : public Tblok
{
public:
    // funkcje skladowe
    void dialog() {
        cout << kto_jestes()
             << " otwiera swoje okno dialogowe i rozmawia...\n"
             << "wcisnij 2 razy Enter " << endl;
        cin.ignore(2) ;
    }
    /*-----------------------------------*/
    void zapisz_nastawy_w_pliku(ofstream & plik_wyj)
    {
        cout << kto_jestes() << " sie zapisuje" << endl;
        plik_wyj << id_matryca_opoznien << endl;
    }
    /*-----------------------------------*/
    void odczytaj_nastawy_z_pliku(ifstream & plik_wej)
    {
        cout << kto_jestes() << " sie odtwarza" << endl;
    }
    /*-----------------------------------*/
    string kto_jestes() {
        return "opoznien matr.";
    }

    // destruktor ---------------------------
    ~Tmatryca_opoznien()
    {
        cout << "destruktor martrycy_opoznien" << endl;
    }
};

//////////////////////////////////////////////////////////////////////
class Tskaler : public Tblok
{
public:
    // funkcje skladowe
    void dialog()
    {
        cout << kto_jestes()
             << " Otwiera swoje okno dialogowe i rozmawia...\n"
             << "Wcisnij 2 razy Enter " << endl;
        cin.ignore(2) ;
    }
    /*-----------------------------------*/
    void zapisz_nastawy_w_pliku(ofstream & plik_wyj)
    {
        cout << kto_jestes() << " sie zapisuje" << endl;
        plik_wyj << id_scaler << endl;
    }
    /*-----------------------------------*/
    void odczytaj_nastawy_z_pliku(ifstream &plik_wej)
    {
        cout << kto_jestes() << " sie odtwarza" << endl;
    }
    /*-----------------------------------*/
    string kto_jestes()  {
        return "skaler";
    }
    // -----------------------destruktor --------
    ~Tskaler() {
        cout << "destruktor skalera" << endl;
    }
};
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
void Tkaseta::wstaw()
{


    if(slot[wybrany_slot])
    {
        error("Slot " + to_string(wybrany_slot) + " jest obecnie zajety" );
        return;
    }
    cout << "Masz do wyboru takie bloki:\n"
         "  1  -  mlynek do kawy\n"
         "  2  -  ekspres do kawy\n"
         "  3  -  blok wysokiego napiecia\n"
         "  4  -  skaler\n"
         "  5  -  jednostka logiczna\n"
         "  6  -  matryca opoznien\n"
         "  0  -  ZADEN Z POWYZSZYCH \n"
         " ------ Podaj numer wstawianego bloku : ";

    char c;
    cin >> c;
    if(!isdigit(c))return;
    cin.putback(c);

    int nr;
    cin >> nr;
    stworca( (typy_blokow) nr);
}
/***********************************************************/
void Tkaseta::stworca(int nr)
{
    switch(nr)
    {
    default :
        cout << "nieznany blok";
        break;
    case id_mlynek :
        slot[wybrany_slot] = new Tmlynek;
        break;
    case id_express :
        slot[wybrany_slot] = new Texpress;
        break;
    case id_blok_napiecia :
        slot[wybrany_slot] = new Twys_napiecie;
        break;
    case id_scaler :
        slot[wybrany_slot] = new Tskaler;
        break;
    case id_jednostka_logiczna :
        slot[wybrany_slot] = new Tjednostka_logiczna;
        break;
    case id_matryca_opoznien :
        slot[wybrany_slot] = new Tmatryca_opoznien;
        break;
    } // switch
}
/********************************************************************/
void Twieza::odczytaj_konfig_z_dysku()
{
    int nr_slotu;           // lokalne nr kasety i slotu
    int typ;
    string wyraz;
    // otwarcie pliku
    ifstream plik_wej("konfiguracja.sav", ios::in);
    if(!plik_wej)
    {
        error("Blad otwarcia pliku do czytania");
		return;
    }
    // sukcesywne czytanie pliku
    // i tworzenie wg tego wzoru
    // odpowiednich blokow w odpowiednich
    // miejscach
    int nr_kasety;
    while(!plik_wej.fail())
    {
        plik_wej >> wyraz;
        if(!plik_wej)break;

        if(wyraz == "kaseta")  // !!
        {
            plik_wej >> nr_kasety;
        }
        else if(wyraz == "slot")
        {
            plik_wej >> nr_slotu;
            k[nr_kasety].wybierz_slot(nr_slotu);        // uaktywnienie tego slotu
            cout << "czytam tresc - slotu nr " << nr_slotu << endl;
            plik_wej >> typ;                         // ma byc ten typ
            // kreacja bloku, ktory jeszcze nie istnieje
            k[nr_kasety].stworca(typ);

            // wczytanie parametrow wlasciwych
            // danemu typowi bloku
            // tu jest polimorfizm
            k[nr_kasety].czytaj_nastawy_blokow(plik_wej);
        }
    }

    plik_wej.close();

}
///////////////////////////////////////// /////////////////////////////
int main()
{
    Twieza w;
    Tmenu m(&w);

    wyczysc_ekran();
    do
    {
        w.narysuj();
        m.narysuj_menu();
    } while ( m.wybor_opcji());

	cout << "Program konczy prace" << endl;
    return 0;  // poprawne zakończenie programu
}
// **************************************************************
void wyczysc_ekran()
{
    cout << string(26, '\n') << endl;
}
//************************************************************
void error(string informacja)
{
    cout << "\n*** " << informacja << " ***\n";
    cout << "wcisnij 2 razy Enter..." ;
	cin.ignore(2);
}
