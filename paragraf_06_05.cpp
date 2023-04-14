// Program z paragrafu 06_05
 #include <iostream>
 using namespace std;

 auto pomnozenie(int a, double b) -> double;   							// 1
 auto dodanie(int k, double r) -> decltype(k); 							// 2

 //*********************************************
 int main()
 {
	double  x{ };
	x = pomnozenie(4, 8.6);							// x = 34.4 		// 3
	cout << x << endl;
	auto y = pomnozenie(3, 1.5); 		 				// y = 4.5 		// 4
	cout << "Rezultat = " <<  dodanie(2, 3.4) << endl; 	// Rezultat = 5 	// 5
 }

 //********************************************
 auto pomnozenie(int a, double b) -> double  							// 6
 {
	return a * b;
 }

 //*******************************************
 auto dodanie(int k, double r) -> decltype(k) 							// 7
 {
	return k + r;
 }

