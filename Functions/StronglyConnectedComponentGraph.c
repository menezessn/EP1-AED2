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

void createStronglyConnectedGraph(int k, pGraph G, int* sc){

}


