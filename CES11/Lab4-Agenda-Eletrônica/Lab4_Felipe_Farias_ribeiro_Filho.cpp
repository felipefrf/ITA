/* Felipe Farias Ribeiro Filho                      */
/* Turma 02                                         */
/* Exercício 4 : Agenda Eletrônica + vetor simples  */
/*                                                  */
/* Programa compilado com Visual Studio Code 1.82.2 */

#include <fstream>
#include <iomanip>
#include <string>
#define MAX_LENGTH 100

struct Task{
    int priority;
    std::string description;
};

/*--------------------------------------------------*/

struct Line{
    Task vec[MAX_LENGTH];
    int length;
    int maxLength;
};

/*--------------------------------------------------*/

/**
 * Função que inicializa a fila
*/
Line* initialize(int maxLength){
    Line* line = new Line;
    line->length = 0;
    line->maxLength = maxLength;

    for(int i = 1; i <= maxLength; i++){
        line->vec[i].priority = 0;
    }

    return line;
}

/*--------------------------------------------------*/

/**
 * Função que retorna se a fila está vazia
*/
bool emptyLine(Line* line){
    return line->length == 0;
}

/*--------------------------------------------------*/

/**
 * Função que retorna se a fila está cheia
*/
bool fullLine(Line* line){
    return line->length == line->maxLength;
}

/*--------------------------------------------------*/

/**
 * Função que encontra a posição que a atividade deve ocupar na fila
*/
int findPosition(int priority, const Line* line) {
    int left = 1;
    int right = line->length;
    int middle;

    if (right == 0) return 1;

    while (left <= right) {
        middle = (left + right) / 2;

        if (priority > line->vec[middle].priority) {
            left = middle + 1;
        } 
        else if (priority < line->vec[middle].priority) {
            right = middle - 1;
        } 
        else {
            return middle;
        }
    }

    return left;
}

/*--------------------------------------------------*/

/**
 * Função que usamos para inserir uma atividade na fila
*/
void insert(int priority, std::string description, Line* line){
    Task add;
    add.description = description;
    add.priority = priority;
    int position = findPosition(priority, line);
    for(int i = line->length; i >= position; i--){
        line->vec[i+1] = line->vec[i];
    }

    line->vec[position] = add;
    line->length++;
}

/*--------------------------------------------------*/

/**
 * Função que deleta a fila de prioridade
*/
void endLine(Line* line){
    delete line;
}

/*--------------------------------------------------*/

/**
 * Função que retorna a ativide de maior prioridade
*/
Task maximumTask(Line* line){
    return line->vec[line->length];
}

/*--------------------------------------------------*/

/**
 * Função que remove a atividade de maior prioridade
*/
void removeMax(Line* line){
    line->vec[line->length].priority = 0;
    line->length--;
}

/*--------------------------------------------------*/

int main(){

    // Abertura dos arquivos de entrada e saída
    std::fstream entry;
    std::fstream exit;
    entry.open("entrada4.txt");
    exit.open("Lab4_Felipe_Farias_Ribeiro_Filho.txt", std::ios::out);

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

    Line* line = initialize(maxLength);

    std::getline(entry, ignore);
    std::getline(entry, ignore);
    std::getline(entry, ignore);

    // Criação do loop que rege o comportamento da agenda
    std::string request;
    int priority;
    std::string description;
    int counter;
    Task toPrint;
    while(entry >> request and request != "FIM"){
        if(request == "NOVA"){
            if(fullLine(line)){
                exit << "ERRO     A agenda está cheia, realize uma das atividades antes de adicionar a próxima.\n";
            }
            else{
                entry >> priority;
                entry.seekg(7, std::ios_base::cur);
                std::getline(entry, description);
                insert(priority, description, line);
            }
        }
        
        else if(request == "PROXIMA"){
            if(emptyLine(line)){
                exit << "AVISO    A agenda esta vazia\n";
            }
            else{
                toPrint = maximumTask(line);
                exit << std::setw(2) << toPrint.priority << "       " << toPrint.description << '\n';
                removeMax(line);
            }
        }
    }
    
    // Escrita das atividades que sobraram para o dia seguinte
    exit << "\n--------------------------------------------------\n"
    << "FICA PARA O DIA SEGUINTE\n"
    << "--------------------------------------------------\n";

    if(emptyLine(line)){
        exit << "A agenda esta vazia para amanha, voce realizou todas as atividades do dia.\n";
    }
    else{
        while(!emptyLine(line)){
            toPrint = maximumTask(line);
            exit << std::setw(2) << toPrint.priority << "       " << toPrint.description << '\n';
            removeMax(line);
        }
    }

    // Fechamento dos arquivos e apagamento da fila
    endLine(line);
    exit.close();
    entry.close();
}