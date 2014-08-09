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

int diff[1100000];
int n,a,b,c,op;

int main() {
	while (scanf("%d", &n) && n) {
		memset(diff,0,sizeof(diff));
		bool halted = false;

		printf("MENSAGEM: [");
		while (n) {
			scanf("%d", &op);
			n--;

			if (halted) continue;

			if (op == 0) {
				halted = true;
			}
			else if (op == 18) {
				scanf("%d %d %d", &a, &b, &c);
				diff[a] += c;
				diff[b+1] -= c;
				n-=3;
			}
			else {
				scanf("%d", &a);
				printf("%c", diff[a] < 0 ? ' ' : 'A'+(diff[a]%26));
				n--;
			}
		}
		printf("]\n");
	}
}