#include <stdio.h>
#include <string.h>

#define NMAX 1000

int vis[NMAX];
int G[NMAX][NMAX];
int g[NMAX];
int N;
int intime;
int ponte;

void reset(){
   for (int i=0; i<N; i++)
       vis[i] = 0;
}
int biponte(int v, int pai){
   if(vis[v]) return vis[v];
   
   int R = vis[v] = intime++;

   for(int i=0; i<g[v]; i++){
       if(G[v][i] == pai)
           continue;
       int r = biponte(G[v][i], v);
       if(r < R){
           // v está na mesma componente biconexa de G[v][i]
           // union_set(v, G[v][i]);
           R = r;
       }
   }
   if(R >= vis[v] && pai != -1)
       ponte = 1;
       // Se o grafo permitir multiplas arestas, verificar
       // se a aresta (v+1, pai+1) ocorre mais de uma vez.
   return R;
}

int biconexo(){
   intime = 1;
   for (int i=0; i<N; i++)
       biponte(i, -1);
}

int main() {
    int M;
    while (scanf("%d %d", &N, &M) && N) {
        memset(g,0,sizeof(g));
        
        for (int i = 0; i < M; i++) {
            int A,B;
            scanf("%d %d", &A, &B);    
            
            A--;
            B--;
            
            G[A][g[A]++] = B;
            G[B][g[B]++] = A;
        }
        
        reset();
        ponte = 0;
        biconexo();
        if (!ponte) printf("S\n");
        else printf("N\n");
    }
    
}
