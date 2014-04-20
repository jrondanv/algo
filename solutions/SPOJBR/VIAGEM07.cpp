#include <stdio.h>
#include <algorithm>

using namespace std;

#define MAXN 40000
char modo;
int n,f;

#define getchar_unlocked getchar

struct est {
    int custo, tempo, escala;

    bool operator< (const est& ot) const {
        if (modo == 'P') {
            if (custo != ot.custo) return custo < ot.custo;
            if (tempo != ot.tempo) return tempo < ot.tempo;
        }
        else {
            if (tempo != ot.tempo) return tempo < ot.tempo;
            if (custo != ot.custo) return custo < ot.custo;
        }
        return escala < ot.escala;
    }

    est operator+ (const est& ot) const {
        est ret = {custo+ot.custo, tempo+ot.tempo, escala+ot.escala};
        return ret;
    }
};

est dist[1000];
est g[1000][1000];
int marc[1000];

est inf = {1000000000, 1000000000, 1000000};
est zero = {0,0,0};

inline int read_int() {
    char c;
    while ((c=getchar_unlocked()) < 48 || c > 57);
    int p = c-48;
    while ((c=getchar_unlocked()) >= 48 && c <= 57) p=p*10+c-48;
    return p;
}

int main() {
    n=read_int();
    f=read_int();
    while ((modo=getchar_unlocked()) != 'P' && modo != 'E');

    int ori = read_int();
    int dest = read_int();
    ori--; dest--;

    for (int i = 0; i < f; i++) {
        int u = read_int();
        int v = read_int();
        int c = read_int();
        int t = read_int();
        u--; v--;

        est voo = {c, t, 1};
        if (g[u][v].escala == 0 || voo < g[u][v]) g[u][v] = voo;
    }

    for (int i = 0; i < n; i++) {
        dist[i] = inf;
    }

    dist[ori] = zero;

    int curr = ori; 
    while (curr != -1) {
        marc[curr] = 1;

        if (curr == dest) break;

        for (int i = 0; i < n; i++) {
            if (g[curr][i].escala != 0) {
                est novo = dist[curr] + g[curr][i];
                if (novo < dist[i]) dist[i] = novo;
            }
        }

        curr = -1;
        for (int i = 0; i < n; i++) {
            if (!marc[i]) {
                if (curr == -1 || dist[i] < dist[curr]) {
                    curr = i;
                }
            }
        }
    }

    if (dist[dest].escala < 10000) printf("%d %d %d\n", dist[dest].custo, dist[dest].tempo, max(0,dist[dest].escala-1));
    else printf("-1\n");
}
