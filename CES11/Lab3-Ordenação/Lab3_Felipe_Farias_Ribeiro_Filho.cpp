/* Felipe Farias Ribeiro Filho                      */
/* Turma 02                                         */
/* Exercício 3 : Ordenação                          */
/*                                                  */
/* Programa compilado com Visual Studio Code 1.82.2 */

#include <vector>
#include <fstream>
#include <string>
#include <chrono>
#include <iomanip>

// Criação das variáveis globais
std::vector<std::string> toOrder1;
std::vector<std::string> toOrder2;
std::vector<std::string> toOrder3;

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

/*--------------------------------------------------*/

/**
 * Função de Ordenação usando o algoritmo Merge Sort com vetor auxiliar auxVec Local e Static
*/
void mergeSort(int init, int end){
    if(init == end) return;
    static std::vector<std::string> auxVec(end-init+1);

    int mid = (init + end) / 2;
    mergeSort(init, mid);
    mergeSort(mid+1, end);

    int j = mid + 1;
    int currentPosition = init;
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

    for(int i = init; i <= end; i++){
        toOrder2[i] = auxVec[i];
    }
}

/*--------------------------------------------------*/

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
    double toPrint;
    entry.open("entrada3.txt");

    // Leitura dos elementos do vetor que será ordenado
    entry >> numberStrings;

    for(int i = 0; i < numberStrings; i++){
        entry >> aux;
        toOrder1.push_back(aux);
    }
    entry.close();
    toOrder2 = toOrder1;
    toOrder3 = toOrder1;

    // Implementação do Bubble Sort e contabilização do seu tempo
    exit.open("Lab3_Felipe_Farias_Ribeiro_Filho_bubble.txt", std::ios::out);
    functionCalls = 0;
    auto start = std::chrono::high_resolution_clock::now();
    bubbleSort();
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    toPrint = duration.count();
    toPrint /= 1000000;
    exit << "Algoritmo: Bubble Sort\n\n"
    << "Tamanho da entrada: " << numberStrings << '\n'
    << "Número de comparações feitas: " << functionCalls << '\n'
    << "Tempo de execução: " << std::fixed << std::setprecision(3) << toPrint << " segundos\n\n"
    << "--------------------------------------------------\n";
    for(std::string printable : toOrder1){
        exit << printable << '\n';
    } 
    exit.close();

    // Implementação do Merge Sort e contabilização do seu tempo
    exit.open("Lab3_Felipe_Farias_Ribeiro_Filho_merge.txt", std::ios::out);
    functionCalls = 0;
    start = std::chrono::high_resolution_clock::now();
    mergeSort(0, toOrder2.size()-1);
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    toPrint = duration.count();
    toPrint /= 1000000;
    exit << "Algoritmo: Merge Sort\n\n"
    << "Tamanho da entrada: " << numberStrings << '\n'
    << "Número de comparações feitas: " << functionCalls << '\n'
    << "Tempo de execução: " << std::fixed << std::setprecision(3) << toPrint << " segundos\n\n"    << "--------------------------------------------------\n";
    for(std::string printable : toOrder2){
        exit << printable << '\n';
    } 
    exit.close();

    // Implementação do Quick Sort e contabilização do seu tempo
    exit.open("Lab3_Felipe_Farias_Ribeiro_Filho_quick.txt", std::ios::out);
    functionCalls = 0;
    start = std::chrono::high_resolution_clock::now();
    quickSort(0, toOrder3.size()-1);
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    toPrint = duration.count();
    toPrint /= 1000000;
    exit << "Algoritmo: Quick Sort\n\n"
    << "Tamanho da entrada: " << numberStrings << '\n'
    << "Número de comparações feitas: " << functionCalls << '\n'
    << "Tempo de execução: " << std::fixed << std::setprecision(3) << toPrint << " segundos\n\n"
    << "--------------------------------------------------\n";
    for(std::string printable : toOrder3){
        exit << printable << '\n';
    } 
    exit.close();
}