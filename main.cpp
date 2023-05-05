#include <iostream>
#include <vector>
#include <string>

int orzel;


namespace{
    // anonimowa przestrzeń nazw
}

void funkcja123(int a[5])
    {
        std::cout<<a[0]<<'\n';
        std::cout<<*(a+1)<<'\n';
    }

void strcpy(char *a, char *b)
{
    while (*a++ = *b++);
}

int main()
{
    int orzel;
    std::cout << "orzeł";
    // static_assert(1 == 2, "niedobry orzel");
    // to jest górny orzeł

    int pawel = 1;
    float monia = 3.14;
    int gruzio = static_cast<int>(monia); // lub int gruzio=monia;
    int gruzia = static_cast<int>(monia); // tu już tylko tym

    // dynamic_cast//to samo co wyżej tylko też w czasie programu

    // const_cast//wskazniki do wartości stałych itp
    // reinterpret_cast//rózne wskazniki do roznych wskazników

    std::vector<int> wektor{1, 2, 3, 4};
    for (auto element : wektor)
    {
        std::cout << element << '\n';
    }

    auto orzelowa_funkcja(int kruczek, float pluczek)->decltype(kruczek);
    // funkcja w inny sposób napisania i bardziej służy
    // do szablonów funkcji (ogółem to potem)

    // i tak se moge zmieniać

    // alignas do wyrównywania adresów i też jest alignof

    // OPERATORY RZUTOWANIA
    // static_cast<>() zwykle rzutowanie
    // const_cast wysylanie wskaznika od zmiennej const
    // dynamic_cast w trakcie dzialania programu sprawdza
    // reinterpret_cast do wskaźników
    
    std::string astring="orzel";
    std::cout<<astring<<'\n';

    // zakresowe for
    std::vector<int>wketro{1,2,3,4,5};
    for(auto elem:wketro)
    {
        std::cout<<elem<<" orzel"<<'\n';
    }


    static int zmienna =3;//że się ona zachowuje i nie jest na stosie

    auto zmienna1=zmienna;
    
    #define wartosc 3//to jest makrodefinicja
    std::cout<<wartosc<<'\n';
    #undef wartosc//to usuwa definicje

    #define suma(a,b) (a+b)//to jest makrodefinicja funkcji
    std::cout<<suma(3,4)<<'\n';

    #define zmienna(a,b) zmienna_##a##_##b//to jest konkatenacja
    int zmienna(jasna,dupa)=3;//to jest zmienna_jasna_dupa

    
    

    int tablica[5]={1,2,3,4,5};
    funkcja123(tablica);

    // kopiowanie stringu za pomocą funkcji strcpy
    char a[]="orzel";
    char b[6];
    strcpy(b,a);
    std::cout<<b<<'\n';

    int tablica1[5][2]={1,2,3,4,5,6,7,8,9,10};
    std::cout<<tablica1[1][1]<<'\n';
    std::cout<<*(*tablica1+3)<<'\n';
    std::cout<<&tablica1[2][1]<<'\n';//to jest adres
    std::cout<<tablica1[2]+1<<'\n';//to jest adres
    std::cout<<*(tablica1+2)+1<<'\n';//to jest adres
    std::cout<<*(*(tablica1+2)+1)<<'\n';//to jest wartość

    


}
