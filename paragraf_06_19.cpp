// Program z paragrafu 06_19

#include <iostream>
using namespace std;

int  sumator(int jeszcze_krokow, int suma_dotychczas); 					// 1
void dwojkowo(int liczba);											// 2
void schodki(int ile, char znak);
//*****************************************************
int  main()
{
    cout << "Sumowanie liczb naturalnych od 0 do n. Podaj wartosc n: ";
    int n = 0;
    cin >> n;    													// 3
    cout << "\nSuma liczb naturalnych od 0 do " << n << " to = "
         << sumator(n, 0) 	   										// 4
         << endl;
    //----------------------------------------------------------
    // zupełnie inny przykład funkcji rekurencyjnej
    //----------------------------------------------------------
    int liczba = 241;

    cout << "\n" << liczba << " to dwojkowo ";
    dwojkowo(liczba);        										// 5
    cout << endl;

    liczba = 30942;
    cout << "\n" << liczba << " to dwojkowo ";
    dwojkowo(liczba);
    cout << endl;
    return 0;
}
//*****************************************************
int sumator(int jeszcze_krokow, int suma_dotychczas)					// 6
{
    int 		rezultat = 0;											// 7
    static int 	krok_rekurencji;										// 8

    int to_pietro_nr = krok_rekurencji;									// 9
    krok_rekurencji++;    											// 10
    schodki(to_pietro_nr, '>');      									// 11
    cout << suma_dotychczas << "+ " << to_pietro_nr << " = "
         << (suma_dotychczas + to_pietro_nr)   << endl;

    // właściwa operacja sumowania
    suma_dotychczas += to_pietro_nr;   								// 12

    // warunek zatrzymujący rekurencję ++++++++++++
    if(jeszcze_krokow > 0)          										// 13
    {   // zatem kontynuujemy wywołania rekurencyjne
        rezultat =    sumator(jeszcze_krokow -1, suma_dotychczas);		// 14
    } else {
        // zatem zatrzymujemy
        cout << "........to ostatni krok, wracamy......" << endl;
        rezultat = suma_dotychczas;        								// 15
    }
    schodki(to_pietro_nr, '<');										// 16
    cout << endl;
    krok_rekurencji--;        											// 17
    return rezultat;       												// 18
}

//*****************************************************
void dwojkowo(int liczba)   											// 19
{
    int reszta = liczba % 2;											// 20
    if(liczba > 1) 							// warunek zatrzymujący 	// 21
    {
        dwojkowo(liczba / 2); 				// wywołanie rekurencyjne	// 22
    }
    cout << reszta;												// 23
    return;
}

//*****************************************************
void schodki(int ile, char znak)										// 24
{
    cout << ile << " pietro: ";
    for(int m = 0 ; m < ile ; m++)
    {
        cout << znak << " ";
    }
    cout << " ";
}
