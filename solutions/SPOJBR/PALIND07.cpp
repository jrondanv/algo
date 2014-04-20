#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 1000000000
int n;

char alfa[30];
long long I;
int k;

long long pd[100];

char c[100];

void imprime(long long I, int k, int i) {
    if (k == 0) return;
    
    for (int j = 0; j < n; j++) {
        if (pd[k-1] < I) I -= pd[k-1];
        else {
            c[i] = alfa[j];
            imprime(I, k-1, i+1);
            return;
        }
    }
}

int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    scanf("%s", alfa);
    scanf("%d %lld", &k, &I);

    pd[0] = 1;
    for (int i = 1; i <= k/2 + 2; i++) {
        if (pd[i-1] > I || 1000000000000000001LL/pd[i-1] <= n) pd[i]=I+1;
        else pd[i] = n*pd[i-1];
    }

    imprime(I, (k+1)/2, 0);
    for (int i = 0; i < (k+1)/2; i++) printf("%c", c[i]);
    for (int i = k/2 - 1; i >= 0; i--) printf("%c", c[i]);
    printf("\n");
}
