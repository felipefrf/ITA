/* -------------------------------------------------- */
/*                 Grafos Direcionados                */
/* -------------------------------------------------- */

/**
 * Matriz de Adjacência com Matriz
*/

// struct Digrafo{
//     int tamanho;
//     bool** aresta;
// };

// Digrafo* inicializaDigrafo(int tamanho){
//     Digrafo* g = new Digrafo;
//     g->tamanho = tamanho;
//     g->aresta = new bool* [tamanho+1];
//     for(int i = 1; i <= tamanho; i++){
//         g->aresta[i] = new bool [tamanho+1];
//         for(int j = 1; j <= tamanho; j++){
//             g->aresta[i][j] = false;
//         }
//     }
//     return g;
// }

/**
 * Matriz de Adjacência com Array Simples
*/

// struct Digrafo{
//     int tamanho;
//     bool* aresta;
// };

// Digrafo* inicializaDigrafo(int tamanho){
//     Digrafo* g = new Digrafo;
//     g->tamanho = tamanho;
//     g->aresta = new bool [tamanho];
//     for(int i = 0; i < tamanho * tamanho; i++)
//         g->aresta[i] = false;
//     return g;
// }

/**
 * Lista de Adjacência
*/

// struct Element{
//     Element* next;
//     int index;
//     float weight;
// };

// struct Digrafo{
//     int order;
//     Element** elementos;
// };

// Digrafo* inicializaDigrafo(int order){
//     Digrafo* g = new Digrafo;
//     g->order = order;
//     g->elementos = new Element* [order+1];
//     for(int i = 1; i <= order; i++)
//         g->elementos[i] = nullptr;
//     return g;
// }

/* -------------------------------------------------- */
/*             Grafos Não-Direcionados                */
/* -------------------------------------------------- */

/**
 * Matriz de Adjacência - Matriz Triangular - Matriz
*/ 

// struct Graph{
//     int order;
//     bool** arestas;
// };

// Graph* inicializaGrafo(int order){
//     Graph* g = new Graph;
//     g->order = order;
//     g->arestas = new bool* [order+1];
//     for(int i = 1; i <= order; i++){
//         g->arestas[i] = new bool [order+1];
//         for(int j = i; j > 0; j--){
//             g->arestas[i][j] = false;
//         }
//     }
//     return g;
// }

/**
 * Matriz de Adjacência - Matriz Triangular - Vetor Unidimensional
*/

// struct Graph{
//     int order;
//     bool* edges;
// };

// Graph* inicializaGrafo(int order){
//     Graph* g = new Graph;
//     g->order = order;
//     g->edges = new bool[(order*(order+1))/2];
//     for(int i = 0; i < (order*(order+1))/2; i++)
//         g->edges[i] = false;
//     return g;
// }

// bool grafoTemAresta(Graph* g, int u, int v){
//     if(u < v){ // u deve ser maior que v
//         int aux = u;
//         u = v;
//         v = aux;
//     }
//     return g->edges[(u*(u+1))/2 + v];
// }

/**
 * Matriz de Adjacência com Grafo Ponderado - Vetor Unidimensional
*/

// struct Element{
//     float weight;
//     bool used;
// };

// struct Digraph{
//     int order;
//     Element** edges;
// };

// Todas as implementações de Grafos Ponderados, basta
// mudar a declaração de forma a criar uma struct
// para o elemento (edges) que contém o booleano que
// diz se este está preenchido, ou não, e diz o que está
// guardado como peso da aresta.