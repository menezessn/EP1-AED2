#include "adjList.c"

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
