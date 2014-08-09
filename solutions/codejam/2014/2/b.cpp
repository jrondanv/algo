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

pii a[1248];
int isr[1248];
set<int> present;

int T, n, teste;

int main() {
	for (scanf("%d", &T); T; T--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i].first);
			a[i].second = i;
			isr[i] = 0;
		}

		sort(a, a+n);

		int l = 0;
		int r = n-1;
		int tot = 0;
		for (int i = 0; i < n; i++) {
			int c = l;
			for (int j = i+1; j < n; j++) {
				if (a[j].second < a[i].second) c++;
				//printf("%d\n", c);
			}
			/*for (int j = 0; j < i; j++) {
				if (a[j].second < a[i].second && isr[j]) c--;
			}*/

			//printf("I think %d is at %d (%d-%d)\n", a[i].first, c, l, r);

			if (c-l < r-c) {
				tot += c-l;
				l++;
			}
			else {
				tot += r-c;
				isr[i]=1;
				r--;
			}
		}

		printf("Case #%d: %d\n", ++teste, tot);
	}
}