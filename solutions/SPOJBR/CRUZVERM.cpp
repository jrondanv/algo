#include <stdio.h>

int adj[6000][6001];
int marc[6000];

int total;

int dfs(int node) {
    marc[node] = 1;
    int children_marked = 0;
    
    for (int i = 1; i < adj[node][0]; i++) {
        int dest = adj[node][i];
        if (!marc[dest]) children_marked += dfs(dest);
    }
    
    if (!children_marked) total++;
    return !children_marked;
}

int main() {
    int T;
    scanf("%d", &T);
    
    for (int t = 0; t < T; t++) {
        int N;
        scanf("%d", &N);
        
        total = 0;
        for (int i = 0; i < N; i++) {
            adj[i][0] = 1;
            marc[i] = 0;
        }
        
        for (int i = 0; i < N-1; i++) {
            int u,v;
            scanf("%d %d", &u, &v);
            
            u--; v--;
            
            adj[u][adj[u][0]++] = v;
            adj[v][adj[v][0]++] = u;
        }
        
        dfs(0);
        printf("%d\n",total);
    }
    
    return 0;
}
            
