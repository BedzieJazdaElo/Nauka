// Program z paragrafu 20_03


#include <iostream>
using namespace std;

int xyz = 10; 							// zmienna globalna 	  			// 1
void zwykla();
//*******************************************************************
int main()
{
    zwykla();
    // Tlokalik BBB; 					 		  						// 2
}
//*******************************************************************
void zwykla()
{
    int xyz = 15; 														// 3
    int lokal_autom; 													// 4
    static float lokal_stat = 77; 											// 5
    //////////////////////////////////////////////////
    class Tlokalik
    {
    public:
        // static int sss; 			// błąd – klasa lokalna nie może  		// 6
        // mieć składników statycznych
        //---------------------
        void lok_funskl()
        {
            cout << "Jestem w funkcji inline (lok_funsk) \n"
                 //	<< "xyz= " << xyz << endl 	 							// 7
                 <<"  Globalne  ::xyz = " << ::xyz      						// 8
                 // 	<< lokal_autom 						// błąd! 			// 9
                 << "\n  Lokalne statyczne  lokal_stat = "
                 << lokal_stat 	 						// OK!			// 10
                 << endl;
        }
    };
    //////////////////////////////////////////////////
    cout << "Jestem w zwyklej funkcji \n";
    Tlokalik A; 														// 11
    A.lok_funskl(); 						 							// 12
}
