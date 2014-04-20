#include <stdio.h>

int main() {
	int T, N;
	
	while (scanf("%d %d", &T, &N)) {
		if (T == 0 && N == 0) break;
		
		int K = 0;
		int i;
		
		char c[20];
		
		for (i=0; i<T; i++) {
			int p;
			scanf("%s %d", &c, &p);
			
			K += p;
		}
		
		printf("%d\n", 3*N - K);
	}
	return 0;
}