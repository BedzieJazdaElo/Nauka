// Program z paragrafu 01_02
/* -----------------------------------------------------------
 Program na przeliczanie wysokosci podanej w stopach na wysokosc w metrach.
 Cwiczymy tu operacje wczytywania z klawiatury i wypisywania na ekranie
 ------------------------------------------------------------*/
 #include <iostream>
 using namespace std;

 int main()
 {
	int 		stopy;						// Do przechowania danej wejsciowej
	double 	metry;						// Do wpisania wyniku
	double 	przelicznik = 0.3;				// przelicznik: stopy na metry

	cout << "Podaj wysokosc w stopach: ";
	cin >> stopy;							// przyjecie danej z klawiatury

	metry = stopy * przelicznik;				// wlasciwe przeliczenie

	cout << "\n"; 							// to samo, co:   cout << endl;

	// -----wypisanie wynikow ---------
	cout << stopy << " stop - to jest: " << metry << " metrow\n";
 }
 //===================================================================
