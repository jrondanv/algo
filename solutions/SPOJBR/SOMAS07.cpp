#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

#define MAX 200001

int p[MAX], rank[MAX];
int set[MAX];

long long cartao[MAX];
long long proibida[101];

void link(int x,int y) {
    if (rank[x] > rank[y])
        p[y] = x;
    else {
        p[x] = y;
        if (rank[x] == rank[y])
            rank[y] = rank[y] + 1;
    }
}

int find_set(int x) {
    if (x != p[x])
        p[x] = find_set(p[x]);
    return p[x];
}

void union_set(int x,int y) {
    link (find_set(x), find_set(y));
}

int n, m;
int T;

int ec;

int main()
{
    scanf("%d%d", &n, &m);
    
    ec = 0;
    for (int i = 0; i < 2*n; i++) {
        p[i] = i;
        rank[i] = 0;
    }

    bool ok = true;
    for(int i = 0; i < n; i++) scanf("%lld", &cartao[i]);
    for(int i = 0; i < m; i++) scanf("%lld", &proibida[i]); 
    sort(cartao,cartao+n);   
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int loc = lower_bound(cartao, cartao+n, proibida[j]-cartao[i]) - cartao;
            if (loc != i && cartao[loc] == proibida[j]-cartao[i]) {
                union_set(2*i, 2*loc+1);
                union_set(2*loc, 2*i+1);
            }
        }
    }

    for (int i = 0; i < 2*n; i++) {
        if (find_set(i) == find_set(i^1)) ok = false;
    }

    memset(set,0,sizeof(set));

    int cntA = 0;
    if (ok)
    {
        for(int i = 0; i < 2*n; i+=2)
        {
            if (set[find_set(i)] == 1 || set[find_set(i^1)] == -1) {
                //cntA++;
                set[find_set(i)] = 1;
                set[find_set(i^1)] = -1;
            }
            else {
                cntA++;
                set[find_set(i)] = -1;
                set[find_set(i^1)] = 1;
            }
        }

        printf("%d", cntA);
        for(int i = 0; i < 2*n; i+=2)
        {
            if (set[find_set(i)] == -1) printf(" %lld", cartao[i>>1]);
        }
        printf("\n");

        printf("%d", n-cntA);
        for(int i = 0; i < 2*n; i+=2)
        {
            if (set[find_set(i)] == 1) printf(" %lld", cartao[i>>1]);
        }
        printf("\n");
    }
    else printf("-1\n-1\n");
    
    return 0;
}