#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string.h>
 
using namespace std;
const int INF = 1000000000;
int n,k,a,b;
 
int loc[1000];
int pd[1100];
int val[1100];
 
int main() {
    int kk;
    while (scanf("%d %d", &n, &kk) > 0 ) {
        loc[0] = 0;
        for (int i = 1; i < n; i++) scanf("%d", &loc[i]);
 
        for (int k = 0; k <= kk; k++) {
            for (int v = n; v >= 0; v-- ) {
                if (v == n) pd[v] = (k == 0) ? 0 : INF;
                else if (k == 0) pd[v] = INF;
                else pd[v] = -loc[v] + val[v];
 
                if (v != n) {
                    val[v] = loc[v] + pd[v+1];
                    if (v != n-1)val[v] = min(val[v], val[v+1]);
                }
            }
        }
 
        printf("%d\n", pd[0]);
    }
}
