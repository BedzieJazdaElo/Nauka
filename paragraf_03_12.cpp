// Program z paragrafu 03_12

  #include <iostream>
 using namespace std;
 int main()
 {
	cout << "Wybierz poziom sledzenia programu [1-5]: ";   				// 1
	int wybor;
	cin >> wybor;													// 2
	const int    poziom_sledzenia { wybor}; 							   // 3
	// od tej pory nikt nie może zmienić wartości obiektu poziom_sledzenia
	// Oto próby naruszenia stałości tego obiektu
	// poziom_sledzenia = 4; 				//  <--kompilator zgłosi błąd  	// 4
	// ++poziom_sledzenia; 					//  <--kompilator zgłosi błąd	// 5
 }
