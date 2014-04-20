#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

#define INF 1000000001

typedef long long ll;

ll F, resp, N, mdc, diff_mdc;
ll fla[100000];

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    else return gcd(b,a%b);
}

void calc(ll k) {
    if (diff_mdc % k != 0) return;
    resp += (N-1)/k;
}

int main() {
    while (scanf("%lld", &F) && F) {
        N = INF;
        mdc = 0;
        for (int i = 0; i < F; i++) {
            scanf("%lld", fla+i);
            N = min(N, fla[i]);
            mdc = gcd(mdc, fla[i]);
        }
        
        diff_mdc = 0;
        for (int i = 1; i < F; i++) {  
            diff_mdc = gcd(diff_mdc, abs(fla[i]-fla[i-1]));
        }
        
        resp = 0;
        for (int i = 1; i*i <= mdc && i<=N/F; i++) {
            if (mdc % i == 0) {
                calc(i*F);
                if (mdc/i != i) calc(mdc/i * F);
            }
        }
        
        printf("%lld\n", resp);
    }    

}
