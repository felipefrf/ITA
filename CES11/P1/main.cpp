#include <iostream>
#include <random>
#include <limits>
#include <string>

int vec[21];
int auxVector[21];
int aux;

struct Plane{
    int flightNumber;
    std::string name;

    Plane* prox;
};

/**
 * Gerador de Vetor Aleatoriezado
*/
void generator(){
    std::random_device ran;
    auto gen = std::mt19937(ran());
    auto dist = std::uniform_int_distribution<int>(0,100);
    for(int i = 1; i < 21; i++){
        vec[i] = dist(gen);
    }
}

/*--------------------------------------------------*/

/**
 * Selection Sort Implementado de Forma Recursiva
*/
void selectionSort(int counter){
    if(counter > 19) return;
    int indiceMenor = counter;
    for(int i = indiceMenor + 1; i < 21; i++){
        if(vec[i] < vec[indiceMenor]){
            indiceMenor = i;
        }
    }

    aux = vec[counter];
    vec[counter] = vec[indiceMenor];
    vec[indiceMenor] = aux;
    selectionSort(counter + 1);
}

/*--------------------------------------------------*/

/**
 * Bubble Sort Implementado de Forma Recursiva
*/
void bubbleSort(){
    bool swapped = false;

    for(int i = 1; i < 20; i++){
        if(vec[i] > vec[i+1]){
            aux = vec[i];
            vec[i] = vec[i+1];
            vec[i+1] = aux;
            
            swapped = true;
        }
    }
    
    if(swapped) bubbleSort();
}

/*--------------------------------------------------*/

/**
 * Merge Sort Implementado de Forma Recursiva
*/
void mergeSort(int init, int end){
    if(init == end) return;

    int mid = (init+end)/2;
    mergeSort(init, mid);
    mergeSort(mid + 1, end);

    int counter = init;
    int j = mid+1;

    for(int i = init; i <= mid; i++){
        while(j <= end and vec[j] <= vec[i]){
            auxVector[counter] = vec[j];
            counter++;
            j++;
        }
        auxVector[counter] = vec[i];
        counter++;
    }

    while(j <= end){
        auxVector[counter] = vec[j];
        counter++;
        j++;
    }

    for(int i = init; i <= end; i++){
        vec[i] = auxVector[i];
    }
}

/*--------------------------------------------------*/

/**
 * Quick Sort Implementação de Forma Recursiva
*/
int partition(int init, int end){
    int pivot;
    int left, right;

    pivot = vec[init];
    left = init+1;
    right = end;

    do{
    // percorrer da esquerda para a direita até encontrar alguém maior que o pivô
    while(left < end and vec[left] < pivot){
        left++;
    }

    // percorrer da direita para a esquerda até encontrar alguém menor ou igual ao pivô
    while(init < right and pivot <= vec[right]) right--;

    // se achou um à esquerda e outro à direita
    if(left < right){
        aux = vec[left];
        vec[left] = vec[right];
        vec[right] = aux;
    }
    } while(left < right);

    // trocar o pivô com o elemento que "divide" os subvetores
    vec[init] = vec[right];
    vec[right] = pivot;

    // retorna a posição da "divisa"
    return right;
}

void quickSort(int init, int end){
    int pivot;

    if(init < end){
        pivot = partition(init, end);
        quickSort(init, pivot-1);
        quickSort(pivot+1, end);
    }
}

/*--------------------------------------------------*/

int binarySearch(int number, int init, int end){
    int mid = (init+end) / 2;

    if(vec[mid] == number) return mid;
    else if(vec[mid] > number) return binarySearch(number, init, mid-1);
    else return binarySearch(number, mid+1, end);
}

/*--------------------------------------------------*/

int main(){
    // generator();

    // for(int number : vec){
    //     std::cout << number << " ";
    // }

    // std::cout << "\n\n";

    /**
     * Bubble Sort Implementado de Forma Iterativa
    */
    // int counter = 1;
    // bool swapped = true;
    // while(swapped == true and counter < 21){
    //     swapped = false;
    //     for(int i = 0; i < 20; i++){
    //         if(vec[i] > vec[i+1]){
    //             aux = vec[i];
    //             vec[i] = vec[i+1];
    //             vec[i+1] = aux;

    //             swapped = true;
    //         }
    //     }
    //     counter++;
    // }

    /**
     * Selection Sort Implementado de Forma Iterativa
    */
    // int indiceMenor;
    // for(int i = 1; i < 20; i++){
    //     indiceMenor = i;
    //     for(int j = i + 1; j < 21; j++){
    //         if(vec[j] < vec[indiceMenor]){
    //             indiceMenor = j;
    //         }
    //     }

    //     aux = vec[i];
    //     vec[i] = vec[indiceMenor];
    //     vec[indiceMenor] = aux;
    // }

    /**
     * Merge Sort Implementado de Forma Iterativa
    */
    // Não vale a pena, precisa usar abordagem de pilha(stack)


    // for(int number : vec){
    //     std::cout << number << ' ';
    // }

    // std::cout << "\n\nBinaries search result was: " <<  binarySearch(vec[5], 1, 20);

    Plane* start;
    start = nullptr;
    Plane* aux;
    std::string message;
    // Implementação de uma lista encadeada
    while(std::cin >> message){
        if(message == "pede_pouso"){
            aux = new Plane;
            std::cin >> aux->flightNumber >> aux->name;
            aux->prox = start;
            start = aux;
        }
    }

    return 0;
}