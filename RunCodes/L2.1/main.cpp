#include <iostream>
#include <sstream>
#include <string>
#include <array>
#include <iomanip>

double calculator(double a, double b, char c){
    double value;
    if (c == '+') value = a + b;
    else if (c == '-') value = a - b;
    else if (c == '*') value = a * b;
    else if (c == '/') value = a / b;
    return value;
}

double valor(std::string num, std::array<double,10>a, std::stringstream& line){
    double value;
    int position;
    if(std::isdigit(num[0]) or num[0] == '-'){
        std::streampos localizacao;
        localizacao = line.tellg();
        line.seekg(-(num.length()),std::ios::cur);
        line >> value;
    }
    else{
        std::string numero(1,num[2]);
        position = std::stoi(numero);
        value = a[position];
    }
    return value;
}

int main(){
    std::array <double,10>x;
    std::string str, palavra;
    int elemento;
    while(std::getline(std::cin, str)){
        std::stringstream entrada(str);
        entrada >> palavra;
        if(palavra[0] == 'x'){
            char ignore, operation;
            double a, b;
            std::string num1, num2;
            std::string numero(1,palavra[2]);
            elemento = std::stoi(numero);
            entrada >> ignore >> num1;
            a = valor(num1,x,entrada);
            entrada >> operation >> num2;
            entrada.seekg(0,std::ios::end);
            b = valor(num2,x,entrada);
            x[elemento] = calculator(a,b,operation);
        }
        else{
            std::string precision;
            std::string vetor;
            entrada >> vetor >> precision;
            std::string numero(1,vetor[2]);
            elemento = std::stoi(numero);
            std::cout << std::fixed << std::setprecision(std::stoi(precision)) << x[elemento] << '\n';
        }
    }
}