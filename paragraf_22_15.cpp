// Program z paragrafu 22_15

#include <iostream>
#include <vector>
using namespace std;
////////////////////////////////////////////////////////////////////////////////////////////////////////
struct Ts
{
    double skladnik; 													// 1
};
////////////////////////////////////////////////////////////////////////////////////////////////////////
int 		funkcja_zw() 		{
    cout << "pracuje funkcja_zw " << endl;     // 2
    return 5;
}
int & 	funkcja_ref(int& arg)  	{
    cout << "pracuje funkcja_ref " << endl;     // 3
    return arg;
}
int && 	funkcja_xv()  		{
    cout << "pracuje funkcja_xv " << endl;    // 4
    return 7;
}
//*******************************************************************5]>
int main()
{
    int zmienna = 10;    											// 5
    int &refzm = zmienna;   // zwykła referencja (lwartości) 				// 6
    int innyint = 1;
    double x = 1.1;
    int *wskint = &innyint;

    // decltype w wariancie pierwszym #####################################
    decltype(zmienna)   obj_a;  				// obj_a jest typu int 		// 7

    Ts obiekt; 														// 8
    decltype (obiekt.skladnik) obj_b1 = 2.3;  		// typ to double 			// 9

    Ts * wsk = new Ts; 												// 10
    decltype (wsk->skladnik) obj_b2 = 2.3;   		// typ to double 			// 11

    // decltype w wariancie drugim ########################################

    // argumentem jest wyrażenie typu prwartość (czysta rwartość) ––––––––––––––
    decltype(zmienna*3.14)  obj_c;   	    	// typ to double  				// 12

    // argumentem jest wyrażenie typu lwartość –––––––––––––––––––––––––––––
    decltype(*wskint)  eee = zmienna;     	// typ to int& (musi być inicjalizacja)  	// 13
    ++eee;
    cout << "eee = " << eee << ", zmienna = " << zmienna << endl;

    // wartość wygasająca (tzw. xwartość), którą wolno rozmontować –––––––––––
    decltype( std::move(zmienna) ) ggg = (6+4);  	   // typ to int&&  		// 14

    // trzecia postać decltype – z wywołaniem funkcji ########################
    decltype(funkcja_zw() )   obj_d;  					// typ to int 		// 15

    decltype(funkcja_ref(zmienna) ) fff = innyint;   			// typ to int&   		// 16
    ++fff;
    cout << "fff = " << fff << ", inna = " << innyint << endl;

    decltype(funkcja_xv()) hhh  = (2+1);      			// typ to int&& 		// 17

    // obiekt i składnik w podwójnym nawiasie, to tak jak lwartość ##############
    decltype((zmienna))  iii = obj_a; 	   				// typ to int&  		// 18

    decltype ((wsk->skladnik)) jjj = x;  					// typ to double &  		 // 19
    jjj += 66;
    cout << "jjj = " << jjj << ", x = " << x << endl;
}
