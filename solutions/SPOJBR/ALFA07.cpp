#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <ctype.h>
#include <functional>

using namespace std;

int stored_a[100][500];
int stored_b[100][500];
int pd[100][500][500];
int arr[100];
int N,Q,a,total;
int lim;
#define INF 1000000000

int func(int i, int a, int b, int c) {
    if (i == N) {
        int ret = total;
        ret -= (Q-a);
        ret -= (Q-b);
        
        //int c = total-(Q-a)-(Q-b);
        ret -= min(Q,c);
        
        return ret;
    }
    
    if (a == 0 && b == 0 && c >= Q) return total-3*Q;
    
    int addr_a = a, addr_b = b;
    int& res = pd[i][addr_a][addr_b];
    
    if (res) {
        if (a == 0) {
            if (stored_a[i][b] >= c) return res;
        }
        else if (b == 0) {
            if (stored_b[i][a] >= c) return res;
        }
        else return res;
    }
    
    if (a == 0) stored_a[i][b]=max(stored_a[i][b],c);
    if (b == 0) stored_b[i][a]=max(stored_b[i][a],c);
    
    int best = INF;
    if (c < Q) best = min(best, func(i+1, a, b, c+arr[i]));
    if (best <= lim) return best;
    
    if (a > 0) best = min(best, func(i+1, max(0,a-arr[i]), b, c));
    if (best <= lim) return best;
    
    if (b > 0) best = min(best, func(i+1, a, max(0,b-arr[i]), c));
    if (best <= lim) return best;
    
    return res=best;
}

int main() {
    //memset(pd,-1,sizeof(pd));
    scanf("%d %d %d", &N, &Q, &a); //N=read_int(), Q=read_int(), a=read_int();
    
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]); //arr[i]=read_int();
        total += arr[i];
    }
    sort(arr,arr+N,greater<int>());
    
    lim = max(0, total-3*Q);
    double resp = func(1,max(0,Q-arr[0]),Q,0) * a;
    resp /= 100;
    printf("%.2lf\n",resp);
}

	
