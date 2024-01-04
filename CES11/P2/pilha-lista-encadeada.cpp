#include <iostream>

struct Elemento{
    Elemento* prox;
    int a;
    /**
     * Dados do elemento
    */
};

struct Pilha{
    Elemento* topo;
    int tamanho;
    int maximo;
};

void inicializarPilha(Pilha& pilha, int maximo){
    pilha.topo = nullptr;
    pilha.tamanho = 0;
    pilha.maximo = maximo;
}

bool pilhaVazia(const Pilha& pilha){
    return pilha.tamanho == 0;
}

bool pilhaCheia(const Pilha& pilha){
    return pilha.tamanho == pilha.maximo;
}

void empilhar(Pilha& pilha, Elemento elemento){
    Elemento* aux = new Elemento;
    if(pilhaCheia(pilha)){
        std::cout << "A fila está cheia, retire um elemento antes de adicionar outro\n";
    }
    else{
        aux->a = elemento.a;
        aux->prox = pilha.topo;
        pilha.topo = aux;
        pilha.tamanho++;
    }
}

void desempilhar(Pilha& pilha){
    if(pilhaVazia(pilha)){
        std::cout << "A fila está vazia, adicione um elemento antes de retirar outro\n";
    }
    else{
        Elemento* aux = new Elemento;
        aux = pilha.topo;
        pilha.topo = pilha.topo->prox;
        delete aux;
        pilha.tamanho--;
    }
}

Elemento consultarTopo(Pilha& pilha){
    // Tenho que ver se a pilha está vazia antes de chamar a função, à partir de agora já assumo que ela não está vazia
    return *(pilha.topo);
}

int main(){
    Pilha pilha;
    inicializarPilha(pilha, 5);
    Elemento aux;
    aux.a = 2;
    empilhar(pilha, aux);
    aux.a = 3;
    empilhar(pilha, aux);
    aux.a = 4;
    empilhar(pilha, aux);
    aux.a = 5;
    empilhar(pilha, aux);
    aux.a = 6;
    empilhar(pilha, aux);
    aux.a = 7;
    empilhar(pilha, aux);
    aux.a = 9;
    empilhar(pilha, aux);
    while(!pilhaVazia(pilha)){
        desempilhar(pilha);
    }
    desempilhar(pilha);
}