// Program z paragrafu 06_18


#include <iostream>
#include <string>
using namespace std;

int    globalny_jedynkowy = 25;
int    globalny_inny = 77;
//****************************************
int f_wartosc(int ktory)    		// rezultat jest rwartością (po prostu liczbą) 	// 1
{
    int lokalny = 4;   												// 2
    // return lokalny;    			// niby poprawne, ale za łatwe! 			 // 3
    // wolimy tak:
    if(ktory == 1)	return   globalny_jedynkowy;
    else			return   globalny_inny;
}
//****************************************
int &   f_ref_lwartosci(int ktory) 		// rezultat jest przezwiskiem jakiegoś obiektu
{
    int lokalny = 4;
    // return lokalny;    			// tego zwracać przez referencję nie wolno! // 4

    if(ktory == 1)	return globalny_jedynkowy;
    else			return globalny_inny;
}

//****************************************
void wypisz(string txt, int a)   				//  funkcja wyświetlająca
{
    cout	<< txt;
    if(a) 	cout << a  << ", ";
    cout << "globalny_jedynkowy = " << globalny_jedynkowy
         << ", globalny_inny = "  << globalny_inny << endl;
}
//****************************************
int main ()
{
    int n {0};  														// 5
    // Po staremu.
    n = f_wartosc(1);       		// odpowiada: 	n = globalny_jedynkowy;  	// 6
    wypisz("rezultat= ", n);
    n = f_wartosc(6); 			// czyli: 			n = globalny_inny;  	// 7
    wypisz("rezultat= ", n);
    //...cdn.


    n = f_ref_lwartosci(1);
    wypisz("Rezult2 = ", n);
    n = f_ref_lwartosci(6); 				// czyli to samo co:   n = globalny_inny;
    wypisz("Rezult2 = ", n);


    cout << "To wywołanie możemy postawic takze po lewej stronie\n";
    // ponieważ rezultatem jest ref do lwartości (czyli obiektu), więc możemy użyć go tak:
    f_ref_lwartosci(1)  = 5000;   	// czyli: globalny_jedynkowy = 5000; 	// 8
    wypisz("Czy wpisalismy? " , 0);
    f_ref_lwartosci(6)  = 8000;  		// czyli: globalny_inny = 8000;  	// 9
    wypisz("Czy wpisalismy? " , 0);

} // koniec funkcji main
