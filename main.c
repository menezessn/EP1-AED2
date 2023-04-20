#include "Functions/FileReader.c"

void main(){
    int num = readFirstLine("teste.txt");
    printf("%d\n", num);

    char** input = convertInput("teste.txt", num);
    int v = 0;
	while(v < (num+2)){
		printf ("\nlendo linha %d ", v);
		printf ("\nconteudo: %s ", input[v]);
		v++;
	}

    // char** nomes = (char**) malloc (sizeof(char*)*4);
    // int i;
    // for (i = 0 ; i<4 ; i++){
    //     nomes[i] = (char*) malloc (sizeof(char)*20);
    // }

    
    // strcpy(nomes[0],"a");
    // strcpy(nomes[1],"b");
    // strcpy(nomes[2],"c");
    // strcpy(nomes[3],"e");
    // printf("%s", nomes[0]);
    // pGraph G = graphInit(4, nomes);

    // printf("hello world");
    // graphInsertArc(G, "a", "b");
    // graphInsertArc(G, "a", "c");
    // graphInsertArc(G, "b", "e");
    // graphInsertArc(G, "c", "e");
    // graphInsertArc(G, "e", "a");
    
    // printf("hello world");
    // printGraph(G);
    // printf ("O grafo contem %d vertices e %d arestas\n", G->V, G->A);

}
