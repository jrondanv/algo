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

int children[4000];
char ss[20];
int n, cnt, sta;
int next[4000][26];
int lk[4000];
int ft[4000];
int dp[4000][101];

void create(int node, int idx) {
	next[node][idx] = cnt;
	children[cnt] = 0;
	lk[cnt] = -1;
	ft[cnt] = -1;

	if (ft[node] == -1) ft[node] = cnt;
	else {
		lk[cnt] = ft[node];
		ft[node] = cnt;
	}
	
	cnt++;
}

void add(char* str) {
	int node = 0;
	children[0]++;

	for (int i = 0; str[i] != '\0'; i++) {
		if (next[node][str[i]-'A'] == -1) {
			create(node, str[i]-'A');
		}
		
		node = next[node][str[i]-'A'];
		children[node]++;
	}
}

int calc(int v, int tot_st, int d) {
	int& ret = dp[v][tot_st];
	if (ret == -1) {
		ret = 100000000;

		int lim = 0;
		if (lk[v] == -1) lim = tot_st;
		for (int st = std::min(tot_st, children[v]); st >= lim; st--) {
			int th = 0;

			if (st == 1) th += d;
			if (children[v] - st == 1) th += d;

			if (ft[v] != -1) {
				if (children[v] - st >= st) th += calc(ft[v], st, d+1); 
				else th += calc(ft[v], children[v] - st, d+1);

				if (st == 1) th -= d+1;
				if (children[v] - st == 1) th -= d+1;
			}
			if (lk[v] != -1) th += calc(lk[v], tot_st - st, d); 
			
			if (th >= 1000000000) break;
			ret = std::min(ret, th);
		}
	}

	return ret;
}

int main() {
	while (scanf("%d", &n) > 0) {
		cnt = 1;
		
		memset(dp,-1,sizeof(dp));
		memset(next,-1,sizeof(next));
		
		children[0] = 0;
		ft[0] = -1;
		lk[0] = -1;
		
		for (int i = 0; i < 2*n; i++) {
			scanf("%s", ss);
			add(ss);
		}

		printf("%d\n", n*calc(ft[0],n,1));
	}
}