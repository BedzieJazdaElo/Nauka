// Program z paragrafu 28_04 i następnych

 #include <iostream>
using namespace std;
#define TEST_NIEPOWODZENIA  rozmiar *= 100000000000;		// 1
void niepowodzenie ();
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Twektorek
{
public :
    double x, y, z;
    ////--- konstruktor -----
    Twektorek (double a=0, double b=0, double c=0) : x (a), y (b), z(c) {
        cout << "\tKonstruktor Twektorek inicjalizuje ten obiekt" << endl;
    }
    virtual ~Twektorek() {
        cout << "\tDestruktor kl.  Twektorek" << endl;
    }
    //---------------------------------------------
    void wypisz() {
        cout << "\tx= "<< x << ", y= "<< y <<", z= "<< z << endl;
    }

    // rezerwacja miejsca (te funkcje mogą rzucić wyjątek std::bad_alloc)
    void * operator new (size_t rozmiar);				// 2
    void * operator new[ ] (size_t rozmiar);				// 3
    // z argumentami użytkownika wg schematu
    // void * operator new (size_t rozmiar, argumenty uzytkownika, ...);
    void * operator new (size_t rozmiar, bool stan);  			// 4
    void * operator new (size_t rozmiar, double r, int n);  		// 5

    // Uwaga: z operatora delete, nie powinno się rzucać wyjątków
    // void   operator delete (void * wsk)  noexcept;				// 6
    void   operator delete (void * wsk, size_t rozmiar) noexcept; 	// 7
    //void   operator delete[ ] (void * wsk) noexcept;   			// 8
    void   operator delete[ ] (void * wsk, size_t rozmiar) noexcept;  	// 9

    // Dotychczasowe funkcje operatorowe new, w razie niepowodzenia mogły rzucić wyjątek.
    // Poniżej są takie wersje, których użyjemy, gdy zamiast rzucania wyjątku
    // wolimy zwrot adresu nullptr

    void * operator new (size_t rozmiar, const nothrow_t&) noexcept ;  // 10
    void * operator new (size_t rozmiar, const nothrow_t&, bool stan)noexcept;  		// 11
    void * operator new (size_t rozmiar, const nothrow_t&, double r,int n) noexcept;		// 12
    void * operator new[ ] (size_t rozmiar, const nothrow_t&) noexcept;			// 13

};
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Twektorek_dziedz : public Twektorek				// 35
{
    int wypelniacz[1000];
public:

    Twektorek_dziedz(double a=0, double b=0, double c=0) : Twektorek(a,b, c) 		// 36
    {
        cout << "\tKonstruktor kl. POCHODNEJ Twektorek_dziedz, x="
             << x  << ", y=" << y << ", z=" << z
             << endl;
    }
    virtual ~Twektorek_dziedz() {   										// 37
        cout << "\tDestruktor kl. POCHODNEJ Twektorek_dziedz" <<endl;
    }
};
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//***************************************************************************************************************
void * Twektorek::operator new ( size_t rozmiar )		// 14
{
    cout << "Rezerw. pamieci na pojedynczy obiekt, new(size_t), gdzie rozmiar = "
         << rozmiar << endl;
    // ... nasze dodatkowe akcje								// 15
    //  TEST_NIEPOWODZENIA;   // <$[symbol><@172><$]symbol>sztuczne wywołanie błędu rezerwacji // 16
    return ( ::new char[rozmiar] );  							 // 17
}
// TABLICE
//*************************************************************************************************************
void * Twektorek::operator new[ ] (size_t rozmiar)		// 24
{
    cout << "Rezerw. new[ ] ( size_t rozmiar ) , rozmiar= " << rozmiar<<endl;
    // ... nasze dodatkowe akcje
    // TEST_NIEPOWODZENIA;
    return ( new char[rozmiar] );
}
//***********************************************************
void * Twektorek::operator new (size_t rozmiar, bool stan) 		 // 30
{
    cout << "Rezerw. pamieci new(size_t, bool),  gdzie rozmiar="
         << rozmiar << ", stan=" << boolalpha << stan << endl;  		// 31
    // ... nasze dodatkowe akcje
    // TEST_NIEPOWODZENIA;
    return ( new char[rozmiar] );
}
//*********************************************************************
void * Twektorek::operator new (size_t rozmiar, double r, int n) 			// 33
{
    cout << "Rezerw. new (size_t rozmiar, double r, int n), " << rozmiar
         << ", " << r << ", "<< n << endl;
    // ... nasze dodatkowe akcje
    // TEST_NIEPOWODZENIA;
    return ( new char[rozmiar] );
}
// Operatory kasujące #############################################
//***********************************************************************************************************
// void Twektorek::operator delete (void * wsk)  noexcept   				// 19
// {
//	 if ( wsk  != nullptr) {  // czyli inaczej:   if(wsk)							// 20
//		 cout << "Odwolanie rezerw. delete ( void * wsk )  noexcept" << endl;
// 		  // nasze własne akcje, a potem...								  // 3
//		 ::delete [] static_cast<char *> (wsk);  								// 22
//	 }
// }
//*******************************************************************************************************
void   Twektorek::operator delete (void * wsk, size_t rozmiar)  noexcept  // 23
{
    if ( wsk ) {
        cout << "Odwolanie rezerw. delete (void *, size_t ), rozmiar= " << rozmiar << endl;
        // nasze własne akcje, a potem...
        delete []   static_cast<char *> (wsk);
    }
}

