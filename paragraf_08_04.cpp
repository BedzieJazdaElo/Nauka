// Program z paragrafu 08_04

  #include <iostream>
 using namespace std;

 void potrojenie(int ile, long t[  ]);										// 1
 //*****************************************************************
 int main()
 {
	constexpr int 	rozmiar = 8192;									// 2
	long 	widmo[rozmiar];										// 3

	for(int i = 0 ; i < rozmiar ; ++i)
	{
		widmo[i] = i;	// wpisanie wartości początkowej do danego elementu	// 4
		if(i < 6)		// pokazanie pierwszych sześciu na ekranie
			cout << "widmo[" << i << "]= " << widmo[i] << endl;
	}
	// --------- uwaga, wywołujemy funkcję!
	potrojenie(rozmiar, widmo);										// 5
	cout << "Po wywolaniu funkcji \n";
	for(int i = 0 ; i < 4 ; ++i)
	{ 															// 6
		cout << "widmo[" << i << "]= " << widmo[i] << endl;
	}
 }
 //******************************************************
 void potrojenie (int ile, long t[ ])										// 7
 {
	for(int i = 0 ; i < ile ; ++i)
	{
		t[i] *= 3; 													// 8
	}
 }
