// Program z paragrafu 04_07

#include <iostream>
 using namespace std;
//*********************************************************
 int main()
 {
	int c;
	cout << "Musisz odpowiedziec TAK lub NIE \n"
			<< "jesli TAK, to napisz 1 \n"
			<< "jesli NIE, to napisz 0 \n"
			<< " Rozumiesz? Odpowiedz: ";
	cin >> c;														// 1

	cout << "Odpowiedziales: "
			<< ( c? "TAK" : "NIE" ) 									// 2
			<< ", prawda ? ";
 }
