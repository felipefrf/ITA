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
std::vector<std::string> toOrder3;

int functionCalls;

/**
 * Função que retorna se a string "a" é maior que a string "b" e contabiliza suas chamadas
*/
bool compare(std::string a, std::string b){
    functionCalls++;
    return a > b;
}

/**
 * Função que nos retorna a posição no qual o pivô está em relação à lista
*/
int partition(int init, int end){
    std::string pivot = toOrder3[init];

    int left = init+1;
    int right = end;

    do{
        while(left < end and compare(pivot, toOrder3[left])) left++;

        while(right > init and !compare(pivot, toOrder3[right])) right--;

        if(left < right){
            std::swap(toOrder3[left], toOrder3[right]);
        }
    }while(left < right);

    toOrder3[init] = toOrder3[right];
    toOrder3[right] = pivot;

    return right;
}

//////////////////////////////////////////////////

/**
 * Função de ordenação utilizando o algoritmo Quick Sort
*/
void quickSort(int init, int end){
    int pivot;

    if(init < end){
        pivot = partition(init, end);
        quickSort(init, pivot-1);
        quickSort(pivot+1, end);
    }
}

/*--------------------------------------------------*/

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
        toOrder3.push_back(aux);
    }
    entry.close();

    // Implementação do Quick Sort e contabilização do seu tempo
    exit.open("Lab3_Felipe_Farias_Ribeiro_Filho_quick.txt", std::ios::out);
    functionCalls = 0;
    auto start = std::chrono::high_resolution_clock::now();
    quickSort(0, toOrder3.size()-1);
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    exit << "Algoritmo: Quick Sort\n\n"
    << "Tamanho da entrada: " << numberStrings << '\n'
    << "Número de comparações feitas: " << functionCalls << '\n'
    << "Tempo de execução: " << duration.count() << " microsegundos\n\n"
    << "--------------------------------------------------\n";
    for(std::string printable : toOrder3){
        exit << printable << '\n';
    } 
    exit.close();
}