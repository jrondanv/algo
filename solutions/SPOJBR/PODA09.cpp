#include <stdio.h>
#include <algorithm>

using namespace std;

#define MAXN 40000

int n;
int alt[40000];
int maxprev[40000], minpost[40000];
double best;

inline int read_int() {
    char c;
    while ((c=getchar_unlocked()) < 48 || c > 57);
    int p = c-48;
    while ((c=getchar_unlocked()) >= 48 && c <= 57) p=p*10+c-48;
    return p;
}

void get_sum(int i, double inc) {
    double a1 = alt[i] - i*inc;
    best = max(best, n*(a1 + (n-1)*inc / 2));
}

struct ponto {
    int x, y;
};

int ccw(ponto p0, ponto p1, ponto p2) {
    return ((p1.y-p0.y)*(p2.x-p0.x) < (p2.y-p0.y)*(p1.x-p0.x));
}

ponto pilha[MAXN];
int tam;

int main() {
    n=read_int();

    for (int i = 0; i < n; i++) alt[i] = read_int()*100+read_int();

    for (int i = 0; i < n; i++) {
        ponto novo = {i, alt[i]};
        while (0 <= tam-2 && !ccw(pilha[tam-2], pilha[tam-1], novo)) tam--;

        pilha[tam++] = novo;

        if (tam >= 2) maxprev[i] = pilha[tam-2].x;//(pilha[tam-2].y - novo.y) / (pilha[tam-2].x - novo.x); 
    }

    tam = 0;
    for (int i = n-1; i >= 0; i--) {
        ponto novo = {i, alt[i]};
        while (0 <= tam-2 && ccw(pilha[tam-2], pilha[tam-1], novo)) tam--;

        pilha[tam++] = novo;

        if (tam >= 2) minpost[i] = pilha[tam-2].x;//(pilha[tam-2].y - novo.y) / (pilha[tam-2].x - novo.x); 
    }

    for (int i = 0; i < n; i++) {
        double mini = (i == 0) ? -100000000 : ((double)(alt[maxprev[i]] - alt[i])) / (maxprev[i] - i);
        double maxi = (i == n-1) ? 100000000 : ((double)(alt[minpost[i]] - alt[i])) / (minpost[i] - i);;

        if (i != n-1) mini = max(mini, ((double)alt[i]) / (i-n+1));
        if (i != 0) maxi = min(maxi, ((double)alt[i]) / i);
        
        if (mini <= maxi) {
            if (i > n/2) get_sum(i, mini);
            else get_sum(i, maxi);
        }
    }

    printf("%.2lf\n", best/100);
}
