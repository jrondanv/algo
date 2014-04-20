#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;

struct pais {
    int o,p,b,id;
    bool operator< (pais ot) const {
        if (o != ot.o) return o > ot.o;
        if (p != ot.p) return p > ot.p;
        return b > ot.b;
    }
};

pais ordem[110];
int o,p,b;

int main(int argc, char const *argv[])
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) ordem[i].id = i+1;

    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &o, &p, &b);
        ordem[o-1].o++;
        ordem[p-1].p++;
        ordem[b-1].b++;
    }

    stable_sort(ordem,ordem+n);
    for (int i = 0; i < n; i++) {
        printf("%d ", ordem[i].id);
    }
}
