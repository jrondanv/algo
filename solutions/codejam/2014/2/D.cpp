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

int T, teste, servers, m;
char str[210];

int nodes;
int ct[210000];
long long choose[210][210];
long long arrange[210][210];
vector< pair<int, char> > adj[210000];
bool end[210000];

const int mod = 1000000007;
long long tot;

long long arra(int tot, int want) {
	if (want > tot) return 0;
	
	long long ret = 1;
	for (int i = 0; i < want; i++) {
		ret = (ret * (tot-i)) % mod;
	}
	return ret;
}

void trie_add(int v, char* str) {
	ct[v]++;
	if (*str == '\0') {end[v]=1;return;}

	for (int i = 0; i < adj[v].size(); i++) {
		if (adj[v][i].second == *str) {
			trie_add(adj[v][i].first, str+1);
			return;
		}
	}

	adj[v].push_back( make_pair(nodes, *str) );
	trie_add(nodes++, str+1);
}

long long t[111][111];
long long pd[111][111];

long long rec(int v, int depth) {
	//printf("%d %d\n", v, ct[v]);
	tot += min(ct[v], servers);

	if (ct[v] <= servers) {
		for (int i = 0; i < adj[v].size(); i++) {
			rec(adj[v][i].first, depth+1);
		}

		return 1;
	}

	for (int i = 0; i <= servers; i++) {
		pd[depth][i] = 0;
	}
	pd[depth][servers] = 1;

	for (int i = 0; i < adj[v].size(); i++) {
		for (int free_servers = 0; free_servers <= servers; free_servers++) {
			t[depth][free_servers] = 0;
		}

		int child = adj[v][i].first;

		int occupies = min(ct[child], servers);
		long long childr = rec(child, depth+1);

		//printf("v %d child %d, childr is %lld\n", v,child,childr);

		for (int free_servers = 0; free_servers <= servers; free_servers++) {
			for (int occupy_free = 0; occupy_free <= min(occupies, free_servers); occupy_free++) {
				long long th = (pd[depth][free_servers] * arrange[servers-free_servers][occupies-occupy_free]) % mod;
				th = (th * choose[occupies][occupies-occupy_free]) % mod;
				t[depth][free_servers-occupy_free] = (t[depth][free_servers-occupy_free] + th) % mod;
			}
		}

		for (int free_servers = 0; free_servers <= servers; free_servers++) {
			pd[depth][free_servers] = (t[depth][free_servers] * childr) % mod;
		}
	}

	if (end[v]) {
		for (int free_servers = 0; free_servers <= servers; free_servers++) {
			t[depth][free_servers] = 0;
		}

		int occupies = 1;
		long long childr = 1;

		for (int free_servers = 0; free_servers <= servers; free_servers++) {
			for (int occupy_free = 0; occupy_free <= min(occupies, free_servers); occupy_free++) {
				long long th = (pd[depth][free_servers] * arrange[servers-free_servers][occupies-occupy_free]) % mod;
				th = (th * choose[occupies][occupies-occupy_free]) % mod;
				t[depth][free_servers-occupy_free] = (t[depth][free_servers-occupy_free] + th) % mod;
			}
		}

		for (int free_servers = 0; free_servers <= servers; free_servers++) {
			pd[depth][free_servers] = (t[depth][free_servers] * childr) % mod;
		}
	}

	return pd[depth][0];
}

int main() {
	for (int i = 0; i <= 200; i++) {
		for (int j = 0; j <= 200; j++) {
			arrange[i][j] = arra(i,j);
		}
	}

	choose[0][0]=1;
	for (int i = 1; i <= 200; i++) {
		choose[i][0] = 1;
		for (int j = 1; j <= 200; j++) {
			choose[i][j] = (choose[i-1][j-1] + choose[i-1][j]) % mod;
		}
	}


	for (scanf("%d", &T); T; T--) {
		printf("Case #%d: ", ++teste);

		memset(ct,0,sizeof(ct));
		nodes = 1;
		tot = 0;
		memset(end,0,sizeof(end));
		for (int i = 0; i < 110000; i++) adj[i].clear();

		scanf("%d %d", &m, &servers);
		for (int i = 0; i < m; i++) {
			scanf("%s", str);
			trie_add(0, str);
		}

		long long r = rec(0, 0);
		int occupies = min(ct[0], servers);
		r = (r * arrange[servers][occupies]) % mod;
		printf("%lld %lld\n", tot, r);
	}
}