// KASOWANIE TABLICY
//****************************************************************************************************
// void Twektorek::operator delete[ ] (void * wsk)  noexcept 		// 28
// {
// 	 if (ws) {
// 		cout << "Odwolanie rezerw. delete[ ](void * wsk) " <<endl ;
//	 	// nasze własne akcje na okoliczność kasowania tablicy, a potem...
//		 ::delete[ ] static_cast<char *> ( wsk );
// 	 }
// }

//********************************************************************************************************
void Twektorek::operator delete[ ] (void * wsk, size_t rozmiar)  noexcept		// 29
{
    if(wsk) {
        cout << "Odwolanie rezerw. delete[](void * wsk, size_t rozmiar),"
        "\n\t\t rozmiar = " << rozmiar << endl ;
        // rozmiar to może być informacja dla tutejszych lokalnych działań (np. Garbage collector).
        ::delete[ ] static_cast<char *> ( wsk );
    }
}

//*********************************************************************************************************
// NOTHROW  – w razie niepowodzenia, nie rzuca wyjątku, tylko zwraca nullptr

void * Twektorek::operator new (size_t rozmiar, const nothrow_t& )noexcept // 43
{
    cout << "Rezerw. new (size_t rozmiar, const nothrow_t& ) rozmiar=" << rozmiar << endl;
    // TEST_NIEPOWODZENIA;
    void *wsk = new ( nothrow ) char[rozmiar] ;   // 44
    return wsk; // 45
}
//************************************************************************************************************
void * Twektorek::operator new (size_t rozmiar, const nothrow_t& ,bool stan) noexcept // 46
{
    cout << "Rezerw. new (size_t rozmiar, const nothrow_t& , bool stan)noexcept, "
    "\n\t\t gdzie rozmiar= " << rozmiar << ", stan = " << stan << endl;
    // TEST_NIEPOWODZENIA;
    void *wsk = new ( nothrow ) char[rozmiar] ;
    return wsk;
}
//************************************************************************************************************
void * Twektorek::operator new (size_t rozmiar, const nothrow_t&,double r, int n) noexcept // 47
{
    cout << "Rezerw. new( size_t, const nothrow_t&, double r,int n) noexcept,"
    "\n\t\tgdzie rozmiar= " << rozmiar << ", r  = " << r << ", n =" << n << endl;
    // TEST_NIEPOWODZENIA;
    return new ( nothrow ) char[rozmiar] ;
}
//************************************************************************
void * Twektorek::operator new[ ](size_t rozmiar, const nothrow_t&) noexcept // 48
{
    cout << "Rezerw new[ ] ( size_t rozmiar, const nothrow_t& ) noexcept"
    "\n\t\tgdzie  rozmiar= " << rozmiar<<endl;
    // TEST_NIEPOWODZENIA;
    return  new ( nothrow ) char[rozmiar] ;
}
//**********************************************************************
void niepowodzenie () // 49
{
    cout << "Porazka w rezerwacji (konstruktor więc nie wystartowal)"<<endl;
}
//**********************************************************************
int main()
{

    try {
        Twektorek *w1;
        w1 = new Twektorek ( 1, 1, 1 );			// 18
        w1->wypisz();
        delete w1;

        cout << "\nRezerwacja operatorem new globalnym..." << endl;
        Twektorek * w2 = ::new Twektorek ( 2, 2, 2 );
        w2->wypisz();
        ::delete w2;
        cout << "Po skasowaniu w2 (globalnym delete)\n" << endl;

        // rezerwacja tablicy obiektów
        Twektorek * wtab = new Twektorek[3];			// 25
        for ( int i = 0; i < 3 ; ++i ) {
            wtab[i].wypisz();   						// 26
        }
        delete [ ] wtab;   // 27

        Twektorek * w3 = new ( true ) Twektorek ( 3, 33, 333 );  // 32
        w3->wypisz();
        delete w3;

        // nawet taki operator jest możliwy, który wysyła dodatkowe argumenty użytkownika
        Twektorek * w4 = new ( 3.14, 100 ) Twektorek (4, 4, 4 );   // 34
        w4->wypisz();
        delete w4;

        cout << "\nProba użycia operatora new dla klasy pochodnej Twektorek_dziedz..."<< endl;
        Twektorek_dziedz * w5 = new Twektorek_dziedz(5, 55, 555);  // 38
        w5->wypisz();
        delete  w5;   // 39

        // teraz wskaźnik jest do kl. podstawowej
        cout << "\nAdres obiektu kl. klasy pochodnej przypisany wskaźnikowi do kl. podst." << endl;

        Twektorek * wpodst = new Twektorek_dziedz (6, 66, 666);		// 40
        wpodst->wypisz();
        delete  wpodst;  // 41

        cout << "\nOperatorem new[ ] z klasy pochodnej Twektorek_dziedz..."<< endl;
        Twektorek_dziedz * w6 = new Twektorek_dziedz[2]; 				// 42
        for ( int i = 0; i < 2 ; ++i ) {
            w6[i].wypisz();
        }
        delete  [] w6;

    } // koniec bloku try
    catch ( bad_alloc &wyj ) {
        cout << "Zlapany obiekt wyjatku klasy std::alloc" << endl;
    }

    cout << "-------- To samo dla operatorów nie-rzucających wyjątków " << endl; // 50
    {   // otwarcie lokalnego bloku, żeby nie musieć zmieniać nazw wskaźników
        Twektorek * w1 = new ( nothrow ) Twektorek ( 20,21,22 );   // 51
        if ( !w1 ) niepowodzenie ();   // 52
        else w1->wypisz();
        delete ( w1 ) ;

        Twektorek * w3 = new ( nothrow,  true ) Twektorek (30, 33, 333 );  // 53
        if ( w3 == nullptr)  niepowodzenie ();
        else				w3->wypisz();
        delete w3; // takie ewentualne wywołanie


        // nawet taki operator jest możliwy, który wysyła dodatkowe argumenty użytkownika
        Twektorek * w4 = new ( nothrow, 3.14, 100 )  Twektorek ( 40,41, 43 ); // 54
        if ( w4 == nullptr)  niepowodzenie ();
        else	w4->wypisz();
        delete w4;

        // rezerwacja tablicy obiektów
        cout << "\nOperatorem new[ ] z klasy Twektorek..." << endl;
        Twektorek * wtab = new ( nothrow ) Twektorek[2];  // 55
        if ( !wtab )   niepowodzenie ();
        else for ( int i = 0; i < 2 ; ++i ) {
                wtab[i].wypisz();
            }
        delete [ ] wtab;

        cout << "Z obiektami klasy pochodnej " << endl;

        cout << "\nOperatorem new z klasy pochodnej Twektorek_dziedz..."<< endl;
        Twektorek_dziedz * w5 = new ( nothrow ) Twektorek_dziedz(50, 51,52);
        if ( w5 == nullptr)  niepowodzenie ();
        else	w5->wypisz();
        delete  w5;


        // Teraz wskaźnik będzie do klasy podstawowej
        cout << "\nOperatorem new z klasy pochodnej Twektorek_dziedz..."<< endl;
        Twektorek * wpodst= new ( nothrow ) Twektorek_dziedz(60, 61, 62);  // 57
        if ( wpodst == nullptr)  niepowodzenie ();
        else		wpodst->wypisz();
        delete  wpodst;

        cout << "\nOperatorem new[ ] z klasy pochodnej Twektorek_dziedz..."<< endl;
        Twektorek_dziedz * w6 = new ( nothrow ) Twektorek_dziedz[2];   // 58
        if ( !w6 ) niepowodzenie ();
        else {
            for ( int i = 0; i < 2 ; ++i ) {
                w6[i].wypisz();
            }
        }
        delete  [] w6;
    } // koniec lokalnego bloku
}
