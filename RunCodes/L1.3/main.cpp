#include <iostream>
#include <string>
#include <iomanip>
#include <cstdio>

int main(){
    double a, c;
    std::string b;
    if (!(std::cin >> a >> b >> c)){
        std::cout << "ERR\n";
    }
    else if(b == "/") std::cout << std::fixed << std::setprecision(1) << a/c << "\n";
    else if(b == "*") std::cout << std::fixed << std::setprecision(1) << a*c << "\n";
    else if(b == "+") std::cout << std::fixed << std::setprecision(1) << a+c << "\n";
    else if(b == "-") std::cout << std::fixed << std::setprecision(1) << a-c << "\n";
    else std::cout << "ERR\n";
}
