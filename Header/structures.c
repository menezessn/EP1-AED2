#include <stdio.h>
#include <stdlib.h>
#include <string.h>



//---------Estruturas para fazer listas de adjacências para representar grafos --------------

typedef int vertex;
typedef char* vertexName;

// estrutura para cada nó da lista de adjacência 
typedef struct aux {
    vertex w; //número do vértice que é vizinho ao vértice v
    struct aux* next; //endereço do nó seguinte da lista
} node;
typedef node* link; //link é um ponteiro para um nó



//estrutura que implementa um grafo
typedef struct {
    int V; //número de vértices do grafo
    int A; //número de arestas do grafo
    vertexName* names; //array com os nomes dos vértices
    link* adj; //array de listas de nós
}graph;

typedef graph* pGraph; //pGraph é um ponteiro para um grafo

//----------------------------------------------------------------------------------------------------