#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
 
const int INF = 1000001000;

int n, m, ga;
int a, b, t;
int k, mana, pt, v, hp;

int op,id,tam;

int dist[1100], marc[1100];
int kn[1100];
int cst[1100];
int g[1100][1100];

int main() {
    while (scanf("%d %d %d %d", &m, &n, &ga, &k) && m) {
    	for (int i = 0; i < n; i++) {
    		for (int j = 0; j < n; j++) g[i][j] = 0;
    		dist[i] = INF;
    		cst[i] = marc[i] = 0;
    	}

    	for (int i = 0; i <= 1000; i++) kn[i] = INF;

    	kn[0] = 0;
    	for (int i = 0; i < m; i++) {
    		scanf("%d %d", &mana, &pt);
    		for (int i = 0; i <= 1000; i++) {
    			kn[i] = min(kn[i], kn[max(0, i - pt)] + mana);
    		}
    	}

    	for (int i = 0; i < ga; i++) {
    		scanf("%d %d", &a, &b); a--; b--;
    		g[a][b]=g[b][a]=1;
    	}

    	for (int i = 0; i < k; i++) {
    		scanf("%d %d", &v, &hp); v--;
    		cst[v] += kn[hp];
    	} 

    	dist[0] = cst[0];
    	while (true) {
    		int b = -1;
    		for (int j = 0; j < n; j++) {
    			if (!marc[j] && (b == -1 || dist[j] < dist[b])) {
    				b = j;
    			}
    		}

    		if (b == -1 || dist[b] == INF) break;

    		marc[b] = 1;
    		for (int j = 0; j < n; j++) {
    			if (g[b][j] && dist[j] == INF) dist[j] = dist[b] + cst[j];
    		}
    	}

    	if (dist[n-1] == INF) printf("-1\n"); 
    	else printf("%d\n", dist[n-1]);
    }
}