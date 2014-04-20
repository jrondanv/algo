#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> adj[100010];
int n,T;

//#define getchar_unlocked getchar

inline int read_int() {
    char c;
    while ((c=getchar_unlocked()) < 48 || c > 57);
    int p = c-48;
    while ((c=getchar_unlocked()) >= 48 && c <= 57) p=p*10+c-48;
    return p;
}

int func(int v) {
    if (adj[v].size() == 0) return 1;

    vector<int> children;
    for (int i = 0; i < adj[v].size(); i++) {
        children.push_back(func(adj[v][i]));
    }

    sort(children.begin(), children.end());

    int ans = 0;
    for (int i = 0; i*100 < T*adj[v].size(); i++) {
        ans += children[i];
    }

    return ans;
}

int main() {
    while (n=read_int()) {
        T=read_int();

        for (int i = 0; i <= n; i++) adj[i].clear();

        for (int i = 1; i <= n; i++) {
            int p = read_int();
            adj[p].push_back(i);
        }

        printf("%d\n", func(0));
    }
}