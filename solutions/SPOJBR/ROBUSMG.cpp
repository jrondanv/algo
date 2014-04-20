#include <stdio.h>
#include <algorithm>

using namespace std;

int n,b;
int c[100];
double falha[100];

double pd[100][1000];
int calc[100][1000];
int cont;

//#define getchar_unlocked getchar

inline int read_int() {
    char c;
    while ((c=getchar_unlocked()) < 48 || c > 57);
    int p = c-48;
    while ((c=getchar_unlocked()) >= 48 && c <= 57) p=p*10+c-48;
    return p;
}

double func(int v, int b) {
    if (v == n) return 1.0;
    if (calc[v][b] == cont) return pd[v][b];

    double& resp = pd[v][b];
    calc[v][b] = cont;
    resp = 0;

    double f = 1;
    for (int k = 0; c[v]*k <= b; k++) {
        resp = max(resp, (1-f) * func(v+1, b - c[v]*k));
        f *= falha[v];
    }

    return resp;
}

int main() {
    while (n=read_int()) {
        b=read_int();
        cont++;
        for (int i = 0; i < n; i++) {
            c[i] = read_int();
            read_int();
            falha[i] = read_int() / ((double) 1000);
        }

        printf("%.3lf\n", func(0, b));
    }
}