#include "randomGraph.c"

//VERSÃO 2 DO ALGORTIMO DE KORASAJU
int graphStrongCompsK_V2( pGraph G, int *sc,char** names) // recebe o grafo e um vetor que servirá para mapear os vértices fortemente conexos
{

   //chamando busca em profundidade para o grafo reverso
   cnt = 0; 
   cntt = 0;
   vertex v; 
   for (v = 0; v < G->V; ++v) {
      p[v] = -1;
   }
   for (v = 0; v < G->V; ++v){
      if (p[v] == -1){
         dfsR( G, v); 
      }
   }

   //criação do grafo reverso
   pGraph GR = createReverseGraph( G,names);
   
   for (v = 0; v < GR->V; ++v){
      vv[d[v]] = v;
   }

   //chamando busca em profundidade para o grafo reverso
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

   //retorno da quantidade de componentes fortemente conectadas do grafo
   return k;
}