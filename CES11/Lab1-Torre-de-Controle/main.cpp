/* Felipe Farias Ribeiro Filho             */
/* Turma 02                                */
/* Exercício 1 : Torre de Controle         */
/*                                         */
/* Programa compilado com CodeBlocks 17.12 */

#include <string>
#include <fstream>
#include <iomanip>

struct Plane{
    int flightNumber;
    std::string origin;
    bool urgent;

    Plane* prox;
};

// Função que exclui o último nó da fila e imprime suas informações
void excludeLastNode(Plane*& init, std::fstream& exit){
    Plane* front;
    Plane* back;
    front = init->prox;
    back = init;
    if(front != nullptr){ // Fila com mais de um elemento
        while(front->prox != nullptr){
            front = front->prox;
            back = back->prox;
        }

        exit << std::setfill('0') << std::setw(4) << front->flightNumber << "    " << front->origin << '\n';
        back->prox = nullptr;
        delete front;
    }
    else{ // Fila com apenas 1 elemento
        exit << back->flightNumber << "    " << back->origin << '\n';
        init = nullptr;
        delete back;
    }
}

/*--------------------------------------------------*/ 
// Função que encontra um nó da fila, dado o seu número do vôo
Plane* findNode(Plane* init, int number){
    Plane* p = new Plane;

    p = init;
    while(p->flightNumber != number){
        p = p->prox;
    }
     
    return p;
}

/*--------------------------------------------------*/ 

// Função que rearranja a posição da urgência na fila
void rearrangeNode(Plane*& init, int number){
    Plane* aux = findNode(init, number);

    if (aux != nullptr and aux->prox != nullptr) {
        Plane* back = init;
        if(aux != init){
            while (back->prox != aux) {
                back = back->prox;
            }
            back->prox = aux->prox;
        }
        else{
            init = aux->prox;
        }

        Plane* front = init;
        back = nullptr;
        while (front != nullptr and !front->urgent) {
            back = front;
            front = front->prox;
        }

        if (back == nullptr) {
            aux->prox = init;
            init = aux;
        } else {
            aux->prox = front;
            back->prox = aux;
        }

        aux->urgent = true;
    }
}

int main(){

    // Abertura dos arquivos que serão usados para leitura e escrita
    std::fstream entry;
    std::fstream exit;
    entry.open("entrada1.txt");
    exit.open("Lab1_Felipe_Farias_Ribeiro_Filho.txt", std::ios::out);


    // Ignora a parte inútil da entrada
    std::string ignore;
    while(entry >> ignore and ignore != "INICIO"){
        std::getline(entry, ignore);
    }
    entry >> ignore;
    entry >> ignore;

    // Cria os operadores que serão usados
    std::string message;
    int flightNumber;

    Plane* start;
    Plane* aux;

    // Escreve o título da saída
    exit << "Joseloid International Airport\n" << 
    "Torre de controle: mensagens enviadas\n" <<
    "AUTORIZAÇÕES DE POUSO\n" <<
    "==================================================\n" << 
    "FLIGHT   FROM\n";
    
    // Implementação da função geral do programa
    start = nullptr;
    aux = new Plane;
    while(entry >> message){
        if(message == "pede_pouso"){
            aux = new Plane;
            entry >> aux->flightNumber;
            std::getline(entry, aux->origin);
            aux->urgent = false;
            aux->prox = start;
            start = aux;
        }
        else if (message == "URGENCIA"){
            entry >> flightNumber;            
            std::getline(entry, ignore);

            rearrangeNode(start, flightNumber);
        }
        else if(message == "pista_liberada"){
            if(start != nullptr){
                excludeLastNode(start, exit);
            }
            else{
                exit << "0000" << "      " << "Nenhum avião pousando\n";
            }
        }
    }
    
    // Impressão da situação da fila pós pousos
    exit << "\nSituação da fila\n\n";
    if(start == nullptr){
        exit << "Não há aviões na fila";
    }
    else{
        while(start != nullptr){
            excludeLastNode(start, exit);
        }
    }

    // Fechamento dos arquivos
    exit.close();
    entry.close();
}