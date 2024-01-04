#include <iostream>
#define MAX 100

struct Elemento{
    int a;
};

struct Pilha{
    Elemento vec[MAX+1];
    int maximo;
    int tamanho;
};

void inicializarPilha(Pilha& pilha, int max){
    pilha.maximo = max;
    pilha.tamanho = 0;
}

bool pilhaVazia(Pilha& pilha){
    return pilha.tamanho == 0;
}

bool pilhaCheia(Pilha& pilha){
    return pilha.tamanho == pilha.maximo;
}

Elemento consultarTopo(Pilha& pilha){
    return pilha.vec[pilha.tamanho];
}

void empilhar(Pilha& pilha, Elemento& elemento){
    if(pilhaCheia(pilha)){
        std::cout << "A pilha está cheia, retire um elemento antes de adicionar outro\n";
    }
    else{
        pilha.tamanho++;
        pilha.vec[pilha.tamanho] = elemento;
    }
}

void desempilhar(Pilha& pilha){
    if(pilhaVazia(pilha)){
        std::cout << "A pilha está vazia, adicione um elemento antes de retirar outro\n";
    }
    else{
        pilha.tamanho--;
    }
}

void finalizarPilha(Pilha& pilha){
    pilha.tamanho = 0;
}