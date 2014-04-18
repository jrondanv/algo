#include <stdio.h>
#include <algorithm>

using namespace std;

long long a, b;

char ans[110000];

int main() {
	scanf("%I64d %I64d", &a, &b);

	int best = 0;
	long long tot = -1000000000000000000LL;
	
	for (int i = 1; i <= a+1; i++) {
		long long sc = max(i-2, 0) + min(a*a, (a-i+2)*(a-i+2));
		long long d = (b/i);
		sc -= d*d*(i - b%i) + (d+1)*(d+1) * (b%i);
		if (sc > tot) {
			tot = sc;
			best = i;
		}
	}

	printf("%I64d\n", tot);
	
	for (int i = 0; i < best; i++) {
		int d = b/best;
		if (b%best > i) d++;
		for (int j = 0; j < d; j++) printf("x");

		if (i == 0) {
			for (int j = 0; j < min(a, a-best+2); j++) printf("o");
		}
		else if (i != best-1) printf("o");
	}
}