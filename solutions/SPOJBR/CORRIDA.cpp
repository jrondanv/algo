#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <cstring>

using namespace std;

#define INF 1000000000

int N,M,t;
int g[210][210];

int main() {
    for (scanf("%d", &t); t; t--) {
    	scanf("%d %d", &N, &M);
        
        for (int i = 1; i <= 2*N; i++) {
            for (int j = 1; j <= 2*N; j++) g[i][j]=INF;
        }
        
        int a, b, c;
        for (int i = 1; i<=M; i++) {
            scanf("%d %d %d", &a, &b, &c);
            if (a!=b) g[a][N+b]=g[N+b][a]=g[N+a][b]=g[b][N+a]=min(g[a][b+N],c);
        }
        
        for (int k = 1; k <= 2*N; k++) {
            for (int i = 1; i <= 2*N; i++) {
                for (int j = 1; j <= 2*N; j++) {
                    g[i][j] = min(g[i][j], g[i][k]+g[k][j]);
                }
            }
        }
    
        int best = INF;
        for (int v = 1; v <= N; v++) {
            best = min(best, g[v][N+v]);
        }
        
        if (best != INF) printf("%d\n",best);
        else printf("impossivel\n");
    }
}
