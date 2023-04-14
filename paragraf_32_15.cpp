// Program z paragrafu 32_15


  #include <iostream>
 using namespace std;
 #include <cstring>

 struct Tpospolita_dana
 {
	int a;
	double b;
	char  tekst[30];
 };

 int main()
 {
	constexpr int rozm = 22;
	Tpospolita_dana tablica[rozm];
	// załadowanie sensowną treścią
	for(int i = 0 ; i < rozm; ++i)
	{
		tablica[i].b = i; ///10.0;
		//...
	}
	Tpospolita_dana archiwalna[rozm];

	// zrobienie archiwalnej kopii
	memcpy(archiwalna, tablica, sizeof(tablica) );

     // wydruk dla sprawdzenia
	for(auto &elem: archiwalna)
	{
		cout << elem.b<< " ";
	}

	cout << is_pod<Tpospolita_dana>::value << endl;
 }
