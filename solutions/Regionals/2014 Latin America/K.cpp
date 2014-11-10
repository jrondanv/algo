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

typedef long long ll;

#define INF 1000000000
#define pb push_back 
#define itr iterator 
#define sz size() 
#define mp make_pair

int n, d, cc;
int distracted[1100000];
int seat[1100000];
int xx[1100000];
int partialSums[2100000];
int lastmin[1100000];
int next[1100000];
std::vector<int> x;
int a, b;

inline int add(int k) {
	k++;
	if (k >= n) k-=n;
	return k;
}

inline int sub(int k) {
	k--;
	if (k < 0) k += n;
	return k;
}

int FindProperty(std::vector<int>& x) {
	int cursum = 0;
	for (int i = 0; i < n; i++) {
		cursum += x[i]-1;
		partialSums[i] = cursum;
	}
	for (int i = 0; i < n; i++) {
		cursum += x[i]-1;
		partialSums[n+i] = cursum;
	}

	int st = 0, ed = 0;
	lastmin[ed++] = 0;

	for (int i = 0; i < n; i++) {
		while (ed > st && partialSums[i] < partialSums[lastmin[ed-1]] ) ed--;
		lastmin[ed++] = i;
	}

	for (int i = 0; i < n; i++) {
		int val = partialSums[n+i] - partialSums[lastmin[st]];
		if (val <= 0) return (i+1)%n;

		if (lastmin[st] == i) st++;
		while (ed > st && partialSums[n+i] < partialSums[lastmin[ed-1]] ) ed--;
		lastmin[ed++] = n+i;
	}	
}

int main() {
	x.reserve(1100000);

	while (scanf("%d %d", &n, &d) != EOF) {
		++cc;
		
		memset(xx,0,sizeof(xx));
		x.clear();

		for (int i = 0; i < d; i++) {
			scanf("%d %d", &a, &b); a--; b--;
			distracted[a]=cc;
			seat[b]=cc;
		}

		if (n == d) {
			printf("1\n");
			continue;
		}

		int empty = 0;
		for (; seat[empty]==cc; empty++);
		next[empty] = empty;
		for (int k = sub(empty) % n; k != empty; k = sub(k)) {
			if (seat[k] != cc) next[k] = k;
			else next[k] = next[add(k)];
		}

		for (int i = 0; i < n; i++) if (distracted[i] != cc) {
			xx[next[i]]++;
		}

		for (int i = 0; i < n; i++) if (seat[i] != cc) {
			x.push_back(xx[i]);
		}

		n = x.size();
		int first = FindProperty(x);
		
		long long ans = x[first];
		x[add(first)] += x[first]-1;

		for (int k = add(first); k != first; k = add(k) ) {
			ans = (ans * x[k]) % 1000000007;
			x[add(k)] += x[k]-1;
		}

		printf("%lld\n", ans);
	}
}