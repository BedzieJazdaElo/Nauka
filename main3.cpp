#include<iostream>

int dodawanie(const int &a, const int &b)
{
    return a+b;
}

int odejmowanie(const int &a, const int &b)
{
    return a-b;
}

int main(int argc,char** argv){

    int (*funkcja)(const int&,const int&)=&dodawanie;// lepiej dawać &dodawanie, ale można też bez
    std::cout<<funkcja(1,2)<<std::endl;

}