// Program z paragrafu 35_02_01

#include <iostream>
#include <sstream>   			//  bo  użyjemy klasy istringstream   		// 1
#include <string>
using namespace std ;

//*****************************************************
int main()
{
    double 	wspolczynnik ;
    string 	wyraz;
    int 		liczba_int;

    string tresc("2157.15  wtorek  0x44");    							// 2
    istringstream   param(tresc); 		  								// 3

    param >> wspolczynnik;										// 4
    cout << "Wczytany wspolczynnik = " << wspolczynnik
         << " a podwojony = " << 2*wspolczynnik << endl; 		// 5

    param >>  wyraz ;   											// 6
    cout << "Wczytany wyraz = " << wyraz << endl;

    param >> hex >> liczba_int;   									// 7
    cout << "Wczytana (w zapisie hex) liczba_int = "	<< liczba_int << endl;	// 8

    cout	<< "To wczytalismy ze strumienia,\n ktorego tresc to: ["
            << param.str() << "]" << endl;								// 9

    if(param.eof())
    {
        cout << "\nUwaga: Flaga ios::eofbit ustawiona!" << endl;
        param.clear( param.rdstate() & ~ios::eofbit) ;					// 10
    }

    // demonstracja możliwości pozycjonowania
    param.seekg(1, ios::beg) ; 										// 11
    char c;
    param.get(c) ;
    cout << "Wydobyty znak c = " << c << endl ;

    param.seekg(7, ios::cur) ;  										// 12
    param.get(c) ;
    cout << "Siodmy znak dalej to = " << c << endl ;

    param.seekg(2);   												// 13
    param >>wspolczynnik;
    cout << "Liczba wydobyta z fragmentu: " << wspolczynnik << endl;

    //=========================================================

    //--------------------------------------------------
    istringstream motto ("Honni soit qui mal y pense ");   					// 14
    cout << "Tresc strumienia to: " << motto.str() ;

    string cytat;
    getline(motto, cytat, 'q');  										// 15
    cout << "\nWczytane: " << cytat << endl;

    string slowo;
    motto >> slowo;   												// 16
    cout << "Wczytane: " << slowo << endl;

}
