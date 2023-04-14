// Program z paragrafu 06_01
#include <iostream>
 using namespace std;

 int kukulka(int ile);													// 1
 //*********************************************
 int main()
 {
	int m = 20;
	cout << "Zaczynamy" << endl;

	m = kukulka(5);												// 2
	cout << "\nNa koniec m = " << m;									// 3
 }
 //*********************************************
 int kukulka(int ile)													// 4
 {																// 5
	for(int i = 0 ; i < ile ; ++i)   {
			cout << "Ku-ku! ";
	}
	return 77;													// 6
 }
