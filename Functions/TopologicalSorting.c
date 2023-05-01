#include "kosarajuAlgorithmV2.c"


//0 = não foi visitado
//1 = nó foi visitado
//3 = terminou a busca do determinado vértice U 


void DFS (pGraph G){
    int cor [G->V];
    int u;
    for(u = 0 ; u <G->V ; u++){
        cor[u] = 0;
    }
    for(u=0; u<G->V; u++){
        if(cor[u] = 0){
            visitaP(G, u, cor);
        }
    }
}
//função para visitar todos os vértices
void visitP(pGraph G, int u, int* cor){
    cor[u] = 1; //marca como 1 o nó visitado
    link v = G->adj[u]->w;
    while(v){
        if(cor[v->w] == 0){
            visitaP(G, v->w, cor);
        }
        v = v->next;
    }
    cor[u] = 3; //terminou a busca do determinado vértice U 
}
