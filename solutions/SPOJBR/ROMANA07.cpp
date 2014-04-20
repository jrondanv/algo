#include <stdio.h>
#include <ctype.h>

using namespace std;
 
int ways[101][25];

int N, P, T;

int g[250][250];
int dist[250];
int marc[250];
int pedre[20];

const int SIZE = 1 << 18;
char buff[SIZE], *p = buff + SIZE;

char read_char()
{
    if( p == buff + SIZE )
    {
        fread( buff, 1, SIZE, stdin );
        p = buff;
    }
    return *(p++);
}

inline int read_int()
{
    char c;

    while( !isdigit( c = read_char() ) );

    int r = c-'0';
    while( isdigit( c = read_char() ) ) r = 10*r + c - '0';

    return r;
}

int prim() {
    int curr = 0;
    int cost = 0;
    
    int cnt = 0;
    while (curr != -1) {
        cnt++;
        marc[curr]=1;
        cost += dist[curr];
        
        for (int j = 0; j < N; j++) {
            if (!marc[j] && g[curr][j]) {
                if (!dist[j] || dist[j] > g[curr][j]) dist[j] = g[curr][j];
            }
        }
        
        curr = -1;
        int min_dist = 1000000000;
        for (int j = 0; j < N; j++) {
            if (!marc[j] && dist[j] && dist[j] < min_dist) {
                curr = j;
                min_dist = dist[j];
            }
        }
    }
    
    if (cnt == N) return cost;
    else return -1;
}

int main() {
    N=read_int(); P=read_int(); T=read_int();
    
    for (int i = 0; i < P; i++) {
        pedre[i] = read_int();
    }
    
    for (int j = 0; j < P; j++) ways[0][j]=1;
    
    for (int i = 1; i <= 100; i++) {
        for (int j = P-1; j >= 0; j--) {
            ways[i][j] = ways[i][j+1];
            if (pedre[j] > i) continue;
            ways[i][j] += ways[i-pedre[j]][j];
        }
    }
    
    int a,b,c;
    for (int i = 0; i < T; i++) {
        a=read_int(); b=read_int(); c=read_int();
        if (ways[c][0]) {
            if (g[a-1][b-1] == 0 || g[a-1][b-1] > ways[c][0]) {
                g[a-1][b-1] = g[b-1][a-1] = ways[c][0];
            }
        }
    }
    /*
    printf("\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", g[i][j]);
        }
        printf("\n");
    }*/
    
    printf("%d\n", prim());
}

