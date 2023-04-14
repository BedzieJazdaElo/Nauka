// Program z paragrafu 20_01

#include <iostream>
using namespace std;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Tzewn 															// 1
{
    int 	priv_a; 														// 2
    using  Tznak = char; 												// 3

    //  A  Pierwszy sposób: definiowanie klasy składowej (prawdziwe zagnieżdżenie)
    class Twew  							// ************   				// 4
    {   //		***
        double priv_x { 3.14}; 				//  	 	   ***
        static int skladnik; 					// 	 	***					// 5
    public: 								// 		 	***
        void funwew1();					// 		 	***					// 6
        void funwew2();					// 		 	***					// 7
    }; 									// ************

    // Poniżej jest błąd, bo tutaj funkcji składowej klasy Twew nie wolno definiować	// 8
    // 	void Twew::funwew1()
    // 	{
    // 	}

    //  B  Drugi sposób: deklarowanie (zapowiadające) klasy składowej
    class Tluzak;		// <-- sama deklaracja, więc typ „niekompletny” (na razie)		// 9

    Twew  objwewn; 													// 10
    // Tluzak  obiekt;		// zwykły obiekt niemożliwy, bo typ niekompletny  		// 11
    Tluzak  *wskluz;  		// do definicji wskaźnika typ niekompletny wystarcza 	// 12
public:
    void skl();   														// 13
};
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// poprawne miejsce definicji funkcji składowej klasy zagnieżdżonej
//*******************************************************************
void  Tzewn::Twew::funwew2()				 							// 14
{
    // uwaga: tu nie ma czegoś takiego jak bieżący obiekt klasy Tzewn
    Tzewn  zorro;
    zorro.priv_a = 4; 	// praca z (prywatnym!) składnikiem klasy zewnętrznej 		// 15
    cout << "   Tzewn::Twew::funwew2()  ->  zorro.priv_a = " << zorro.priv_a << endl;
}
//*******************************************************************
int  Tzewn::Twew::skladnik = 66;											// 16
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Tzewn::Tluzak   													// 17
{
    int priv_m;
public:
    void fun_luz() 														// 18
    {   // uwaga: tu nie ma czegoś takiego jak bieżący obiekt klasy Tzewn
        // musimy taki obiekt dopiero wytworzyć
        Tzewn zew;  													// 19
        // czy stąd możliwa praca z prywatnym składnikiem obiektu klasy zewnętrznej?
        zew.priv_a = 8;   					// możliwa! 					// 20
        cout << "   Tzewn::Tluzak::funluz()  ->  zew.priv_a = " << zew.priv_a << endl;

        Tznak z = 'm';   												// 21
    }
};
//*******************************************************************
void Tzewn::skl()														// 22
{
    cout << "Tzewn::skl() " << endl;
    // czy mamy dostęp do prywatnego składnika obiektu typu zagnieżdżonego?
    // objwewn.priv_x = 1.1;   		// niemożliwe, bo składnik x jest prywatny 		// 23
    objwewn.funwew2(); 				// publiczna funkcja  					// 24

    wskluz = new Tluzak;			// możliwe dopiero poniżej definicji klasy Tluzak	 // 25
    // wskluz->priv_m = 3;   		// niemożliwe  						// 26
    wskluz->fun_luz(); 	  			// publiczna funkcja 					// 27
    delete wskluz;
}
//*******************************************************************
int main()
{
    Tzewn obiektB;  													// 28
    obiektB.skl();
}
