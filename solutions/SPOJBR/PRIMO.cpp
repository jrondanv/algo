#include <stdio.h>

int main() {
	int N;
	
	scanf("%d", &N);
	if (N < 0) N = -N;
	
	int i;
	int primo = 1;
	if (N < 2) primo = 0;
	
	for (i=2; i*i<=N; i++) {
		if (N % i == 0) {
			primo = 0;
			break;
		}
	}
	
	if (primo) printf("sim\n");
	else printf("nao\n");
	
	return 0;
}