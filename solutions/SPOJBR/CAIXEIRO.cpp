#include <stdio.h>
#include <string.h>
#include <queue>
#include <algorithm>

using namespace std;

int pd[601][600];

int adjdeg[300];
int adj[300][300];

int deg[300];
int children[300][300];
int parent[300];

int bfs_order[300];

int main() {
    int C, F;
    int teste=1;
    
    while (scanf("%d %d", &C, &F) && C) {
        memset(adjdeg,0,sizeof(adjdeg));
        
        for (int i = 0; i < C-1; i++) {
            int a, b;
            scanf("%d %d", &a, &b);
            
            a--;
            b--;
            
            adj[a][adjdeg[a]++]=b;
            adj[b][adjdeg[b]++]=a;
        }
        
        queue<int> fila;
        fila.push(0);
        parent[0] = -1;
        
        memset(deg,0,sizeof(deg));
        
        int bfs_count = 0;
        for (int i = 0; i < C; i++) {
             int elem = fila.front();
             fila.pop();
             
             bfs_order[bfs_count++] = elem;
             
             for (int j = 0; j < adjdeg[elem]; j++) {
                int dest = adj[elem][j];
                if (dest != parent[elem]) {
                    fila.push(dest);
                    parent[dest]=elem;
                    children[elem][deg[elem]++]=dest;
                }
            }
        }
        
        for (int i = 0; i < 2*C; i++) {
            pd[0][i]=0;
        }
        
        for (int d = 1; d <= F; d++) {
            int festa;
            scanf("%d", &festa);
            festa--;
            
            for (int i = 0; i < C; i++) {
                int node = bfs_order[i];
                pd[d][node] = pd[d-1][node];
                
                if (node == festa) pd[d][node]++;
                else if (node != 0) pd[d][node] = max(pd[d][node], pd[d][parent[node]]);
            }
            
            for (int i = C; i < 2*C; i++) {
                int node = bfs_order[2*C-i-1];
                int index = C+node;
                
                pd[d][index] = max(pd[d-1][index], pd[d-1][node]);
                
                if (festa == node) pd[d][index]++;
                
                for (int j = 0; j < deg[node]; j++) {
                        pd[d][index] = max(pd[d][index], pd[d][children[node][j] + C]);
                }
            }
        }
        
        printf("Teste %d\n", teste++);
        printf("%d\n\n", pd[F][C]);    
    }
    
    return 0;
}
        
        
