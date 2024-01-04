#include <iostream>
#define MAX 100

struct Elemento{
    int a;
};

struct Fila{
    Elemento vec[MAX+1];
    int tamanho;
    int max;
};

void inicializarFila(Fila& fila, int maximo){
    fila.tamanho = 0;
    fila.max = maximo;
}

int position(const Fila& fila, const Elemento& elemento){
    int esq = 0;
    int dir = fila.tamanho;
    int mid;

    while(esq <= dir){
        mid = (esq+dir)/2;
        if(fila.vec[mid].a == elemento.a){
            return mid;
        }
        else if(fila.vec[mid].a < elemento.a){
            esq = mid + 1;
        }
        else{
            dir = mid -1;
        }
    }
    return esq;
}

bool filaVazia(Fila& fila){
    return fila.tamanho == 0;
}

bool filaCheia(Fila& fila){
    return fila.tamanho == fila.max;
}

void inserir(Fila& fila, Elemento elemento){
    if(filaCheia){
        std::cout << "A fila está cheia, retire um elemento antes de adicionar\n";
    }
    else{
        int pos = position(fila, elemento);

        for(int i = fila.tamanho; i >= pos; i--){
            fila.vec[i+1] = fila.vec[i];
        }
        fila.vec[pos] = elemento;
        fila.tamanho++;
    }
}

void remover(Fila& fila){
    if(filaVazia){
        std::cout << "A fila está vazia, adicione um elemento antes de retirar\n";
    }
    else{
        fila.tamanho--;
    }
}

Elemento consultarFila(Fila& fila){
    return fila.vec[fila.tamanho];
}