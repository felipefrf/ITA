#include <iostream>
#include <string>

void palindromo(std::string str, int i){
    int tamanho = str.length();
    if(str[i] == str[tamanho-1-i]){
        i++;
        if(i == tamanho/2) std::cout << "true" << '\n';
        else palindromo(str, i);
    }
    else std::cout << "false" << '\n';
}

int main(){
    std::string entrada;
    while(std::getline(std::cin, entrada)){
        palindromo(entrada,0);
    }
}