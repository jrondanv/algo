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

int n,a;
int main() {
	while (scanf("%d", &n) && n) {
		int c=0, e;
		for (int i = 0; i < n; i++) {
			scanf("%d", &a);
			if (c == 0) {
				e = a;
				c++;
			}
			else {
				if (e == a) c++;
				else c--;
			}
		}
		printf("%d\n", e);
	}
}