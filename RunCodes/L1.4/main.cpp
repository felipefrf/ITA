#include <iostream>
#include <iomanip>

int main(){
    unsigned xsize,ysize;
    std::cin >> xsize >> ysize;
    for(unsigned i = 1; i <= ysize;i++){
        for (unsigned n = 1; n <= xsize;n++){
            std::cout << n * i << std::setw(4);
        }
        std::cout << "\n";
    }
}