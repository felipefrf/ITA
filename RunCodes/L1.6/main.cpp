#include <iostream>
#include <string>

int main(){
    long long int inteiro = 0, inp_inteiro;
    char ponto, operation;
    int frac = 0, inp_frac;
    bool is_negative = false;
    while (std::cin >> operation >> inp_inteiro >> ponto >> inp_frac){
        if (is_negative == false) {
            if (operation == 'd') {
                inteiro += inp_inteiro;
                frac += inp_frac;
                if (frac >= 100){
                    inteiro += 1;
                    frac -= 100;
                }
            }
            if (operation == 'w') {
                inteiro -= inp_inteiro;
                frac -= inp_frac;
                if (inteiro > 0 and frac < 0){
                    inteiro -= 1;
                    frac += 100;
                }
                if (inteiro < 0 and frac > 0){
                    frac -= 100;
                    inteiro += 1;
                }
                if (inteiro == 0 and frac < 0){
                    is_negative = true;
                    frac *=-1;
                }
                if (inteiro < 0) {
                    is_negative = true;
                    inteiro *= -1;
                    frac *= -1;
                }
            }
        }
        else {
            inteiro *= -1;
            frac *= -1;
            if (operation == 'd'){
                inteiro += inp_inteiro;
                frac += inp_frac;
                if (inteiro > 0 and frac < 0){
                    inteiro -= 1;
                    frac += 100;
                }
                if (inteiro < 0 and frac > 0){
                    frac -= 100;
                    inteiro += 1;
                }
                if (inteiro > 0){
                    is_negative = false;
                }
                else if (inteiro == 0 and frac > 0){
                    is_negative = false;
                }
                else{
                    inteiro *= -1;
                    frac *= -1;
                }
            }
            if (operation == 'w'){
                inteiro -= inp_inteiro;
                frac -= inp_frac;
                if (frac <= -100){
                    inteiro -= 1;
                    frac += 100;
                }
                inteiro *= -1;
                frac *= -1;
            }
        }
        if (is_negative == false){
            if (frac < 10) std::cout << inteiro << ".0" << frac << "\n";
            else std::cout << inteiro << "." << frac << "\n";
        }
        if (is_negative == true) {
            if (frac < 10) std::cout << "(" << inteiro << ".0" << frac << ")" << "\n";
            else std::cout << "(" << inteiro << "." << frac << ")" << "\n";
        }
    }
}