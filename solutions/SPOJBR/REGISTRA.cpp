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
#include <tr1/unordered_map>

using namespace std; 

typedef long long ll; 
typedef pair<int, int> pii;

#define INF 1000000000
#define pb push_back 
#define itr iterator 
#define sz size() 

const int dim = 32;
int mod = 2;
int n;

void copia(int c[dim][dim], int a[dim][dim]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) c[i][j] = a[i][j];
    }
}

void mult(int c[dim][dim], int a[dim][dim], int b[dim][dim]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            c[i][j] = 0;
            for (int k = 0; k < n; k++) {
                c[i][j] += a[i][k]*b[k][j];
            }
            c[i][j] &= 1;
        }
    }

}

void pow(int c[dim][dim], int a[dim][dim], int b) {
    if (b == 1) {
        copia(c, a);
        return;
    }

    int temp[dim][dim];

    pow(c, a, b/2);
    mult(temp, c, c);

    if (b&1) mult(c, temp, a);
    else copia(c, temp);
}

int t,a;
int m[32][32];
int mp[32][32];
unsigned b[32], bp[32];

unsigned ini, fim;


void construct(unsigned b[32], int m[32][32]) {
	for (int j = 0; j < n; j++) {
		b[j] = 0;
		for (int i = 0; i < n; i++) {
			if (m[i][j]) {
				b[j] |= 1<<(n-1-i);
			}
		}
	}
}

unsigned advance(unsigned th, unsigned b[32]) {
	unsigned r = 0;

	for (int i = 0; i < n; i++) {
		r ^= (!(!(th & (1<<(n-1-i))))) * b[i];
	}

	return r;
}

int main() {
	while (scanf("%d %d", &n, &t) && n) {
		for (int i = 0; i < 32; i++) {
			for (int j = 0; j < 32; j++) m[i][j] = 0;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i > 0 && j == i-1) m[i][j] = 1;
				else m[i][j] = 0;
			}
		}

		for (int i = 0; i < t; i++) {
			scanf("%d", &a);
			m[0][n-1-a] = 1;
		}

		tr1::unordered_map<unsigned, int> indices;
		tr1::unordered_map<unsigned, int> final;

		scanf("%x %x", &ini, &fim);

		if (ini == fim) {
			printf("0\n");
			continue;
		}

		indices[ini] = 0;
		unsigned th = ini;
		bool ok = true;
		bool found = false;

		int xp = max(0, n/2);
		int baby = 1<<xp;

		//printf("%u\n", th);
		construct(b,m);
		for (int i = 0; i < baby-1; i++) {
			th = advance(th, b);
			//printf("%u\n", th);

			if (th == fim) {
				found = true;
				printf("%d\n", i+1);
				break;
			}
			if (indices.find(th) != indices.end()) {
				ok = false;
				break;
			}
			
			indices[th] = i+1;
		}

		if (found) {
			continue;
		}

		if (!ok) {
			printf("*\n");
			continue;
		}

		pow(mp, m, baby);
		construct(bp,mp);

		unsigned cyc_tot = 0;
		th = ini;
		while (true) {
			th = advance(th, bp);
			cyc_tot += baby;
			if (indices.find(th) != indices.end()) {
				cyc_tot -= indices[th];
				break;
			}
		}

		//final.clear();
		final[fim] = 0;
		th = fim;
		for (int i = 0; i < baby-1; i++) {
			th = advance(th, b);
			//printf("%u\n", th);

			if (th == ini) {
				final[th] = i+1;
				found = true;
				break;
			}
			if (final.find(th) != final.end()) {
				ok = false;
				break;
			}
			
			final[th] = i+1;
		}

		if (!ok) {
			printf("*\n");
			continue;
		} 

		unsigned new_cyc = 0;
		if (final.count(ini)) new_cyc = final[ini];
		else {
			th = fim;
			while (true) {
				th = advance(th, bp);
				new_cyc += baby;
				if (indices.find(th) != indices.end()) {
					new_cyc -= indices[th];
					break;
				}
				if (final.count(th)) {
					ok = false;
					break;
				}
			}
		}

		if (!ok) {
			printf("*\n");
			continue;
		} 

		printf("%u\n", cyc_tot - new_cyc);
	}
}