// Program z paragrafu 21_10_03


#include <iostream>
#include <initializer_list>
#include <string>
using namespace std;
////////////////////////////////////////////////////////////////////////////////////////////////////////
class Temperatury   														// 1
{
    long unsigned int 		ile_pomiarow;  									// 2
    int  * 				dane;		  									// 3
    string 				termin_pomiarow;    					  			// 4
public:
    // konstruktor z listą inicjalizatorów
    Temperatury(initializer_list<int> pomiary) 									// 5
    {
        ile_pomiarow = pomiary.size(); 										// 6
        dane = new int[ile_pomiarow]; 										// 7
        int i = 0;
        for(auto t : pomiary) {
            dane[i++] = t;    // 8
        }
    }

    ~Temperatury()   // destruktor oddający rezerwację pamięci ----------------------
    {
        if(dane) delete [ ] dane;    											// 9
    }

    // konstruktor z listą inicjalizatorów i dodatkowym napisem ---------------------
    Temperatury(initializer_list<int> pomiary, string kiedy_zrobione):
        Temperatury {pomiary} 			// 10
    {
        termin_pomiarow = kiedy_zrobione;   									// 11
    }

    Temperatury(int a, int b) 			// najzwyklejszy konstruktor 			// 12
    {
        cout << "Konstruktor (int , int b) dla argumentów (" << a << ", " << b << ")" << endl;
        ile_pomiarow = 2;
        dane = new int[ile_pomiarow];
        dane[0] = a;
        dane[1] = b;
    }
    //-----------------------------------------------------
    void  wypisz_wszystkie_pomiary ()   										// 13
    {
        cout << "Wypisanie pomiarow " <<  termin_pomiarow   << endl;
        for(unsigned int i = 0 ; i < ile_pomiarow ; ++i)
        {
            cout << "[" << i << "]= " << dane[i] << ", " << flush;
        }
        cout << endl;
    }
};
//*******************************************************************
int main()
{
    Temperatury  tydzien { 12,12,14,15, 18, 18, 20 };   							// 14
    tydzien.wypisz_wszystkie_pomiary();   									// 15

    //------- innym konstruktorem -------
    Temperatury  tyd2( { 25, 24, 20, 19, 19, 19, 20 }, "sprzed miesiaca");    			// 16
    tyd2.wypisz_wszystkie_pomiary();

    // <@198>wiczenia – który konstruktor tu zadziała?
    Temperatury 	 q {6, 7};	 	// użyty zostaje Temperatury::Temperatury(initializer_list)	 // 17
    Temperatury	 s = {8, 9};	// użyty zostaje Temperatury::Temperatury(initializer_list) 	// 18

    Temperatury  	 m (4, 5); 	// użyty zostaje Temperatury::Temperatury(int, int) 		// 19
    Temperatury  	 n ( {4, 5} ); 	// użyty zostaje Temperatury::Temperatury(initializer_list) 	// 20
}
