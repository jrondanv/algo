#include <stdio.h>

int main(void) {
	int n;
	int soma = 0;
	scanf("%d", &n);
	
	for (int i=0; i<n; i++) {
		int k;
		scanf("%d", &k);
		soma += k;
	}
	
	printf("%d", soma);
}
