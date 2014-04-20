#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int N, M, L;
int a,b;
int g[160][160];
int alt[160];
int pd[160];

int func(int v) {
    int &best = pd[v];
    if (best != -1) return best;
    
    best = 0;
    
    for (int i = 1; i <= N; i++) {
        //printf("%d %d %d %d\n", i, g[v][i], alt[i], alt[v]);
        if (v != i && g[v][i] && alt[i]<alt[v]) {
            
            best = max(best, 1+func(i));
        }
    }
    
    return best;
}

int main() {
    int t = 0;
    while (scanf("%d %d %d", &N, &M, &L) && N) { 
        for (int i = 1; i <= N; i++) scanf("%d", &alt[i]);
        
        memset(g,0,sizeof(g));
        memset(pd,-1,sizeof(pd));
        
        for (int i = 0; i < M; i++) {
            scanf("%d %d", &a, &b);
            g[a][b]=1;
        }
        
        printf("Teste %d\n",++t);
        printf("%d\n\n",func(L));
    }
}
