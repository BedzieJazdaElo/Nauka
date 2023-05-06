#include <iostream>

int main()
{
    std::cout << "Hello, World!" << std::endl;
    int** p = new int*[10];//p to tablica wskaznikow na tablice
    for (int i = 0; i < 10; i++)//tworzenie tablicy
    {
        p[i] = new int[10]{1,2,3,4,5,6,7,8,9,10};
    }
    std::cout<<p[1][5]<<std::endl;

    for (int i = 0; i < 10; i++)//usuwanie tablicy
    {
        delete[] p[i];
    }

    //inny sposob
    int (*tablica)[10] = new int[8][10]{};//tablica wskaznikow na tablice
    std::cout<<tablica[1][5]<<std::endl;
    
}