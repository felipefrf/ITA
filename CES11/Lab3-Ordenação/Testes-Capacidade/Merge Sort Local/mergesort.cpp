#include <vector>
#include <fstream>
#include <string>
#include <chrono>

// Criação das variáveis globais
std::vector<std::string> toOrder2;

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
 * Função de Ordenação usando o algoritmo Merge Sort
*/
void mergeSort(int init, int end){
    if(init == end) return;
    std::vector<std::string> auxVec(end-init+1);

    int mid = (init + end) / 2;
    mergeSort(init, mid);
    mergeSort(mid+1, end);

    int j = mid + 1;
    int currentPosition = 0;
    for(int i = init; i < mid + 1; i++){
        while(j <= end and compare(toOrder2[i], toOrder2[j])){
            auxVec[currentPosition] = toOrder2[j];
            currentPosition++;
            j++;
        }
        auxVec[currentPosition] = toOrder2[i];
        currentPosition++;
    }

    while(j <= end){
        auxVec[currentPosition] = toOrder2[j];
        currentPosition++;
        j++;
    }

    for(int i = 0; i <= end-init; i++){
        toOrder2[i+init] = auxVec[i];
    }
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
        toOrder2.push_back(aux);
    }
    entry.close();

    // Implementação do Merge Sort e contabilização do seu tempo
    exit.open("Lab3_Felipe_Farias_Ribeiro_Filho_merge.txt", std::ios::out);
    functionCalls = 0;
    auto start = std::chrono::high_resolution_clock::now();
    mergeSort(0, toOrder2.size()-1);
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    exit << "Algoritmo: Merge Sort\n\n"
    << "Tamanho da entrada: " << numberStrings << '\n'
    << "Número de comparações feitas: " << functionCalls << '\n'
    << "Tempo de execução: " << duration.count() << " microsegundos\n\n"
    << "--------------------------------------------------\n";
    for(std::string printable : toOrder2){
        exit << printable << '\n';
    } 
    exit.close();
}