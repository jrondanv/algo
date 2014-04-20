#include <stdio.h>

int main() {
	int K;
	
	while (scanf("%d", &K) && K) {
        int cont = 0;
        int rest = 0;
        
		for (int i = 0; i < K; i++) {
            int M, N;
		    scanf("%d %d", &M, &N);
		    
		    cont += N / 4;
		    N = N % 4;
		    
		    if (N >= 2) rest++;
        }
		
		printf("%d\n", cont+rest/2);
	}
	
	return 0;
}