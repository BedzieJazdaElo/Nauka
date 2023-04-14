// Program z paragrafu 30_02


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>   				// dla funkcji count_if
using namespace std;

int main()
{
    vector<int>  v { 4, 2, 13, 11, 5, 24, 7 };
    //  przygotujmy sobie iteratory
    auto pocz = v.begin();
    auto kon = v.end();
    cout << "Uzywajac wyrazen lambda, ustalamy, ze w wektorze v:" << endl;

    int ile = count_if(pocz, kon,  [ ] (int liczba )  {
        return(liczba%2);
    } ); 			// 1
    cout << "\tNieparzystych liczb jest " << ile << endl;

    ile = count_if(pocz, kon, [ ] (int liczba) {
        return (liczba>9);
    } ); 			// 2
    cout << "\tLiczb > 9 jest " << ile << endl;

    for(int k = 3; k < 6 ; k++)
    {
        ile = count_if(pocz, kon, [k] (int liczba) {
            return (liczba > k);
        }  );  		// 3
        cout << "\t\tLiczb > " << k << " jest " << ile << endl;
    }
    cout << "Ciekawostka, wyrazenie lambda nie musi byc wysyłane do funkcji..." 	<< endl;

    [ ] (string txt)  {
        cout << "Lambda: Przyslano mi " << txt << endl;
    }  ("argo");		// 4
}
