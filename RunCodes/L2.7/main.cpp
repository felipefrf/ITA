#include <iostream>

void saveUpperLine(char**& matrix, char m, int& column, int size){
    if(m == '1' or m == '4'){
        for(int i = 0; i < size + 2; i++){
            matrix[i + column][0] = '.';
        }
        column += size + 2;
    }
    else{
        matrix[column][0] = '.';
        column++;
        for(int i = 0; i < size; i++){
            matrix[i + column][0] = '-';
        }
        column += size;
        matrix[column][0] = '.';
        column++;
    }
}

void saveMiddleUpperLines(char**& matrix, char m, int& column, int& row, int size){
    if(m == '5' or m == '6'){
        matrix[column][row] = '|';
        column++;
        for(int i = 0; i < size + 1; i++) matrix[i + column][row] = '.';
        column += size + 1;
    }
    else if(m == '1' or m == '3' or m == '7' or m == '2'){
        for(int i = 0; i < size + 1; i++) matrix[i + column][row] = '.';
        column += size + 1;
        matrix[column][row] = '|';
        column++;
    }
    else{
        matrix[column][row] = '|';
        column++;
        for(int i = 0; i < size; i++) matrix[i + column][row] = '.';
        column += size;
        matrix[column][row] = '|';
        column++;
    }
}

void saveMiddleLine(char**& matrix, char m, int& column, int& row, int size){
    if(m == '0' or m == '1' or m == '7'){
        for(int i = 0; i < size + 2; i++) matrix[i + column][row] = '.';
        column += size + 2;
    }
    else{
        matrix[column][row] = '.';
        column++;
        for(int i = 0; i < size; i++) matrix[i + column][row] = '-';
        column += size;
        matrix[column][row] = '.';
        column++;
    }
}

void saveMiddleLowerLines(char**& matrix, char m, int& column, int& row, int size){
    if(m == '0' or m == '6' or m == '8'){
        matrix[column][row] = '|';
        column++;
        for(int i = 0; i < size; i++) matrix[i + column][row] = '.';
        column += size;
        matrix[column][row] = '|';
        column++;
    }
    else if(m == '2'){
        matrix[column][row] = '|';
        column++;
        for(int i = 0; i < size+1; i++) matrix[i + column][row] = '.';
        column += size + 1;
    }
    else{
        for(int i = 0; i < size + 1; i++) matrix[i + column][row] = '.';
        column += size + 1;
        matrix[column][row] = '|';
        column++;
    }
}

void saveLowerLine(char**& matrix, char m, int& column, int& row, int size){
    if(m == '1' or m == '4' or m == '7'){
        for(int i = 0; i < size + 2; i++) matrix[i + column][row] = '.';
        column += size + 2;
    }
    else{
        matrix[column][row] = '.';
        column++;
        for(int i = 0; i < size; i++) matrix[i + column][row] = '-';
        column += size;
        matrix[column][row] = '.';
        column++;
    }
}

void printMatrix(char**& matrix, int size, int length){
    for(int i = 0; i < (2 * size + 3); i++){
        for(int j = 0; j < (size + 2)*length; j++){
            std::cout << matrix[j][i];
        }
        std::cout << '\n';
    }
}

void deleteMatrix(char**& matrix, int size, int length){
    for(int i = 0; i < length*(size+2); i++){
        delete[] matrix[i];
    }
    delete[] matrix;
    matrix = nullptr;
}

int main(){
    int size, length = 0;
    char m;
    std::cin >> size;
    char* array = new char[1000];
    bool start = false;
    while(std::cin >> m){
        if(start == false and m == '0') continue;
        if(start == false and m != '0') start = true;
        array[length] = m;
        length++;
    }
    char** matrix = new char*[(length)*(size+2)];
    for(int i = 0; i < (length*(size+2)); i++){
        matrix[i] = new char[(2*size+3)];
    }
    int column = 0;
    for(int i = 0; i < length; i++) saveUpperLine(matrix, array[i], column, size);
    column = 0;
    int row = 1;
    for(int i = 0; i < size; i++){
        for(int i = 0; i < length; i++){
            saveMiddleUpperLines(matrix, array[i], column, row, size);
        }
        column = 0;
        row++;
    }
    for(int i = 0; i < length; i++) saveMiddleLine(matrix, array[i], column, row, size);
    row++;
    column = 0;
    for(int i = 0; i < size; i++){
        for(int i = 0; i < length; i++){
            saveMiddleLowerLines(matrix, array[i], column, row, size);
        }
        column = 0;
        row++;
    }
    for(int i = 0; i < length; i++) saveLowerLine(matrix, array[i], column, row, size);
    row++;
    printMatrix(matrix, size, length);
    deleteMatrix(matrix, size, length);
    delete[] array;
    array = nullptr;
}