#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <map>
#include <string>

using namespace std;

struct tim {
    char nome[25];
    int pontos;
    int sets;
    int jogos;
    
    bool operator< (tim b) const {
        if (jogos != b.jogos) return jogos > b.jogos;
        if (sets != b.sets) return sets > b.sets;
        if (pontos != b.pontos) return pontos > b.pontos;
        return strcmp(nome, b.nome) < 0;
    } 
    
    void print() {
        printf("%-20s%5d%5d%10d\n",nome,jogos,sets,pontos);
    }
};

char entrada[10000];
tim times[1010];

int T,M;
int main() {
    map<string, int> m;
    while (scanf(" %d", &T) && T) {
        m.clear();
        while (getchar() != '\n');
        
        memset(times,0,sizeof(times));
        
        for (int i = 0; i < T; i++) {
            gets(times[i].nome);
            m[times[i].nome] = i;
        }
        
        scanf("%d", &M);
        while (getchar() != '\n');
        
        for (int i = 0; i < M; i++) {
            gets(entrada);
            
            string k;
            
            int i = 0;
            while (entrada[i] != '-') {
                k += entrada[i];
                i++;
            }   
            
            int t1 = m[k];
            
            k = "";
            
            i++;
            while (entrada[i] != ':') {
                k += entrada[i];
                i++;
            }
            
            int t2 = m[k];   
            
            int s[2] = {0};
            int p1,p2;
            
            i++;
            int inc;
            while (sscanf(entrada+i, "%d-%d%n", &p1, &p2, &inc) == 2) {
                times[t1].pontos += p1;
                times[t2].pontos += p2;
                
                int venc, perd;
                if (p1 > p2) {s[0]++; venc = t1; perd = t2;}
                else {s[1]++; venc = t2; perd = t1;}
                
                times[venc].sets++;
                times[perd].sets--;
                i += inc;
            }
            
            if (s[0] > s[1]) times[t1].jogos++;
            else times[t2].jogos++;
        }
        
        sort(times, times+T);
        for (int i = 0; i < T; i++) {times[i].print();}
    }
}
          
