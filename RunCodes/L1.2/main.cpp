#include <iostream>
#include <iomanip>
#include <string>

int main(){
    double input, soma = 0;
    int i = 0;
    while(std::cin >> input){
        soma += input;
        i++;
    }
    std::cout << std::fixed << std::setprecision(3) << soma/i << "\n";
}