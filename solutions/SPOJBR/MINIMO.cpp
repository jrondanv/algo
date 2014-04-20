#include <stdio.h>
#include <algorithm>

using namespace std;

int g[110][110][110];
#define INF 1000000000

int main() {
    int n, m;
    int teste = 1;
    
    while (scanf("%d %d", &n, &m) != EOF) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                g[i][j][0] = INF;
            }
        }
        
        for (int i = 0; i < n; i++) g[i][i][0] = 0;
        
        for (int i = 0; i < m; i++) {
            int u, v, c;
            scanf("%d %d %d", &u, &v, &c);
            
            g[u-1][v-1][0] = min(g[u-1][v-1][0], c);
        }
        
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    g[i][j][k+1] = min(g[i][k][k] + g[k][j][k], g[i][j][k]);
                }
            }
        }
        
        int c;
        scanf("%d", &c);
        
        printf("Instancia %d\n", teste++);
        for (int i = 0; i < c; i++) {
           int o, d, t;
           scanf("%d %d %d", &o, &d, &t);
           
           printf("%d\n", g[o-1][d-1][t] == INF ? -1 : g[o-1][d-1][t]);
        }
        printf("\n");
    }
    
    return 0;
}