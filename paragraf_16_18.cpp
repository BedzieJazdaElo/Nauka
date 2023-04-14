// Program z paragrafu 16_18

#include <iostream>
using namespace std;
////////////////////////////////////////////////////////////////////////////////////////////////////
class Tsilnik {   														// 1
private:
	string	nazwa;
	int		biezaca_moc;
	//...
public:
	static	int	licznik_silnikow;										// 2
private:
	static 	int 	niezawodnosc; 										// 3
public:


	// zwykłe funkcje składowe 	––––––––––––––––––––––––––
	Tsilnik(string naz, int moc) 				// konstruktor
	{
		biezaca_moc = moc;
		++licznik_silnikow;
		// ...
	}
	~Tsilnik() 							// destruktor
	{
		stop();
		--licznik_silnikow;
	}
	void cala_naprzod()  { 	/* ...*/ }
	void stop() 	{ /*... */ 	}



	int ile_godz_wytrzyma() 											// 4
	{
		cout << "Zwykly skladnik: " << biezaca_moc  << endl;					// 5
		return niezawodnosc + 5033;
	}



	// statyczna funkcja składowa	 ––––––––––––––––––––––––
	static int podaj_bezawaryjnosc_w_godzinach()     						// 6
	{
		// int m = biezaca_moc;	 				// <->nie wolno!   			// 7
		return niezawodnosc + 5033;
	}
};
////////////////////////////////////////////////////////////////////////////////////////////////////



// DEFINICJE  składników statycznych klasy Tsilnik
int 		Tsilnik::licznik_silnikow = 0;
int  		Tsilnik::niezawodnosc = 130000; 			// prywatny!
//*******************************************************************
int main()
{
	int s = Tsilnik::licznik_silnikow; 										// 8
	cout << "Stocznia, silnikow jest teraz = "<< s << endl;

	// int ile =  Tsilnik::niezawodnosc	;						// błąd, bo private 		// 9
	// int ile2 =  nieznany_obiekt.ile_godz_wytrzyma();  		// błąd składni 		// 10

	int ile3 = Tsilnik::podaj_bezawaryjnosc_w_godzinach()  ; 					// 11
	cout << "Bezawaryjnosc wywolaniem 'klasa::funkcja' = " << ile3 << endl;

	Tsilnik lewy("Lewy", 1200);
	int ile4 = lewy.podaj_bezawaryjnosc_w_godzinach();   			 		// 12

	cout << "Bezawaryjnosc wywolaniem 'obiekt.funkcja' = " << ile4 << endl;

	int ile5 = lewy. ile_godz_wytrzyma();  									// 13
	cout << "Wywolaniem zwyklej funkcji skladowej " << ile5 << endl;
}

