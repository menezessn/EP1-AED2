#include "Functions/TopologicalSorting.c"

void main(int argc, char *argv[]){
    //if(argc<2) return;
    //argv[1]
    int num = readFirstLine("grafo.txt");  //recebe e guarda o número de vértices presente na primeira linha do arquivo input
    char** input = convertInput("grafo.txt", num); //coloca cada linha do input em um endereço de um array de strings
    char** names = readVertexNames(input, num); //guarda os nomes dos vértices em um array
    pGraph G = graphInit(num, names); //inicializa o grafo
    inputInsertArc(G, num, input, names);  //insere as arestas do grafo, devidamente informadas no input
    int* sc = (int*) malloc(sizeof(int)*G->V);
    int lastLine = readLastLine(G->V, input);//função para ler a ultima linha do arquivo de entrada
    int k;
    //verificando se utilizará a versão 1 ou 2 do algoritmo de Korasaju
    if(lastLine == 1){
        k = graphStrongCompsK(G, sc, names);
    } else if(lastLine == 2){
        k = graphStrongCompsK_V2(G, sc, names);
    }
    
    //verificando se o grafo é fortemente conexo
    if (k==1){
        printf("Sim\n");
    }else{
        printf("Nao\n");
    }
    printf("%d\n", k);//print da quantidade de componentes fortemente conectadas

    List topological = (List) malloc(sizeof(list));
    DFS(G, topological);//busca em profundiade para implementar a ordenação topológica
    printList(topological);//print da lista de ordenação topológica do grafo de componentes fortemente conectados
    

    // //linha 12 e 13 apenas para ver o funcionamento do programa, dps deverão ser excluídas
    // printGraph(G); //imprime o grafo
    // printf ("O grafo contem %d vertices e %d arestas\n", G->V, G->A); //informação extra
    // int* sc = (int*) malloc(sizeof(int)*G->V);

    // int k = graphStrongCompsK_V2(G, sc, names);


    // int lastLine = readLastLine(G->V, input);

    // printf("Versao do algoritmo de Kosaraju: %d", lastLine);

    // printf("\nTEste do grafo reverso\n");
    // pGraph reverse = createReverseGraph(G, names);
    // printGraph(reverse);

    // printf("\nTeste grafo aleatorio:\n");
    // char** namesRand;
    // pGraph rand = graphRandER(5,5, namesRand);
    // printGraph(rand);

    

    // int sc[G->V];
    // graphStrongCompsK(G, sc, names, input);

    // //linha 12 e 13 apenas para ver o funcionamento do programa, dps deverão ser excluídas
    // printGraph(G); //imprime o grafo
    // printf ("O grafo contem %d vertices e %d arestas\n", G->V, G->A); //informação extra
}

