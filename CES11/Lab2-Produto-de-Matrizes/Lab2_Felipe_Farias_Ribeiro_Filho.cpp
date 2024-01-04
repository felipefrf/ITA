/* Felipe Farias Ribeiro Filho             */
/* Turma 02                                */
/* Exercício 2 : Produto de Matrizes       */
/*                                         */
/* Programa compilado com CodeBlocks 17.12 */

#include <fstream>
#include <string>
#include <limits>

struct Matrix{
    int columns;
    int lines;
};

int functionCalls = 0;
int betterCut[21][21];
int matrixNumber;
int front;
int back;

/*--------------------------------------------------*/

// Encontra o número mínimo de operações de forma recursiva
int findMinimum(Matrix vec[21], int init, int end){
    functionCalls++;
    if(init == end) return 0;
    
    int min = std::numeric_limits<int>::max();
    int aux;
    for(int mid = init; mid < end; mid++){
        aux = findMinimum(vec, init, mid) + findMinimum(vec, mid+1, end) + vec[init].lines * vec[mid].columns * vec[end].columns;
        if(aux <= min){
            min = aux;
            betterCut[init][end] = mid;
        }
    }
    return min;
}

/*--------------------------------------------------*/

// Imprime a ordem na qual as operações devem ser realizadas resultando no mínimo de operações
void printPath(std::fstream& exit, int betterCut[21][21], int down, int up){
    if(down == up) return;

    int mid = betterCut[down][up];
    printPath(exit, betterCut, down, mid);
    printPath(exit, betterCut, mid+1, up);
    
    if(up - down == 1) exit << "   "<< down << " x " << up << '\n';
    else{
        if(back > up) exit << down << "- " << up << " x " << back << "- " << front << '\n';
        else if(back > down) exit << "   " << down << " x " << back << "- " << up << '\n'; 
        else exit << back << "- " << front << " x " << up << '\n';
    }
    front = up;
    back = down;
}

/*--------------------------------------------------*/

int main(){
    // Abertura dos arquivos de entrada e saída
    std::fstream entry;
    std::fstream exit;
    entry.open("entrada2.txt");
    exit.open("Lab2_Felipe_Farias_Ribeiro_Filho.txt", std::ios::out);

    // Leitura da entrada a ser ignorada
    std::string ignore;
    entry >> ignore;
    while(ignore != "matrizes"){
        entry >> ignore;
    }
    ignore = " ";

    // Escrita do "Header" da saída
    exit << "Exercício 2\n" <<
    "Produto de matrizes\n\n";

    // Leitura do número de matrizes com a qual trabalharemos
    entry >> matrixNumber;

    while(ignore != "matrizes"){
        entry >> ignore;
    }

    // Matriz que contém as linhas e as colunas das matrizes trabalhadas
    Matrix vec[21];
    for(int i = 1; i <= matrixNumber; i++){
        entry >> vec[i].lines >> vec[i].columns;
    }

    // Imprime o número de operações e o número de chamadas na função recursiva no arquivo de saída
    exit << "Total de multiplicações escalares = " << findMinimum(vec, 1, matrixNumber) 
    << '\n'
    << '\n'
    << "Chamadas na função: " << functionCalls
    << "\n\n"
    << "Melhor ordem para realizar os produtos: \n";


    printPath(exit, betterCut, 1 ,matrixNumber);

    entry.close();
    exit.close();
}