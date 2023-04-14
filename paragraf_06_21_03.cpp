// Program z paragrafu 06_21_03

#include <iostream>
#include <cmath>    										// 24
using namespace std;
//****************************************************
constexpr double mile_na_kilometry(double mil)       			// 1
{
    return (1.609344 * mil);									// 2
}
//***********************************************************************************
bool  zwykla_funkcja(char pierwszy, char drugi);
//***********************************************************************************
constexpr bool czy_alfabetycznie(char a, char b)				// 9
{
    return  a < b ? true : zwykla_funkcja(a,b);
}
//***********************************************************************************
constexpr int porownaj(char a, char b)						// 13
{
    return  a < b ? -1 : (a == b) ?  0 : +1;
}
//***********************************************************************************
constexpr double pi = 3.14159265;							// 16
//***********************************************************************************
constexpr  double dwa_pi_r(const double & promien)			// 17
{
    return 2 * pi* promien  ;   // może odnosić się do nielokalnych obiektów (ale ich nie zmieniać)
}
//***********************************************************************************
constexpr long long silnia(int n)								// 19
{
    return  n > 0  ?  n * silnia(n - 1)   :   1;
}
//***********************************************************************************

constexpr  double nasz_sinus(double x)  						// 21
{
    return 	x
            - (x*x*x) /silnia(3)
            + (x*x*x*x*x)/silnia(5)
            - (x*x*x*x*x*x*x) / silnia(7)
            + (x*x*x*x*x*x*x*x*x) / silnia(9);
}
//***********************************************************************************
constexpr double stopnie_na_radiany(double stopni)  			// 22
{
    return   pi* stopni / 180;
}
//------------------------------------------
// dla znających tablice
constexpr double tablica_sinusow[] = {						// 26
    nasz_sinus(stopnie_na_radiany(0)),
    nasz_sinus(stopnie_na_radiany(2.5)),
    nasz_sinus(stopnie_na_radiany(5)),
    nasz_sinus(stopnie_na_radiany(7.5))
    // i tak dalej
};

//***********************************************************************************
constexpr double wbezwzgledna(const double & n) 			// 29
{
    return  n < 0  ? -n  :  n;    // OK
}
//***********************************************************************************
constexpr double promien_orb_marsa = 228 ; 		//  wikipedia: 228 milionów km
constexpr double poziom_zanurzenia = -333;
//***********************************************************************************
int main()
{
    constexpr  double  buty_kilometrowe  =  mile_na_kilometry(7); 	// 3
    cout << "7-milowe buty to inaczej buty " << buty_kilometrowe << "-kilometrowe"  << endl;

    constexpr double dystans_mile = 2614 ; 			// w milach	 	// 4
    constexpr double dystans_km = mile_na_kilometry(dystans_mile);  // 5

    cout << "Odleglosc Paryz - Dakar to " << dystans_km << " kilometrow" << endl;

    for(int m = 100 ; m < 600 ; m+= 200)
    {
        cout << "   " << m << " mil odpowiada "
             << mile_na_kilometry(m) << " km." <<endl; 			// 6
        // constexpr double km = mile_na_kilometry(m);	// błąd kompilacji 	// 7
    }
    //== pojedyncze wyrażenie warunkowe ===
    constexpr bool r = czy_alfabetycznie('a', 'z') ;    					// 10
    cout << "r = " << r << endl;

    int odp = czy_alfabetycznie('z', 'm') ; 							// 11
    // constexpr int odp2 = czy_alfabetycznie('z', 'm') ; 				// 12
    // podwójne wyrażenie warunkowe ======
    constexpr int szacowanie_pozycji = porownaj('g', 'k'); 			// 14
    cout << "szacowanie_pozycji = " << szacowanie_pozycji << endl;

    constexpr int inne_szacowanie = porownaj('g', 'g');          			// 15
    cout << "inne_szacowanie = " << inne_szacowanie << endl;

    // posłużenie się obiektem globalnym (pi)
    constexpr double dl_orbity_marsa = dwa_pi_r(promien_orb_marsa); // 18

    // mogą być wywołania rekurencyjne ----------------------------
    constexpr long long silnia14 = silnia(14) ;    					// 20
    cout << "Silnia: 14! to " << silnia14 << endl;

    // rozwinięcie w szereg Taylora - nasz własny sinus -----------
    cout << "nasz_sinus(1 rad) = " << nasz_sinus(1)				// 23
                                   << " a biblioteczny sinus(1 rad) = " << sin(1) << endl;

    // obiekt globalny pi – w zamianie stopni na radiany -------------------
    cout << "nasz_sinus(45 stopni) = "
                                       << nasz_sinus(stopnie_na_radiany(45)) 						// 25
                                       << " a biblioteczny sinus(45 stopni) = " << sin(stopnie_na_radiany(45))
                                               << endl;
    // dla wtajemniczonych w tablice
    for(int i = 0 ; i < 4 ; ++i)
    {
        cout << "sinus " << i*2.5 << " stopni to = " 	<< tablica_sinusow[i] << endl;	// 27
    }
    // to u Ciebie może nie zadziałać
    constexpr double proba = sin(stopnie_na_radiany(45)); 			// 28
    // argumenty będące referencjami ====================================
    const double x = wbezwzgledna(promien_orb_marsa); 				//   // 30
    cout << "wartość bezwzgledna z promienia_orb_marsa " << x << endl;

    const double g = wbezwzgledna(poziom_zanurzenia);			// 31
    cout << "Batyskaf jest na glebokości " << g << " metrow" << endl;

    return 0;
}

//***********************************************************************************
bool  zwykla_funkcja(char pierwszy, char drugi)					// 8
{
    cout << "Dziwna sytuacja dla " << pierwszy << " i " << drugi << endl;
    return false;
}



