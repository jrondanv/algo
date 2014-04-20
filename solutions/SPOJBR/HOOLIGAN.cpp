/**
 *   //////////////////
 *   // MAXIMUM FLOW //
 *   //////////////////
 *
 * This file is part of my library of algorithms found here:
 *      http://www.palmcommander.com:8081/tools/
 * LICENSE:
 *      http://www.palmcommander.com:8081/tools/LICENSE.html
 * Copyright (c) 2004
 * Contact author:
 *      igor at cs.ubc.ca
 **/

/****************
 * Maximum flow * (Ford-Fulkerson on an adjacency matrix)
 ****************
 * Takes a weighted directed graph of edge capacities as an adjacency 
 * matrix 'cap' and returns the maximum flow from s to t.
 *
 * PARAMETERS:
 *      - cap (global): adjacency matrix where cap[u][v] is the capacity
 *          of the edge u->v. cap[u][v] is 0 for non-existent edges.
 *      - n: the number of vertices ([0, n-1] are considered as vertices).
 *      - s: source vertex.
 *      - t: sink.
 * RETURNS:
 *      - the flow
 *      - fnet contains the flow network. Careful: both fnet[u][v] and
 *          fnet[v][u] could be positive. Take the difference.
 *      - prev contains the minimum cut. If prev[v] == -1, then v is not
 *          reachable from s; otherwise, it is reachable.
 * DETAILS:
 * FIELD TESTING:
 *      - Valladolid 10330: Power Transmission
 *      - Valladolid 653:   Crimewave
 *      - Valladolid 753:   A Plug for UNIX
 *      - Valladolid 10511: Councilling
 *      - Valladolid 820:   Internet Bandwidth
 *      - Valladolid 10779: Collector's Problem
 * #include <string.h>
 * #include <queue>
 **/

#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

// the maximum number of vertices
#define NN 800

// adjacency matrix (fill this up)
int cap[NN][NN];

// flow network
int fnet[NN][NN];

// BFS
int q[NN], qf, qb, prev[NN];

int fordFulkerson( int n, int s, int t )
{
    // init the flow network
    memset( fnet, 0, sizeof( fnet ) );

    int flow = 0;

    while( true )
    {
        // find an augmenting path
        memset( prev, -1, sizeof( prev ) );
        qf = qb = 0;
        prev[q[qb++] = s] = -2;
        while( qb > qf && prev[t] == -1 )
            for( int u = q[qf++], v = 0; v < n; v++ )
                if( prev[v] == -1 && fnet[u][v] - fnet[v][u] < cap[u][v] )
                    prev[q[qb++] = v] = u;

        // see if we're done
        if( prev[t] == -1 ) break;

        // get the bottleneck capacity
        int bot = 0x7FFFFFFF;
        for( int v = t, u = prev[v]; u >= 0; v = u, u = prev[v] )
            bot = min(bot,cap[u][v] - fnet[u][v] + fnet[v][u]);

        // update the flow network
        for( int v = t, u = prev[v]; u >= 0; v = u, u = prev[v] )
            fnet[u][v] += bot;

        flow += bot;
    }

    return flow;
}

int enfrenta[40][40];
int pontos[40];

int main() {
    int N,M,G;
    int teste = 1;

   while(scanf("%d %d %d", &N, &M, &G) && N) {
        memset(pontos,0,sizeof(pontos));
        
        int games_left = M*N*(N-1)/2 - G;
        
        for (int i = 0; i < N; i++) {
            for (int j = i+1; j < N; j++) {
                enfrenta[i][j] = enfrenta[j][i] = M;
            }
        }
        
        for (int i = 0; i < G; i++) {
            int u, v;
            char c;
            
            scanf(" %d %c %d", &u,&c,&v);
            
            enfrenta[u][v]--;
            enfrenta[v][u]--;
            
            if (c == '<') pontos[v] += 2;
            else {
                pontos[u]++;
                pontos[v]++;
            }
        }
        
        for (int i = 1; i < N; i++) {
            pontos[0] += 2*enfrenta[0][i];
            games_left -= enfrenta[0][i];
        }
        
        memset(cap, 0, sizeof(cap));
        
        int tot = 0;
        for (int i = 1; i < N; i++) {
            for (int j = i+1; j < N; j++) {
                if (enfrenta[i][j] != 0) {
                    cap[0][N+tot] = cap[N+tot][i] = cap[N+tot][j] = 2*enfrenta[i][j];
                    tot++;
                }
            }
        }
        
        int t = N+tot;
        
        int impossible = 0;
        for (int i = 1; i < N; i++) {
            if (pontos[i] >= pontos[0]) impossible = 1;
            cap[i][t] = pontos[0] - pontos[i] - 1;
        }
        
        if (impossible) {
            printf("N\n");
            continue;
        }
        
        int flow = fordFulkerson(t+1, 0, t);
        if (flow == games_left*2) printf("Y\n");
        else printf("N\n");
   }
}
