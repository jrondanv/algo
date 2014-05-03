#include <stdio.h>
#include <algorithm>

using namespace std;

int n,t,x,y;
int sx;
int sy;

int main() {
	#ifdef ONLINE_JUDGE
	freopen("knights.in","r", stdin);
	freopen("knights.out", "w", stdout);
	#endif

	while (scanf("%d", &n) && n) {
		sx = 1000000000;
		sy = 1000000000;
		for (int i = 0; i < n; i++) {
			scanf("%d %d", &x, &y);
			sx = min(sx, x);
			sy = min(sy, y);
		}

		int al = (sx + 1) / 3;
		int pl = sy / 3;

		if (al <= pl) printf("Peter wins the game\n");
		else printf("Andrew wins the game\n");
	}
}