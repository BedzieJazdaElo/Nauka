// Program z paragrafu 32_11_01

  #include <iostream>
 #include <string>
 #include <vector>
 #include <iomanip>   			// dla setw
using namespace std;
 //////////////////////////////////////////////////////////////////////////////////////////////
 class Telement_pomiarowy  											// 1
 {
 protected:
	string moja_nazwa;
 public:
	Telement_pomiarowy(string naz) : moja_nazwa(naz) { } 					// 2
	virtual   ~Telement_pomiarowy()										// 3
	{ cout << __func__;}

	virtual void wczytaj_swoje_parametry(string trzon_nazwy_pliku) { };   		// 4
	virtual void analizuj_biezace_zdarzenie() { }							// 5
	virtual void zapisz_wyniki_analizy() { } 									// 6

	string podaj_nazwe() { return moja_nazwa; }
 };
 //////////////////////////////////////////////////////////////////////////////////////////////
 class Tkomora final : public Telement_pomiarowy 							// 7
 {
	vector<double> wyniki; 												 // 8
 public:
	Tkomora ( string nazwa ) : Telement_pomiarowy ( nazwa ) {  }    			// 9
	~Tkomora()  override; 												// 10

	void wczytaj_swoje_parametry()  // override								  // 11
	{  };
	void wczytaj_swoje_parametry(string plik) override;						 // 12
	void analizuj_biezace_zdarzenie()  override; 							 // 13
	void zapisz_wyniki_analizy() override;									 // 14
 };
 //*******************************************************
 Tkomora::~Tkomora()  													// 15
 {
		 cout << __func__ << ", ";
 }
 //*******************************************************
 void Tkomora::wczytaj_swoje_parametry ( string trzon_nazwy_pliku ) 	 		// 16
 {
	string plik = trzon_nazwy_pliku + "_" + moja_nazwa + ".txt";
	cout << "  " << moja_nazwa << ": Czytam parametry komory z pliku" << plik << endl;
	// otwarcie pliku i odczytanie wybranych parametrów...
	// ...
	wyniki.clear();
 }
 //*******************************************************
 void Tkomora::analizuj_biezace_zdarzenie()   								// 17
 {
	// Sięgamy do interfejsu tego urządzenia elektronicznego i odbieramy
	// od niego liczbę (zwykle całkowitą),
	// potem przeliczamy na stosowne jednostki, zależnie od zadanych  parametrów.

	static double 		trajektoria_lotu_jonu;
	trajektoria_lotu_jonu += 3.57;   // tu w programie analizę imitujemy  taką (fikcyjną) operacją
	wyniki.push_back(trajektoria_lotu_jonu);
	cout << "% ";
 }
 //*******************************************************
 void Tkomora::zapisz_wyniki_analizy() 									// 18
 {
	cout << "  " << moja_nazwa << " Zebrane wyniki pomiarow tej komory\n  ";
	for(unsigned int nr = 0 ; nr < wyniki.size() ; ++nr)
		cout << "| " << setw(4) << wyniki[nr] << " ";
	cout << "|\n";
 }
 //////////////////////////////////////////////////////////////////////////////////////////////
 class Tscyntylator : public  Telement_pomiarowy   							// 19
 {
 public:
	Tscyntylator(string n): Telement_pomiarowy ( n )  						// 20
	{
		robocza_tablica = new int[4000] { 0};
	}
	~Tscyntylator()   override  											// 21
	{
		 cout << __func__ << " (delete!), ";
	 	delete [ ] robocza_tablica;										// 22
	}

	void wczytaj_swoje_parametry(string  trzon_nazwy_pliku) override;
	void analizuj_biezace_zdarzenie()  override;
	void zapisz_wyniki_analizy() final; 									// 23

 protected:
	int * robocza_tablica;
	vector<int> wynik;
 };
 //*******************************************************
 void Tscyntylator::wczytaj_swoje_parametry ( string trzon_nazwy_pliku)
 {
	string plik = trzon_nazwy_pliku + "_" + moja_nazwa + ".txt";
	cout << "  " << moja_nazwa << ": Czytam parametry scyntylatora z pliku " << plik << endl;
	// ...
	// Przy okazji przygotowanie do pętli pomiarowej
	wynik.clear();
 }
 //*******************************************************
 void Tscyntylator::analizuj_biezace_zdarzenie()
 {
	static int wartosc;
	wartosc += 27;
	wartosc %= 100;
	wynik.push_back(wartosc);
	cout << "* ";
 }
 //*******************************************************
 void Tscyntylator::zapisz_wyniki_analizy()
 {
	cout << "  Zebrane wyniki pomiarow tego scyntylatora " << moja_nazwa<< "\n  ";
	for(auto w : wynik)     cout << setw(6) << w << " ";
	cout << endl;
 }
 //////////////////////////////////////////////////////////////////////////////////////////////
 class Tscyntylator_XY : public  Tscyntylator   								// 24
 {
 public:
	Tscyntylator_XY(string n): Tscyntylator ( n ) {  }
   	~Tscyntylator_XY()   {   cout << __func__ << ", ";  }

	void wczytaj_swoje_parametry(string  trzon_nazwy_pliku) override
	{
		cout << "  " << moja_nazwa << ": Czytam parametry scyntylatoraXY\n";
	}
	void analizuj_biezace_zdarzenie()  override;
	//  void zapisz_wyniki_analizy() { };   // błąd, bo w klasie Tscyntylator było final  	// 25
 };
 //*******************************************************
 void Tscyntylator_XY::analizuj_biezace_zdarzenie()
 {
	// sięganie do innych rejestrów interfejsu
	static int fikcyjna_wartosc;
	wynik.push_back(++fikcyjna_wartosc);
	cout << "# ";
 }
 //////////////////////////////////////////////////////////////////////////////////////////////
 /*---
 class Tkomora_drutowa : public Tkomora   	// niemożliwe dziedziczenie		// 26
 {

 };
 ---*/
