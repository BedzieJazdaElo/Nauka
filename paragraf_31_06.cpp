// Program z paragrafu 31_06


#include <iostream>
using namespace std;
//////////////////////////////////////////////////////////////////////////////////////////////
class Tsilnik
{
protected:
    int	typ;
public:
    Tsilnik(int n) : typ(n)
    {
        cout << "\tKonstruktor Tsilnika (skladnik Tsamochodu)\n";
    }
    ~Tsilnik()
    {
        cout << "\tDestruktor Tsilnika (skladnik Tsamochodu)\n";
    }
};
//////////////////////////////////////////////////////////////////////////////////////////////
class Tklimatyzacja
{
    double temperat;
public:
    int nic;
    Tklimatyzacja(double t) : temperat(t)
    {
        cout << "\t\tKonstruktor klimatyzacji (skladnik mercedesa)\n";
    }
    ~Tklimatyzacja()
    {
        cout << "\t\tDestruktor klimatyzacji (skladnik mercedesa)\n";
    }
};
//////////////////////////////////////////////////////////////////////////////////////////////
class Tsrodek_transportu
{
protected:
    double 	poz_x,								// bieżące współrzędne
            poz_y;								// 	np. geograficzne
public:
    Tsrodek_transportu()
    {
        cout << " Konstruktor Tsrodek_transportu\n";
    }
    ~Tsrodek_transportu()
    {
        cout << " Destruktor Tsrodek_transportu\n";
    }
};
//////////////////////////////////////////////////////////////////////////////////////////////
class Tsamochod : public Tsrodek_transportu
{
protected:
    int aa;
    Tsilnik    jego_silnik;
public:
    Tsamochod(int typ_silnika)  	: Tsrodek_transportu(), jego_silnik(typ_silnika) 		// 1
    {
        cout << "\tKonstruktor Tsamochodu \n";
    }
    ~Tsamochod()
    {
        cout << "\tDestruktor Tsamochodu \n";
    }
};
//////////////////////////////////////////////////////////////////////////////////////////////
class Tmercedes : public Tsamochod
{
protected:
    double xxx;
    Tklimatyzacja 	casablanca;
public:
    Tmercedes(double x, int typ_motoru, double klim) : 	xxx(x), Tsamochod(typ_motoru), 															casablanca(klim)		// 2
    {
        cout << "\t\tKonstruktor Tmercedesa\n";
    }
    ~Tmercedes()
    {
        cout << "\t\tDestruktor Tmercedesa\n";
    }
};
//*******************************************************
int main()
{
    {
        cout << "Kreacja obiektu klasy Tsamochod \n";

        Tsamochod 	czarny(500);
        cout << "\nobiekt czarny samochod istnieje \nteraz bedzie likwidowany!\n\n";
    }
    cout << "obiekt Tsamochod zlikwidowany\n\n";
    {
        cout << "Kreacja obiektu klasy Tmercedes \n";
        Tmercedes 	popielaty(6.5, 1200, 22.5);
        cout << "obiekt Tmercedes istnieje \nteraz bedzie likwidowany!\n";
    }
    cout << "obiekt Tmercedes zlikwidowany\n";
}
