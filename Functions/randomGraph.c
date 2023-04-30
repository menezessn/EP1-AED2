#include "DFS.c"

/* A função randV() devolve um vértice aleatório do grafo G. Vamos supor que G->V <= RAND_MAX. */
vertex randV( pGraph G) { 
    static int initialized = 0;
    if (!initialized) {
        srand((unsigned) time(NULL));
        initialized = 1;
    }
    int r;
    r = rand( ) % G->V;
    return r;
}

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
        char* nv = (char*) malloc(sizeof(char));
        sprintf(nv, "%d", v);
        vertex w = randV(G);
        char* nw = (char*) malloc(sizeof(char));
        sprintf(nw, "%d", w);
        if (v != w) 
            graphInsertArc( G, nv, nw);
    }
    return G;
}
