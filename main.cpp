#include <iostream>
#include <vector>

int orzel;

int main()
{
    int orzel;
    std::cout << "orzeł";
    //static_assert(1 == 2, "niedobry orzel");
    ::orzel; // to jest górny orzeł

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

    // i tak se moge zmieniać XD
}