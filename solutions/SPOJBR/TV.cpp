#include <stdio.h>

int main() {
	int teste = 0;
	int M, N;
	
	while (scanf("%d %d", &M, &N)) {
		if (M == 0 && N == 0) break;
		
		int mat[M][N];
		int i, j;
		
		for (i=0; i<M; i++) {
			for (j=0; j<N; j++) {
				scanf("%d", &mat[i][j]);
			}
		}
		
		int X, Y;
		int m0 = 0, n0 = 0;
		
		while (scanf("%d %d", &X, &Y)) {
			if (X == 0 && Y == 0) break;
			
			m0 = (m0 + M + Y) % M;
			n0 = (n0 + N - X) % N;
		}
		
		printf("Teste %d\n", ++teste);
		for (i=0; i<M; i++) {
			for (j=0; j<N; j++) {
				printf("%d ", mat[(m0+i)%M][(n0+j)%N]); 
			}
			printf("\n");
		}
		printf("\n");
	}
}