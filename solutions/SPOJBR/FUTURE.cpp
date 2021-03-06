#include <stdio.h>
#include <queue>

using namespace std;

typedef long long ll;
#define MAX 256
struct flow{
    ll cost, flow;
};
struct aresta{
    int v; long long cst, cap, flow;
    aresta(): v(0), cst(0), cap(0), flow(0) {}
    aresta(int _v, long long _cap, long long _cst, long long _flow):
        v(_v), cap(_cap), cst(_cst), flow(_flow){}
};
int fila[2][MAX], lbl[2][MAX], qf[2];
long long dist[MAX];
aresta arestas[MAX*MAX*2];
int grau[MAX], pai[MAX], adj[MAX][MAX], NV, S, T, e_contador;
const int inf = 1000000000;
struct MCMF {
    void inic(int n) {
        NV = n+2; S = n; T = n+1; e_contador = 0;
        for(int i = 0; i < NV; i++) grau[i] = 0;
    }
    void insere(int v1, int v2, int cap, int cst) {
        arestas[e_contador++] = aresta(v2, cap, cst, 0);
        arestas[e_contador++] = aresta(v1, 0, -cst, 0);
        adj[v1][ grau[v1]++ ] = e_contador - 2;
        adj[v2][ grau[v2]++ ] = e_contador - 1;
    }
    void insereDoS(int v2, int cap, int cst) {
        insere(S, v2, cap, cst);
    }
    void insereProT(int v1, int cap, int cst) {
        insere(v1, T, cap, cst);
    }
    bool belman() {
        for(int i = 0; i < NV; i++) {
            dist[i] = inf;
            lbl[0][i] = lbl[1][i] = 0;
            pai[i] = -1;
        }
        qf[0] = 0; fila[0][qf[0]++] = S;
        pai[S] = -2; dist[S] = 0;
        for(int k = 0; k < NV; k++) {
            int fila_at = k&1;
            int fila_prox = 1 - fila_at;
            qf[fila_prox] = 0;
            for(int i = 0; i < qf[fila_at]; i++) {
                int v = fila[fila_at][i];
                lbl[fila_at][v] = 0;
                for(int j = 0; j < grau[v]; j++) {
                    aresta e = arestas[adj[v][j]];
                    aresta ei = arestas[adj[v][j] ^ 1];
                    int w = e.v;
                    ll cap = e.cap - e.flow, cst = e.cst;
                    if(ei.flow) cst = -ei.cst;
                    if(cap > 0 && dist[w] > dist[v] + cst) {
                        if(!lbl[fila_prox][w]){
                            fila[fila_prox][qf[fila_prox]++] = w;
                            lbl[fila_prox][w] = 1;
                        }
                        dist[w] = dist[v] + cst;
                        pai[w] = adj[v][j];
                    }
                }
            }
        }
        return pai[T] != -1;
    }
    flow mcmf() {
        flow f = (flow) { 0 , 0 };
        while(belman()) {
            ll bot = inf, cst = 0;
            for(int v = T; pai[v] >= 0; v = arestas[pai[v] ^ 1].v) {
                bot = min (bot , arestas[pai[v]].cap - arestas[pai[v]].flow);
            }
            for(int v = T; pai[v] >= 0; v = arestas[pai[v] ^ 1].v) {
                aresta &e = arestas[pai[v]];
                aresta &ei = arestas[pai[v] ^ 1];
                if(ei.flow) { cst += bot*(-ei.cst); }
                else { cst += bot*e.cst; }
                e.flow += bot;
                ei.flow -= bot;
            }
            f.flow += bot;
            f.cost += cst;
        }
        return f;
    }
};

int n,m;

int u[5000], v[5000], cst[5000];

int main() {
    int t = 1;
    while (scanf("%d %d", &n, &m) != EOF) {
        printf("Instancia %d\n", t++);
        
        MCMF grafo;
        grafo.inic(n);
        
        
        for (int i = 0; i < m; i++) {
            scanf("%d %d %d", &u[i], &v[i], &cst[i]);
        }    
        
        int d,k;
        scanf("%d %d", &d, &k);
        
        grafo.insereDoS(0, d, 0);
        
        for (int i = 0; i < m; i++) {
            grafo.insere(u[i]-1,v[i]-1,k,cst[i]);
            grafo.insere(v[i]-1,u[i]-1,k,cst[i]);
        }
        
        grafo.insereProT(n-1, d, 0);
        
        flow res = grafo.mcmf();
        if (res.flow != d) printf("impossivel\n");
        else printf("%d\n", res.cost);
        
        printf("\n");
    }
}
