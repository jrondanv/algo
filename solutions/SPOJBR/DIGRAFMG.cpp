#include <stdio.h>
#include <string.h>
#include <vector>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int ent[1001];

int a,b,c,d;
int t, N;

inline int read_int() {
    char c;
    while ((c=getchar_unlocked()) < 48 || c > 57);
    int p = c-48;
    while ((c=getchar_unlocked()) >= 48 && c <= 57) p=p*10+c-48;
    return p;
}

int main(){
    while (N=read_int()) {
        bool poss = true;
        memset(ent,0,sizeof(ent));
        for (int i = 0; i < N; i++) {
            a=read_int();
            ent[a]++;
        }
        
        for (int i = 0; i < N; i++) {
            b=read_int();
            int next = ent[1000];
            for (int j = 1000; j > 0 && b && poss; j--) {
                int rem = min(next,b);
                next = ent[j-1];
                ent[j]-=rem;
                ent[j-1]+=rem;
                b -= rem;
            }
            
            if (b > 0) poss = false;
        }
        
        if (ent[0] != N) poss = false;
        
        if (!poss) printf("N\n");
        else printf("E\n");
    }
}

