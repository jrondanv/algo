#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <cmath>

int N, M, S;

using namespace std;

char mapa[110][110];

int fx, fy;
int x, y;

void rotE() {
    int temp = fx;
    fx = fy;
    fy = -temp;
}

void rotD() {
    int temp = fy;
    fy = fx;
    fx = -temp;
}

int main() {
    while (scanf("%d %d %d", &N, &M, &S) && N) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                scanf(" %c", &mapa[i][j]);
                
                if (mapa[i][j] == 'N') { x = j; y = i; mapa[i][j] = '.'; fx = 0; fy = -1; } 
                else if (mapa[i][j] == 'O') { x = j; y = i; mapa[i][j] = '.'; fx = -1; fy = 0; }
                else if (mapa[i][j] == 'L') { x = j; y = i; mapa[i][j] = '.'; fx = 1; fy = 0; }
                else if (mapa[i][j] == 'S') { x = j; y = i; mapa[i][j] = '.'; fx = 0; fy = 1; }
            }
        }
        
        for (int i = 0; i <= M+1; i++) mapa[0][i] = mapa[N+1][i] = '#';
        for (int i = 0; i <= N+1; i++) mapa[i][0] = mapa[i][M+1] = '#';
        
        int cnt = 0;
        
        for (int i = 0; i < S; i++) {
            char op;
            scanf(" %c", &op);
            
            if (op == 'E') rotE();
            else if (op == 'D') rotD();
            else {
                int destx = x+fx, desty = y+fy;
                
                if (mapa[desty][destx] == '#') continue;
                else if (mapa[desty][destx] == '*') {
                    cnt++;
                    mapa[desty][destx] = '.';
                }
                
                x = destx; y = desty;
            }
        }
        
        printf("%d\n", cnt);
    }
    
}
