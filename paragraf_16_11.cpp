// Program z paragrafu 16_11
#include <iostream>
using namespace std;
int balkon = 77;						// nazwa globalna				// 1
void spiew();							// deklaracja jakiejś funkcji (globalnej)

////////////////////////////////////////////////// definicja klasy /////////////////////////////////////////////////////////////////////
class Topera
{
public:
    int		n;
    double 	balkon;						// składnik klasy 			// 2
    // ...
    void funkcja();
    void	spiew()													// 3
    {
        cout << "funkcja spiew (z opery): tra-la-la!\n";
    }
};
//////////////////////////////////////////////// koniec definicji klasy //////////////////////////////////////////////////////////////

void Topera::funkcja() 	  											// 4
{
    // jeszcze się nic nie dzieje   									// 5
    cout << "balkon (skladnik klasy) = " << balkon << endl;
    cout << "balkon (zmienna globalna) = " << ::balkon << endl;

    // definicja zmiennej lokalnej (lokalnej dla tej funkcji)				// 6
    char balkon = 'M';

    cout << "\nPo definicji zmiennej lokalnej ---\n";
    cout << "balkon (zmienna lokalna) = " << balkon << endl;
    cout << "balkon (skladnik klasy) = " << Topera::balkon << endl;
    cout << "balkon (zmienna globalna) = " << ::balkon << endl;

    // ------ wywołanie funkcji
    spiew();														// 7
    int spiew; 													// 8
    spiew = 7; 													// 9
    // spiew();				//  <--- błąd w trakcie kompilacji 			   // 10
    //        bo nazwa funkcji jest już zasłonięta

    cout	<<	"Po zaslonieciu da sie wywolac funkcje spiew tak\n";
    Topera::spiew(); 			// lub tak:     this->spiew();     			// 11
}
//*************************************************
int main()
{
    Topera Lohengrin;
    Lohengrin.balkon = 6;	 										// 12
    Lohengrin.funkcja();											// 13
    spiew();				 										// 14
}

//*************************************************
void spiew()
{
    cout << "zwykla funkcja spiew (niemajaca nic wspolnego z klasa)\n";
}
