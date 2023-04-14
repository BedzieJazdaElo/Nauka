// Program z paragrafu 05_02
 #include <iostream>
 #include <vector>					 									// 1
 #include <string>
 using namespace std; 													// 2
//************************************************************
 int main()
 {
		vector<int> ww { 9,  4,  7,  -6,  2,  7 };								// 3
		cout << "ww[1]= " <<   ww[1]   << endl; 							// 4

		int rozmiar = ww.size();											// 5
		cout << "Wektor ww ma elementów " << rozmiar << endl;

		for(unsigned int i = 0 ; i < ww.size() ; ++i) {									// 6
			cout << ww[i] << ", " ;										 // 7
		}
		cout << endl;

		int b = ww[4] + 500;					// 2 + 500				// 8
		ww[2] = ww[3] * 10;					// –6 * 10				// 9
		cout << "b = " << b << " ww[2] = " << ww[2] << endl;

		cout << "Obecna zawartosc wektora ww: " << endl;
		for(unsigned  int nr = 0 ; nr < ww.size() ; ++nr)								// 10
		{
				cout << "ww[" << nr << "] = " << ww[nr];
				if(ww[nr] == 2) {										// 11
					 		cout << "	<->dwa!";
		 		}
				cout << endl;
		}
		// ciąg dalszy programu nastąpi  poniżej...

				vector<int> m; 												// 12
		vector<char> symbole(10);										// 13
		vector<char> litery(12, '.');				 						// 14

		cout << "Tresc wektora litery:\n";
		for(unsigned int i = 0 ; i < litery.size() ; ++i)	  cout << litery[i];
		cout << endl;

		litery[0]   = 'M';												// 15
		litery[6]   = 'B';
		litery[10] = 'X';

		for(unsigned int i = 0 ; i < litery.size() ; ++i)  cout << litery[i] ;
		cout << endl;
 // ciąg dalszy programu nastąpi  poniżej...

		// ciąg dalszy programu
		vector<string> fizycy { "G. Galilei", "I. Newton", "A. Einstein" }; 			// 16

		vector<string> muzycy; 											// 17
		cout << "a) muzycy.size() = " << muzycy.size() << endl;

		muzycy.push_back("Chopin");									// 18
		cout << "b) muzycy.size() = " << muzycy.size() << endl;				// 19

		muzycy.push_back("Lutoslawski");
		muzycy.push_back("Debussy");

		for(unsigned int i = 0 ; i < muzycy.size() ; ++i)								// 20
		{
			cout << "muzycy[" << i << "] to: " << muzycy[i] << endl;
		}

		// zamiana treści
		muzycy[1] = "Moniuszko";		 								// 21
		muzycy[2] = muzycy[0];		 									// 22
		cout << "Podaj samo nazwisko kompozytora: "; 						// 23
		string ulubiony;
		cin >> ulubiony;
		muzycy.push_back(ulubiony);	 								// 24

		for(unsigned int i = 0 ; i < muzycy.size() ; ++i)    cout << muzycy[i] << ", ";
		cout << endl;
 }
