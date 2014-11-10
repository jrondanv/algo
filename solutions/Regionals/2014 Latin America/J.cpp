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

typedef pair<int, int> pii;
#define mp make_pair

int r, c, n;
set< pair<int, pii> > open;
pii pt[5];
int V[510][510];
int R[510][510];
int C[510][510];

struct RangeBIT {
	int vals[501][501];

	void init(int x, int y) {
		memset(vals,0,sizeof(vals));
		for (int i = 1; i <= x; i++) {
			for (int j = 1; j <= y; j++) {
				add(i, j, 1);
			}
		}
	}
	
	void add(int x, int y, int delta) {
		for (; x <= r; x += x&-x) {
			for (int yy = y; yy <= c; yy += yy&-yy) vals[x][yy]+=delta;
		}
	}

	int read(int x, int y) {
		int s = 0;
		for (; x > 0; x -= x&-x) {
			for (int yy = y; yy > 0; yy -= yy&-yy) s += vals[x][yy];
		}
		return s;
	}

	int rect(int rMin, int rMax, int cMin, int cMax) {
		return read(rMax, cMax) - read(rMin-1, cMax) - read(rMax, cMin-1) + read(rMin-1, cMin-1);
	}

	void proc(int rMin, int rMax, int cMin, int cMax, int cost, int tot) {
		if (tot == -1) tot = rect(rMin, rMax, cMin, cMax);
		if (tot == 0) return;

		if (rMin == rMax) {
			if (cMin == cMax) {
				open.insert(mp(V[rMin][cMin] + cost, mp(rMin, cMin)));
				add(rMin, cMin, -1);
				return;
			}

			int amt = rect(rMin, rMax, cMin, (cMin+cMax)/2);
			if (amt) proc(rMin, rMax, cMin, (cMin+cMax)/2, cost, amt);
			if (amt < tot) proc(rMin, rMax, 1+(cMin+cMax)/2, cMax, cost, tot-amt);
		}
		else {
			int amt = rect(rMin, (rMin+rMax)/2, cMin, cMax);
			if (amt) proc(rMin, (rMin+rMax)/2, cMin, cMax, cost, amt);
			if (amt < tot) proc((rMin+rMax)/2 + 1, rMax, cMin, cMax, cost, tot-amt);
		}
	}
} range_tree;


int dijkstra(int r1, int c1, int r2, int c2) {
	if (r1 == r2 && c1 == c2) return 0;

	range_tree.init(r,c);
	range_tree.add(r1,c1,-1);

	open.clear();
	open.insert( mp(V[r1][c1], mp(r1,c1)) );

	while (!open.empty()) {
		int cost = open.begin()->first;
		int curR = open.begin()->second.first;
		int curC = open.begin()->second.second;

		if (abs(curC - c2) <= C[curR][curC] && abs(curR - r2) <= R[curR][curC]) return cost;
		open.erase(open.begin());

		range_tree.proc(max(1, curR - R[curR][curC]), 
					 min(r, curR + R[curR][curC]),
					 max(1, curC - C[curR][curC]),
					 min(c, curC + C[curR][curC]), cost, -1);
	}

	return -1;
}

int main() {
	while (scanf("%d %d %d", &r, &c, &n) > 0) {
		for (int i = 1; i <= r; i++) 
			for (int j = 1; j <= c; j++) scanf("%d", &V[i][j]);
		for (int i = 1; i <= r; i++) 
			for (int j = 1; j <= c; j++) scanf("%d", &R[i][j]);
		for (int i = 1; i <= r; i++) 
			for (int j = 1; j <= c; j++) scanf("%d", &C[i][j]);

		for (int i = 0; i < n; i++) scanf("%d %d", &pt[i].first, &pt[i].second);

		for (int i = 0; i < n-1; i++) {
			if (i != 0) printf(" ");
			printf("%d", dijkstra(pt[i].first, pt[i].second, pt[i+1].first, pt[i+1].second));
		}
		printf("\n");
	}
}