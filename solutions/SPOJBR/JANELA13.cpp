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

int a, b, c;

bool cover(int l, int a) {
	return (a <= l && a + 200 > l);
}

int main() {
	scanf("%d %d %d", &a, &b, &c);
	int ans = 0;
	for (int l = 0; l < 600; l++) {
		if (!cover(l,a) && !cover(l,b) && !cover(l,c)) ans++;
	}	
	printf("%d\n", ans * 100);
}