#include <stdio.h>

int main() {
	int N, C;
	scanf("%d %d", &N, &C);
	
	int i;
	int pess = 0;
	int exc = 0;
	
	for (i=0; i<N; i++) {
		int E, S;
		scanf("%d %d", &S, &E);
		
		pess += E - S;
		if (pess > C) exc = 1;
	}
	
	if (exc) printf("S\n");
	else printf("N\n");
	return 0;
}