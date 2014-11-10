#include <stdio.h>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int I, S, cc, a, b;
int sv[110000];
int C[11000];
vector<int> adj[11000];
vector<int> divi[11000];
int seen[11000][1000];

int mdc(int a, int b) {
	if (b == 0) return a;
	return mdc(b, a%b);
}

void put_divisors(int i, int C, int fact) {
	if (C == 1) {
		divi[i].push_back(fact);
		return;
	}
	
	int div = sv[C];
	if (div == 0) div = C;
	int cnt = 0;
	do {
		C /= div;
		cnt += 1;
	} while (sv[C] == div);
	 
	for (int c = 0; c <= cnt; c++) {
		put_divisors(i, C, fact);
		fact *= div;
	}
}

set<int> ps;

void dfs(int v, int d) {
	if (seen[v][d] == cc) return;
	ps.insert(divi[v][d]);
	seen[v][d] = cc;
	
	for (int ad = 0; ad < adj[v].size(); ad++) {
		int ot = adj[v][ad];
		int val = mdc(C[ot], divi[v][d]);
		
		int st = 0, end = divi[ot].size()-1;
		while (st < end) {
			int mid = (st+end)/2;
			if (divi[ot][mid] < val) st = mid+1;
			else end = mid;
		}
		dfs(ot, st);
	}
}

int main() {
	for (long long i = 2; i <= 100000; i++) {
		if (!sv[i]) {
			for (long long j = i; j <= 100000; j += i) {
				sv[j] = i;
			}
		}
	}
	
	while (scanf("%d %d", &I, &S) != EOF) {
		++cc;
		ps.clear();
		
		for (int i = 0; i < I; i++) {
			adj[i].clear();
			divi[i].clear();
		}
		
		for (int i = 0; i < I; i++) {
			scanf("%d", &C[i]);
			put_divisors(i, C[i], 1);
			sort(divi[i].begin(), divi[i].end());
		}
		
		for (int i = 0; i < S; i++) {
			scanf("%d %d", &a, &b); a--; b--;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		
		for (int i = 0; i < I; i++) {
			dfs(i, divi[i].size()-1);
		}
		printf("%d\n", ps.size());
	}
}
