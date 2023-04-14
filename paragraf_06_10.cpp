// Program z paragrafu 06_10

 #include <iostream>
 using namespace std;
 //*********************************************
 void fun_przez_wartosc(int wart) ;
 void fun_referencja_Lwartosci(int & przezwisko_lwartosci);
 void fun_referen_constLwartosci(const int & przezwisko_stalej_lwartosci);
 void fun_referencja_Rwartosci(int && przezwisko_wart_chwilowej);
 //*********************************************
 int main ()
 {
	int obj  = 40;   			 				//  obj jest lwartością     	// 2
	// A------------
	fun_przez_wartosc(obj);										// 3
	cout << "   main: obj = " << obj << endl;   							// 4
	fun_przez_wartosc(80+1); 										// 5
	cout << "\n" ;
	// B ------------
	fun_referencja_Lwartosci(obj);              							// 7
	cout << "   kontrola, w main obj = " << obj << endl;  					// 8
	// fun_referencja_Lwartosci(80+2);   							// 9			cout << "!  fun_referencja_Lwartosci(80+2) - niemozliwe wyslanie rwartosci \n\n" ;
	// C ------------
	fun_referen_constLwartosci(obj);									// 11
	fun_referen_constLwartosci(80+3);     // ale jeśli jest przydomek const - to wolno.	// 12
	const int & przezwisko_stalej_lwartosci = (80+3);  // inny dowód, że wolno 		// 13
	cout << "\n" ;
	// D ------------
	// fun_referencja_Rwartosci(obj); // niemożliwe, podobnie jak: int && rr = obj; 	// 16
	cout << "!  fun_referencja_Rwartosci(obj) - niemozliwe wyslanie lwartosci\n" ;
	fun_referencja_Rwartosci(80+4); 	// czyli int && rr2 = (80+4)		// 17
	int && rr2 = (80+4);			// inny dowód, że wolno
 }
 void fun_przez_wartosc(int wart)   										// 1
 {
	++wart;    // inkrementacja lokalnej kopii
	cout << "A. fun_przez_wartosc  odebrala arg. przez wartosc i teraz = " << wart << " \n";
 }
 void fun_referencja_Lwartosci(int & przezwisko_lwartosci)   					// 6
 {
	cout << "B. fun_referencja_Lwartosci(" << przezwisko_lwartosci
		<< ")   odebrala arg. jako ref. lwartosci\n";
	++przezwisko_lwartosci ;				// inkrementacja oryginału
 }
 void fun_referen_constLwartosci(const int & przezwisko_stalej_lwartosci) 		// 10
 {
	cout << "C. fun_referen_constLwartosci("<< przezwisko_stalej_lwartosci
		<< ") odebrala arg jako ref. stalej lwartosci\n";
 	// inkrementacja zabroniona, bo to referencja do const
}
 //*********************************************
 void fun_referencja_Rwartosci(int && przezwisko_wart_chwilowej) 			// 14
 {
	cout << "D. fun_referencja_Rwartosci odbierajaca argument jako ref.  rwartosci \n";

	 // inkrementacja czegoś, co jest traktowane jako (chwilowa, zatem nieistotna) rwartość
	++przezwisko_wart_chwilowej ; 										// 15
 }
