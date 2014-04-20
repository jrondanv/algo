#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int g[100][100];
long long pd[100][1010];

int N,S,E,T;

int main() {
    int t = 0;
    while (scanf("%d %d %d %d", &N, &S, &E, &T) && N) { 
        S--;
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) scanf("%d", &g[i][j]);
        }
        
        for (int i = 0; i < N; i++) pd[i][1] = g[S][i];
        
        for (int t = 2; t <= T; t++) {
            for (int i = 0; i < N; i++) {
                pd[i][t]=0;
                for (int j = 0; j < N; j++) {
                    //if (j != i && pd[j][T-1]!=-1)
                    pd[i][t] = max(pd[i][t], pd[j][t-1]+g[j][i]); 
                    //printf("pd[%d][%d]=%d\n",i,T,pd[i][T]);
                }
            }
        }
        
        long long best = 0;
        int a;
        for (int i = 0; i < E; i++) {
            scanf("%d", &a);
            best = max(best, pd[a-1][T]);
        }
        
        printf("%lld\n", best);
    }
}
