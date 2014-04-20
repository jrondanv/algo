#include <stdio.h>

int main() {
	int T;
	
	scanf("%d", &T);
	
	int i;
	for (i=0; i<T; i++) {
		int N;
		scanf("%d", &N);
		
		int nums[N];
		
		int j;
		for (j=0; j<N; j++) {
			scanf("%d", nums+j);
		}
		
		int cnt = 0;
		
		j = 0;
			
		for (j=0; j<N; j++) {
			int temp = nums[j];
			if (temp != j-1) nums[j] = -1;
			
			while (temp != -1) {
				if (nums[temp-1] != -1) cnt++;
				int t2 = nums[temp-1];
				nums[temp-1] = temp;
				temp = t2;
			}
		}
				
		printf("%d\n", cnt);
	}			
}