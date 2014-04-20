#include <stdio.h>

int main() {
	int C, M;
	
	scanf("%d %d", &C, &M);
	
	int g[C][C];
	int min = -1;
	
	int i, j;
	for (i=0; i<C; i++) {
		for (j=0; j<C; j++) {
			g[i][j] = 0;
		}
	}
	
	for (i=0; i<M; i++) {
		int x, y, w;
		scanf("%d %d %d", &x, &y, &w);
		
		if (g[x][y] > w || g[x][y] == 0) {
			g[x][y] = g[y][x] = w;
		}
	}
	
	int L;
	for (L=0; L<C; L++) {
		int c[C];
		int marcado[C];
		
		int i;
		for (i=0; i<C; i++) {
			marcado[i] = 0;
			c[i] = -1;
		}
			
		int curr = L;
		c[curr] = 0;
		
		while (curr != -1) {
			marcado[curr] = 1;
			
			for (i=0; i<C; i++) {
				if (!marcado[i] && g[curr][i]) {
					if (c[i] > c[curr] + g[curr][i] || c[i] == -1) c[i] = c[curr] + g[curr][i];
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
		
		int m = 0;
		for (i=0; i<C; i++) {
			if (c[i] > m) m = c[i];
		}
		
		if (m < min || min == -1) min = m;
	}
	
	printf("%d\n", min);
	return 0;
}