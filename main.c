#include "Functions/AdjList.c"

void main(){
    pGraph G = graphInit(5);
    graphInsertArc(G, 0, 1);
    graphInsertArc(G, 0, 4);
    graphInsertArc(G, 1, 2);
    graphInsertArc(G, 1, 3);
    graphInsertArc(G, 1, 4);
    graphInsertArc(G, 2, 3);
    graphInsertArc(G, 3, 4);

    printGraph(G);
    printf ("O grafo contem %d vertices e %d arestas\n", G->V, G->A);
}
