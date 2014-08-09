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

int n, m;
int g[20], c[20];
int dist[1000];

int main() {
	while (scanf("%d", &m) && m) {
		for (int i = 0; i < m; i++) scanf("%d", &g[i]);
		for (int i = 0; i < m; i++) {
			scanf("%d", &c[i]);
		}
		memset(dist,-1,sizeof(dist));

		queue<int> q;
		q.push(100);
		dist[100] = 0;
		bool ok = false;
		while (!q.empty() && !ok) {
			int t = q.front();
			q.pop();

			for (int i = 0; i < m; i++) {
				if (g[i] == t) {
					dist[0] = dist[t]+1;
					ok = true;
					break;
				}
				else if (g[i] < t) {
					int nn = t - g[i] + c[i];
					if (nn <= 1000 && dist[nn] == -1) {
						dist[nn] = dist[t]+1;
						q.push(nn);
					}
				}
			}
		}

		if (ok) printf("%d\n", dist[0]);
		else printf("cavaleiro morreu\n");
	}
}