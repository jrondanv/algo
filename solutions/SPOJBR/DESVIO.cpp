#include <stdio.h>

int g[250][250];
int marc[250];
int dist[250];

int bfs(int orig, int dest, int c) {
    dist[orig] = 0;

    while (1) {
        int menor=1000000000;
        int idmenor=0;

        for (int i = 0; i < c; i++) {
            if (dist[i] < menor && !marc[i]) {
                menor = dist[i];
                idmenor = i;
            }
        }

        if (menor==1000000000) return -1;
        if (idmenor == dest) return dist[idmenor];

        marc[idmenor] = 1;
        for (int i = 0; i < c; i++) {
            if (!marc[i] && dist[idmenor]+g[idmenor][i] < dist[i]) {
                dist[i] = dist[idmenor]+g[idmenor][i];
            }
        }
    }
}

int main() {
    int n,m,c,k;
    
    while (scanf("%d %d %d %d", &n, &m, &c, &k) && n) {
        for (int i = 0; i < n; i++) {
            marc[i] = 0;
            dist[i] = 1000000000;
            for (int j = 0; j < n; j++) {
                g[i][j]=1000000000;
            }
        }


        for (int i = 0; i < m; i++) {
            int orig, dest, pedagio;
            scanf("%d %d %d", &orig, &dest, &pedagio);

            if (orig > c-1 || dest == orig+1) g[orig][dest] = pedagio<g[orig][dest] ? pedagio : g[orig][dest];
            if (dest > c-1 || orig == dest+1) g[dest][orig] = pedagio<g[dest][orig] ? pedagio : g[dest][orig];
        }
        
        printf("%d\n", bfs(k, c-1, n));
    }
}