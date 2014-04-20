#include <stdio.h>
#include <algorithm>
using namespace std;

int main() {
	int P, S;
	int teste = 0;
	
	while (scanf("%d %d", &P, &S)) {
		if (P == 0 && S == 0) break;
		
		int start[S];
		int end[S];
		
		int i;
		for (i=0; i<S; i++) {
			scanf("%d", start+i);
			scanf("%d", end+i);
		}
		
		sort(start, start+S);
		sort(end, end+S);
		
		int c_start = 0;
		int c_end = 0;
		int evts = 0;
		
		printf("Teste %d\n", ++teste);
		
		while (c_start < S) {
			if (start[c_start] < end[c_end]) {
				if (evts == 0) printf("%d ", start[c_start]);
				evts++;
				c_start++;
			}
			else if (end[c_end] < start[c_start]) {
				if (evts == 1) printf("%d\n", end[c_end]);
				evts--;
				c_end++;
			}
			else {
				c_start++;
				c_end++;
			}
		}
		printf("%d\n\n", end[S-1]);
	}
}