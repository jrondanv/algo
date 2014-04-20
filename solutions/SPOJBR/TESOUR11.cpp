#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int K,x,y,d;

int pista[101][101];

inline int read_int() {
    char c;
    while ((c=getchar_unlocked()) < 48 || c > 57);
    int p = c-48;
    while ((c=getchar_unlocked()) >= 48 && c <= 57) p=p*10+c-48;
    return p;
}

int main() {
    N=read_int();
    K=read_int();
    
    for (int i = 0; i < K; i++) {
        x=read_int();
        y=read_int();
        d=read_int();
        
        for (int dx = max(-x,-d); dx <= d && x+dx < N; dx++) {
            int dy = d-abs(dx);
            if (0 <= y+dy && y+dy < N) {
                pista[x+dx][y+dy]++;
            }
            if (dy != 0) {
                if (0 <= y-dy && y-dy < N) {
                    pista[x+dx][y-dy]++;
                }
            }
        }
    }
    
    int locx = -2;
    int locy = 0;
    
    for (int i = 0; i < N && locx != -1; i++) {
        for (int j = 0; j < N && locx != -1; j++) {
            if (pista[i][j] == K) {
                if (locx == -2) {
                    locx = i;
                    locy = j;
                }
                else locx = locy = -1;
            }
        }
    } 
    
    printf("%d %d\n", locx, locy);
}

