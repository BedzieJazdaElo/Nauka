// Program z paragrafu 32_13

#include <iostream>
using namespace std;
//////////////////////////////////////////////////////////////////////////////////////////////
class Tstrunowy {														// 1
public:
    int liczba_lat;
    // ...
    Tstrunowy() : liczba_lat(0)					// konstruktor domniemany
    { }

    //---------------------------------------------------------------------------
    virtual Tstrunowy*  stworz_nowy_dziewiczy() = 0;
    virtual Tstrunowy*  stworz_nowy_sklonowany() = 0;
    //---------------------------------------------------------------------------
    virtual void jestem() = 0;
};
//////////////////////////////////////////////////////////////////////////////////////////////
class Tskrzypce : public Tstrunowy {										// 2
    // ...
    Tstrunowy*  stworz_nowy_dziewiczy( )									// 3
    {
        return   new Tskrzypce;  				// wywołaj konstruktor domniemany
    }
    //--------------------------------------------------------------------------
    Tstrunowy*  stworz_nowy_sklonowany()
    {
        return new Tskrzypce(*this);				// wywołaj konstruktor kopiujący
    }
    //--------------------------------------------------------------------------
public:
    void jestem()
    {
        cout << "Jestem klasy Tskrzypce, mam lat = " << liczba_lat << endl;
    }
};
//////////////////////////////////////////////////////////////////////////////////////////////
class Twiolonczela : public Tstrunowy 									// 4
{
    // ...
    Tstrunowy*  stworz_nowy_dziewiczy()
    {
        return  new Twiolonczela();	        		// <-- wywołaj konstruktor domniemany
    }
    //----------------------------------------------------------------------------
    Tstrunowy*  stworz_nowy_sklonowany()
    {
        return  new Twiolonczela(*this);      		// <-- wywołaj konstruktor kopiujący
    }
    //----------------------------------------------------------------------------
public:
    void jestem() {
        cout << "Jestem klasy Twiolonczela, mam lat = " << liczba_lat << endl;
    }
};
//////////////////////////////////////////////////////////////////////////////////////////////
int main()  															// 5
{
    Tskrzypce	skrz;
    Twiolonczela	wiol;

    wiol.liczba_lat = 157;						// niech będzie tak stara
    skrz.jestem();
    wiol.jestem();
    cout << "Teraz bedziemy wirtualnie konstruowac dodatkowe obiekty\n";
    Tstrunowy * wskaznik;												// 6
    wskaznik = &skrz;													// 7

    Tstrunowy * wsk1;													// 8
    wsk1 = wskaznik->stworz_nowy_dziewiczy();							// 9

    // Wskaźnik wskazywał na skrzypce, więc przekonajmy się, czy to
    // powstały naprawdę skrzypce.
    wsk1->jestem();													// 10
    //-----------------------
    wskaznik = &wiol;													// 11

    Tstrunowy * wsk2 = wskaznik->stworz_nowy_dziewiczy();				// 12
    wsk2->jestem();

    // następna tak kreowana wiolonczela niech będzie dokładną kopią tej starej
    Tstrunowy * wsk3 = wskaznik->stworz_nowy_sklonowany();				// 13
    wsk3->jestem();

    delete wsk1;														// 14
    delete wsk2;
    delete wsk3;
}
