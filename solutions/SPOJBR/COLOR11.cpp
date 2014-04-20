#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int M,X,Y,K,x,y,d,t;

int g[201][201];
struct p {
    int x, y;
} fila[40000];
int ini, fim;

// #define getchar_unlocked() getchar()

inline int read_int() {
    char c;
    while ((c=getchar_unlocked()) < 48 || c > 57);
    int p = c-48;
    while ((c=getchar_unlocked()) >= 48 && c <= 57) p=p*10+c-48;
    return p;
}

int main() {
    N=read_int();
    M=read_int();
    X=read_int();
    Y=read_int();
    K=read_int();
    
    for (int i = 0; i < K; i++) {
        x=read_int(); y=read_int();
        g[x][y]=1;
    }
    
    fila[0].x = X;
    fila[0].y = Y;
    g[X][Y]=1;
    fim++;
    
    int cnt = 0;
    while (ini != fim) {
        cnt++;
        p th = fila[ini++];
        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                if (dx*dy == 0 && dx+dy == 0) continue;
                if (th.x+dx <= 0 || th.x+dx > N) continue;
                if (th.y+dy <= 0 || th.y+dy > M) continue;
                if (!g[th.x+dx][th.y+dy]) {
                    g[th.x+dx][th.y+dy]=1;
                    fila[fim].x=th.x+dx;
                    fila[fim++].y=th.y+dy;
                }
            }
        }
    }
    
    printf("%d\n",cnt);
}

