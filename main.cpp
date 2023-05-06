#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

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

void funkcjaVector(const std::vector<int> &wektor)//tutaj const pozwala na to żeby zmieniać wektor, tylko nie pozwala zmienić adresu wektora
{
    std::cout<<"-------------------"<<'\n';
    for(const auto elem:wektor) //tutaj const nie pozwala na to żeby zmieniać wektor
    {
        std::cout<<elem<<'\n';
    }
    std::cout<<"-------------------"<<'\n';
}

void wypiszWektor(const std::vector<std::vector<int>> &wektor)
{
    std::cout<<"-------------------"<<'\n';
    for(const auto& elem:wektor)
    {
        int i=0;
        for(i=0;i<elem.size()-1;i++)
        {
            std::cout<< std::setw(3) <<elem[i];
        }
        std::cout<< std::setw(3)<<elem[i]<<'\n';
    }
    std::cout<<"-------------------"<<'\n';
}

void wypiszTablice(int tablica[][3]){
    std::cout<<"-------------------"<<'\n';
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            std::cout<< std::setw(3) <<tablica[i][j];
        }
        std::cout<<'\n';
    }
    std::cout<<"-------------------"<<'\n';
}


void funkcjaWypisująca(const int tablica[], int rozmiar)
{
    for(int i=0;i<rozmiar;i++)
    {
        std::cout<<tablica[i]<<'\n';
        //tablica[i]=0; nie zadziała ponieważ const
    }
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
    

    std::cout<<"-------------------"<<'\n';
    char a1=0b00000000;
    do
    {
        
        std::cout<<a1<<'\n';
        a1++;
    } while (a1!=0);
    

    std::vector<int> wektor1{1,2,3,4,5};
    funkcjaVector(wektor1);

    std::vector<std::vector<int>> wektor2{{1,2,3},{4,5,6},{7,8,9}};
    wypiszWektor(wektor2);

    // napisz wektor wektorów od 1 do 15
    std::vector<std::vector<int>> wektor3{{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15}};

    wypiszWektor(wektor3);

    // Zmiana rozmiaru wektora
    std::vector<int> wektor4{1,2,3,4,5};
    wektor4.resize(10);
    funkcjaVector(wektor4);

    wektor4.push_back(6);
    funkcjaVector(wektor4);

    wektor4.pop_back();
    funkcjaVector(wektor4);
    
    int tablica3[3][3]{{1,2,3},{4,5,6},{7,8,9}};
    wypiszTablice(tablica3);

    // warunek za pomocą ?:
    int a2=3;
    int b2=4;
    std::cout<<(a2>b2 ? "a2 jest większe od b2" : "a2 jest mniejsze od b2")<<'\n';

    int tablica4[3][3]{{1,2,3},{4,5,6},{7,8,9}};
    std::cout<<**(tablica4+1)<<'\n';
    
    int tablica5[3][4][5]{{{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20}},{{21,22,23,24,25},{26,27,28,29,30},{31,32,33,34,35},{36,37,38,39,40}},{{41,42,43,44,45},{46,47,48,49,50},{51,52,53,54,55},{56,57,58,59,60}}};
    std::cout<<tablica5[1][2][3]<<'\n';
    std::cout<<*(**tablica5+33)<<'\n';

    // używanie new i delete
    int *wskaznik2=new int[5]{1,2,3,4,5};//tworzenie tablicy
    std::cout<<wskaznik2[2]<<'\n';
    delete[] wskaznik2;//usuwanie tablicy

}
