// Program z paragrafu 02_06
#include <iostream>
using namespace std;
int main()
{

 cout 	<< "Kapitanie, ktory podzespol sprawdzic ? \n"
			<< "nr 10 - Silnik \nnr 35 - Stery \nnr 28 - radar\n"
			<< "Podaj, kapitanie, numer: ";
 int ktory;
 cin >> ktory;
 switch(ktory){
	case 10:
		cout << "sprawdzamy silnik \n";
		break;
	case 28:
		cout << "sprawdzamy radar \n";
		break;
	case 35:
		cout << "sprawdzamy stery \n";
		break;
	default:
		cout << "Zazadales nr " << ktory 	<< " - nie znam takiego ! ";
		break;
 }
 // ... dalsza część programu

}
