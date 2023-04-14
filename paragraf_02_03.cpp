// Program z paragrafu 2.3
  #include <iostream>
 using namespace std;
 int main()
 {
	int ile;
	cout << "Ile gwiazdek ma miec kapitan ? : ";
	cin >> ile;
	cout << "\n No to narysujmy wszystkie " << ile << " : ";
	// pętla while rysująca gwiazdki
	while(ile)
	{
		cout << "*";
		ile = ile - 1;
	}
	// na dowód, że miał prawo przerwać pętlę
	cout << "\n Teraz zmienna ile ma wartosc " << ile;
 }
