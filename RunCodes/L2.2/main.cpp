#include <iostream>

int main(){
    //ler os valores de entrada
    unsigned num1, num2;
    std::cin >> num1 >> num2;

    //escolher num1 como o maior entre as duas entradas
    if (num1 < num2) {
        unsigned num3;
        num3 = num1;
        num1 = num2;
        num2 = num3;
    }

    //reproduzir o algoritmo de euclides
    unsigned resto;
    while(true){
        resto = num1%num2;
        if(resto == 0){
            std::cout << num2 << '\n';
            break;
        }
        num1 = num2;
        num2 = resto;
    }
}