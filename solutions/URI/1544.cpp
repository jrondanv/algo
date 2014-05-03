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

int n, k;
int pow2[] = {6, 2, 4, 8};

int calc(int n, int k) {
	if (k > n) return 1;

	int ans = 1;
	while (k < n && k % 5 != 1) {
		ans *= k++;
		ans %= 10;
	}

	while (n > k && n % 5 != 0) {
		ans *= n--;
		ans %= 10;
	}

	if (n == k) {
		while (n % 5 == 0) n /= 5;
		return (ans * n) % 10;
	}

	ans *= calc(k/5, n/5);
	ans *= pow2[( (n-k)/5 ) % 4];

	printf("calc %d %d %d\n", n, k, ans%10);
	return ans % 10;
}

int main() {
	while (scanf("%d %d", &n, &k) > 0) {
		k=n-k+1;
		printf("%d\n", calc(n, k));
	}
}