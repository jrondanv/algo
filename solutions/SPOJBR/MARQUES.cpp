#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>

using namespace std;

#define NN 250
int cap[NN][NN], deg[NN], adj[NN][NN];
int q[NN], prev[NN];

int dinic( int n, int s, int t )
{
    int flow = 0;

    while( true )
    {
        memset( prev, -1, sizeof( prev ) );
        int qf = 0, qb = 0;
        prev[q[qb++] = s] = -2;
        while( qb > qf && prev[t] == -1 )
            for( int u = q[qf++], i = 0, v; i < deg[u]; i++ )
                if( prev[v = adj[u][i]] == -1 && cap[u][v] )
                    prev[q[qb++] = v] = u;

        if( prev[t] == -1 ) break;

        for( int z = 0; z < n; z++ ) if( cap[z][t] && prev[z] != -1 )
        {
            int bot = cap[z][t];
            for( int v = z, u = prev[v]; u >= 0; v = u, u = prev[v] )
                bot = min(bot, cap[u][v]);
            if( !bot ) continue;

            cap[z][t] -= bot;
            cap[t][z] += bot;
            for( int v = z, u = prev[v]; u >= 0; v = u, u = prev[v] )
            {
                cap[u][v] -= bot;
                cap[v][u] += bot;
            }
            flow += bot;
        }
    }

    return flow;
}

int T, N, M;
int h,m;

int bus[100];
int passcnt[100];
int pass[100][100];

int conn[100][100];

int main() {
    scanf("%d", &T);
    
    for (int t = 0; t < T; t++) {
        scanf("%d %d", &N, &M);
        
        int s = 0;
        int t = N+M+1;
        
        for (int i = 0; i < M; i++) {
            scanf("%d:%d", &h, &m);
            bus[i]=h*60+m;
        }
        for (int i = 0; i < N; i++) {
            int k;
            scanf("%d", &k);
            passcnt[i] = k;
            
            for (int j = 0; j < k; j++) {
                scanf("%d:%d", &h, &m);
                pass[i][j]=h*60+m;
            }
        }
        
        memset(cap,0,sizeof(cap));
        memset(conn,0,sizeof(conn));
        for (int i = 1; i <= N; i++) cap[s][i] = 1;
        for (int i = 1; i <= M; i++) cap[N+i][t] = 1;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                for (int k = 0; k < passcnt[i]; k++) {
                    if (pass[i][k] == bus[j]) {
                        cap[i+1][N+j+1]=1;
                        conn[i][j]=1;
                        break;
                    }
                }
            }
        }
        
        memset( deg, 0, sizeof( deg ) );
        for( int u = 0; u < t+1; u++ )
            for( int v = 0; v < t+1; v++ ) if( cap[u][v] || cap[v][u] )
                adj[u][deg[u]++] = v;
                
        int e = 1, d = N;
        while (e < d) {
            int mid = (e+d)/2;
            
            for (int i = 1; i <= N; i++) cap[s][i] = 1;
            for (int i = 1; i <= M; i++) cap[N+i][t] = mid;
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    if (conn[i][j]) cap[i+1][N+j+1]=1;
                }
            }
        
            int flow = dinic(t+1,s,t);
            if (flow == N) d = mid;
            else e = mid+1;
        }
        
        printf("%d\n",e); 
    }
}

