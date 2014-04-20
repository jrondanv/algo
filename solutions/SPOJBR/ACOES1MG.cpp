#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int pd[1000001];
int cal[1000001];
int n, k;
int cont;

int calc(int n) {
    if (n <= k) return 1;
    if (cal[n] == cont) return pd[n];
    cal[n]=cont;
    return pd[n] = calc(n/2) + calc((n+1)/2);
}

int main() {
    while (scanf("%d %d", &n, &k) && n) {
        cont++;
        printf("%d\n",calc(n));
    }
}