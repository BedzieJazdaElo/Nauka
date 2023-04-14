// Program z paragrafu 26_15_02

#include <iostream>
#include <stdexcept>  			// dla wyjątku std::runtime_error
using namespace std;
//*******************************************************
int     operator"" _bin(const char * ciag ) 									// 1
{
    int rezultat {0};
    for(const char * wsk = ciag  ;  *wsk != 0  ;  ++wsk)
    {
        switch(*wsk)
        {
        case '1':
            rezultat = (2* rezultat) + 1;
            break;
        case '0':
            rezultat = (2* rezultat) + 0;
            break;
        default :
            char znak = *wsk;
            string  info = string {"Niepoprawny znak '"};
            info += znak;
            info += "' w zapisie stalej binarnej: ";
            (info += ciag) += "_bin";     		// inaczej: info += ciag;  info += "_bin";
            throw std::runtime_error(info);   							// 2
        }
    }
    return    rezultat;
}
//*******************************************************
int main()
{
    cout << "101_bin to dziesiatkowo " << 101_bin << endl; 					// 3
    cout << "111_bin to dziesiatkowo " << 111_bin << endl;
    cout << "11111111_bin to dziesiatkowo " << 11111111_bin << endl;

    //  1118111_bin;     // to byłby błąd   									// 4

    int wyrazenie = (1111_bin + 10)  * 101_bin;   // czyli (15 + 10) * 5 			// 5
    cout << "wyrazenie = " << wyrazenie << endl;
}
