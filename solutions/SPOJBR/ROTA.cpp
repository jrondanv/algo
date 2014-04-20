#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <map>

using namespace std;

map<string, int> m;
string back[100];

int N, M;

struct conn {
    int n, id;
} c[100];

int dom[100][100];
int g[100][100];

struct edge {
    int a, b;
};

bool dfs(int i, int blocked) {
    if (dom[i][blocked]) return false;
    dom[i][blocked] = 1;
    
    for (int j = 0; j < N; j++) {
        if (j == blocked) {
            if (g[j][i]) {
                c[j].n++;
                c[j].id = i;
                if (c[j].n == 2) return true;
            }
        }
        if (j != blocked && j != i && g[j][i]) {
            if (dfs(j,blocked)) return true;
        }
    }
    
    return false;
}

edge e[10000];

int main() {
    string a,b;
    while (scanf("%d %d",&N, &M) && N) {
        m.clear();
        
        memset(g,0,sizeof(g));
        memset(dom,0,sizeof(dom));
        memset(c,0,sizeof(c));
        
        for (int i = 0; i < N; i++) {
            cin >> a;
            m[a]=i;
            back[i]=a;
        }
        
        for (int i = 0; i < M; i++) {
            cin >> a >> b;
            int c1 = m[a], c2 = m[b];
            
            e[i].a=c1;
            e[i].b=c2;
            g[c1][c2]++;
        }
        
        for (int i = 1; i < N; i++) {
            dfs(0, i);
        }
        
        bool found = false;
        for (int i = 0; i < M; i++) {
            if (e[i].a != 0 && g[e[i].a][e[i].b] == 1) {
                //printf("%d %d %d %d\n", e[i].a, e[i].b, c[e[i].a].n, c[e[i].a].id);
                if (c[e[i].a].n == 1 && c[e[i].a].id == e[i].b) {
                    found = true;
                    printf("%s %s\n", back[e[i].a].c_str(), back[e[i].b].c_str());
                }
            }
        }
        
        if (!found) printf("Nenhuma\n");
        printf("\n");
    }
}
