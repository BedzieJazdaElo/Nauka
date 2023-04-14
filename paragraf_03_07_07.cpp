// Program z paragrafu 03_07_07

 #include <iostream>
 using namespace std;

 int main()
 {
	cout <<	"Lecimy promem \"Columbia\", tu \\ bekslesz" << endl;
	cout << 	R"(Lecimy promem "Columbia", tu \ bekslesz)" << endl;	  		// 1

	cout << 	"C:\\transport\\nowy_projekt\\projekt1" << endl;;
	cout << 	R"(C:\transport\nowy_projekt\projekt1)" << endl;   				// 2

	// gdy konieczne jest użycie znaku nowej linii
	cout << "linia pierwsza\nlina druga\n";

	cout 	<< R"(linia raw pierwsza
lina raw druga
)";
	// a gdy w tekście ma wystąpić // )"//  zmieniamy ogranicznik na odpowiedniejszy
	cout	<< R"ogranicznik(Zawisza "(Czarny)" zawolal)ogranicznik" << endl;         		 // 4
	cout << R"##(Boleslaw "(Krzywousty)" wszedl do komnaty)##" << endl;
 }
