#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>

int T,E,P,J;

using namespace std;

int fila1[1000010];
int fila2[1000010];
int ini1, tam1, ini2, tam2;

int gols[1000010];

char melhor[1000];
char curr[1000];

int main() {
    for (scanf("%d", &T); T; T--) {
        scanf("%d %d %d", &E, &P, &J);

        int best = -1;

        for (int i = 0; i < E; i++) {
            ini1=tam1=ini2=tam2=0;
            scanf("%s", curr);
            
            int cnt = 0;
            for (int j = 0; j < P; j++) {
                scanf("%d", &gols[j]);

                if (j >= J) {
                    if (ini1 != tam1 && fila1[ini1] == gols[j-J]) ini1++;
                    if (ini2 != tam2 && fila2[ini2] == gols[j-J]) ini2++;
                }

                while (tam1 != ini1 && fila1[tam1-1] > gols[j]) tam1--;
                fila1[tam1++] = gols[j];
                
                while (tam2 != ini2 && fila2[tam2-1] < gols[j]) tam2--;
                fila2[tam2++] = gols[j];

                if (j+1 >= J) cnt += fila1[ini1] + fila2[ini2];
            }

            if (cnt > best || (cnt == best && strcmp(curr,melhor)<0)) {
                strcpy(melhor,curr);
                best=cnt;
            }
        }

        printf("%s %d\n", melhor, best);
    }
}

