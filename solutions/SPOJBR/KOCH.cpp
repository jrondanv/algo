#include <stdio.h>

int fib(int n) {
	if (n == 0) return 0;
	int a = 0;
	int b = 1;
	
	int i;
	for (i=1; i<n; i++) {
		int temp = b;
		b = (a+b) % 1000;
		a = temp;
	}
	
	return b;
}

int main() {
	int T;
	char c;
	
	scanf("%d", &T);
	scanf("%c", &c);
	
	int i;
	for (i=0; i<T; i++) {
		int n = 0;
		
		while (1) {
			scanf("%c", &c);
			if (c == '\n') break;
			else n = (10*n + c - '0') % 1500;
		}
		
		printf("%03d\n", fib(n));
	}
}