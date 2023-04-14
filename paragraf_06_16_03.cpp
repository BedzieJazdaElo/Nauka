// Program z paragrafu 06_16_03

#include <iostream>
using namespace std;
/* ------------------- deklaracje funkcji ----------------------*/
void czerwona(void);												// 1
void biala(void);
//*********************************************
int main()
{
    czerwona();													// 2
    czerwona();
    biala();
    czerwona();
    biala();
}
//*********************************************
void czerwona(void)
{
    static int ktory_raz;												// 3
    ktory_raz++;
    cout << "Funkcja czerwona wywolana "<< ktory_raz << " raz\n";
}
//*********************************************
void biala(void)
{
    static int ktory_raz = 100;										// 4
    ktory_raz = ktory_raz + 1;										// 5
    cout << "Funkcja biala wywolana "<< ktory_raz << " raz\n";			// 6
}
//*********************************************
