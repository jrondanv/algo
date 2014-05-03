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

int win = 0;
int mod = 1000000007;
int n, kk, juc, h;

long long fac[1<<17];
long long arr[1<<17];
long long pass[20];
long long fail[20];

long long sub(long long a, long long b) {
	return (((a-b+mod)%mod) + mod)%mod;
}

int main() {
	scanf("%d %d", &n, &kk);
	scanf("%d", &juc);

	for (int i = 0; i < (1<<n)-1; i++) {
		scanf("%d", &h);
		if (h < juc) win++;
	}

	fac[0] = 1;
	arr[0] = 1;
	for (int i = 1; i <= (1<<n); i++) {
		fac[i] = (fac[i-1] * i) % mod;
		arr[i] = (arr[i-1] * (win-i+1)) % mod;
	}

	pass[0] = fac[(1<<n)];

	for (int k = 1; k <= n; k++) {
		pass[k] = (1<<n);
		pass[k] = (pass[k] * arr[(1<<k)-1]) % mod;
		pass[k] = (pass[k] * fac[(1<<n)-(1<<k)]) % mod;
		//printf("pass[%d]=%lld\n", k, pass[k]);
	}

	for (int k = 0; k <= n; k++) {
		fail[k] = sub(pass[k], pass[k+1]);
	}

	printf("%lld\n", fail[kk-1]);
}