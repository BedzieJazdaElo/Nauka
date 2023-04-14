// Program z paragrafu 37_02

 #include <iostream>
 using namespace std;
 template <typename T>    												// 1
 class Tschowek
 {
	T sejf;
 public:
	void schowaj(T x) { sejf = x; }
	T oddaj() { return sejf; }
 };
 //********************************************************************
 int  main()
 {
	Tschowek<double>   g;  											// 2
	g.schowaj(9.81);
	double wart = g.oddaj();
	cout << "Wartosc wyjeta z czynnika g = " << wart << endl;

	Tschowek<string>  tekstowy;										// 3
	tekstowy.schowaj("Ogary poszly w las z radosnym psim halasem");
	cout	<< "W schowku tekstowym = " << tekstowy.oddaj()	<< endl;

	Tschowek<string> podpis; 											// 4
	podpis.schowaj("Jeremi P.");
 }
