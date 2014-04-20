#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include <algorithm>
using namespace std;

int m,d,T;
int dir[1<<21];
int tot[1<<21];

int main() {
    for (scanf("%d", &T); T; T--) {
        scanf("%d %d", &m, &d);

        for (int i = 0; i < d; i++) {
            int num;
            dir[1<<i] = 0;
            scanf("%d", &num);
            for (int j = 0; j < num; j++) {
                int chave;
                scanf("%d", &chave);
                dir[1<<i] |= (1<<chave);
            }
        }

        tot[0] = 0;
        int best = m==0?0:100;
        for (int i = 1; i < (1<<d); i++) {
            int bit = i&-i;
            tot[i] = tot[i-bit] | dir[bit];
            if (__builtin_popcount(tot[i]) >= m) best = min(best, __builtin_popcount(i));
        }

        if (best == 100) printf("Desastre!\n");
        else printf("%d\n", best);
    }
}

