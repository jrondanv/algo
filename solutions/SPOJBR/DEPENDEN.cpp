#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int M,x,d,t;

int g[100][100];

 #define getchar_unlocked() getchar()

inline int read_int() {
    char c;
    while ((c=getchar_unlocked()) < 48 || c > 57);
    int p = c-48;
    while ((c=getchar_unlocked()) >= 48 && c <= 57) p=p*10+c-48;
    return p;
}

int seen[100];
int cont,contg;
int dfs(int x) {
    if (seen[x]==cont) return 0;
    seen[x]=cont;
    
    int ret = 1;
    for (int i = 0; i < N; i++) {
        if (g[x][i]==contg) ret += dfs(i);
    }
    return ret;
}

int main() {
    while (N=read_int()) {
        contg++;
        for (int i = 0; i < N; i++) {
            t=read_int();
            for (int j = 0; j < t; j++) {
                d=read_int()-1;
                g[i][d]=contg;
            }
        }
        
        int b = 0, id;
        for (int i = 0; i < N; i++) {
            cont++;
            int curr = dfs(i);
            if (curr > b) {
                b = curr;
                id = i;
            }
        }
        printf("%d\n",id+1);
    }
}

