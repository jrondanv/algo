#include <stdio.h>
#include <iostream>
#include <string.h>
#include <map> 
#include <algorithm>
#include <string>
#include <math.h>
 
using namespace std;
 
int a, b, c, d;
double f,r,g;
char op;
 
map<int, string> ddd;
 
double M[12][12];
int arr[11000];
 
#define mp make_pair
 
int t,n,m,l,k;
const int inf = 1000000000;

int func(int n, int m) {
    if (m*100 % l != 0) return inf;

    int num = m*100/l;
    int resp = 0;
    for (int val = n; n-val <= val; val--) {
        int coloca;
        if (val+val != n)
            coloca = min(num, min(arr[val], arr[n-val]));
        else 
            coloca = min(num, arr[val]/2);
        num -= coloca;

        if (val == n) resp += coloca;
        else resp += coloca*2;
    }

    if (num != 0) return inf;
    return resp;
}
 
int main() {
    while (scanf("%d %d", &n, &m) && n) {
        memset(arr,0,sizeof(arr));
        arr[0] = 100000;

        scanf("%d", &l);
        scanf("%d", &k);
        for (int i = 0; i < k; i++) {
            scanf("%d", &t);
            arr[t]++;
        }

        int best = inf;
        best = min(best, func(n,m));
        best = min(best, func(m,n));

        if (best == inf) printf("impossivel\n");
        else printf("%d\n", best);
    }
}