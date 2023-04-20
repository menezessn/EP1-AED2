#include "adjList.c"

//---------funções de leitura de arquivo para receber entradas-------------------

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
		input[v][strcspn(input[v], "\n")] = 0;
		//printf ("\nconteudo: %s ", input[v]);
		v++;
	}
	fclose(fp);
	return input;
}
//faz uma cópia dos inputs
char** copyInput (char** input, int num){
	char** inputCopy = (char**) malloc (sizeof(char*)*(num+2));
	int i;
	for (i = 0 ; i<(num+2) ; i++){
		inputCopy[i] = (char*) malloc (sizeof(char)*100);
	}

	for (i=0 ; i<(num+2) ; i++) {
		strcpy(inputCopy[i], input[i]);
	}
		return inputCopy;
}

//Le o input e retorna um array com os nomes dos vértices
char ** readVertexNames(char** input, int num){
	char** inputCopy = copyInput(input, num);
	char delimiters[] = ":";
	char** names = (char**) malloc ((num)*sizeof(char*));
    int i;
    for (i = 0 ; i<(num) ; i++){
        names[i] = (char*) malloc (sizeof(char)*20);
    }
	for(i = 0 ; i<num ; i++){
		names[i] = strtok(inputCopy[i+1], delimiters);
	}
	return names;
}

//Faz as inserções de arestas no grafo
void inputInsertArc(pGraph G, int num, char** input, char** names){
	char** inputCopy = copyInput(input, num);
	char delimiters[] = ":;";

	int i = 1;

	while(i<num+1){
		char* vertexW = strtok(inputCopy[i], delimiters);
		while(vertexW != NULL){
			//printf("%s;", vertexW);
			if(strcmp(vertexW, names[i-1])==0){
				vertexW = strtok(NULL, delimiters);
				continue;
			}
			graphInsertArc(G, names[i-1], vertexW);
			vertexW = strtok(NULL, delimiters);
		}
		//printf("\n");
		i++;
	}
	
}
