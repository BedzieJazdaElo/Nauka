// Program z paragrafu 2.5
  #include <iostream>
 using namespace std;
 int main()
 {
	cout << "Stewardzie, ilu leci pasazerów ? ";
	int	ile;						// liczba pasażerów
	cin >> ile;

	int i;							// licznik obiegów pętli			  	   // 1
	for(i = 1 ; i <= ile ; i = i + 1) 		    								// 2
	{
		cout 	<< "Pasazer nr " << i << " prosze zapiac pasy ! \n";
	}
	cout << "Skoro wszyscy juz zapieli, to ladujemy. ";
 }
