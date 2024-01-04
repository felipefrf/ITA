/* Felipe Farias Ribeiro Filho                      */
/* Turma 02                                         */
/* Exercício 5 : Agenda Eletrônica + Heap           */
/*                                                  */
/* Programa compilado com Visual Studio Code 1.82.2 */

#include <fstream>
#include <iomanip>
#include <string>
#include <vector>

struct Task{
    int priority;
    std::string description;
};

/*--------------------------------------------------*/
struct Heap{
    Task* vec;
    int length;
    int maxLength;
};

/*--------------------------------------------------*/

/**
 * Função que inicializa a fila
*/
Heap* initialize(int maxLength){
    Heap* heap = new Heap;
    heap->length = 0;
    heap->maxLength = maxLength;
    heap->vec = new Task[maxLength+1];

    return heap;
}

/*--------------------------------------------------*/

/**
 * Função que retorna se a fila está vazia
*/
bool emptyLine(Heap* heap){
    return heap->length == 0;
}

/*--------------------------------------------------*/

/**
 * Função que retorna se a fila está cheia
*/
bool fullLine(Heap* heap){
    return heap->length == heap->maxLength;
}

/*--------------------------------------------------*/

/**
 * Função que usamos para inserir uma atividade na fila
*/
void insert(int priority, std::string description, Heap* heap){
    Task add;
    add.description = description;
    add.priority = priority;
    heap->length++;
    heap->vec[heap->length] = add;
    int index = heap->length;

    // Mantém a propriedade da Max Heap
    while(index > 1 and priority > heap->vec[index/2].priority){
        std::swap(heap->vec[index/2], heap->vec[index]);
        index /= 2;
    }
}

/*--------------------------------------------------*/

/**
 * Função que deleta a fila de prioridade
*/
void endLine(Heap* heap){
    delete heap;
}

/*--------------------------------------------------*/

/**
 * Função que retorna a ativide de maior prioridade
*/
Task maximumTask(Heap* heap){
    return heap->vec[1];
}

/*--------------------------------------------------*/

/**
 * Função que remove a atividade de maior prioridade
*/
void removeMax(Heap* heap){
    // Move o último elemento para a raiz e decrementa o comprimento
    heap->vec[1] = heap->vec[heap->length];
    heap->length--;

    // Mantém a propriedade da Max Heap
    int index = 1;
    bool swapped = true;
    while(2 * index <= heap->length and swapped){
        swapped = false;
        int childIndex = 2 * index;
        if(childIndex + 1 <= heap->length and heap->vec[childIndex + 1].priority > heap->vec[childIndex].priority){
            childIndex++;
        }

        if(heap->vec[childIndex].priority > heap->vec[index].priority){
            std::swap(heap->vec[childIndex], heap->vec[index]);
            index = childIndex;
            swapped = true;
        }
    }
}

/*--------------------------------------------------*/

int main(){

    // Abertura dos arquivos de entrada e saída
    std::fstream entry;
    std::fstream exit;
    entry.open("entrada5.txt");
    exit.open("Lab5_Felipe_Farias_Ribeiro_Filho.txt", std::ios::out);

    // Escrita do cabeçalho da agenda eletrônica
    exit << "Agenda Eletronica - Arquivo de Saida\n"
    << "As atividades feitas estao impressas por ordem de realizaçao.\n"
    << "As atividades que sobraram estao impressas por ordem de prioridade.\n\n\n"
    << "--------------------------------------------------\n"
    << "RESPOSTAS DAS CONSULTAS\n"
    << "--------------------------------------------------\n";

    // Leitura do arquivo de entrada
    std::string ignore;
    int maxLength;
    while(entry >> ignore and ignore != "Numero");
    std::getline(entry, ignore);
    entry >> maxLength;

    Heap* heap = initialize(maxLength);

    std::getline(entry, ignore);
    std::getline(entry, ignore);
    std::getline(entry, ignore);
    std::getline(entry, ignore);

    // Criação do loop que rege o comportamento da agenda
    std::string request;
    int priority;
    char aux;
    std::string description;
    int counter;
    Task toPrint;
    while(entry >> request and request != "FIM"){
        if(request == "NOVA"){
            if(fullLine(heap)){
                exit << "ERRO     A agenda esta cheia. Impossivel inserir.\n";
                std::getline(entry, ignore);
            }
            else{
                entry >> priority;
                while(entry >> aux and !isalpha(aux)); // implementado caso o usuário não insira a descrição com espaçamento correto
                entry.seekg(-1, std::ios_base::cur); // nesse caso o meu programa ainda consegue ler as atividades de forma hábil
                std::getline(entry, description);
                insert(priority, description, heap);
            }
        }
        
        else if(request == "PROXIMA"){
            if(emptyLine(heap)){
                exit << "AVISO    A agenda esta vazia. Impossível retirar.\n";
            }
            else{
                toPrint = maximumTask(heap);
                exit << std::setw(2) << toPrint.priority << "       " << toPrint.description << '\n';
                removeMax(heap);
            }
        }
    }
    
    // Escrita das atividades que sobraram para o dia seguinte
    exit << "\n--------------------------------------------------\n"
    << "FICA PARA O DIA SEGUINTE\n"
    << "--------------------------------------------------\n";

    if(emptyLine(heap)){
        exit << "         Nao ha pendencias para amanha. Parabens, voce finalizou as atividades no dia.\n";
    }
    else{
        while(!emptyLine(heap)){
            toPrint = maximumTask(heap);
            exit << std::setw(2) << toPrint.priority << "       " << toPrint.description << '\n';
            removeMax(heap);
        }
    }

    // Fechamento dos arquivos e apagamento da fila
    endLine(heap);
    exit.close();
    entry.close();
}