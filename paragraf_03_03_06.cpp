// Program z paragrafu 03_03_06
#include <iostream>
 #include <limits>   												 // 1
 #include <iomanip>
 using namespace std;

//******************************************************************
 template <typename T>
 void info_o_typie(string opis)  										 // 2
 {
	cout	<< setw(18)
		<< opis << ":"
		<< setw(2) << sizeof(T)
		<< "|"
		<< setw( 2)
		<< numeric_limits<T>::digits 							// Bit znaku się w to nie wlicza
		<< (numeric_limits<T>::is_signed ? "|zn|" : "|bz|") 		// Ma? Czy nie ma znaku?
		<< "[" << numeric_limits<T>::min()
		<< ", " 	<< numeric_limits<T>::max()
		<< "]" <<endl;
 }
//********************************************************************
 int main()
 {
	cout << "int: "
		<< numeric_limits<int>::digits    								 // 3
		<< " bitow, "
		<< (numeric_limits<int>::is_signed ? "znak " : "b/zn ")  			 // 4
		<< " bajtow: "
		<< sizeof(int)   											 // 5
		<< "  [" <<  numeric_limits<int>::min()   						// 6
		<< ", " 	<<  numeric_limits<int>::max()   // 7
		<< "]" <<endl;

	cout << "Informacje o typie przechowujacym znaki" << endl;

	cout << " 			 char: "
		<< sizeof(char)
		<< "|"
		<< numeric_limits<char>::digits
		<< (numeric_limits<char>::is_signed ? "|zn|" : "|bz|")
		<< "[" <<  (int) numeric_limits<char>::min()     					// 8
		<< ", " 	<< (int) numeric_limits<char>::max()
		<< "]" <<endl;

	cout 	<< "\nWypisanie za pomoca szablonu funkcji " <<endl;

		info_o_typie<short int>("short int");   							 // 9
		info_o_typie<signed short int>("signed short int");
		info_o_typie<unsigned short int>("unsigned short int");
		info_o_typie<int>("int");
		info_o_typie<signed int>("signed int");
		info_o_typie<unsigned int>("unsigned int");
	cout << endl;
		info_o_typie<long int>("long int");
		info_o_typie<signed long>("signed long");
		info_o_typie<unsigned long>("unsigned long");
	cout << endl;
		info_o_typie<long long int>("long long int");
		info_o_typie<signed long long>("signed long long");
		info_o_typie<unsigned long long>("unsigned long long");
	cout << endl;
		info_o_typie<float>("float");
		info_o_typie<double>("double");
		info_o_typie<long double>("long double");
 }
