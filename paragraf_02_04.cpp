// Program z paragrafu 2.4
 #include <iostream>
	using namespace std;
	int main()
	{
		char litera;
		do {
			cout << "Napisz jakas litere: ";
			cin >> litera;
			cout << "\n Napisales: " << litera << " \n";
		}while(litera != 'K'); 										// `1

		cout << "\n Skoro napisales K to konczymy !";
	}
