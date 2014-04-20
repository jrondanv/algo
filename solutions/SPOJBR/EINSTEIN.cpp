/**
 *  //////////////////////////////
 *  // Stoer-Wagner Minimum Cut //
 *  //////////////////////////////
 *
 * MAIN FUNCTION: minCut( n )
 *      Takes an undirected, weighted graph and returns the weight
 *      of the minimum cut in it. A cut is a set of edges that,
 *      when removed, disconnects the graph. A minimum cut is a
 *      cut of minimum total weight.
 * ALGORITHM:
 *      This is a O(n^3) implementation of the Stoer-Wagner
 *      deterministic algorithm (no randomization is required).
 * FIELD TESTING:
 *      - UVa 10989: Bomb, Divide and Conquer
 *
 * LAST MODIFIED:
 *      January 31, 2006
 *
 * This file is part of my library of algorithms found here:
 *      http://shygypsy.com/tools/
 * LICENSE:
 *      http://shygypsy.com/tools/LICENSE.html
 * Copyright (c) 2006
 **/

#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

// Maximum number of vertices in the graph
#define NN 110

// Maximum edge weight (MAXW * NN * NN must fit into an int)
#define MAXW 110

// Adjacency matrix and some internal arrays
int g[NN][NN], v[NN], w[NN], na[NN];
bool a[NN];

int minCut( int n )
{
    // init the remaining vertex set
    for( int i = 0; i < n; i++ ) v[i] = i;

    // run Stoer-Wagner
    int best = MAXW * n * n;
    while( n > 1 )
    {
        // initialize the set A and vertex weights
        a[v[0]] = true;
        for( int i = 1; i < n; i++ )
        {
            a[v[i]] = false;
            na[i - 1] = i;
            w[i] = g[v[0]][v[i]];
        }

        // add the other vertices
        int prev = v[0];
        for( int i = 1; i < n; i++ )
        {
            // find the most tightly connected non-A vertex
            int zj = -1;
            for( int j = 1; j < n; j++ )
                if( !a[v[j]] && ( zj < 0 || w[j] > w[zj] ) )
                    zj = j;

            // add it to A
            a[v[zj]] = true;

            // last vertex?
            if( i == n - 1 )
            {
                // remember the cut weight
                best = min(best,w[zj]);

                // merge prev and v[zj]
                for( int i = 0; i < n; i++ )
                    g[v[i]][prev] = g[prev][v[i]] += g[v[zj]][v[i]];
                v[zj] = v[--n];
                break;
            }
            prev = v[zj];

            // update the weights of its neighbours
            for( int j = 1; j < n; j++ ) if( !a[v[j]] )
                w[j] += g[v[zj]][v[j]];
        }
    }
    return best;
}



int main(){
    int T;
    scanf("%d", &T);
    
    for (int t = 0; t < T; t++) {
        int N,M;
        scanf("%d %d", &N, &M);
        
        memset(g,0,sizeof(g));
        
        for (int i = 0; i < M; i++) {
            int u,v,c;
            scanf("%d %d %d", &u,&v,&c);
            
            g[u-1][v-1]=g[v-1][u-1]=c;   
        }
        
        printf("%d\n", minCut(N));
    }


return 0;

}
