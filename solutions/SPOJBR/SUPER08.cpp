#include <stdio.h>
#include <map>
#include <cstring>

using namespace std;

#define INF 1000000000
#define M 128
#define N 128

bool graph[M][N];
int FW[M][N];

bool seen[N];
int matchL[M], matchR[N];
int n, m, e;
int size;

struct sc {
    bool operator() (char* a, char* b) {
        if (strcmp(a,b) < 0) return 1;
        else return 0;
    }
};

map<char*, int, sc> heroi;
map<char*, int, sc> nomes;

char revmaph[100][32], revmapn[100][32];
char temp[32];

bool bpm( int u )
{
    for( int v = 0; v < n; v++ ) if( graph[u][v] )
    {
        if( seen[v] ) continue;
        seen[v] = true;

        if( matchR[v] < 0 || bpm( matchR[v] ) )
        {
            matchL[u] = v;
            matchR[v] = u;
            return true;
        }
    }
    return false;
}

int herois[100];
int pessoas[100];
int h, no;

int main()
{
    // Read input and populate graph[][]
    // Set m, n

    scanf("%d %d", &m, &e);
    n = m;
    for (int i = 0; i < m; i++) {
        scanf("%s", revmaph[i]);
        heroi[revmaph[i]]=h++;
    }
    for (int i = 0; i < n; i++) {
        scanf("%s", revmapn[i]);
        nomes[revmapn[i]]=no++;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) graph[i][j]=1;
    }

    for (int i = 0; i < e; i++) {
        scanf("%d", &size);
        h=no=0;
        for (int j = 0; j < size; j++) {
            scanf("%s", temp);
            if (heroi.find(temp) == heroi.end()) {
                pessoas[no++] = nomes[temp];
            }
            else herois[h++] = heroi[temp];
        }

        for (int j = 0; j < h; j++) {
            for (int k = 0; k < no; k++) {
                graph[herois[j]][pessoas[k]]=0;
            }
        }
    }

    memset( matchL, -1, sizeof( matchL ) );
    memset( matchR, -1, sizeof( matchR ) );
    int cnt = 0;
    for( int i = 0; i < m; i++ )
    {
        memset( seen, 0, sizeof( seen ) );
        if( bpm( i ) ) cnt++;
    }

    // cnt contains the number of happy pigeons
    // matchL[i] contains the hole of pigeon i or -1 if pigeon i is unhappy
    // matchR[j] contains the pigeon in hole j or -1 if hole j is empty

    if (cnt != n) {
        printf("IMPOSSIVEL\n");
        return 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) FW[i][j] = INF;
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j]) {
                FW[i][matchR[j]]=0;
            }
        }
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                FW[i][j] = min(FW[i][j], FW[i][k]+FW[k][j]);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%s:", revmaph[i]);
        for (int j = 0; j < n; j++) {
            if (graph[i][j] && !FW[matchR[j]][i]) printf(" %s", revmapn[j]);
        }
        printf("\n");
    }

    return 0;
}