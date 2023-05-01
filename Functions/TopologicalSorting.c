#include "kosarajuAlgorithmV2.c"


//0 = não foi visitado
//1 = nó foi visitado
//3 = terminou a busca do determinado vértice U 

//função para visitar todos os vértices
void visitP(pGraph G, int u, int* cor, List topological){
    cor[u] = 1; //marca como 1 o nó visitado
    link v = G->adj[u];
    while(v){
        if(cor[v->w] == 0){
            visitP(G, v->w, cor, topological);
        }
        v = v->next;
    }
    cor[u] = 3; //terminou a busca do determinado vértice U 
    link w = (link) malloc(sizeof(node));
    w->w = u;
    w->next = topological->cabeca->next;
    topological->cabeca->next = w;
}

void DFS (pGraph G, List topological){
    topological->names = G->names;
    topological->cabeca = (link) malloc (sizeof(node));
    topological->cabeca->next = NULL;
    topological->cabeca->w = -1;
    int cor [G->V];
    int u;
    for(u = 0 ; u < G->V ; u++){
        cor[u] = 0;
    }
    for(u = 0; u < G->V; u++){
        if(cor[u] == 0){
            visitP(G, u, cor, topological);
        }
    }
}



void printList(List topological){
    link u = topological->cabeca->next;
    while(u!=NULL){
        printf("%s ", topological->names[u->w]);
        u = u->next;
    }
}
