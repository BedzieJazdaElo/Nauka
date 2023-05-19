#include <iostream>
#include <stdio.h>

void f(char** namePtr){
    std::cout<<&namePtr<<std::endl; // wyświetla adres wskaźnika 'namePtr' w funkcji 'f' 
    std::cout<<namePtr<<std::endl; // wyświetla adres oryginalnej zmiennej 'name' w funkcji 'main'
    std::cout<<*namePtr<<std::endl; // wyświetla ciąg znaków, na który wskazuje 'name'
    (*namePtr)+=2; // zwiększa wskaźnik 'name'
    // wyświetl mi adres zmiennej 'name' w funkcji 'main' za pomoca funkcji 'printf'
}

int main(){
    char* name="John";
    std::cout<<&name<<std::endl; // wyświetla adres zmiennej 'name' w funkcji 'main'
    f(&name); // wywołuje funkcję 'f' z adresem 'name' jako argumentem
    std::cout<<&name<<std::endl; // wyświetla adres zmiennej 'name' w funkcji 'main'
}
