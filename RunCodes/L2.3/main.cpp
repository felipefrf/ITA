#include <iostream>

unsigned euclides(unsigned a, unsigned b){
    unsigned resto;
    resto = a%b;
    if(resto==0){
        std::cout << b << '\n';
        return 0;
    }
    euclides(b,resto);
    return 0;
}

int main(){
    unsigned num1, num2;
    std::cin >> num1 >> num2;

    if (num1 < num2) {
        unsigned num3;
        num3 = num1;
        num1 = num2;
        num2 = num3;
    }

    euclides(num1,num2);
}