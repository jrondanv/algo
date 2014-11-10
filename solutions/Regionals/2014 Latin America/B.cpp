#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <set>

using namespace std;

int A, B;
char ss[6000];
int n;

set<int> wh;
set<int> bl;

void sw(int firstwhite, int firstblack) {
	wh.erase(firstwhite);
	bl.erase(firstblack);
	wh.insert(firstblack);
	bl.insert(firstwhite);
}

int main() {
	while (scanf("%d %d", &A, &B) != EOF) {
		wh.clear();
		bl.clear();
		
		scanf("%s", ss);
		long long ans = 0;
		
		n = strlen(ss);
		for (int i = 0; i < n; i++) {
			if (ss[i] == 'W') wh.insert(i);
			else bl.insert(i);
		}
		
		if (wh.empty() || bl.empty()) {
			printf("0\n");
			continue;
		}
		
		while (true) {
			int firstwhite = *wh.begin(), firstblack = *bl.rbegin();
			if (firstwhite > firstblack) break;
			
			long long inv = firstblack-firstwhite;
			if ((A-B)*inv > A) {
				sw(firstwhite, firstblack);
				ans += A;
			}
			else {
				int k = *bl.lower_bound(firstwhite);
				sw(k-1, k);
				ans += A-B;
			}
		}
		
		printf("%lld\n", ans);
	}
}
