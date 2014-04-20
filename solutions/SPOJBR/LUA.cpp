#include <stdio.h>

int main() {
	int teste = 0;
	
	int N, M;
	while (scanf("%d %d", &N, &M) && N != 0) {
		int intervalo[M];
		
		int i;
		int soma = 0;
		for (i=0; i<M; i++) {
			scanf("%d", intervalo+i);
			soma += intervalo[i];
		}
		
		int min = soma;
		int max = soma;
		
		for (i=0; i<N-M; i++) {
			soma -= intervalo[i%M];
			scanf("%d", intervalo+(i%M));
			soma += intervalo[i%M];
			
			if (soma < min) min = soma;
			if (soma > max) max = soma;
		}
		
		printf("Teste %d\n", ++teste);
		printf("%d %d\n", min/M, max/M);
	}
	
	return 0;
}