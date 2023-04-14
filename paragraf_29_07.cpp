// Program z paragrafu 29_07

#include <iostream>
#include <cstring>			// dla funkcji memset
using namespace std;
constexpr int 		MAX_URZADZ = 15;
constexpr int 		MAX_CZUJN = 10;
// tablica na wyniki pomiarów
int detektor[MAX_URZADZ][MAX_CZUJN];								// 1
// deklaracje funkcji
bool odczytaj_zdarzenie();
void analizuj_zdarzenie();
uint32_t     pobierz_slowo_danych();
//*******************************************************
int main()
{
    cout << "Program analizujacy ciagle dostarczane dane pomiarowe" << endl;
    while(odczytaj_zdarzenie() ) 			// odebranie i rozszyfrowanie danych 		 // 2
    {
        analizuj_zdarzenie();			// pokazanie danych i ewentualna analiza 	// 3
    }
    cout << "Nie ma wiecej danych, konczymy " << endl;
}
//*******************************************************
bool odczytaj_zdarzenie()												// 4
{
    // Lokalna struktura składająca się z pól bitowych reprezentujących grupy bitów słowa
    // przychodzącego z układów elektronicznych VXI
    struct Tslowo_vxi													// 5
    {
        unsigned int 	dana		:  16;
        unsigned int 	urzadzenie	:  8;
        unsigned int 	czujnik		:  6;
        unsigned int 				:  2;
    };
    // unia (anonimowa), dzięki której słowo możemy zobaczyć w postaci pociętej na pola
    union															// 6
    {
        uint32_t			cale_slowo;
        Tslowo_vxi		pole;
    };

    cout << "Nastepne zdarzenie...\n";
    // pętla wczytująca wiele słów należących do jednego „zdarzenia”
    while(1)
    {
        cale_slowo = pobierz_slowo_danych();							// 7
        if(!cale_slowo)  			// jeśli jest tam zero, to znaczy, że... 		// 8
            return false; 			// ...koniec całego pomiaru

        // poniżej korzystamy już z postaci pociętej na pola bitowe
        if(pole.urzadzenie == 0xf8)		// czy to koniec zdarzenia?			// 9
        {
            // numer urządzenia 0xf8 oznacza, że to tzw. znacznik końca zdarzenia
            // a nie słowo z wynikiem pomiaru
            cout << "Zakonczony odczyt slow zdarzenia nr "
                 << pole.dana << endl;									// 10
            return true;   			// zakończyły się poprawnie dane tego zdarzenia
        }
        else   				// Tu jesteśmy, gdy jest to słowo z wynikiem pomiaru.
        {
            // sprawdzamy, czy numery urządzenia i czujnika mają sens
            if((pole.urzadzenie < MAX_URZADZ) || (pole.czujnik < MAX_CZUJN))		// 11
            {
                // dobra dana – zapamiętujemy ją w określonym detektorze
                detektor[pole.urzadzenie][pole.czujnik] = pole.dana;			// 12
            }
        }
    }
}
//*******************************************************
void analizuj_zdarzenie()												// 13
{
    cout << "Analiza zdarzenia. W tym zdarzeniu zadzialaly:  " <<endl;
    for(int u = 0; u < MAX_URZADZ ; u++)
        for(int c = 0 ; c < MAX_CZUJN ; c++) {
            if(detektor[u][c]) {
                cout<< "\turzadzenie " << u << ", czujnik " << c
                    << ", odczyt = " << detektor[u][c] << endl;
                // tu dokonujemy prawdziwej analizy
                // .....
            }
        }

    // po analizie tego zdarzenia przygotowujemy się na następne
    memset(detektor, 0, sizeof(detektor));	// wyzerowanie całej tablicy 		// 14
}
//*******************************************************
uint32_t	pobierz_slowo_danych()										// 15
{
    // ta funkcja imituje odbieranie danych z elektronicznego układu akwizycji danych
    static uint32_t   dane[ ] =
    {
        0x4060658, 0x60201ff, 0x9058c, 0xf80000, 328457, 100729404, 0xf80001,
        197827, 134417127, 84087033, 50927293, 16848207, 17105686,
        16847128, 0xf80002,
        0 		// <-- słowo puste oznacza dla nas koniec danych pomiarowych
    };

    static int licznik;
    return dane[licznik++];
}

