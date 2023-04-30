#include "fileReader.c"

//função que é responsável por fazer a busca em profundidade
void DFS(pGraph G, int v, int *visited, int *discTime) {
   
    visited[v] = 1; // marca o vértice como visitado
    printf("%d ", v); // imprime o vértice visitado

    vertex w;
    link list = G->adj[v];
    while(list != NULL) {
        w = list->w;
        if(!visited[w]) { // se o vértice ainda não foi visitado
            discTime[w] = discTime[v] + 1; // atualiza o tempo de descoberta
            DFS(G, w, visited, discTime); // chama a DFS recursivamente
        }
        list = list->next; // avança para o próximo vértice adjacente
    }
}
