#include <stdio.h>

int fac(int n) {
	int r = 1;
	while (n) {
		r *= n;
		n--;
		}
	return r;
	}
	
int main(void) {
	int n;
	scanf("%d", &n);
	printf("%d", fac(n));
	}