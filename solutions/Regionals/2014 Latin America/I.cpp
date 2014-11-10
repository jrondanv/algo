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

int n, f, big;
int a, b, c;
vector<pii> adj[110000];
int fr[110000];

int dfs(int v, int d) {
	int ret = 0;

	if (fr[v]) big = max(big, d);

	for (int ot =0; ot < adj[v].size(); ot++) {
		int child = adj[v][ot].first;
		int cost = adj[v][ot].second;

		ret += dfs(child, d+cost);
		if (fr[child]) {
			fr[v]=1;
			ret += cost;
		}
	}

	return ret;
}

int main() {
	while (scanf("%d %d", &n, &f) > 0) {
		memset(fr,0,sizeof(fr));
		for (int i = 0; i < n; i++) adj[i].clear();

		for (int i = 0; i < n-1; i++) {
			scanf("%d %d %d", &a, &b, &c); a--; b--;
			adj[a].push_back(mp(b,c));
		}

		for (int i = 0; i < f; i++) {
			scanf("%d", &a); a--;
			fr[a]=1;
		}

		big = 0;
		printf("%d\n", dfs(0, 0) - big);
	}
}