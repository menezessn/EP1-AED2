#include "../Header/structures.c"


//-----------------Funções para criar grafos com listas de adjacências ---------------------------

//Função que cria o grafo
//int V é o número de vértices do grafo
pGraph graphInit(int V, char** names ){
    pGraph G = (pGraph) malloc(sizeof(graph));
    G->V = V;
    G->A = 0;
    G->adj = (link*) malloc (V*sizeof(link));
    G->names = (char**) malloc (sizeof(char*)*V);
    int i;
    for (i = 0 ; i<V ; i++){
        G->names[i] = (char*) malloc (sizeof(char)*20);
    }
    int v;
    for (v = 0; v < V; v++){ 
        G->adj[v] = NULL; 
        strcpy( G->names[v], names[v]);
    }
    return G;
}

//Cria um novo nó
link newNode( vertex w, link next) { 
   link a = (link) malloc( sizeof (node));
   a->w = w; 
   a->next = next;     
   return a;                         
}
int findVertexIndex(pGraph G, vertexName name) {
    int i;
    for(i = 0; i < G->V; i++) {
        if(strcmp(G->names[i], name) == 0) {
            return i;
        }
    }
    return -1; // retorna -1 se não encontrar o vértice com o nome especificado
}

//Insere o novo nó grafo, criando uma nova aresta
void graphInsertArc(pGraph G, vertexName nv, vertexName nw){
    vertex v = findVertexIndex(G, nv);
    vertex w = findVertexIndex(G, nw);
    link a = G->adj[v];
    while(a != NULL){
        if(a->w == w) return;
        a = a->next;
    }
    G->adj[v] = newNode (w, G->adj[v]);
    G->A++;
}

//imprime o grafo
void printGraph(pGraph G){
    int i = 0;
    for(i = 0 ; i < G->V ; i++){
        link node = G->adj[i];
        printf ("%s:", G->names[i]);
        while(node != NULL){
            printf ("%s;", G->names[node->w]);
            node = node->next;
        }
        printf("\n");
    }
}

//----------------------------------------------------------------------