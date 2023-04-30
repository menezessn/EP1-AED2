#include "DFS.c"

pGraph graphRand( int V, int A) {
    char ** names = (char**) malloc(V*sizeof(char*));
    int i;
    for(i = 0; i<V; i++){
        names[i] = (char*) malloc(sizeof(char));
        sprintf(names[i], "%d", i);
    }
    pGraph G = graphInit(V, names);
    while (G->A < A) {
        vertex v = randV(G);
        vertex w = randV(G);
        if (v != w) 
            GRAPHinsertArc( G, v, w);
    }
    return G;
    }
    /* A função randV() devolve um vértice aleatório do grafo G. Vamos supor que G->V <= RAND_MAX. */
    vertex randV( pGraph G) { 
    int r;
    r = rand( ) % G->V;
    return r;
}