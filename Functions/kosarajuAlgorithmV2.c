#include "kosarajuAlgorithm.c"


int GRAPHstrongCompsKV2( pGraph G, int *sc,char** names) // recebe o grafo e um vetor que servirá para mapear os vértices fortemente conexos
{

   //chamar DFS (V, A) para calcular f[u]
   cnt = 0; 
   cntt = 0;
   vertex v; 
   for (v = 0; v < G->V; ++v) {
      pre[v] = -1;
   }
   for (v = 0; v < G->V; ++v){
      if (pre[v] == -1){
         dfsR( G, v); 
      }
         
   }

   //Calcular A(T)
   // fase 1:
   pGraph GR = createReverseGraph( G,names);
   
      
   for (v = 0; v < GR->V; ++v){
      vv[post[v]] = v;
   }
   //Chamar DFS (V, A(T) considerando no laço principal
   //os vértices em ordem decrescente de f (calculados na linha 1)
   // fase 2:
   for (v = 0; v < GR->V; ++v) sc[v] = -1;
   int k = 0;
   int i;
   for (i = GR->V-1; i >= 0; --i) {
      v = vv[i];
      if (sc[v] == -1) { // nova etapa
         dfsRstrongCompsK( GR, v, sc, k);
         k++;
      }
   };
   
   return k;
}