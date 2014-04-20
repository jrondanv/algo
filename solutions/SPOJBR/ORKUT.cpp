#include <stdio.h>
#include <string.h>
#include <queue>

using namespace std;

int marc[50];
char nomes[50][20];

int exigs[50];
int exig_by[50][50];
    

int main() {
    int N, teste = 1;
    while (scanf("%d", &N) && N) {
        queue<int> no_exigs;
        queue<int> resp;
        
        memset(marc,0,sizeof(marc));
        memset(exigs,0,sizeof(exigs));
        memset(exig_by,0,sizeof(exig_by));
        
        for (int i = 0; i < N; i++) scanf("%s", nomes[i]);
        
        for (int i = 0; i < N; i++) {
            char nome[20];
            scanf("%s", nome);
            
            int j;
            for (j=0; strcmp(nomes[j], nome)!=0; j++);
            
            int e;
            scanf("%d", &e);
            
            exigs[j] = e;
            
            for (int k = 0; k < e; k++) {
                scanf("%s", nome);
                
                int p;
                for (p=0; strcmp(nomes[p], nome)!=0; p++);
                
                exig_by[p][++exig_by[p][0]] = j;
            }
        }
        
        for (int i = 0; i < N; i++) {
            if (exigs[i] == 0) no_exigs.push(i);
        }
        
        while (!no_exigs.empty()) {
            int p = no_exigs.front();
            no_exigs.pop();
            
            for (int j = 1; j <= exig_by[p][0]; j++) {
                int exigd = exig_by[p][j];
                if (--exigs[exigd] == 0) {
                    no_exigs.push(exigd);
                }
            }
            
            resp.push(p);
        }
        
        printf("Teste %d\n", teste++);
        if (resp.size() != N) printf("impossivel\n");
        else {
            for (int i = 0; i < N; i++) {
                printf("%s", nomes[resp.front()]);
                resp.pop();
                
                if (i+1 != N) printf(" ");
                else printf("\n");
            }
        }
        printf("\n");
    }

}
