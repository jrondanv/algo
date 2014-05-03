#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <queue>
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <ctime> 
#include <cstring> 

using namespace std; 

typedef long long ll; 
typedef pair<int, int> pii;

#define INF 1000000000
#define pb push_back 
#define itr iterator 
#define sz size() 
#define mp make_pair

int n;

pii points[100100];
vector<int> pointset[100100];
vector<int> big;
int maxx;
int bound;

void walk(int ix, int i1, int& i2, int dist){
	while (i2+1 < pointset[ix].sz && pointset[ix][i2] - pointset[ix][i1] < dist ) {
		i2++;
	}
}

int test(int x, int y1, int y2) {
	if (x < 0 || x > maxx) return false;

	vector<int>::itr fi = lower_bound(pointset[x].begin(), pointset[x].end(), y1);
	vector<int>::itr ss = lower_bound(pointset[x].begin(), pointset[x].end(), y2);

	bool fiok = fi != pointset[x].end() && *fi == y1;
	bool ssok = ss != pointset[x].end() && *ss == y2;

	if (fiok && ssok) {
		return pointset[x].sz > bound ? 2 : 1;
	}
	return 0;
}

int main() {
	scanf("%d", &n);

	maxx = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &points[i].first);
		scanf("%d", &points[i].second);

		maxx = max(points[i].first, maxx);
	}

	sort(points, points+n);
	for (int i = 0; i < n; i++) {
		pointset[points[i].first].push_back(points[i].second);
	}

	int p = 1;
	int l = -1;
	while (p <= n) {
		l++;
		p<<=1;
	}
	if (l==0) l++;

	bound = sqrt(n/l);

	int smallct = 0;
	int bigct = 0;

	for (int i = 0; i <= maxx; i++) {
		int tot = pointset[i].sz;
		if (tot > bound) big.push_back(i);
		else {
			for (int j = 0; j < tot; j++) {
				for (int k = j+1; k < tot; k++) {
					int dist = pointset[i][k] - pointset[i][j];

					int fx = i + dist;
					int sx = i - dist;

					smallct += test(fx, pointset[i][j], pointset[i][k]);
					smallct += test(sx, pointset[i][j], pointset[i][k]);
				}
			}
		}
	}

	for (int i = 0; i < big.sz; i++) {
		for (int j = i+1; j < big.sz; j++) {
			int ix = big[i];
			int jx = big[j];

			int i1 = 0, i2 = 0, j1 = 0, j2 = 0;
			int dist = jx - ix;

			walk(ix, i1, i2, dist);
			walk(jx, j1, j2, dist);

			const vector<int>& ip = pointset[ix];
			const vector<int>& jp = pointset[jx];
			const int is = pointset[ix].sz;
			const int js = pointset[jx].sz;

			do {
				if (ip[i2] - ip[i1] == dist &&
					jp[j2] == ip[i2] &&
					jp[j1] == ip[i1]) {
						bigct++;
				} 

				if ( (i1+1 < is && ip[i1] < jp[j1]) || j1+1==js) {
					walk(ix, ++i1, i2, dist);
				}

				else {
					walk(jx, ++j1, j2, dist);
				}
			} while (ip[i2] - ip[i1] >= dist && jp[j2] - jp[j1] >= dist);
		}
	}

	printf("%d\n", smallct/2 + bigct);
}
