// Program z paragrafu 17_06_02


#include <iostream>
#include <string>
using namespace std;
int main()
{
    string tabliczka("Palenie Wzbronione");
    cout << "Ktora pozycje stringu " << tabliczka << " chcesz odczytac? :";
    size_t poz;
    cin >> poz;

    // sprawdzamy poprawność
    if(poz >= 0 && poz < tabliczka.size())
    {
        cout << "Na tej pozycji stoi znak: " << tabliczka.at(poz) << endl;
    }
    else
    {
        cout << "To jest niepoprawna pozycja " << endl;
    }
}
