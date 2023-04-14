// Program z paragrafu 12_02


#include <iostream>
using namespace std;
void	hydraulik(int *wsk_do_kranu);									// 1
//****************************************************
int main()
{
    int kran = -1;														// 2
    cout << "Stan techniczny kranu = "<< kran << endl;
    hydraulik( &kran );												// 3
    cout << "Po wezwaniu hydraulika stan techniczny kranu = " << kran << endl; 		// 4
}
//****************************************************
void	hydraulik(int *wsk_do_kranu) 									// 5
{
    *wsk_do_kranu = 100;						// <--akcja naprawiania 		  // 6
} 																	// 7
