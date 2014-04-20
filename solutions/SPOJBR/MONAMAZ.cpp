#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std ;

#define BUFSIZE 4*1024
char ans[BUFSIZE];
int pos;

inline int read_int() {
    char c;
    while ((c=getchar_unlocked()) < 48 || c > 57) if (c == '-') break;
    int p = 0;
    int sign = 1;
    if (c == '-') sign = -1;
    else p = c-48;
    while ((c=getchar_unlocked()) >= 48 && c <= 57) p=p*10+c-48;
    return p*sign;
}

int marc[1024], n;
int cont;
struct ponto {
    int x, y;
};

ponto p[1024];
int p1, p2, d1, d2, d;

int dist(int i, int j) {
    int dx = p[i].x-p[j].x;
    int dy = p[i].y - p[j].y;
    return dx*dx+dy*dy;
}

bool melhor(int i, int j) {
    if (p1 == -1) return true;

    if (d < d1) return true;
    else if (d == d1) {
        if (p[j].x < p[p1].x) return true;
        else if (p[j].x == p[p1].x && p[j].y < p[p1].y) return true;
    }

    return false;
}

bool melhor2(int i, int j) {
    if (p2 == -1) return true;

    if (d < d2) return true;
    else if (d == d2) {
        if (p[j].x < p[p2].x) return true;
        else if (p[j].x == p[p2].x && p[j].y < p[p2].y) return true;
    }

    return false;
}

int fila[1024];
int ini,tam;

int main(int argc, char const *argv[])
{
    while (n=read_int()) {
        cont++;
        for (int i = 0; i < n; i++) {
            p[i].x=read_int();
            p[i].y=read_int();
        }

        ini=0;
        tam=1;
        int cnt = 0;
        marc[0] = cont;

        while (ini != tam) {
            int i = fila[ini++];
            cnt++;

            p1=-1, p2=-1;
            d1 = -1, d2 = -1;

            for (int j = 0; j < n; j++) {
                if (i == j) continue;

                d = dist(i,j);
                if (melhor(i, j)) {
                    swap(d1,d2);
                    swap(p1,p2);
                    p1 = j;
                    d1 = d;
                }
                else if (melhor2(i,j)) {
                    p2 = j;
                    d2 = d;
                }
            }

            if (p1 != -1 && marc[p1] != cont) {
                marc[p1]=cont; fila[tam++]=p1;
            }
            if (p2 != -1 && marc[p2] != cont) {
                marc[p2]=cont; fila[tam++]=p2;
            }
        }

        if (cnt == n) {
            strcpy(ans+pos, "All stations are reachable.\n");
            pos += 28;
        }
        else {
            strcpy(ans+pos,"There are stations that are unreachable.\n");
            pos += 41;
        }
    }

    fwrite(ans, 1, pos, stdout);
    return 0;
}