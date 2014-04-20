#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using namespace std;

int N,t,resp;
int ngosta[20]; 

//#define getchar_unlocked() getchar()

inline int read_int() {
    char c;
    while ((c=getchar_unlocked()) < 48 || c > 57);
    int p = c-48;
    while ((c=getchar_unlocked()) >= 48 && c <= 57) p=p*10+c-48;
    return p;
}

int rec(int prev, int cur, int s) {
    if (cur == N) return s;
    
    int best = s;
    for (int i = cur; i < N; i++) {
        if (!(ngosta[i] & prev)) best = max(best, rec(prev|(1<<i), i+1, s+1));
    }
    
    return best;
}

int main() {
    int teste=0;
    while (N=read_int()) {
        memset(ngosta,0,sizeof(ngosta));
        for (int i = 0; i < N; i++) {
            while (t=read_int()) {
                t--;
                ngosta[i] |= (1<<t);
                ngosta[t] |= (1<<i);
            }
        }
        
        printf("Teste %d\n",++teste);
        printf("%d\n\n", rec(0,0,0));
    }
}

