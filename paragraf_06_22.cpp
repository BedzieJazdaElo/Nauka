// Program z paragrafu 06_22
 #include <iostream>
#include <string>
using namespace std;
double zielony = 1.1, czerwony = 2.2, niebieski = 7.7; // zmienne globalne 	// 1
//******************************************************************
double &  fun_referencja_zwykla(int nr)								// 2
{
    if(nr == 1) 			return zielony;
    else if (nr == 2) 		return czerwony;
    else 				return niebieski;
}
//****************************************************************
const double &  fun_referencja_const(int nr) 							// 3
{
    if(nr == 1) 		return zielony;
    else if (nr == 2) 	return czerwony;
    else 			return niebieski;
}

//********************************************************************

void porownaj_je(const double & a, string opis1, const double &b, string opis2) 	// 4
{
    cout << opis1 << " = " << a << ", " << opis2 << " = " << b << ". ";

    cout << "Ich adresy sa "
         << ((&a == &b)? "Identyczne (referencja)" : "rozne (kopia)") 		// 5
         << endl;
}

//*******************************************************************
int main()
{
    double 			d 	= 5.5; 		// zwykły obiekt 				// 6
    double & 		rd 	= d; 				// przykładowa referencja 		// 7
    const double & 	crd = d; 			// przykładowa referencja do stałej 	// 8

    //------------------------Czy tak powstaną referencje ?
    auto v1 = d; 			// v1 jest typu double - (czyli to kopia obiektu d) 	// 9
    auto v2 = rd;			// v2 jest typu double 						// 10
    auto v3 = crd; 			// v3 jest typu double						// 11

    d = -20;														// 12
    porownaj_je(v1, "v1", d, "d "); 									// 13
    porownaj_je(v2, "v2", rd, "rd ");
    porownaj_je(v3, "v3", crd, "crd");

    //---------------------------------------------------------------------------
    cout << "--- Tworzymy prawdziwe referencje " << endl;

    auto & 	ref_d 	= d; 						// double& // 14
    auto & 	ref_rd 	= rd; 					// double& 		// 15
    auto & 	ref_crd 	= crd; 					// const double & 		// 16
    // to const powyżej kompilator narzucił, by nie było przestępstwa
    d = -40; 														// 17
    porownaj_je(ref_d, "ref_d ", d, "d "); 								// 18
    porownaj_je(ref_rd, "ref_rd ", rd, "rd ");
    porownaj_je(ref_crd, "ref_crd", crd, "crd");

    ref_rd = 177; 				// tak się da, bo to zwykła referencja 		// 19
    // ref_crd = 1000000 ; 		// za pomocą ref. do stałej – przypisanie niemożliwe // 20

    cout << "Po probach przypisania przy użyciu obu (zwykłych) referencji" << endl;
    porownaj_je(ref_rd, "ref_rd ", rd, "rd "); 							// 21
    porownaj_je(ref_crd, "ref_crd", crd, "crd");

    // chcemy stworzyć referencje do stałej, to musimy napisać const
    const auto & 	cref_rd 	 	= rd; 			// const double& 		// 22
    const auto & 	cref_crd 		= crd; 			// const double &		// 23
    rd = 6.6; 														// 24
    // cref_rd = 0; 			// niemożliwe, więc to rzeczywiście stała referencja
    // cref_crd = 0;	 	// niemożliwe, więc to rzeczywiście stała referencja

    cout << "Po probach przypisania przy użyciu obu (stalych) referencji" << endl;
    porownaj_je(cref_rd, "cref_rd ", rd, "rd "); 							// 25
    porownaj_je(cref_crd, "cref_crd", crd, "crd");

    //=============================================
    cout << "\nTo samo, gdy w wyrażeniu inicjalizującym jest wywolanie funkcji" << endl;
    auto w2 = fun_referencja_zwykla(15); 			// double			// 26
    auto w3 = fun_referencja_const(15); 			// double			// 27

    w2 = 11.1;
    w3 = 12.1;

    porownaj_je(w2, "v2", niebieski, "niebieski");
    porownaj_je(w3, "v3", niebieski, "niebieski");

    cout << " Tworzymy prawdziwe referencje i inicjalizujemy wartosciami funkcyj" << endl;
    auto &  ref_niebfz 	= fun_referencja_zwykla(15);  		// double& 	// 28
    auto &  ref_niebfc 	= fun_referencja_const(15);  		// const double & 	// 29

    ref_niebfz = 5.5;
    // ref_niebfc = 2.2;

    porownaj_je(ref_niebfz, "ref_niebfz ",niebieski, "niebieski");
    porownaj_je(ref_niebfc, "ref_niebfc", niebieski, "niebieski");
    ref_niebfz = 2;
    // ref_niebfc = 3; 			// błąd

    cout << " Gdy w definicji napiszemy const auto & " << endl;

    const auto & 	c_ref_niebfz 	= fun_referencja_zwykla(15); 	// double& 		// 30
    const auto & 	c_ref_niebfc 	= fun_referencja_const(15); 		// const double &	// 31

    niebieski = 120.2 ;

    porownaj_je(c_ref_niebfz, "c_ref_niebfz ",niebieski, "niebieski");
    porownaj_je(c_ref_niebfc, "c_ref_niebfc", niebieski, "niebieski");
    // c_ref_niebfz = 2;				// błąd
    // c_ref_niebfc = 3; 			// błąd
}
