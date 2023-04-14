// Program z paragrafu 34_01

#include <iostream>
#include <fstream>
using namespace std;
//*******************************************************
int main()
{
    ofstream osrodek; 										// etap // 1
    osrodek.open("mars.tmp"); 								// etap // 2
    osrodek << "misja"; 									// etap // 3
    osrodek.close(); 										// etap // 4
}

