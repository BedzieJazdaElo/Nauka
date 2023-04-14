
// Program z paragrafu 2.2
  #include <iostream>
 using namespace std;
 //***********************************************************************
 int main()
 {
	int wys, punkty_karne;      	// definicja dwóch zmiennych typu int
							// 		Obie są tego samego typu, więc wystarczy przecinek
							//  		oddzielający nazwy
	cout << "Na jakiej wysokosci lecimy ? [w metrach]: ";
	cin >> wys;
 	// ----------- rozważamy sytuację ------------------------
 	if(wys < 500)
	{
		cout << "\n" << wys << " metrow to za nisko !\n";
		punkty_karne = 1;
 	}
 	else
 	{
		cout << "\nNa wysokosci " << wys << " metrow jestes juz bezpieczny \n";
		punkty_karne = 0;
 	}
	// -------------- ocena Twoich wyników ----------------
	cout << "Masz " << punkty_karne << " punktow karnych \n";
	if(punkty_karne)  cout << "Popraw sie !";
 }
