#include <stdio.h>

int main() {
	int N;
	scanf("%d", &N);
	
	N = 2*N-1;
	
	int i;
	int cnt = 0;
	for (i=3; i*i<=N; i+=2) {
		if (N % i == 0) cnt++;
	}
	
	printf("%d\n", cnt);
}