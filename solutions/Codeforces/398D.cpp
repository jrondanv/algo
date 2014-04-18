// gets TLE because of the log factor in conn :(

#include <stdio.h>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

int n, m, q;
int o, u, v;
char op;

int on[50000];
int ans[50000];
int is_big[50000];
set<int> conn[50000];

int lim = 900;
vector<int> big;

int countf(int x) {
	if (is_big[x]) return ans[x];

	int an = 0;
	for (set<int>::iterator it = conn[x].begin(); it != conn[x].end(); it++) {
		an += on[*it]; 
	} 
	return an;
}

void online(int k) {
	on[k]=1;
	for (int i = 0; i < big.size(); i++) {
		if (conn[k].count(big[i])) ans[big[i]]++;
	}
}

void offline(int k) {
	on[k] = 0;
	for (int i = 0; i < big.size(); i++) {
		if (conn[k].count(big[i])) ans[big[i]]--;
	}
}

void add_friend(int x, int y) {
	conn[x].insert(y);
	conn[y].insert(x);

	if (is_big[x] && on[y]) ans[x]++;
	if (is_big[y] && on[x]) ans[y]++;
	
	if (!is_big[x] && conn[x].size()>lim) {
		ans[x] = countf(x);
		is_big[x] = 1;
		big.push_back(x);
	}

	if (!is_big[y] && conn[y].size()>lim) {
		ans[y] = countf(y);
		is_big[y] = 1;
		big.push_back(y);
	}
}

void del_friend(int x, int y) {
	conn[x].erase(y);
	conn[y].erase(x);

	if (is_big[x] && on[y]) ans[x]--;
	if (is_big[y] && on[x]) ans[y]--;
}

int main() {
	scanf("%d %d %d", &n, &m, &q);

	scanf("%d", &o);
	for (int i = 0; i < o; i++) {
		scanf("%d", &u); u--;
		on[u]=1;
	}

	for (int i = 0; i < m; i++) {
		scanf("%d %d", &u, &v); u--; v--;
		add_friend(u,v);
	}

	for (int i = 0; i < q; i++) {
		scanf(" %c %d", &op, &u); u--;

		if (op == 'O') online(u);
		else if (op == 'F') offline(u);
		else if (op == 'C') printf("%d\n", countf(u));
		else if (op == 'A') {
			scanf("%d", &v); v--;
			add_friend(u,v);
		}
		else {
			scanf("%d", &v); v--;
			del_friend(u,v);
		}
	}
}