// @

// Koniec hierarchii klas. Poniżej jest klasa, która z tej
// hierarchii skorzysta

 //////////////////////////////////////////////////////////////////////////////////////////////
 class Teksperyment   													// 27
 {
	vector<Telement_pomiarowy  *>	  detektor;   							// 28
 public:
	Teksperyment();
	// -----------
	~Teksperyment();

	void wypisz_konfiguracje();
	void przed_petla_analizujaca();
	void analiza_zdarzenia_przez_detektory();
	void wyniki_pomiaru();
 };
 //*******************************************************
 Teksperyment::Teksperyment()
 {
	Tscyntylator	*adr = new Tscyntylator ( "scy01" );						// 29
	detektor.push_back ( adr );   											// 30

	detektor.push_back ( new Tscyntylator ( "scy02" ) );  						 // 31
	detektor.push_back ( new Tkomora ( "kom01" ) ); 						// 32
	detektor.push_back ( new Tkomora ( "kom02" ) );
	detektor.push_back ( new Tscyntylator_XY("scyXY") ); 					// 33
 }
 //*******************************************************
 Teksperyment::~Teksperyment()  										// 34
 {
	// kasujemy detektory tworzone operatorem new
	for (unsigned int i = 0 ; i < detektor.size() ; ++i )  {
		cout  << detektor[i]->podaj_nazwe() << " destruktory: ";
		delete detektor[i];												// 35
		cout << endl;
	}
 }
 //*******************************************************
 void Teksperyment::wypisz_konfiguracje()  								// 36
 {
	cout	<< "Biezaca konfiguracja detektorow eksperymentu: " << endl;
	for (unsigned int i = 0 ; i < detektor.size() ; ++i )
		 cout << i << ") " << detektor[i]->podaj_nazwe() << ",  ";
	cout  << "\n" << endl;
 }
 //*******************************************************
 void Teksperyment::przed_petla_analizujaca()   							// 37
 {
	cout << "Funkcja  Teksperyment::" << __func__  << endl;
	string  trzon_nazwy_pliku ( "param" );

	for ( auto det : detektor )   det->wczytaj_swoje_parametry ( trzon_nazwy_pliku);
 }
 //*******************************************************
 void Teksperyment::analiza_zdarzenia_przez_detektory() 					// 38
 {
	for ( auto det : detektor )   det->analizuj_biezace_zdarzenie();
 }
 //*******************************************************
 void Teksperyment::wyniki_pomiaru()   									// 39
 {
	cout << "Funkcja  Teksperyment::wyniki_pomiaru" << endl;
	for ( auto det : detektor )   det->zapisz_wyniki_analizy();
 }
 //*******************************************************
 //*******************************************************
 int main()
 {
	cout << "Tu CERN, Rozpoczynamy eksperyment z ATLAS-em" << endl;

	Teksperyment  atlas;												// 40
	atlas.wypisz_konfiguracje();
	atlas.przed_petla_analizujaca();										// 41
	cout << "--- Rozpoczyna sie petla analizy kolejnych zdarzen(reakcji)" << endl;
	for(int z = 0 ; z < 6 ; z++)
	{
		cout << "  Zdarzenie nr = " << z << "  ";
		atlas.analiza_zdarzenia_przez_detektory();
		cout << " – obsluzone " << endl;
	}
	cout << "---  Po petli analizy kolejnych zdarzen" << endl;
	atlas.wyniki_pomiaru();  											// 42
	cout << "----------Koniec programu pomiarow" << endl;
 }
