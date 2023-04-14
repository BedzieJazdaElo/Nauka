// Program z paragrafu 12_04_08

#include <iostream>
using namespace std;
//********************************************************************
int main()
{
int *czerwony, *zolty;						// definicja dwóch wskaźników	`1

	czerwony = new int;					// tworzymy obiekt A 		`2
	zolty = new int;						// tworzymy obiekt B

	*czerwony = 100;						// ładujemy 100 do obiektu A  	`3
	*zolty = 200;							// ładujemy 200 do obiektu B

	cout << " Po wpisaniu: Na czerwonym = "<< *czerwony
		<< " Na zoltym = " << * zolty << endl;

	czerwony = zolty; 	 					// <$[symbol><@172><@190><$]symbol> Niefortunna linijka !  	`4

	cout << " Po przelozeniu - Na czerwonym = "<< *czerwony
		<< " Na zoltym = " << * zolty << endl;

	*czerwony = 5;
	*zolty = 1; 												 	// `5

	cout << " Jakis wpis - Na czerwonym = "<< *czerwony
		<< " Na zoltym = " << * zolty << endl;

	delete zolty; 	 												// `6
	// delete czerwony;				// Horror !
}
