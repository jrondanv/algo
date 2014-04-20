#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int T, N, M;

int visit[52][52][52][52];
int id = 0;

char mapa1[52][52];
char mapa2[52][52];

struct point {
    int x1,y1,x2,y2;
    
    bool operator==(point ot) const {
        return x1==ot.x1 && y1==ot.y1 && x2==ot.x2 && y2 == ot.y2;
    }
};

point fila[2000000];
int inic, fim;

int x1,y1,x2,y2;
int gx1,gy1,gx2,gy2;

int delta[2] = {1, 0};
void rot() {
    int temp = delta[0];
    delta[0] = -delta[1];
    delta[1] = temp;
} 

void le(char mapa[52][52], int& x, int& y, int& gx, int& gy) {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            scanf(" %c", &mapa[i][j]);
            if (mapa[i][j] == 'R') {
                mapa[i][j] = '.';
                x = i; y = j;
            }
            if (mapa[i][j] == 'F') {
                mapa[i][j] = '.';
                gx = i; gy = j;
            }
        }
    }
}

int main() {
    for (int i = 0; i < 52; i++) mapa1[0][i] = mapa2[0][i] = 'B';
    for (int i = 0; i < 52; i++) mapa1[i][0] = mapa2[i][0] = 'B';
        
    scanf("%d", &T);
    for (int t = 0; t < T; t++) {
        inic=fim=0;
        id++;
        
        scanf("%d %d", &N, &M);
        
        le(mapa1,x1,y1,gx1,gy1);
        le(mapa2,x2,y2,gx2,gy2);
        
        for (int i = 1; i <= M; i++) mapa1[N+1][i]=mapa2[N+1][i]='B';
        for (int i = 1; i <= N; i++) mapa1[i][M+1]=mapa2[i][M+1]='B';
        
        point start = {x1,y1,x2,y2};
        point goal = {gx1,gy1,gx2,gy2};
        fila[0] = start;
        fim++;
        
        int transition = 1;
        int dt = -1;
        bool trans = false;
        
        int d = -1;
        
        while (inic != fim) {
            point p = fila[inic++];
            
            if (inic == transition) {trans = true; dt++;}
            if (dt == 50) break;
            
            for (int i = 0; i < 4; i++, rot()) {
                point dest = p;
                dest.x1 += delta[0]; dest.x2 += delta[0];
                dest.y1 += delta[1]; dest.y2 += delta[1];
                
                if (mapa1[dest.x1][dest.y1] == 'B' || mapa2[dest.x2][dest.y2] == 'B') continue;
                
                if (mapa1[dest.x1][dest.y1] == '#') { dest.x1 -= delta[0]; dest.y1 -= delta[1]; }
                if (mapa2[dest.x2][dest.y2] == '#') { dest.x2 -= delta[0]; dest.y2 -= delta[1]; }
                
                if (dest == goal) {
                    d = dt+1;
                    break;
                }
                if (visit[dest.x1][dest.y1][dest.x2][dest.y2] == id) continue;
                visit[dest.x1][dest.y1][dest.x2][dest.y2]=id;
                fila[fim++]=dest;
                if (trans) { trans = false; transition = fim; }
            }
            
            if (d != -1) break;
        }
        
        if (d == -1) printf("impossivel\n");
        else printf("%d\n",d);
    }
    
    return 0;
}


