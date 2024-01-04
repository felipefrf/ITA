#include <iostream>
#include <string>
#include <array>
#include <sstream>
#include <iomanip>

double calculator(double a, double b, char op){
    double value;
    if (op == '+') value = a + b;
    else if (op == '-') value = a - b;
    else if (op == '*') value = a * b;
    else if (op == '/') value = a / b;
    return value;
}

void leitor(std::stringstream& entrada, double& num, std::array<double,10>a){
    char verif;
    entrada >> verif;
    if(isdigit(verif) or verif == '-'){
        entrada.seekg(-1,std::ios::cur);
        entrada >> num;
    }
    else{
        unsigned element;
        entrada.seekg(1,std::ios::cur);
        entrada >> element;
        num = a[element];
        entrada.seekg(1,std::ios::cur);
    }
}

int main(){
    std::array <double,10>x;
    std::string line;
    unsigned elemento;
    while(std::getline(std::cin,line)){ 
        std::stringstream entrada(line);
        entrada.seekg(2,std::ios::cur);
        entrada >> elemento;
        entrada.seekg(4,std::ios::cur);
        double num1;
        leitor(entrada, num1, x);
        std::streampos cursor = entrada.tellg();
        if (cursor == -1){
            x[elemento] = num1;
        }
        else{
            char op;
            entrada >> op;
            double num2;
            leitor(entrada, num2, x);
            x[elemento] = calculator(num1,num2,op);
        }
    }
    for(std::size_t i = 0; i < 10; i++){
        std::cout << "x[" << i << "] = " << std::fixed << std::setprecision(2) << x[i] << '\n';
    }
}