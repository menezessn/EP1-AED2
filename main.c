#include "Functions/kosarajuAlgorithm.c"
    


void main(int argc, char *argv[]){
    if(argc<2) return;
    int num = readFirstLine(argv[1]);  //recebe e guarda o número de vértices presente na primeira linha do arquivo input
    char** input = convertInput(argv[1], num); //coloca cada linha do input em um endereço de um array de strings
    char** names = readVertexNames(input, num); //guarda os nomes dos vértices em um array
    pGraph G = graphInit(num, names); //inicializa o grafo
    inputInsertArc(G, num, input, names);  //insere as arestas do grafo, devidamente informadas no input

    int sc[G->V];
    GRAPHstrongCompsK(G, sc, names, input);

    //linha 12 e 13 apenas para ver o funcionamento do programa, dps deverão ser excluídas
    printGraph(G); //imprime o grafo
    printf ("O grafo contem %d vertices e %d arestas\n", G->V, G->A); //informação extra
}
