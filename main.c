#include "Functions/AdjList.c"

void main(){
    char** nomes= (char**)malloc(sizeof(char*)*4);
    int i;
    for(i=0 ; i<4 ; i++){
        nomes[i] = (char*)malloc(sizeof(char)*1);
    }
    
    strcpy(nomes[1][1],"a");
    strcpy(nomes[1][2],"b");
    strcpy(nomes[1][3],"c");
    strcpy(nomes[1][4],"e");
    
    pGraph G = graphInit(4, nomes);
    graphInsertArc(G, "a", "b");
    graphInsertArc(G, "a", "c");
    graphInsertArc(G, "b", "e");
    graphInsertArc(G, "c", "e");
    graphInsertArc(G, "e", "a");
    

    printGraph(G);
    printf ("O grafo contem %d vertices e %d arestas\n", G->V, G->A);
}
