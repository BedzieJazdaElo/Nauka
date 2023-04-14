// Program z paragrafu 12_04_07

#include <iostream>
using namespace std;
#include <new>            									 			// 1
//****************************************************
int main()
{
    // Wstępna rezerwacja dużego obszaru pamięci
    // (czyli kupujemy grunt na osiedle domów)
    int *osiedle = new int[5000];  									 	// 2
    // Niwelowanie zdobytego właśnie obszaru
    for(int i = 0 ; i < 5000 ; ++i) osiedle[i] = 1;							 	// 3
    // Teraz na tym terenie możemy tworzyć obiekty
    // umieszczenie nowego obiektu
    void *gdzie = &osiedle[100];    	// decydujemy, że tu! 					// 4
    int *wskint = new (gdzie)  int;	// akt budowy 						 // 5
    //--- praca z tym obiektem
    *wskint = 222;														// 6
    cout << "*wskint = " << (*wskint) << endl;

    //== tu będą trzy domki w zabudowie szeregowej ===
    gdzie = &osiedle[102];
    int * wTabi = new (gdzie) int[3]; 										// 7
    //--- praca z tą tablicą ----
    for(int m = 0 ; m < 3 ; m++)   {
        wTabi[m] = 1000 + m;
        cout << "wTabi[" << m << "] = " << wTabi[m] << "  ";
    }
    cout << endl;
    //=====budowa następnych trzech  ================================
    gdzie = &osiedle[106];
    double * wTabd = new (gdzie) double[3]; 								// 8
    //--- praca z tą tablicą ----
    for(int n = 0 ; n < 3 ; n++)   {
        wTabd[n] = 1 + (0.1 * n);
        cout << "wTabd[" << n << "] = " << wTabd[n] << "  ";
    }
    cout << endl;
    // === budowa w miejscu o adresie podanym liczbowo =====================
    cout << "Napisz jakis adres pomiedzy: "
         << reinterpret_cast<long>(&osiedle[112])   							// 9
         << " - "
         << reinterpret_cast<long>(&osiedle[116])
         << "\na ja tam zbuduje ci obiekt: ";

    int adres;
    cin >> adres;
    gdzie = reinterpret_cast<void *>(adres); 								// 10
    int * wskA = new (gdzie) int;   				// budowa			    	// 11

    //--- praca z tym obiektem ----
    *wskA = 114;
    cout << "Wartosc = " << (*wskA) << endl;
    //======================================
    cout << "Popatrzmy na te dzialke \n"; 									// 12

    for(int k = 99 ; k < 116 ; ++k)
        cout << "[" << k << "]=" << osiedle[k] << endl;

    delete [ ] osiedle;
}
