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

int S, n;
int pd[1100000];
int vet[1100000];

int main() {
	for (scanf("%d", &S); S; S--) {
		memset(pd,0,sizeof(pd));

		scanf("%d", &n);
		int cur = 0;
		int la = 0;
		for (int i = 0; i < n; i++) {
			if (i != 0) pd[i] = max(pd[i], pd[i-1]);
			scanf("%d", &vet[i]);
			cur += vet[i];

			while (la < i && cur > 42) {
				cur -= vet[la++];
			}

			if (cur == 42) {
				if (la == 0) pd[i] = max(pd[i], 1);
				else pd[i] = max(pd[i], pd[la-1] + 1);
			}
		}

		printf("%d\n", pd[n-1]);
	}
}