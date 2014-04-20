#include <stdio.h>
#include <cstring>
#include <map>
#include <algorithm>
#include <cctype>

using namespace std;

#define INF 1000000000

int N, M;
int g[120][120];

int main(){
	while (scanf("%d %d", &N, &M) > 0 && N) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) g[i][j]=INF;
            g[i][i]=0;
        }
        
        for (int i = 1; i<= M; i++) {
            int a,b,c;
            scanf("%d %d %d", &a, &b, &c);
            g[a][b]=c;
        }
        
        for (int k = 1; k <= N; k++) 
            for (int i = 1; i <= N; i++) 
                for (int j = 1; j <= N; j++)
                    g[i][j] = min(g[i][j], g[i][k]+g[k][j]);
                    
        
        int s,t;
        scanf("%d %d", &s, &t);
        
        if (g[s][t] == INF) printf("-1\n");
        else printf("%d\n",g[s][t]);
    }
}



