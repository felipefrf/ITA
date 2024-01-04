#include <cctype>
#include <iostream>
#include <iomanip>
#include <array>

int main(){
    std::array<char,32> x;
    std::size_t n = 0;
    int value = 0;
    while(n <= 32 and std::cin >> std::noskipws >> x[n]){
        if (std::isspace(x[n]) != 0 and value == 1) continue;
        if(std::isspace(x[n]) != 0){
            value += 1;
            while (n > 0){ 
                n--;
                std::cout << x[n];
            }
            std::cout << '\n';
            continue;
        }
        if (value == 1) value--;
        n++;
    }
}
