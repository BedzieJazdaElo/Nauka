// Program z paragrafu 05_01

#include <iostream>
 #include <string>					 								// 1
 using namespace std; 												// 2
//****************************************************************
 int main()
 {
	string 	solar {"Panel-sloneczny"}; 								// 3
	string 	antena ("Antena");										// 4

	cout << "Napisz, jak masz na imie: ";
	string imie;						// wstępnie pusty				// 5
	cin >> imie;
	cout << "Sterowanie sonda kosmiczna przejal wlasnie " << imie << endl;
	if(imie == "Jurek")												// 6
	{
		cout << "(To jest najgorszy pilot)\n";
	}

	string rozkaz;
	rozkaz = "Naprawic " + solar;							 			// 7
	string komunikat = antena + " dziala poprawnie";	// "Antena dziala poprawnie"

	rozkaz += " natychmiast"; 			// doczepienie do końca 		// 8
	cout << rozkaz << endl;

	rozkaz = komunikat;											// 9
	cout << rozkaz << endl;

	string raport = "Alfabetycznie wczesniej jest: ";
	if(solar < antena)												// 10
			raport += solar;
	else
			raport += antena; 										// 11
	cout << raport << endl;

	komunikat = "Sprawdzone juz zostaly segmenty: ";
	for(int nr_segm = 39 ; nr_segm < 42 ; ++nr_segm)	 				// 12
	{
		string  liczba_tekstowo  =  to_string(nr_segm); 					// 13
		string  element  =  antena + liczba_tekstowo; 					// 14

		string nazwa_pliku  =  element + ".txt";							// 15
		cout << " Test segmentu " << nr_segm << " zapisany w pliku c:\\"
			 << nazwa_pliku << endl; 								// 16

		komunikat +=	  ( element + ", " ); 								// 17
	}
	cout << komunikat << endl;										// 18

	//------------------
	string info = " NIE DZIALA  Antena satelitarna ";						// 19

	// tworzenie tekstu alarmowego w ramce
	int szer = info.size() + 6; 										// 20
	string kreska (szer, '*'); 											// 21

	string alarm = kreska + "\n";										// 22
	alarm += "*!*" + info + "*!*\n";
	alarm += kreska;
	cout << alarm << endl;
 }
