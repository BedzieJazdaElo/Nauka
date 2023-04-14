// Program z paragrafu 03_11b

#include <iostream>
using namespace std;
int k = 33;						// zmienna globalna (obiekt typu int)		`1
//************************************************************
int main()
{
	cout << "Jestem w main, k =" << k << "\n";
	{
		int k = 10;						// zmienna lokalna   			`2
		cout	 	<< "po lokalnej definicji k =" << k  						// `3
				<< "\nale obiekt globalny k =" << ::k; 	 				 	// `4
	}
	cout << "\nPoza blokiem k =" << k << endl;
}
