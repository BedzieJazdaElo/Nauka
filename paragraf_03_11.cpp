// Program z paragrafu 03_11


 #include <iostream>
 using namespace std;
 int k = 33;	 // zmienna globalna (obiekt typu int) 						// 1
 //************************************************************
 int main()
 {
	cout << "Jestem w main, k =" << k << "\n"; 							 	// 2
	{ 	// <---	// 3
		int k = 10;			  // zmienna lokalna  						// 4
		cout << " po lokalnej definicji k =" << k << endl; 					 	// 5
	} 	// <---	// 6

	cout << "Poza blokiem k =" << k << endl;							 	// 7
 }
