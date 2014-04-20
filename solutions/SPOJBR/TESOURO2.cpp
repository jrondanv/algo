#include <stdio.h>
#include <vector>

using namespace std;

int ma, n;

vector<int> adj[10000];
int tes[10000];
int visitado[10000];
int ret[10000];
int id = 0;

int busca(int v) {
    if (visitado[v] == id) return ret[v];
    
    visitado[v] = id;
    
    int m = 0;
    int sz = adj[v].size();
    for (int i = 0; i < sz; i++) {
        int val = busca(adj[v][i]);
        m = max(m, val);
    }
    
    //printf("busca[%d] retorna %d\n",v,m+tes[v]);

    ma = max(ma, m+tes[v]);
    return (ret[v] = m+tes[v]);
}

int main() {
    while (scanf("%d", &n) && n) {
        id++;
        ma = 0;
        
        for (int i = 0; i < n; i++) adj[i].clear();
            
        for (int i = 0; i < n; i++) {    
            int q,p;
            scanf("%d %d", &q, &p);
        
            tes[i] = q;
            for (int j = 0; j < p; j++) {
                int w;
                scanf("%d", &w);
                adj[w-1].push_back(i);
            }
        }
        
        for (int i = 0; i < n; i++) {
            if (visitado[i] != id) busca(i);
        }
        printf("%d\n",ma);
    }
}