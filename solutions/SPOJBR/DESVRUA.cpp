#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
 
int n, m;
int a, b, t;

int op,id,tam;

#define NMAX 1000

int intime;
int g[NMAX], g1[NMAX][NMAX], g2[NMAX][NMAX], G[NMAX][NMAX];
int vis[NMAX];
int seen[NMAX], seen2[NMAX];

bool ok;

void reset(){
	for (int i=0; i<n; i++) {
		g[i] = seen[i] = seen2[i] = vis[i] = 0;
		
		for (int j = 0; j < n; j++) g1[i][j]=g2[i][j]=0;
	}

	ok = false;
}

int biponte(int v, int pai){
	if(vis[v]) return vis[v];
	int R = vis[v] = intime++;
	
	for(int i=0; i<g[v]; i++){
		if(G[v][i] == pai)
			continue;
		int r = biponte(G[v][i], v);
		if(r < R) R = r;
	}
	
	if(R >= vis[v] && pai != -1) {
		if (g1[v][pai] != 2) {
			ok = true;
		}
	}

	return R;
}

bool biconexo(){
	intime = 1;
	for (int i=0; i<n; i++)
		biponte(i, -1);
	return !ok;
}


void dfs2(int v) {
	if (seen2[v]) return;
	seen2[v] = 1;

	for (int i = 0; i < n; i++) {
		if (g2[v][i]) dfs2(i);
	}
}

void dfs1(int v) {
	if (seen[v]) return;
	seen[v] = 1;

	for (int i = 0; i < n; i++) {
		if (g1[v][i]) dfs1(i);
	}
}

int main() {
    while (scanf("%d %d", &n, &m) > 0) {
    	int orig, dest, dupl;
    	scanf("%d %d %d", &orig, &dest, &dupl);
    	orig--; dest--;

    	reset();

    	for (int i = 1; i < m; i++) {
    		scanf("%d %d %d", &a, &b, &t);
    		a--; b--;

    		G[a][g[a]++] = b;
    		g1[a][b]=t;
    		G[b][g[b]++] = a;
    		if (t == 2) g1[b][a] = t;

    		g2[a][b]=g2[b][a]=1;
    	}

    	dfs2(orig);
    	dfs1(orig);

    	if (!seen2[dest]) {
    		printf("*\n");
    		continue;
    	}

    	memset(seen2,0,sizeof(seen2));
    	dfs2(dest);
    	if (!seen2[orig]) {
    		printf("*\n");
    		continue;
    	}

    	//printf("SD: %d\n", seen[dest]);
    	if (seen[dest]) {
    		//printf("ODS\n");
    		memset(seen,0,sizeof(seen));
    		dfs1(dest);
    		if (seen[orig]) {
    			//printf("DOS\n");
    			printf("-\n");
    			continue;
    		}
    	}

    	
    	if (biconexo()) {
    		printf("1\n");
    		continue;
    	}

    	printf("2\n");
    }
}