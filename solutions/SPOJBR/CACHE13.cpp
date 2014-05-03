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

int mod = 1000000007;
long long n;

void copia(ll c[2][2], ll a[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) c[i][j] = a[i][j];
    }
}

long long modit(ll c) {
    return ((c%mod)+mod)%mod;
}

void mult(ll c[2][2], ll a[2][2], ll b[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            c[i][j] = 0;
            for (int k = 0; k < 2; k++) {
                c[i][j] += a[i][k]*b[k][j];
            }
            c[i][j] = modit(c[i][j]);
        }
    }

}

void pow(ll c[2][2], ll a[2][2], ll b) {
    if (b == 0) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                if (i == j) c[i][j] = 1;
                else c[i][j] = 0;
            }
        }
        return;
    }
    if (b == 1) {
        copia(c, a);
        return;
    }

    ll temp[2][2];

    pow(c, a, b/2);
    mult(temp, c, c);

    if (b&1) mult(c, temp, a);
    else copia(c, temp);
}

int main() {
    ll start[2][2] = { {5, -2}, {1, 0} };
    ll init[2][2] = { {54, 0}, {12, 0} };

    scanf("%lld", &n);
    
    ll pot[2][2];
    pow(pot, start, n-1);
    mult(start, pot, init);

    printf("%lld\n", start[1][0]);
}