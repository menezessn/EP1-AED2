#include "fileReader.c"

static int cnt, p[1000]; // p salva o tempo de descoberta
static int cntt, d[1000]; //d salva o tempo que foi visitado 
static vertex vv[1000];

//VERSÃO 1 DO ALGORTIMO DE KORASAJU

//faz uma cópia do array de nomes do array original
char** copyNames (char** names, int V){
	char** namesCopy = (char**) malloc (sizeof(char*)*V);
	int i;
	for (i = 0 ; i<V ; i++){
		namesCopy[i] = (char*) malloc (sizeof(char)*100);
	}

	for (i=0 ; i<V ; i++) {
		strcpy(namesCopy[i], names[i]);
	}
		return namesCopy;
}

//cria um grafo reverso
pGraph createReverseGraph( pGraph G,char** names) {
   char** namesCopy = copyNames(names, G->V);
   pGraph GR = graphInit( G->V, namesCopy);
   for (vertex v = 0; v < G->V; ++v){
      link a = G->adj[v];
      while(a != NULL){
         graphInsertArc(GR, namesCopy[a->w], namesCopy[v] );
         a = a->next;
      }
      
   }      
   return GR;//retorna o grafo reverso
}
//busca em profundidade para o grafo
static void dfsRstrongCompsK( pGraph G, vertex v, int *sc, int k) { 
   sc[v] = k;
   link a = G->adj[v];
   while(a != NULL){
      if (sc[a->w] == -1) {
         dfsRstrongCompsK( G, a->w, sc, k);
      }
      a = a->next;
   } 
}
//busca em profundidade para o grafo reverso
static void dfsR( pGraph GR, vertex v) 
{ 
   p[v] = cnt++; 
   link a = GR->adj[v];
   while(a != NULL){
      if (p[a->w] == -1){
         dfsR( GR, a->w); 
      }
      a = a->next;
   }
   d[v] = cntt++;
}


int graphStrongCompsK( pGraph G, int *sc,char** names) // recebe o grafo e um vetor que servirá para mapear os vértices fortemente conexos
{
   //criação do grafo reverso
   pGraph GR = createReverseGraph( G,names);

   //chamando busca em profundidade para o grafo reverso
   cnt = 0; 
   cntt = 0;
   vertex v; 
   for (v = 0; v < GR->V; ++v) {
      p[v] = -1;
   }
   for (v = 0; v < GR->V; ++v){
      if (p[v] == -1){
         dfsR( GR, v); 
      }
         
   }
      
   for (v = 0; v < GR->V; ++v){
      vv[d[v]] = v;
   }
      
  
   //chamando busca em profundidade para o Grafo 
   for (v = 0; v < G->V; ++v) sc[v] = -1;
   int k = 0;
   int i;
   for (i = G->V-1; i >= 0; --i) {
      v = vv[i];
      if (sc[v] == -1) { // nova etapa
         dfsRstrongCompsK( G, v, sc, k);
         k++;
      }
   };
   
   //retorno da quantidade de componentes fortemente conectadas do grafo
   return k;
}