#include <stdio.h>

int main() {
	int K;
	
	while (scanf("%d", &K) && K) {
		int M, N;
		scanf("%d %d", &M, &N);
		
		int i;
		for (i=0; i<K; i++) {
			int X, Y;
			scanf("%d %d", &X, &Y);
			
			char out[3];
            out[2] = '\0';
			if (X == M || Y == N) printf("divisa\n");
			else {
				if (X > M) out[1] = 'E';
				else out[1] = 'O';
				
				if (Y > N) out[0] = 'N';
				else out[0] = 'S';
				
				printf("%s\n", out);
			}
		}
	}
	
	return 0;
}
