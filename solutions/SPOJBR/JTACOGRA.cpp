#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	
	int i;
	int d = 0;
	for (i=0; i<n; i++) {
		int t, v;
		scanf("%d %d", &t, &v);
		
		d += t*v;
	}
	
	printf("%d\n", d);
}
	