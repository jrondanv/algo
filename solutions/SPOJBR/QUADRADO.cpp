#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>
using namespace std;
 
typedef unsigned long long hash;

const hash B = 3573;
hash powB[1010];

int N,M;
hash tgt;
bool found;

map<hash, vector< pair<int,int> > > positions;

void build_pow() {
    powB[0] = 1;
    for (int i = 1; i <= 61; i++) {
        powB[i] = powB[i-1]*B;
    }
}

long long pattern[70];
long long quadrad[1010][1010];
hash tally[1010][1010];

char linha[1100];
long long clear;

int main() {
    int t = 0;
    build_pow();

    while (scanf("%d %d", &N, &M)>0) { 
        positions.clear();
        gets(linha);
        clear = ~(1LL<<M);
        
        for (int i = 0; i < N; i++) {
            gets(linha);
            long long tot = 0;
            for (int j = 0; j < N; j++) {
                tot = (tot<<1) + (linha[j] == '_');
                tot &= clear;
                
                if (j >= M-1) {
                    quadrad[j-M+1][i] = tot;

                    if (i == 0) tally[j-M+1][i] = tot;
                    else if (i < M) tally[j-M+1][i] = tally[j-M+1][i-1]*B + quadrad[j-M+1][i];
                    else tally[j-M+1][i] = (tally[j-M+1][i-1]-quadrad[j-M+1][i-M]*powB[M-1])*B + quadrad[j-M+1][i];

                    if (i >= M-1) positions[tally[j-M+1][i]].push_back(make_pair(i-M+1,j-M+1)); 

                }
            }
        }
        
        for (int i = 0; i < M; i++) {
            gets(linha);
            long long tot = 0;
            for (int j = 0; j < M; j++) {
                tot = (tot<<1) + (linha[j] == '_');
                tot &= clear;
                
                if (j >= M-1) pattern[i] = tot; 
            }
        }
        
        tgt=0;
        for (int i = 1; i <= M; i++) {
          tgt = tgt*B + pattern[i-1];
        }

                
        printf("Instancia %d\n", ++t);

        sort(positions[tgt].begin(), positions[tgt].end() );
        for (int i = 0; i < positions[tgt].size(); i++) {
            printf("%d %d\n", positions[tgt][i].second, positions[tgt][i].first);
        }

        if (positions[tgt].empty()) printf("nenhuma ocorrencia\n");
        printf("\n");
    }
}
