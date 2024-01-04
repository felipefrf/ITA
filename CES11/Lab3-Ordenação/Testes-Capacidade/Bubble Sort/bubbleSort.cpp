/* Felipe Farias Ribeiro Filho             */
/* Turma 02                                */
/* Exercício 3 : Ordenação                 */
/*                                         */
/* Programa compilado com CodeBlocks 17.12 */

#include <vector>
#include <fstream>
#include <string>
#include <chrono>

// Criação das variáveis globais
std::vector<std::string> toOrder1;

int functionCalls;

/**
 * Função que retorna se a string "a" é maior que a string "b" e contabiliza suas chamadas
*/
bool compare(std::string a, std::string b){
    functionCalls++;
    return a > b;
}

/*--------------------------------------------------*/

/**
 * Função de ordenação usando o algoritmo Bubble Sort
*/
void bubbleSort(){
    bool swapped = false;
    int length = toOrder1.size();

    for(int i = 0; i < length - 1; i++){
        if(compare(toOrder1[i], toOrder1[i+1])){
            std::swap(toOrder1[i], toOrder1[i+1]);
            swapped = true;
        }
    }

    if(swapped) bubbleSort();
}

int main(){

    // Criação das variáveis locais
    int numberStrings;
    std::string aux;
    std::fstream entry;
    std::fstream exit;
    entry.open("entrada3.txt");

    // Leitura dos elementos do vetor que será ordenado
    entry >> numberStrings;

    for(int i = 0; i < numberStrings; i++){
        entry >> aux;
        toOrder1.push_back(aux);
    }
    entry.close();

    // Implementação do Bubble Sort e contabilização do seu tempo
    exit.open("Lab3_Felipe_Farias_Ribeiro_Filho_bubble.txt", std::ios::out);
    functionCalls = 0;
    auto start = std::chrono::high_resolution_clock::now();
    bubbleSort();
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    exit << "Algoritmo: Bubble Sort\n\n"
    << "Tamanho da entrada: " << numberStrings << '\n'
    << "Número de comparações feitas: " << functionCalls << '\n'
    << "Tempo de execução: " << duration.count() << " microsegundos\n\n"
    << "--------------------------------------------------\n";
    for(std::string printable : toOrder1){
        exit << printable << '\n';
    } 
    exit.close();
}