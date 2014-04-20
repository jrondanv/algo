/**
 *   ///////////////////////////////////
 *   // STRONGLY CONNECTED COMPONENTS //
 *   ///////////////////////////////////
 *
 * This file is part of my library of algorithms found here:
 *      http://www.palmcommander.com:8081/tools/
 * LICENSE:
 *      http://www.palmcommander.com:8081/tools/LICENSE.html
 * Copyright (c) 2008
 * Contact author:
 *      igor at cs.ubc.ca
 **/

/*********************************
 * Strongly Connected Components * (Tarjan's linear-time)
 *********************************
 * Takes a directed graph and produces a Union-Find array.
 *
 * PARAMETERS:
 *      - deg (global): vertex degrees
 *      - adj (global): adjacency list
 *      - n: the number of vertices ([0, n-1] are considered as vertices).
 * RETURNS:
 *      - uf (global): FIND(u) == FIND(v) iff u and v are in the same component.
 * FIELD TESTING:
 *      - Valladolid 11324: Largest Clique
 **/

#define NN 4000
#include <stdio.h>
#include <map>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
map<string,int> comidas;

// Inputs (populate these).
int deg[NN];
int adj[NN][NN];

// Union-Find.
int uf[NN];
int FIND( int x ) { return uf[x] == x ? x : uf[x] = FIND( uf[x] ); }
void UNION( int x, int y ) { uf[FIND( x )] = FIND( y ); }

// dfsn[u] is the DFS number of vertex u.
int dfsn[NN], dfsnext;

// mindfsn[u] is the smallest DFS number reachable from u.
int mindfsn[NN];

// The O(1)-membership stack containing the vertices of the current component.
int comp[NN], ncomp;
bool incomp[NN];

void dfs( int n, int u )
{
  dfsn[u] = mindfsn[u] = dfsnext++;
  incomp[comp[ncomp++] = u] = true;
  for( int i = 0, v; v = adj[u][i], i < deg[u]; i++ )
  {
    if( !dfsn[v] ) dfs( n, v );
    if( incomp[v] ) mindfsn[u] = min(mindfsn[u],mindfsn[v]);
  }
  
  if( dfsn[u] == mindfsn[u] )
  {
    // u is the root of a connected component. Unify and forget it.
    do
    {
      UNION( u, comp[--ncomp] );
      incomp[comp[ncomp]] = false;
    } while( comp[ncomp] != u );
  }
}

void scc( int n )
{
  // Init union-find and DFS numbers.
  for( int i = 0; i < n; i++ ) dfsn[uf[i] = i] = ncomp = incomp[i] = 0;
  dfsnext = 1;

  for( int i = 0; i < n; i++ ) if( !dfsn[i] ) dfs( n, i );
}

//----------------- EXAMPLE USAGE -----------------
int last;

int get_index(string& a) {
    map<string,int>::iterator it;
    it = comidas.find(a);
    
    if (it != comidas.end()) {
        return it->second;
    }
    
    else {
        comidas[a] = last;
        deg[last]=deg[last+1]=0;
        
        last += 2;
        return last-2;
    }
}

int main()
{
    int n, t = 1;
    while (scanf("%d", &n) != EOF) {
        comidas.clear();
        last = 0;
        string a, b;
        
        for (int i = 0; i < n; i++) {
            cin >> a >> b;
    
            int nega = 0;
            int negb = 0;
            
            if (a[0] == '!') {
                nega = 1;
                a = a.substr(1);
            }
            if (b[0] == '!') {
                negb = 1;
                b = b.substr(1);
            }
            
            int inda,indb;
            inda = get_index(a) + nega;
            indb = get_index(b) + negb;
            
            if (negb) adj[inda][deg[inda]++] = indb - 1;
            else adj[inda][deg[inda]++] = indb + 1;
            
            if (nega) adj[indb][deg[indb]++] = inda - 1;
            else adj[indb][deg[indb]++] = inda + 1;
        }

        scc( last );

        int imp = 0;
        for( int i = 0; i < last && !imp; i+=2 ) {
            if( FIND( i ) == FIND( i+1 ) ) {
                imp = 1;
            }
        }
        
        printf("Instancia %d\n", t++);
        if (imp) printf("nao\n");
        else printf("sim\n");
        printf("\n");
    }
       
    return 0;
}
