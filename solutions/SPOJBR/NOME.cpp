#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define MAXM 350
#define MAXW 350

int m, n;
int L[MAXM][MAXW], R[MAXW][MAXM];
int L2R[MAXM], R2L[MAXW];

int p[MAXM];

struct tipo_nome {
    char nome[40];
    int id;
    
    bool operator<(tipo_nome b) const {
        return strcmp(nome,b.nome)<0;
    }
};

void stableMarriage()
{
    memset( R2L, -1, sizeof( R2L ) );
    memset( p, 0, sizeof( p ) );

    // Each man proposes...
    for( int i = 0; i < m; i++ )
    {
        int man = i;
        while( man >= 0 )
        {
            // to the next woman on his list in order of decreasing preference,
            // until one of them accepts;
            int wom;
            while( 1 )
            {
                wom = L[man][p[man]++];
                if( R2L[wom] < 0 || R[wom][man] > R[wom][R2L[wom]] ) break;
            }

            // Remember the old husband of wom.
            int hubby = R2L[wom];

            // Marry man and wom.
            R2L[L2R[man] = wom] = man;

            // If a guy was dumped in the process, remarry him now.
            man = hubby;
        }
    }
}

char nomes[400][40];
tipo_nome nomes_sorted[400];
tipo_nome prefs_sorted[400];

char nome[40];

int main() {
    int T;
    scanf("%d", &T);

    for (int t = 0; t < T; t++) {
        scanf("%d", &n);
        m = n;

        for (int i = 0; i < n; i++) {
            scanf("%s", nomes[i]);
            
            strcpy(nomes_sorted[i].nome,nomes[i]);
            nomes_sorted[i].id=i;
            
            for (int j = 0; j < n; j++) {
                int time;
                scanf("%d", &time);

                // o nome/"homem" i prefere o time/"mulher" como j-ésima opção
                L[i][j] = time-1;
            }
        }
        
        sort(nomes_sorted,nomes_sorted+n);

        for (int j = 0; j < n; j++) {
            for (int i = 0; i < n; i++) {
                scanf("%s", prefs_sorted[i].nome);
                prefs_sorted[i].id = i;
            }
            
            sort(prefs_sorted,prefs_sorted+n);
            
            for (int i = 0; i < n; i++) {
                // o time/"mulher" j prefere o nome/"homem" k como i-ésima opção
                R[j][nomes_sorted[i].id]=1000-prefs_sorted[i].id;
            }
        }
        
        stableMarriage();
        
        for (int i = 0; i < n; i++) {
            printf("%s\n", nomes[R2L[i]]);
        }
        
        printf("\n");    
    }

    return 0;
}

