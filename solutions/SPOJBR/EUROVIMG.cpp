#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include <algorithm>
#include <vector>
#include <map>
#include <string>
using namespace std;

int n,T;

map<string, int> pais;
int L, teste;
char inp[1000];
vector<int> enemy[1000];
int perm[9];

int get_pais(char* c) {
    map<string, int>::iterator it = pais.find(c);
    if (it != pais.end()) return it->second;
    else return pais[c]=L++;
}

int main() {
    for (scanf("%d", &T); T; T--) {
        L=0;
        pais.clear();

        scanf("%d", &n);

        for (int i = 0; i < n; i++) enemy[i].clear();

        int num;
        for (int i = 0; i < n; i++) {
            scanf("%s %d", inp, &num);
            int th = get_pais(inp);

            for (int j = 0; j < num; j++) {
                scanf("%s", inp);
                enemy[th].push_back(get_pais(inp));
            }
        }

        for (int i = 0; i < n; i++) perm[i] = i;

        int cnt = 0;
        do {
            bool ok = true;
            for (int i = 0; i < n && ok; i++) {
                for (int j = 0; j < enemy[i].size(); j++) {
                    if (abs( perm[enemy[i][j]] - perm[i] ) == 1) {
                        ok = false;
                        break;
                    }
                }
            }

            cnt += ok;
        } while(next_permutation(perm,perm+n));
    
        printf("Teste #%d: %d\n", ++teste, cnt);
    }
}

