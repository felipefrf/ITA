#include <iostream>

int main(){
    unsigned n;
    std::cin >> n;
    int binario[7] = {};
    if (n > 127){
        std::cout << "ERR\n";
        return 0;
    }
    for (int i=6;i>=0;i--){
        int quociente = n/2;
        int resto = n%2;
        n = quociente;
        binario[i]=resto;
    }
    for (const auto &value: binario){
        std::cout << value;
    }
    std::cout << '\n';
}
