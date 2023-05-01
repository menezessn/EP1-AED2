#include "Functions/StronglyConnectedComponentGraph.c"

void main(int argc, char *argv[]){

    pGraph G;
    char** names;
    int kosarajuVersion;

    if(argc>1){
    int num = readFirstLine(argv[1]);  //recebe e guarda o número de vértices presente na primeira linha do arquivo input
    char** input = convertInput(argv[1], num); //coloca cada linha do input em um endereço de um array de strings
    names = readVertexNames(input, num); //guarda os nomes dos vértices em um array
    G = graphInit(num, names); //inicializa o grafo
    inputInsertArc(G, num, input, names);  //insere as arestas do grafo, devidamente informadas no input
    kosarajuVersion = readLastLine(G->V, input);//função para ler a ultima linha do arquivo de entrada
    } else{
        G = graphRandER(30, 500, names);
        kosarajuVersion = 1;
    }

    
    int* sc = (int*) malloc(sizeof(int)*G->V); //array com associações dos vértices das componentes conectadas
    int k; //quantidade de componentes fortemente conectadas
    

    //verificando se utilizará a versão 1 ou 2 do algoritmo de Korasaju
    if(kosarajuVersion == 1){
        k = graphStrongCompsK(G, sc);
    } else if(kosarajuVersion == 2){
        k = graphStrongCompsK_V2(G, sc);
    }
    
    //verificando se o grafo é fortemente conexo
    if (k==1){
        printf("Sim\n");
    }else{
        printf("Nao\n");
    }

    //print da quantidade de componentes fortemente conectadas
    printf("%d\n", k);

    
    //cria o array com os nomes dos vértices do grafo de componentes fortemente conectadas
    char** newNames = createNewNamesArray(G, sc, k);
    
    //cria o grafo de componentes fortemente conectadas
    pGraph GFC = createStronglyConnectedGraph(k, G, sc);

    //Cria uma lista topológica
    List topological = (List) malloc(sizeof(list));
    DFS(GFC, topological);
    printList(topological);

    printf("\n");

    //imprime o grafo de componentes fortemente conectadas
    printGraph(GFC);

}

