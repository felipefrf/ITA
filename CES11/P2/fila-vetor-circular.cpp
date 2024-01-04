#include <iostream>
#define MAX 100

struct Elemento{
    int a;
};

struct Fila{
    Elemento* vec;
    int fim;
    int inicio;
    int max;
    int tamanho;
};

void inicializarFila(Fila& fila){
    fila.vec = new Elemento[fila.max];
    fila.inicio = 0;
    fila.fim = fila.max-1;
}

void enfileirar(Fila& fila, Elemento& elemento){
    if(fila.tamanho == fila.max){
        std::cout << "error\n";
    }
    else{
        fila.fim = (fila.fim++) % fila.max;
        fila.vec[fila.fim] = elemento;
        fila.tamanho++;
    }
}

void desenfileirar(Fila& fila){
    if(fila.tamanho == 0){
        std::cout << "A fila está vazia, impossível remover um elemento\n";
    }
    else{
        fila.inicio = (fila.inicio++) % fila.max;
        fila.tamanho--;
    }
}

Elemento consultarFila(Fila& fila){
    if(fila.tamanho == 0){
        std::cout << "A fila está vazia, impossível consultar um elemento\n";
    }
    else{
        return fila.vec[fila.inicio];
    }
}

bool filaVazia(Fila& fila){
    return !fila.tamanho;
}

bool filaCheia(Fila& fila){
    return fila.tamanho == fila.max;
}

void eliminarFila(Fila& fila){
    delete fila.vec;
}