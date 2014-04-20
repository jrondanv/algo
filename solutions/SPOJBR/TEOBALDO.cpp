#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <queue>

using namespace std;

int N,M;

inline int read_int() {
    char c;
    while ((c=getchar_unlocked()) < 48 || c > 57);
    int p = c-48;
    while ((c=getchar_unlocked()) >= 48 && c <= 57) p=p*10+c-48;
    return p;
}

int a, b;
int S,E,D;
int g[100][100];
int marc[200];
queue<int> fila;
const int INF = 1000000000;

int main() {
    N=read_int();
    M=read_int();
    while (N) { 
        for (int i = 0; i < 2*N; i++) marc[i]=INF;
        memset(g,0,sizeof(g));
        
        for (int i = 0; i < M; i++) {
            a=read_int(); b=read_int(); a--; b--;
            g[a][b]=g[b][a]=1;
        }
        
        S=read_int();E=read_int();D=read_int();
        S--; E--;

        bool ok;
        fila.push(S<<1);
        marc[S<<1]=0;

        while (!fila.empty()) {
            int curr = fila.front();
            fila.pop();

            for (int i = 0; i < N; i++) {
                int dest = (i<<1) + ((curr&1)^1);
                if (g[curr>>1][i] && marc[dest]==INF) {
                    marc[dest] = marc[curr]+1;
                    fila.push(dest); 
                }
            }
        }

        int final = (E<<1) + (D&1);

        if (marc[final]<=D) printf("Yes, Teobaldo can travel.\n");
        else printf("No, Teobaldo can not travel.\n");

        N=read_int();
        M=read_int();
    }
}
