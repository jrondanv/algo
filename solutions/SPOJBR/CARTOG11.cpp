#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>

using namespace std;

int N;
vector<int> edge[1000010];
int seen[1000010];
int id,val;
int cont;

inline int read_int() {
    char c;
    while ((c=getchar_unlocked()) < 48 || c > 57);
    int p = c-48;
    while ((c=getchar_unlocked()) >= 48 && c <= 57) p=p*10+c-48;
    return p;
}

void dfs(int x, int d) {
    if (seen[x]==cont) return;
    seen[x]=cont;
    if (d > val) {
        val = d;
        id = x;
    }
    
    for (int i = 0; i < edge[x].size(); i++) dfs(edge[x][i],d+1);
}

int main() {
    N=read_int();
    
    int a, b;
    for (int i = 0; i < N-1; i++) {
        a=read_int(); b=read_int();
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    
    cont=1; id=1; val=0;
    dfs(1,0);
    
    cont=2;
    val = 0;
    dfs(id,0);
    printf("%d\n", val);
}

