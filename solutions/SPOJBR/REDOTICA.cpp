#include <stdio.h>

int main() {
	int N, M;
	int teste = 0;
	
	while (scanf("%d %d", &N, &M) && N != 0) {
		int g[N][N];
		int marcado[N];
		int comp[N];
		int prev[N];
		
		int i, j;
		for (i=0; i<N; i++) {
			marcado[i] = 0;
			comp[i] = prev[i] = -1;
			for (j=0; j<N; j++) {
				g[i][j] = -1;
			}
		}
		
		for (i=0; i<M; i++) {
			int x, y, c;
			scanf("%d %d %d", &x, &y, &c);
			
			if (x == y) continue;
			g[x-1][y-1] = c;
			g[y-1][x-1] = c;
		}
		
		int curr = 0;
		for (i=0; i<N; i++) {
			for (j=0; j<N; j++) {
				if (!marcado[j] && g[j][curr] != -1) {
					if (comp[j] == -1 || g[j][curr] < comp[j]) {
						comp[j] = g[j][curr];
						prev[j] = curr;
					}
				}
			}
			
			marcado[curr] = 1;
			
			int min = -1;
			int min_idx = -1;
			
			for (j=0; j<N; j++) {
				if (!marcado[j] && comp[j] != -1 && (comp[j] < min || min == -1)) {
					min = comp[j];
					min_idx = j;
				}
			}
			
			curr = min_idx;
		}
		
		printf("Teste %d\n", ++teste);
		for (i=1; i<N; i++) {
			if (i < prev[i]) printf("%d %d\n", i+1, prev[i]+1);
			else printf("%d %d\n", prev[i]+1, i+1);
		}
		printf("\n");
	}
	
	return 0;
}