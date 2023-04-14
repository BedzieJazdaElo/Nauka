// Program z paragrafu 27_05


#include <iostream>
using namespace std;
//////////////////////////////////////////////////////////////////////////////////////////////
class Tab_calkow
{
    int a[100];
public:
    // deklaracja funkcji operatorowej
    int &   operator[ ](unsigned int ktory)		//<-- tutaj cała tajemnica
    {
        return a[ktory];
    }
};
//////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
    Tab_calkow t;

    for(int i = 0 ; i < 100 ; ++i)   t[i] = 100 + i;		// załadowanie tablicy
    t[1] = t[2] + 50 + t[3];						// pracujemy tak jak na zwykłej tablicy!

    cout	<< "Mamy kolejno " << t[0] << ", " << t[1] << ", " << t[2]<< ", " << t[3] << " itd...";
}
