#include <iostream>
#include <vector>
#include <string>

int orzel;


namespace{
    // anonimowa przestrzeń nazw
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
    

}
