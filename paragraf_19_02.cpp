// Program z paragrafu 19_02

#include <iostream>
using namespace std;
double  ryzykowna(double promien);
struct   Tblad_ujemnego_promienia    									// 1
{    };
//*******************************************************************
int main()
{
    try {   		//----------------------------------							// 2
        double wartosc = ryzykowna(5.5);   								// 3
        cout << "a) Pole kola = " << wartosc << endl;
        wartosc = ryzykowna(-6); 										// 4
        cout << "b) Pole kola = " << wartosc << endl;  						// 5
    } 			//----------------------------------							// 6
    catch(Tblad_ujemnego_promienia  kapsula)   							// 7
    {
        cout << "    Sytuacja bledu - zadany promien nie moze byc ujemny" << endl; 	// 8
    }
    cout << "Dalsze, zwykle instrukcje " << endl;   							// 9
}
//*******************************************************************59]>
double  ryzykowna(double r)   											// 10
{
    cout << "obliczamy pole kola o promieniu " << r << endl;
    if(r >= 0) 															// 11
    {
        return 3.14 * r * r;
    }
    else 		// dla ujemnego promienia nie ma sensu liczenie pola
    {
        cout << "   !!!Rzucenie wyjatku!!!" << endl;
        Tblad_ujemnego_promienia    kapsula;   							// 12
        throw kapsula;   												// 13
    }
}
