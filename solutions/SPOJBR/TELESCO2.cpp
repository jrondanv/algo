#include <stdio.h>

int main() {
	int A, N;
	
	scanf("%d", &A);
	scanf("%d", &N);
	
	int i;
	int cnt = 0;
	for (i=0; i<N; i++) {
		int F;
		scanf("%d", &F);
		
		if (F*A >= 40000000) cnt++;
	}
	
	printf("%d\n", cnt);
	
	return 0;
}