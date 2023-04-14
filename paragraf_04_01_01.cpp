// Program z paragrafu 04_01_01

#include <iostream>
 using namespace std;
 int main()
 {
	int i;
	for(i = 0 ; i < 32 ; i = i + 1)
	{
		if(i % 8)													// 1
			cout << "\t"; 				// wypis tabulatora			// 2
		else
			cout << "\n";	 			// przejście do nowej linii <N>		// 3

		cout << i;													// 4
	}
 }
