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

int ct[2000000];
int k,a;

int main() {
	while (scanf("%d", &k) > 0 && k) {
		fill(ct, ct+k+4, 1);
		for (int i = 0; i < k; i++) {
			scanf("%d", &a);
			ct[a]++;
		}

		printf("%d", ct[1]);
		for (int i = 2; i <= k+2; i++) printf(" %d", ct[i]);
		printf("\n");
	}
}