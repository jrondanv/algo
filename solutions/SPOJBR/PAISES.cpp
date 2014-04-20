#include <stdio.h>
#include <string.h>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

#define NMAX 510

/* Determina as CFC em O(V+E)
* Entrada:
* - G: Matriz de adjacência do grafo direcionado
* - n: Quantidade de vértices
* Saída:
* A gosto do freguês, modifique a função CFC().
* Obs: vértices de 0 a n-1
*/

struct aresta {
    int dest;
    int custo;
};

int n;
int G[NMAX][NMAX];
bool foi[NMAX];
int cfc[NMAX];
int dist[NMAX];
stack<int> P;
vector<int> V;
vector<aresta> adj[NMAX];

int cc;

void dfs(int i){
    foi[i] = true;
    for (int j=0;j<n;j++)
        if (G[i][j] && !foi[j])
            dfs(j);
    P.push(i);
}

void dfsT(int i){
    foi[i] = true;
    V.push_back(i);
    for(int j=0;j<n;j++)
        if (G[j][i] && !foi[j]){
            // j está na mesma componente conexa que i
            dfsT(j);
        }
}

void CFC(){
    cc=0;
    memset(foi,0,sizeof(foi));
    for(int i=0;i<n;i++)
        if (!foi[i])
            dfs(i);

    memset(foi,0,sizeof(foi));
    while(!P.empty()){
        int u = P.top(); P.pop();
        if (!foi[u]){
            V.clear();
            dfsT(u);
            for (int j=0; j<V.size(); j++) cfc[V[j]]=cc;
            adj[cc].clear();
            cc++;
        }
    }
}

int dfsbd(int i) {
    foi[i]=true;
    for (int j=0;j<n;j++) {
        if (G[i][j]) {
            if (cfc[j] != cfc[i]) {
                aresta aux;
                aux.dest = cfc[j];
                aux.custo = G[i][j];
                adj[cfc[i]].push_back(aux);
            }
            
            if (!foi[j]) dfsbd(j);
        }
    }
}

int dij(int a, int b) {
    a = cfc[a];
    b = cfc[b];
    
    if (a == b) return 0;
    
    memset(foi,0,sizeof(foi));
    for (int i = 0; i < cc; i++) dist[i]=1000000000;
    dist[a] = 0;
    
    int curr = a;
    while (curr != -1 && curr != b) {
        foi[curr]=true;
        for (int i = 0; i < adj[curr].size(); i++) {
            aresta aux = adj[curr][i];
            dist[aux.dest] = min(dist[aux.dest], dist[curr]+aux.custo);
        }
        
        curr = -1;
        int min_dist = 1000000000;
        
        //for (int i = 0; i < cc; i++) printf("%d ", dist[i]);
        //printf("\n");
        
        for (int i = 0; i < cc; i++) {
            if (!foi[i] && dist[i] < min_dist) {
                curr = i;
                min_dist = dist[i];
            }
        }
    }
    
    if (curr == -1) return -1;
    return dist[b];
}

int e;

int main() {
    while (scanf("%d %d", &n, &e) && n) {
        memset(G,0,sizeof(G));
        for (int i = 0; i < e; i++) {
            int a,b,c;
            scanf("%d %d %d", &a, &b, &c);
            
            G[a-1][b-1]=c;
        }
        
        CFC();
        memset(foi,0,sizeof(foi));
        for (int i = 0; i < n; i++) {
            if (!foi[i]) dfsbd(i);
        }
        
        int k;
        scanf("%d", &k);
        
        for (int i = 0; i < k; i++) {
            int a, b;
            scanf("%d %d", &a, &b);
            
            int res = dij(a-1,b-1);
            if (res == -1) printf("Nao e possivel entregar a carta\n");
            else printf("%d\n", res);
        }
        
        printf("\n");
    }
}
