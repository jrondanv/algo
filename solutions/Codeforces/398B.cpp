#include <stdio.h>
#include <algorithm>

using namespace std;

int occx[2010], occy[2010];
int n,m,r,c;

double ans[2010][2010];

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &r, &c); r--; c--;
		occx[r]=1;
		occy[c]=1;
	}

	int cx = n, cy = n;
	for (int i = 0; i < n; i++) if (occx[i]) cx--;
	for (int i = 0; i < n; i++) if (occy[i]) cy--;

	for (int x = 0; x <= n; x++) {
		for (int y = 0; y <= n; y++) {
			if (x == 0 && y == 0) {
				ans[x][y] = 0;
				continue;
			}

			int singlex = x*(n - y);
			int singley = y*(n - x);
			int two = x*y;
			int zero = n*n - singlex - singley - two;
			
			// axy = zero/n² axy + ...
			// (1 - zero/n²) axy
			ans[x][y] = n*n;
			if (x > 0 && y > 0) ans[x][y] += two * ans[x-1][y-1];
			if (x > 0) ans[x][y] += singlex * ans[x-1][y];
			if (y > 0) ans[x][y] += singley * ans[x][y-1];
			ans[x][y] /= (n*n - zero);
		}
	}

	printf("%lf\n", ans[cx][cy]);
}
