#include <stdio.h>
#include <string.h>

char ss[1100000];

long long getCount(int a, int b) {
	long long cnt[3] = {1,0,0};
	
	int curmod = 0;
	for (int x = a; x < b; x++) {
		curmod = (curmod*10 + ss[x]-'0') % 3;
		cnt[curmod]++;
	}
	
	long long ret = 0;
	for (int i = 0; i < 3; i++) {
		ret += cnt[i] * (cnt[i]-1) / 2;
	}
	
	return ret;
}

int main() {
	while (scanf("%s", ss) != EOF) {
		int n = strlen(ss);
		
		int la = 0;
		long long ans = 0;
		for (int i = 0; i < n; i++) {
			if (ss[i] < '0' || ss[i] > '9') {
				ans += getCount(la, i);
				la = i+1;
			}
		}
		
		ans += getCount(la, n);
		
		printf("%lld\n", ans);
	}	
}
