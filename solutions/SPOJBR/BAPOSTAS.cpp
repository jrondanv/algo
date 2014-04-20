#include <stdio.h>

int main() {
	int N;
	
	while (scanf("%d", &N) && N != 0) {
		int i;
		
		int max = 0;
		int curr = 0;
		
		for (i = 0; i < N; i++) {
			int val;
			scanf("%d", &val);
			
			curr += val;
			if (curr > max) max = curr;
			else if (curr < 0) curr = 0;
		}
		
		if (max == 0) printf("Losing streak.\n");
		else printf("The maximum winning streak is %d.\n", max);
	}
}