#include <stdio.h>
#include <stdlib.h>
#define vertex int;

//---------Estruturas para fazer listas de adjacências para representar grafos --------------

// estrutura para cada nó da lista de adjacência 
typedef struct {
    vertex w; //número do vértice que é vizinho ao vértice v
    link next; //endereço do nó seguinte da lista
} node;

typedef struct node* link; //link é um ponteiro para um nó

//estrutura que implementa um grafo
typedef struct {
    int V; //número de vértices do grafo
    int A; //número de arestas do grafo
    link* adj; //array de listas de nós
}graph;

typedef struct graph* pGraph; //pGraph é um ponteiro para um grafo

//----------------------------------------------------------------------------------------------------