#include <stdio.h>
#include <map>

int main() {
	int N;
	scanf("%d", &N);
	
	std::map<int, int> contador;
	int i;
	int max = 0;
	int max_c = 0;
	
	for (i=0; i<N; i++) {
		int c;
		scanf("%d", &c);
		
		int val = ++contador[c];
		if (val > max) {
			max = val;
			max_c = c;
		}
	}
	
	printf("%d\n", max_c);
	return 0;
}