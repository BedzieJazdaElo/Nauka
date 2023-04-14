// Program z paragrafu 17_05_04

#include <iostream>
#include <string>
using namespace std;
int main()
{
    string  poemat;
    size_t    poprz_pojemnosc = poemat.capacity();

    for(int k = 1 ; k < 1500 ; k++)
    {
        poemat += 'A'; 			 					// dodanie jednego znaku
        // pytamy o obecną pojemność
        size_t pojemnosc = poemat.capacity();
        if(pojemnosc != poprz_pojemnosc)				// jeśli pojemność się zmieniła
        {
            cout << "Gdy liter =" << k << ", zwiekszylem pojemnosc = " << pojemnosc
                 << ", (+"
                 << (pojemnosc  - poprz_pojemnosc)
                 << ")" << endl;
            poprz_pojemnosc = pojemnosc;
        }
    }
}

