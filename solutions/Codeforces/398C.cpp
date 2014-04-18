#include <stdio.h>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;
int n;

int main() {
	scanf("%d", &n);

	if (n == 5) {
		printf("1 2 1\n");
		printf("2 5 1\n");
		printf("4 5 1\n");
		printf("3 4 1\n");
		printf("1 2\n");
		printf("1 3\n");
	}
	else if (n == 6) {
		printf("1 2 1\n");
		printf("2 6 1\n");
		printf("5 6 1\n");
		printf("3 5 1\n");
		printf("3 4 1\n");
		printf("1 3\n");
		printf("1 4\n");
		printf("2 4\n");
	}

	else {

	int gr = (n-1)/3;
	for (int i = 0; i < gr; i++) {
		printf("%d %d %d\n", n-i-1, n, i==0?1:1+3*(i-1));
	}

	for (int i = 0; i < gr; i++) {		
		printf("%d %d %d\n", 2*i+1, 2*i+2, 1);
		if (i!=0) printf("%d %d %d\n", 2*i+1, n-i-1, 1);
		else printf("%d %d %d\n", 2*i+2, n-i-1, 1);
	}

	for (int i = 0; i < n - gr*3 - 1; i++) {
		printf("%d %d %d\n", 2*gr+i+1, n, 1);
	}

	int cnt = 0;
	int lim = n/2;
	for (int j = 1; j < gr; j++) {
		printf("%d %d\n", 1, 2*j+1); cnt++;
		if (cnt == lim) return 0;
		printf("%d %d\n", 2, 2*j+2); cnt++;
		if (cnt == lim) return 0;
		printf("%d %d\n", 1, 2*j+2); cnt++;
		if (cnt == lim) return 0;
		printf("%d %d\n", 2, 2*j+1); cnt++;
		if (cnt == lim) return 0;
	}

	}
}