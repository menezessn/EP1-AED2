//todo código em um único arquivo 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



//---------Estruturas para fazer listas de adjacências para representar grafos --------------

typedef int vertex;
typedef char* vertexName;

// estrutura para cada nó da lista de adjacência 
typedef struct aux {
    vertex w; //número do vértice que é vizinho ao vértice v
    struct aux* next; //endereço do nó seguinte da lista
} node;
typedef node* link; //link é um ponteiro para um nó



//estrutura que implementa um grafo
typedef struct {
    int V; //número de vértices do grafo
    int A; //número de arestas do grafo
    vertexName* names; //array com os nomes dos vértices
    link* adj; //array de listas de nós
}graph;

typedef graph* pGraph; //pGraph é um ponteiro para um grafo

//----------------------------------------------------------------------------------------------------



//-----------------Funções para criar grafos com listas de adjacências ---------------------------

//Função que cria o grafo
//int V é o número de vértices do grafo
pGraph graphInit(int V, char** names ){
    pGraph G = (pGraph) malloc(sizeof(graph));
    G->V = V;
    G->A = 0;
    G->adj = (link*) malloc (V*sizeof(link));
    G->names = (char**) malloc (sizeof(char**)*V);
    int i;
    for (i = 0 ; i<V ; i++){
        G->names[i] = (char*) malloc (sizeof(char)*20);
    }
    int v;
    for (v = 0; v < V; v++){ 
        G->adj[v] = NULL; 
        strcpy( G->names[v], names[v]);
    }
    return G;
}

//Cria um novo nó
link newNode( vertex w, link next) { 
   link a = (link) malloc( sizeof (node));
   a->w = w; 
   a->next = next;     
   return a;                         
}
int findVertexIndex(pGraph G, vertexName name) {
    int i;
    for(i = 0; i < G->V; i++) {
        if(strcmp(G->names[i], name) == 0) {
            return i;
        }
    }
    return -1; // retorna -1 se não encontrar o vértice com o nome especificado
}

//Insere o novo nó grafo, criando uma nova aresta
void graphInsertArc(pGraph G, vertexName nv, vertexName nw){
    vertex v = findVertexIndex(G, nv);
    vertex w = findVertexIndex(G, nw);
    link a = G->adj[v];
    while(a != NULL){
        if(a->w == w) return;
        a = a->next;
    }
    G->adj[v] = newNode (w, G->adj[v]);
    G->A++;
}

//imprime o grafo
void printGraph(pGraph G){
    int i = 0;
    for(i = 0 ; i < G->V ; i++){
        link node = G->adj[i];
        printf ("Lista de adjacencias do vertice %s: \n", G->names[i]);
        while(node != NULL){
            printf ("%s -> ", G->names[node->w]);
            node = node->next;
        }
        printf("\n");
    }
}

//----------------------------------------------------------------------



//funções de leitura de arquivo para receber entradas

//le a primeira linha do output pra verificar a quantidade de vértices que a entrada vai ter
int readFirstLine (char* fileName) {
    int firstLine; //vai receber o valor da primeira linha
	FILE *fp;
	fp= fopen(fileName, "r");
	fscanf (fp, "%d\n", &firstLine);
	fclose(fp);
	return firstLine; //retorna o valor da primeira linha
}

//converte a entrada em texto para um array de strings, onde cada linha está contida em um indíce do array
char** convertInput (char* fileName, int num){
	char** input = (char**) malloc ((num+2)*sizeof(char*));
    int i;
    for (i = 0 ; i<(num+2) ; i++){
        input[i] = (char*) malloc (sizeof(char)*100);
    }
	
	FILE *fp;
	fp= fopen(fileName, "r");
	int v = 0;
	while(!feof(fp)){
		//printf ("\nlendo linha %d ", v);
		fgets (input[v], 100, fp );
		//printf ("\nconteudo: %s ", input[v]);
		v++;
	}
	fclose(fp);
	return input;
}


char ** readVertexNames(char** input, int num){
	char delimiters[] = ":";
	char** names = (char**) malloc ((num)*sizeof(char*));
    int i;
    for (i = 0 ; i<(num) ; i++){
        names[i] = (char*) malloc (sizeof(char)*20);
    }
	for(i = 0 ; i<num ; i++){
		names[i] = strtok(input[i+1], delimiters);
	}
	return names;
}

void inputInsertArc(pGraph G, int num, char** input, char** names){
	char delimiters[] = ":;";

	int i = 1;

	while(i<num+1){
		char* vertexW = strtok(input[i], delimiters);
		//printf("%s\n", vertexW);
		while(vertexW != NULL){
			vertexW = strtok(NULL, delimiters);
			printf("isso é %s\n", vertexW);
			printf("Pao");
			//graphInsertArc(G, names[i-1], vertexW);
		}
		i++;
	}
	
}

void main(){
    int num = readFirstLine("teste.txt");
    //printf("%d\n", num);

    char** input = convertInput("teste.txt", num);
     int v = 0;
	while(v < (num+2)){
		printf ("\nlendo linha %d ", (v+1));
		printf ("\nconteudo: %s ", input[v]);
		v++;
	}

    printf("\n-------------------\n");

    char** names = readVertexNames(input, num);
    v = 0;
    while (v<num)
    {
        printf("%s\n", names[v]);
        v++;
    }

    printf("\n-------------------\n");

    pGraph G = graphInit(num, names);

    printf("\n-------------------\n");

    inputInsertArc(G, num, input, names);

    printf("\n-------------------\n");

    //printGraph(G);
    


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
