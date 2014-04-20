#include <stdio.h>

int main() {
	int C, E, L, P;
	int teste = 0;
	
	while (scanf("%d %d %d %d", &C, &E, &L, &P) && C != 0) {
		int c[C];
		int marcado[C];
		int g[C][C];
		
		int i, j;
		for (i=0; i<C; i++) {
			marcado[i] = 0;
			c[i] = -1;
			for (j=0; j<C; j++) {
				g[i][j] = 0;
			}
		}
		
		for (i=0; i<E; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			
			g[a-1][b-1] = 1;
			g[b-1][a-1] = 1;
		}
			
		int curr = L-1;
		c[curr] = 0;
		
		while (curr != -1) {
			marcado[curr] = 1;
			
			for (i=0; i<C; i++) {
				if (!marcado[i] && g[curr][i]) {
					if (c[i] > c[curr] + 1 || c[i] == -1) c[i] = c[curr] + 1;
				}
			}
			
			int min = -1;
			int min_idx = -1;
			for (i=0; i<C; i++) {
				if (!marcado[i] && c[i] != -1 && (c[i] < min || min == -1)) {
					min = c[i];
					min_idx = i;
				}
			}
			
			curr = min_idx;
		}
		
		printf("Teste %d\n", ++teste);
		for (i=0; i<C; i++) {
			if (c[i] > 0 && c[i] <= P) printf("%d ", i+1);
		}
		printf("\n\n");
	}
	
	return 0;
}