#include<iostream>

int main(){
    char name[4]{ 'A', 'B', 'C', '\0'};
    std::cout<<"Adres: "<<static_cast<void *>(&name)<<std::endl;
    std::cout<<"Wartosc: "<<name<<std::endl;
}