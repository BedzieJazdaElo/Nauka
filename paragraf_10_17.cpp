// Program z paragrafu 10_17

#include <iostream>
#include <vector>
#include <iomanip>   			// dla manipulatora setw
using namespace std;

string tekst_nikt("Bilet nie sprzedany");
void wyswietlenie_rezerwacji_miejsc(vector<vector<vector<string>>> widownia);
void grafik_zajetosci_miejsc(vector<vector<vector<string>>> widownia);
//***********************************************************
int main()
{
    int liczba_pieter = 2;
    int liczba_rzedow = 15;
    int liczba_foteli_w_rzedzie = 25;

    // łatwiej to wygląda jeśli posłużymy się synonimami
    using Trzad  = vector<string> ;
    using Tpietro  = vector<Trzad>;
    using Twidownia = vector<Tpietro>;

    Twidownia  teatr_wielki( 	liczba_pieter,
                                Tpietro(	liczba_rzedow,
                                            Trzad(
                                                    liczba_foteli_w_rzedzie,
                                                    tekst_nikt)
                                       )
                           );

    // Robimy rezerwacje
    teatr_wielki[1][0][12] = "Jozef Pilsudski";
    teatr_wielki[0][8][4] = "Wincenty Witos";
    teatr_wielki[0][2][16] = "Boleslaw Wieniawa-Dlugoszowski";
    teatr_wielki[0][2][17] = "Hanka Ordonowna";

    cout << "Grafik zajetosci miejsc w Teatrze Wielkim " << endl;
    grafik_zajetosci_miejsc(teatr_wielki);
    cout << "\nRezultaty rezerwacji w Teatrze Wielkim" << endl;
    wyswietlenie_rezerwacji_miejsc(teatr_wielki);
    // -------------------------------------------------------------------------------
    vector<vector<vector<string>>>    teatr_slowackiego(   // Twidownia
        liczba_pieter,
        vector<vector<string> >(                    	// czyli Tpiętro
            liczba_rzedow,
            vector<string>(         	                        // czyli Trząd
                liczba_foteli_w_rzedzie,  tekst_nikt
            )
        )
    );
    // dokonywanie rezerwacji
    teatr_slowackiego[0][2][15] = "Stanislaw Wyspianski";
    teatr_slowackiego[0][2][16] = "Teofila Wyspianska";
    teatr_slowackiego[1][1][8] = "Lucjan Rydel";

    cout << "Rezultaty rezerwacji w Teatrze Slowackiego " << endl;
    wyswietlenie_rezerwacji_miejsc(teatr_slowackiego);
    cout << "Na miejscu pietro 0, rzad 3, fotel 8 siedzi:   " << teatr_slowackiego[0][3][8] << endl;

    // osiąganie docelowych rozmiarów ("pompowanie") za pomocą funkcji resize
    vector<vector<vector<string>>>  teatr_groteska;    // nie napompowany!

    teatr_groteska.resize(liczba_pieter);   // pompowanie pięter
    for(int nr_pietra = 0 ; nr_pietra < liczba_pieter ; ++nr_pietra)
    {
        // pompowanie rzędów na konkretnym piętrze
        teatr_groteska[nr_pietra].resize(liczba_rzedow);
        for(int nr_rzedu = 0 ; nr_rzedu < liczba_rzedow ;  ++nr_rzedu)
        {
            // pompowanie foteli w konkretnym rzędzie
            teatr_groteska[nr_pietra][nr_rzedu].resize(liczba_foteli_w_rzedzie);
            // gotowe, ale skoro już tu jesteśmy, to wpiszmy jakąś wartość wstępną
            for(int nr_fotela = 0 ; nr_fotela < liczba_foteli_w_rzedzie; ++nr_fotela)
            {
                teatr_groteska[nr_pietra][nr_rzedu][nr_fotela] = tekst_nikt;
            }
        }
    }

    teatr_groteska[1][2][15] = "Marysia Kmiecik";
    teatr_groteska[0][8][4] = "Wojtus Krolas";
    cout << "Rezultaty rezerwacji w Teatrze Groteska" << endl;
    wyswietlenie_rezerwacji_miejsc(teatr_groteska);


    // osiąganie docelowych rozmiarów ("pompowanie") za pomocą funkcji push_back
    vector<vector<vector<string>>>  teatr_stu;    // nie napompowany!

    for(int nr_pietra = 0 ; (int) teatr_stu.size() < liczba_pieter ; ++nr_pietra)
    {
        Tpietro robocze_pietro;   	// jest puste, ale ponieważ składać się ma
        // z rzędów, to musimy taki jeden przygotować

        for(int nr_rzedu = 0 ; nr_rzedu < liczba_rzedow ;  ++nr_rzedu)
        {
            Trzad  roboczy_rzad; // na razie pusty
            for(int nr_fotela = 0 ; nr_fotela < liczba_foteli_w_rzedzie ; ++nr_fotela)
            {
                roboczy_rzad.push_back(tekst_nikt);
            }
            robocze_pietro.push_back(roboczy_rzad);
        }
        teatr_stu.push_back(robocze_pietro);
    }

    teatr_stu[1][2][15] = "Krzysztof Jasinski";
    teatr_stu[0][8][4] = "Maryla Rodowicz";
    teatr_stu[1][3][20] = "Marek Grechuta";

    cout << "Rezultaty rezerwacji w Teatrze Stu " << endl;
    wyswietlenie_rezerwacji_miejsc(teatr_stu);

    // Nie-prostokątne (nie-prostopadłościenna) tablica trójwymiarowa
    vector<vector<vector<string>>>  sydney_opera;    // nie napompowany!

    vector<vector<int>> opis_widowni // pomocniczy wektor  2D
    {
        { 26, 26, 30, 30,  28},   		// piętro 0 ma 5 rzędów mających po tyle foteli
        { 26, 24, 24, 20} ,  			// piętro I ma 4 rzędy mających po tyle foteli
        { 30, 30, 28  },   			// piętro II ma 3 rzędów mających po tyle foteli
        { 28, 14}     				// piętro III – 2 rzędy po tyle foteli
    };

    sydney_opera.resize(opis_widowni.size() );

    for(unsigned int nr_pietra = 0 ; nr_pietra < sydney_opera.size() ; ++nr_pietra  )
    {
        int ile_rzedow_na_tym_pietrze =  opis_widowni[nr_pietra].size() ;
        sydney_opera[nr_pietra].resize(ile_rzedow_na_tym_pietrze);

        for(int nr_rzedu = 0 ; nr_rzedu < ile_rzedow_na_tym_pietrze ; ++nr_rzedu  )
        {
            int ile_foteli_w_tym_rzedzie = opis_widowni[nr_pietra][nr_rzedu];
            sydney_opera[nr_pietra][nr_rzedu].resize(ile_foteli_w_tym_rzedzie);

            for(int nr_fotela = 0 ; nr_fotela < ile_foteli_w_tym_rzedzie ; ++nr_fotela  )
            {
                sydney_opera[nr_pietra][nr_rzedu][nr_fotela] = tekst_nikt;
            }
        }
    }

    sydney_opera[1][3][4] = "Tadeusz Boy-Zelenski" ;
    sydney_opera[0][3][9] = "Bronislaw Malinowski" ;
    sydney_opera[3][1][12] = "Piotr Skrzynecki" ;
    sydney_opera[2][1][5] = "S. I. Witkiewicz (Witkacy)" ;

    cout << "Grafik zajetosci widowni Sydney Opera house" << endl;
    grafik_zajetosci_miejsc(sydney_opera);
    cout << "Rezultaty rezerwacji w Sydney Opera" << endl;
    wyswietlenie_rezerwacji_miejsc(sydney_opera);
}
//***********************************************************
void grafik_zajetosci_miejsc(vector<vector<vector<string>>> widownia)
{
    for(unsigned int nr_pietra = 0 ; nr_pietra < widownia.size() ; ++nr_pietra ) {
        cout << "Pietro nr " << nr_pietra << endl;
        for(auto rzad : widownia[nr_pietra] ) {
            for(auto fotel: rzad)
            {
                if(fotel == tekst_nikt) cout << "|.";
                else cout << "|X" ;
            }
            cout << "|" << endl;
        }
        cout << endl;
    }
}
//***********************************************************
void wyswietlenie_rezerwacji_miejsc(vector<vector<vector<string>>> widownia)
{
    int ile_widzow = 0;
    cout << "Na dzisiejszym wieczornym przedstawieniu zasiada" << endl;
    for(unsigned int nr_pietra = 0 ; nr_pietra < widownia.size() ; ++nr_pietra)
        for(unsigned int nr_rzedu = 0 ; nr_rzedu < widownia[nr_pietra].size() ; ++nr_rzedu)
            for(unsigned int nr_fotela = 0 ; nr_fotela < widownia[nr_pietra][nr_rzedu].size() ; ++nr_fotela)
            {

                if(widownia[nr_pietra][nr_rzedu][nr_fotela] != tekst_nikt )
                {
                    cout <<  "   Pan(i) " << setw(30)
                         << widownia[nr_pietra][nr_rzedu][nr_fotela]
                         << " - pietro " << nr_pietra << ", rzad: " << nr_rzedu
                         << ", fotel: " << nr_fotela << endl;
                    ++ile_widzow;
                }
            }
    cout << "Czyli lacznie " << ile_widzow << " widzow" << endl;
}
