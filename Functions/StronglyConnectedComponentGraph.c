#include "TopologicalSorting.c"

char** createNewNamesArray(pGraph G, int* sc, int k){
    char** newNames = (char**) malloc(sizeof(char*)*k);
    int i;
    for(i = 0 ; i<k ; i++){
        newNames[i] = (char*) malloc(sizeof(char) * 100);
    }
    i = 0;
    int j;
    int u = 0;
    char aux [100] = "";
    char empty[] = "";
    while (i  < k){
        for(j = 0; j < G->V; j++){
            if(sc[j] == i){
                strcat(aux, G->names[j]);
            }
        }
        strcpy(newNames[i], aux);
        strcpy(aux, empty);
        i++;
    }
    return newNames;
}
char* insertNewArcs(pGraph G, int* sc, int i, pGraph GFC, char** newNames){
    int j = 0;
    while(j < G->V){
        if(sc[j] == i){
            link node = G->adj[j];
            while(node != NULL){
                if(sc[node->w] != i){
                    graphInsertArc(GFC,  newNames[i], newNames[sc[node->w]]);
                }
                node = node->next;
            }
        }
        j++;
    }
}

pGraph createStronglyConnectedGraph(int k, pGraph G, int* sc){
    char** newNames = createNewNamesArray(G, sc, k);
    pGraph GFC = graphInit(k, newNames);
    int i;
    for (i = 0 ; i < k ; i++){
        insertNewArcs(G, sc, i, GFC, newNames);
        
    }
    return GFC;
}


