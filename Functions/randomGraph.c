#include "kosarajuAlgorithm.c"


pGraph graphRandER( int V, int A, char** names) { 
    names = (char**) malloc(V*sizeof(char*));
    int i;
    for(i = 0; i<V; i++){
            names[i] = (char*) malloc(sizeof(char));
            sprintf(names[i], "%d", i);
    }
    static int initialized = 0;
    if (!initialized) {
        srand((unsigned) time(NULL));
        initialized = 1;
    }
    double prob = (double) A / (V*(V-1));
    pGraph G = graphInit(V, names);
    vertex v;
    vertex w;
    for (v = 0; v < V; ++v)
        for ( w = 0; w < V; ++w)
            if (v != w){
                if (rand( ) < prob*(RAND_MAX+1.0)){
                    char* nv = (char*) malloc(sizeof(char));
                    sprintf(nv, "%d", v);
                    char* nw = (char*) malloc(sizeof(char));
                    sprintf(nw, "%d", w);
                    graphInsertArc( G, nv, nw);
                }
            }
    return G;
}
// /* A função randV() devolve um vértice aleatório do grafo G. Vamos supor que G->V <= RAND_MAX. */
// vertex randV( pGraph G) { 
//     static int initialized = 0;
//     if (!initialized) {
//         srand((unsigned) time(NULL));
//         initialized = 1;
//     }
//     int r;
//     r = rand( ) % G->V;
//     return r;
// }

// pGraph graphRand( int V, int A) {
//     char ** names = (char**) malloc(V*sizeof(char*));
//     int i;
//     for(i = 0; i<V; i++){
//         names[i] = (char*) malloc(sizeof(char));
//         sprintf(names[i], "%d", i);
//     }
//     pGraph G = graphInit(V, names);
//     while (G->A < A) {
//         vertex v = randV(G);
//         char* nv = (char*) malloc(sizeof(char));
//         sprintf(nv, "%d", v);
//         vertex w = randV(G);
//         char* nw = (char*) malloc(sizeof(char));
//         sprintf(nw, "%d", w);
//         if (v != w) 
//             graphInsertArc( G, nv, nw);
//     }
//     return G;
// }
