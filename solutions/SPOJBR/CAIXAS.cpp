#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <sstream>
#include <map>

using namespace std;

typedef char str[220];

int t, teste;

int h[11000], b;
int n, p, alt, loc;

int main() {
	while (scanf("%d %d", &n, &p) && n) {
		for (int i = 0; i < p; i++) {
			scanf("%d", &h[i]);

			for (int j = 0; j < h[i]; j++) {
				scanf("%d", &b);
				if (b == 1) {
					alt = j+1;
					loc = i;
				}
			}

		}

		int cnt = 0;
		for (int k = loc; k >= 0; k--) {
			if (h[k] >= alt) cnt += h[k]-alt+1;
			else break; 
		}

		int cnt2 = 0;
		for (int k = loc; k < p; k++) {
			if (h[k] >= alt) cnt2 += h[k]-alt+1;
			else break; 
		}

		printf("%d\n", min(cnt, cnt2)-1);
	}
}