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

long long c[8];
int n;

int main() {
	scanf("%d", &n);
	
	c[0] = 1;
	int s = 0;
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		s = (s + a) % 8;
		c[s]++;
	}

	long long ans = 0;
	for (int i = 0; i < 8; i++) ans += c[i]*(c[i]-1)/2;
	
	printf("%lld\n", ans);
}