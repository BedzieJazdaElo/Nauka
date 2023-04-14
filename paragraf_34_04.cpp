// Program z paragrafu 34_04

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;
//*******************************************************
class Twekt															// 1
{
public:
    double x, y, z;
};
//*******************************************************
// globalne funkcje operatorowe realizujące przeładowania << oraz >> dla klasy Twekt
//*******************************************************
ostream& operator<<(ostream& strumien_wyj, Twekt w)						// 2
{
    strumien_wyj << w.x << " " << w.y << " " << w.z;
    return strumien_wyj;
}
//*******************************************************
istream& operator>>(istream& strumien_wej, Twekt &w)						// 3
{
    strumien_wej >> w.x >> w.y >> w.z;
    return strumien_wej;
}
//*******************************************************
void error(string opis)													// 4
{
    cout << "Opis bledu:  " << opis << "\nKonczymy program "<< endl;
    exit(2); 															// 5
}
//*******************************************************
int main()
{
    // mamy kilka obiektów różnych typów
    double  d { 1234.567890123};										// 6
    int 		n { 255};													// 7
    string 	txt { "to jest wielowyrazowy tekst" }; 							// 8
    string 	komunikat { "to jest \nkilka linijek\nciekawego tekstu" };  			// 9
    Twekt wek { 20, 30, 40 }; 											// 10
    //–––––––––––––––––––––––––––––––––––––––––––––––––––––––––––
    cout << "----------------- Zapis danych do pliku tekstowego \n";
    string nazwa_pliku_tekstowego { "plik.txt"};
    ofstream  strumA(nazwa_pliku_tekstowego); // tryb nie jest binarny, więc tekstowy 	// 11
    if(!strumA)  														// 12
        error("Nie moge otworzyc pliku: " + nazwa_pliku_tekstowego + " do  zapisu");

    strumA << setprecision(15) << d; 										// 13
    strumA << "  " << n; 												// 14
    strumA << '\n' << txt << endl;  			// jedna linjka   				// 15
    strumA << komunikat;  					// kilka linijek   				// 16
    strumA << '$' << endl; 					// taki wymyślamy ogranicznik  		// 17
    strumA << wek;		// wywołanie przeładowanego operatora z klasy Twekt 	// 18

    if(!strumA)   														// 19
        error("Nie powiodla sie jedna z operacji zapisu tekstowego");
    strumA.close(); 													// 20

    cout << "----------------- Odczytanie danych z pliku tekstowego \n"  ;
    double d2;	    													// 21
    int n2;
    string txt2;
    string kom2;
    Twekt   wek2;

    ifstream strum2(nazwa_pliku_tekstowego);			// otwieramy tekstowo 		// 22
    if(!strum2)
        error("Nie moge otworzyc pliku: " + nazwa_pliku_tekstowego + " do odczytu");

    // wczytujemy w tej samej kolejności, w której pisaliśmy
    strum2 >> d2 >> n2; 												// 23
    strum2 >> ws; 				// podjedź do początku tekstu	  		// 24
    getline(strum2, txt2); 			// domniemany ogranicznik – jedna linijka 		// 25
    getline(strum2, kom2, '$');		// aż do ogranicznika $					// 26
    strum2 >> wek2;				// wczytanie wektora					// 27

    if(!strum2) error("Nie powiodla sie jedna z operacji odczytu tekstowego");
    strum2.close();

    cout << "Odczytanie z dysku wartości to kolejno:\n"						// 28
         << setprecision(15) << d2 << '\n' << n2 << '\n' << txt2 << '\n'  << kom2
         << "\nwektor o skladnikach: "
         << wek2.x << " " << wek2.y << " " << wek2.z << endl;

    //---------------------------- sprawdzenie, czy nie było przekłamań --------------
    if(d != d2) 	error("zle wczytane d2");								// 29
    if(n != n2)		error("zle wczytane n2");
    if (txt != txt2) 	error("zle wczytany txt2");
    if(komunikat != kom2)	error("zle wczytany kom2");
    if(wek.x != wek2.x || wek.y != wek2.y ||wek.z != wek2.z)
        error("zle wczytane wek2");
    //–––––––––––––––––––––––––––––––––––––––––––––––––––––––––
    cout << "----------------- Zapis danych do pliku binarnego\n";

    string nazwa_pliku_binarnego { "plik.bin"};
    ofstream	plikB("plik.bin", ios::out | ios::binary);  							// 30
    if(!plikB)
        error("Nie moge otworzyc pliku: " + nazwa_pliku_binarnego +  "  do zapisu");

    plikB.write((char*) &d, sizeof(d) );										// 31
    plikB.write((char*) &n, sizeof(n) );										// 32

    int dlugosc_txt = txt.size(); 											// 33
    plikB.write((char*) &dlugosc_txt, sizeof(int) );  							// 34
    plikB.write((char*) txt.data(), sizeof(char)*dlugosc_txt ); 					// 35

    int dlugosc_kom = komunikat.size();
    plikB.write((char*) &dlugosc_kom, sizeof(int) );  							// 36
    plikB.write((char*) komunikat.data(), sizeof(char)*dlugosc_kom );  			// 37

    plikB.write((char*) &wek, sizeof(wek) );   	// zapis treści całego obiektu 		// 38

    if(!plikB)
        error("Blad w pisaniu do pliku " + nazwa_pliku_binarnego);

    plikB.close(); 														// 39

    cout << "----------------- Odczyt danych z pliku binarnego \n";

    ifstream s("plik.bin", ios::in | ios::binary); 								// 40
    if(!s)
        error("Nie moge otworzyc pliku: " + nazwa_pliku_binarnego  +  " do odczytu");

    double d3;  														// 41
    int n3;
    string txt3;
    string kom3 {};

    s.read((char*) &d3, sizeof(d3) );  										// 42
    s.read((char*) &n3, sizeof(n3) ); 										// 43

    int dlugosc;
    s.read((char*) &dlugosc, sizeof(int) );   	// wczytanie „ile nastąpi znaków”		 // 44

    for(int nr = 0 ; nr < dlugosc ; ++nr)   {
        txt3 += s.get();												// 45
        if(!s)
            error("blad czytania txt3 przy znaku nr: " + to_string(nr) );
    }

    // Drugi tekst (komunikat) czytamy tak, żeby było jakoś inaczej
    s.read((char*) &dlugosc, sizeof(int) );   // wczytanie liczby znaków następnego tekstu

    char * tablica = new char[dlugosc+1] { };   	// to+1 jest na znak null		// 46
    s.read(tablica, dlugosc);  											// 47
    kom3 = tablica;
    delete [ ] tablica;
    if(!s)error("blad czytania kom3" );

    Twekt wek3;
    s.read((char*) &wek3, sizeof(wek3) );  		// wczytanie całego obiektu wek3 		// 48
    s.close();

    cout << d3 << '\n' << n3 << '\n' << txt3 << '\n' << kom3 					// 49
         << "\nwektor ma skladniki: "
         << wek3.x << " " << wek3.y << " " << wek3.z  << endl;
    //---------------------------- sprawdzenie, czy nie było przekłamań --------------
    if(d != d3) error("zle wczytane d3"); 									// 50
    if(n != n3)error("zle wczytane n3");
    if (txt != txt3) error("zle wczytany txt3");
    if(komunikat != kom3)error("zle wczytany kom3");
    if(wek.x != wek3.x || wek.y != wek3.y ||wek.z != wek3.z)
        error("zle wczytany wek3");
    cout << "Wykonane poprawnie\n";
}

