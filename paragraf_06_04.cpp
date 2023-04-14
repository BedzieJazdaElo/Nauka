// Program z paragrafu 06_04
  #include <iostream>
 using namespace std;
 long  potega(int stopien, long liczba);
//*****************************************************************
int main()
{
	cout << 	"Program na obliczanie poteg liczb calkowitych z zadanego przedzialu\n"
			"Podaj poczatek przedzialu: ";
	int pocz;
	cin >> pocz;
	cout << "Podaj koniec przedzialu: ";
	int koniec;
	cin >> koniec;
	// pętla drukująca wyniki z danego przedziału
	for(int i = pocz; i <= koniec; ++i)
	{
		cout << i
			<< " do kwadratu = "
			<< potega(2, i) 			//  <--  wywołanie funkcji 		// 1
			<< ", a do szescianu = "
			<< potega(3, i)			// <--   wywołanie funkcji 		// 2
			<< endl;
	}
	auto tesa = potega(35, 3); 			  								// 3
	cout << "W obiekcie tesa jest wartosc: " << tesa << endl;    			// 4
	cout << "sizeof(tesa) = " << sizeof(tesa)
		<< ", a sizeof(long) = " << sizeof(long) << endl;  					// 5
}
//***************************************************************
long potega(int stopien, long liczba)
{
	long wynik = liczba;
	for(int s = 1 ; s < stopien ; ++s)   {
		wynik = wynik * liczba;     // zwięźlej można zapisać to samo jako: wynik *= liczba;
	}
	return wynik;													// 6
}
