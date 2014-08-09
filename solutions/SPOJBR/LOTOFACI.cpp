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

int ct[100];
int n, a, teste;

int choose(int n, int k) {
	if (k > n) return 0;

	int r = 1;
	for (int i = n; i > k; i--) {
		r *= i;
	}
	for (int i = 2; i <= n-k; i++) r /= i;
	return r;
}

int main() {
	for (int i = 0; i < 15; i++) {
		scanf("%d", &a);
		ct[a]=1;
	}

	bool f = true;
	while (scanf("%d", &n) > 0) {
		//if (!f) printf("\n");
		//else f = false;

		printf("Aposta %d\n", ++teste);
		int cnt = 0;
		for (int i = 0 ; i < n; i++) {
			scanf("%d", &a);
			if (ct[a]) cnt++;
		}

		if (cnt < 11) {
			printf("nenhum premio aqui\n");
			continue;
		}

		for (int i = 11; i <= 15; i++) {
			int tot = choose(cnt, i) * choose(n-cnt, 15-i);
			if (tot) printf("%d: %d\n", i, tot);
		}

		printf("\n");
	}
}