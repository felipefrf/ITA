struct Elemento{
    Elemento* prox;
    int a;
};

struct Fila{
    Elemento* inicio;
    Elemento* fim;
    int tamanho;
    int max;
};

void inicializarFila(Fila& fila, int max){
    fila.tamanho = 0;
    fila.max = max;
    fila.inicio = nullptr;
    fila.fim = nullptr;
}

void enfileirar(Fila& fila, Elemento& elemento){
    Elemento* aux;
    aux->a = elemento.a;
    aux->prox = nullptr;
    if(fila.inicio == nullptr){
        fila.inicio = aux;
        fila.fim = aux;
    }
    else{
        fila.fim->prox = aux;
        fila.fim = aux;
    }
}

void retirar(Fila& fila){
    if(fila.inicio == nullptr){}
    else{
        Elemento* aux;
        aux = fila.inicio;
        fila.inicio = fila.inicio->prox;
        delete aux;
        if(fila.inicio == nullptr){
            fila.fim == nullptr;
        }
    }
}

Elemento consultar(Fila& fila){
    return *fila.inicio;
}