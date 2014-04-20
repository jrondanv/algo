#include <stdio.h>
#include <string.h>

int max_depth;
int max_paren;

int N;

char nomes[1010][100];
int adj[1010][1010];
int marc[1010];

int index(char* str) {
    int i;
    for (i = 0; i < N && strcmp(nomes[i],str) != 0; i++);
    
    if (i == N) {
        strcpy(nomes[N], str);
        N++;
    }
    return i;
}

void dfs(int i, int depth) {
    if (marc[i]) return;
    else marc[i] = 1;
    
    if (depth > max_depth) {
        max_depth = depth;
        max_paren = i;
    }
    
    for (int j = 1; j <= adj[i][0]; j++) {
        dfs(adj[i][j], depth+1);
    }
}

int main() {
    int R;
    scanf("%d", &R);
    
    memset(adj,0,sizeof(adj));
    N = 0;
    
    for (int r = 0; r < R; r++) {
        char pai[100];
        char filho[100];
        
        scanf("%s %s", pai, filho);
        
        int p = index(pai);
        int f = index(filho);
        
        adj[p][++adj[p][0]] = f;
        adj[f][++adj[f][0]] = p;
    }
    
    memset(marc,0,sizeof(marc));
    max_depth = -1;
    dfs(0, 0);
    
    memset(marc,0,sizeof(marc));
    int inic = max_paren;
    
    max_depth = -1;
    dfs(inic, 0);
    
    char* n1;
    char* n2;
    if (strcmp(nomes[inic], nomes[max_paren]) > 0) {
        n1 = nomes[max_paren];
        n2 = nomes[inic];
    }
    else {
        n1 = nomes[inic];
        n2 = nomes[max_paren];
    }
    printf("%s %s %d\n", n1, n2, max_depth);
    return 0;
}
