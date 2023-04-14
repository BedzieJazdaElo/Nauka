// Program z paragrafu 16_24

#include <iostream>
#include <iomanip>
using namespace std;
#include <string>
//////////////////////////////////////////////////////////////////////////////////
class Tmodul_zegarowy												// 1
{
    mutable long 	moj_biezacy_czas;    									// 2
    string 		nazwa;    											// 3
    int 			co_ile_przyspiesza;   									// 4
public:
    Tmodul_zegarowy(string opis, int niedokl)								// 5
    {
        nazwa = opis;
        co_ile_przyspiesza = niedokl;
        moj_biezacy_czas = 0;
    }
    //––––––––––––––––––––––––––––––––––
    void mija_milisekunda() const  										// 6
    {
        moj_biezacy_czas++;											// 7
        if( !(moj_biezacy_czas % co_ile_przyspiesza))  						// 8
        {
            moj_biezacy_czas++;
        }
    }
    // ––––––––––––––––––––––––––––––––
    long podaj_milisekundy() const  										// 9
    {
        return moj_biezacy_czas;
    }
    // ––––––––––––––––––––––––––––––––
    long podaj_sekundy()  const  										// 10
    {
        return moj_biezacy_czas / 1000;
    }
    // ––––––––––––––––––––––––––––––––
    void drukuj_czas()   												// 11
    {
        cout << nazwa << " : " << moj_biezacy_czas / 1000.0 << " s ";
    }
    // ––––––––––––––––––––––––––––––––
    void   synchronizuj_sie_z(const Tmodul_zegarowy * wsk_z_kim)			// 12
    {
        long czas_odniesienia = wsk_z_kim->podaj_milisekundy();			// 13
        if(moj_biezacy_czas != czas_odniesienia)   						// 14
        {
            cout << "[" << setw(3) << (czas_odniesienia / 1000) 				// 15
                 << " s]:  zegar " << nazwa <<" koryguje sie o "
                 << czas_odniesienia - moj_biezacy_czas  << " ms "  << endl;
            // właściwa synchronizacja
            moj_biezacy_czas = czas_odniesienia; 						// 16
        }
    }
    // ––––––––––––––––––––––––––––––––
    void wyzeruj_czas()  												// 17
    {
        moj_biezacy_czas = 0;
    }
};
////////////////////////////////////////////////// koniec definicji klasy //////////////////////////////////////////////////////////////////////
int main()
{
    Tmodul_zegarowy 		gamma("GAMMA",    4000);    					// 18
    Tmodul_zegarowy 		separ("SEPAR",  5010);
    Tmodul_zegarowy 		alfap("ALFAP",9200);

    cout << "Sprawdzenie dokladnosci zegarow\n";
    while(true) 	  													// 19
    {
        gamma.mija_milisekunda();  										// 20
        separ.mija_milisekunda();
        alfap.mija_milisekunda();

        // kontrolnie drukujemy na ekran co 20 sekund (20000 milisekund)
        if( !(separ.podaj_milisekundy() % 20000))							// 21
        {
            gamma.drukuj_czas(); 	 									// 22
            separ.drukuj_czas();
            alfap.drukuj_czas();
            cout << endl;
        }
        if(separ.podaj_sekundy() > 60)    									// 23
            break;
    }

    cout << "Jak widac, zegary chodza nierowno, a roznice beda sie caly czas powiekszaly\n";
    //------------------------------------------------
    cout << "Wprowadzenie obiektu odniesienia===\n";
    const Tmodul_zegarowy zloty("ZLOTY", 9999999); 						// 24
    while(true)   														// 25
    {
        gamma.mija_milisekunda();
        separ.mija_milisekunda();
        alfap.mija_milisekunda();

        zloty.mija_milisekunda();    										// 26

        if(!(zloty.podaj_milisekundy() % 1000))   							// 27
        {
            gamma.synchronizuj_sie_z(&zloty);  							// 28
            separ.synchronizuj_sie_z(&zloty);
            alfap.synchronizuj_sie_z(&zloty);
            // zloty.synchronizuj_sie_z(&gamma); 							// 29
        }

        if(zloty.podaj_milisekundy() / 1000.0 >= 600) 						 // 30
        {
            cout << "Podsumowanie po 600 sekundach...\n";
            gamma.drukuj_czas();
            separ.drukuj_czas();
            alfap.drukuj_czas();
            cout << endl;
            break;
        }
    }
}
