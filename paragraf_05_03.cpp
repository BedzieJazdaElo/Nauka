// Program z paragrafu 05_03
   #include <iostream>
 #include <vector>
 #include <string>
 using namespace std;
//*******************************************************
 int main()
 {
	vector<double> liczby { 3.14,   4.4,    -6.6,   7.7 };
	for(auto elem : liczby)	 {										// 1
		cout << elem << ", ";
	}
	for(auto & k : liczby)	{										// 2
			k = k * 10; 											// 3
	}
	cout << "\nPo pomnozeniu: ";
	for(auto elem : liczby)   cout << elem << ", ";
	cout << endl;

	 // Obiekt typu string to też pojemnik (na znaki)
	string przyslowie {"Przyszla koza do woza"};
	cout << "Skakanie po kolejnych znakach stringu\n";
	for(auto znak : przyslowie)   {									// 4
			cout << "–" << znak;
	}
	cout << endl;

 // lista inicjalizatorów
	cout << "Pojemnikiem jest też tresc { ... }\n";
	for(auto x : { 6, 9, 3, 8, 4, 7, 5, 7 } )	 {							// 5
		cout << x << ", ";
	}
	cout << endl;

	// dla wtajemniczonych: prawdziwa tablica
	cout << "zakresowe for potrafi obsłuzyc też tablice\n";
	int tablica[ ] { 100, 200, 300, 50 };
	for(auto & n : tablica)   {
		cout << n << ",	";	 									// 6
		n++;														// 7
	}
	cout << "\nEfekt po inkrementacji\n";
	for(auto n : tablica)	cout << n << ",	";
 }
