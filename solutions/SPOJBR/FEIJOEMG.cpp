#include <stdio.h>
#include <string.h>
#include <vector>
#include <stdlib.h>
#include <algorithm>
using namespace std;

#define pop(x) __builtin_popcount(x)
#define ind(x) __builtin_ctz(x)

int t,K;
long long N;

inline long long read_int() {
    char c;
    while ((c=getchar_unlocked()) < 48 || c > 57);
    long long p = c-48;
    while ((c=getchar_unlocked()) >= 48 && c <= 57) p=p*10+c-48;
    return p;
}

int digs[18];
int size;
int d;

void pd(int d) {
    for (int i = d-1; i >= 0; i--) {
            printf("%d",digs[i]);
    }
    printf("\n");
}

bool rec(int dig, int there, bool any) {
    int tot = pop(there);
    if (dig == -1) return tot == K;
    if (tot > K) return false;
    
    if (any) {
        if (tot == K) {
            int f = ind(there&-there);
            digs[dig]=f;
            return rec(dig-1, there, true);
        }
        else if (K-tot < dig+1) {
            digs[dig]=0;
            return rec(dig-1,there|1, true);
        }
        else {
            int n = ~there;
            int f = ind(n&-n);
            digs[dig]=f;
            return rec(dig-1, there|(1<<f), true);
        }
    }
    
    int p = digs[dig];
    if (rec(dig-1, there | (1<<p), false)) return true;
    for (int i = p+1; i <= 9; i++) {
        digs[dig]=i;
        if (rec(dig-1, there | (1<<i), true)) return true;
    }
    digs[dig]=p;
    return false;
}

int main(){
    int teste=0;
    for (t=read_int(); t; t--) {
        printf("Caso %d: ", ++teste);
        N=read_int();
        K=read_int();
        
        d = 0;
        while (N) {
            digs[d++]=N%10;
            N /= 10;
        }
        
        bool any = false;
        int present=0;
        while (!rec(d-1, present, any)) {
            if (!any) {
                any=true;
                present=2;
            }
            else d++;
            digs[d]=1;
        }
        
        pd(d+any);
    }
}


