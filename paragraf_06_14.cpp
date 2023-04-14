// Program z paragrafu 06_14

#include <iostream>
using namespace std;

double	poczatek_x; 				// początek układu współrzędnych 	// 1
double	poczatek_y;
double	skala_x = 1;				// skale: pozioma i pionowa
double	skala_y = 1;
//*********************************************1
inline double wspx(double wspolrzedna)								// 2
{
    return( (wspolrzedna - poczatek_x) * skala_x);
}
//*********************************************1
inline double wspy(double wspolrzedna) 								// 3
{
    return( (wspolrzedna - poczatek_y) * skala_y);
}
//*********************************************1
int main()
{
    double 	x1 = 100, 			// przykładowy punkt
            y1 = 100;

    cout << "Mamy w punkt o wspolrzednych "
         << " x = " << wspx(x1)										// 4
         << " y = " << wspy(y1) << endl;								// 5

    // zmieniamy początek układu współrzędnych
    poczatek_x = 20;
    poczatek_y = -500;

    cout << "Gdy przesuniemy uklad wspolrzednych tak, \n"
         << "ze poczatek znajdzie sie w punkcie "
         << poczatek_x << ", " << poczatek_y
         << "\nto nowe wspolrzedne punktu \n"
         << "w takim ukladzie sa: "
         << " x = " << wspx(x1) 										// 6
         << " y = " << wspy(y1) << endl;								// 7

    // zagęszczamy skalę na osi poziomej
    skala_x = 0.5;
    cout << "Gdy dodatkowo zmienimy skale pozioma tak, ze skala_x = " <<	skala_x
         << "\nto ten sam punkt ma teraz wspolrzedne: "
         << " x = " << wspx(x1) 										// 8
         << " y = " << wspy(y1) << endl;								// 9
}
