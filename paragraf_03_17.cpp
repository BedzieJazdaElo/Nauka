// Program z paragrafu 03_17

#include <iostream>
using namespace std;

#include <string>

 enum class Tpraca_silnikow {										// 1
					cala_wstecz = -100,
					pol_wstecz = -50,
					wolno_wstecz = -25,
					bardzo_wolno_wstecz = -5,
					stop = 0,  									// 2
					bardzo_wolno_naprzod = 5,
					wolno_naprzod = 20,
					pol_naprzod = 50,
					cala_naprzod = 100   };

 //--------------------------------------------------------------
 enum Todtwarzanie  {												// 3
					play,
					stop, 				// <--   uwaga!
					pause = 16,									// 4
					rewind_tape   };

//***************************************************************
 int main()
 {
	cout << "Kapitan na mostku sygnalizuje telegrafem." << endl;
	Tpraca_silnikow    telegraf = Tpraca_silnikow::stop; 					// 5

	// czas ruszyć
	telegraf = Tpraca_silnikow::wolno_naprzod; 						// 6
	// zakładamy, że tutaj mechanik reaguje na tę komendę

	using Tsilniki = Tpraca_silnikow;		// deklaracja wygodnego aliasu 	// 7
	// kapitan decyduje, żeby płynąć szybciej
	telegraf = Tsilniki::pol_naprzod;									// 8

	// Co na taką komendę robi mechanik?
	cout << "Mowi mechanik. Kapitan przez telegraf rozkazal: ";
	switch(telegraf) 												// 9
	{
		case  Tpraca_silnikow::bardzo_wolno_naprzod: 					// 10
			cout << "*bardzo wolno naprzod*" << endl;
			// ...
			break;
		case Tsilniki::pol_naprzod: 									// 11
			cout << "*pol_naprzod*" << endl;
			// ...
			break;
		case Tpraca_silnikow::cala_naprzod:
			cout << "*cala_naprzod*" << endl;
			// ...
			break;
		// i tak dalej, tu powinny nastąpić reakcje na dalsze pozycje z listy
	}

	// int m = Tpraca_silnikow::stop; 				// <-- błąd 			// 12
	// int p = telegraf; 							// <-- błąd 			// 13

	int moc_silnikow = static_cast<int>(telegraf);						// 14
	cout << "co oznacza " << moc_silnikow  << "% mocy silnikow " << endl;

	// telegraf = 0;													// 15
	// telegraf = stop;												// 16
	telegraf = Tpraca_silnikow::stop;									// 17
	//---------------------------------------------------
	enum { 														// 18
			liczba_kotwic = 2,
			liczba_ladowni = 6 };

	for(int k = 0 ; k < liczba_kotwic ; ++k) 								// 19
	{
		cout << "Opuszczamy kotwice nr " << k << " (z " << liczba_kotwic << ")"<< endl;
	}
	cout << "Obserwujemy kazda z " << liczba_ladowni << " ladowni" << endl;
 }

