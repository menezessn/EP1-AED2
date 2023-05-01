#include "DFS.c"

static int cnt, pre[1000]; // pre salva o tempo de descoberta
static int cntt, post[1000]; //post salva o tempo que foi visitado 
static vertex vv[1000];

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
   return GR;
}

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
static void dfsR( pGraph GR, vertex v) 
{ 
   pre[v] = cnt++; 
   link a = GR->adj[v];
   while(a != NULL){
      if (pre[a->w] == -1){
         dfsR( GR, a->w); 
      }
      a = a->next;
   }
   post[v] = cntt++;
}
int GRAPHstrongCompsK( pGraph G, int *sc,char** names) // recebe o grafo e um vetor que servirá para mapear os vértices fortemente conexos
{
   
   // fase 1:
   pGraph GR = createReverseGraph( G,names);
   cnt = 0; 
   cntt = 0;
   vertex v; 
   for (v = 0; v < GR->V; ++v) {
      pre[v] = -1;
   }
   for (v = 0; v < GR->V; ++v){
      if (pre[v] == -1){
         dfsR( GR, v); 
      }
         
   }
      
   for (v = 0; v < GR->V; ++v){
      vv[post[v]] = v;
   }
      
   // vv[0..V-1] é permutação de GR em pós-ordem

   // fase 2:
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
   
   return k;
}