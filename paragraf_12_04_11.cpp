// Program z paragrafu 12_04_11

#include <iostream>
#include <cstdlib>				// zawiera deklarację funkcji exit			// 1
#include <new> 				// zawiera deklarację funkcji set_new_handler		// 2
using namespace std;
//****************************************************
void funkcja_obslugujaca();												// 3
long rez	;															// 4
//****************************************************
int main()
{
    set_new_handler(funkcja_obslugujaca);								// 5
    try {
        for(rez = 1 ; ; rez++ )	{
            new  int[1000000000];				 // tworzenie obiektu  		// 6
        }
    }
    catch(std::bad_alloc &e)   											// 7
    {
        cout << "Zlapany wyjatek std::bad_alloc" << endl;
    }
}

//****************************************************
void funkcja_obslugujaca()
{
    cout << "Funkcja obslugujaca: pamieci zabraklo przy rezerwacji = " << rez << "!\n";
    //exit(1); 															// 8
    throw bad_alloc(); 													// 9
}

