#include <stdio.h>
#include <stdlib.h>
#include <set>
#include <vector>
#include <cctype>

using namespace std;

vector<int> dependencia_para[50000];
int depende_de[50000];
int ordem[50000];

set<int> no_deps;

inline int read_int() {
    char c;
    while ((c=getchar_unlocked()) < 48 || c > 57);
    int p = c-48;
    while ((c=getchar_unlocked()) >= 48 && c <= 57) p=p*10+c-48;
    return p;
}

int main() {
    int N, M;
    N=read_int();
    M=read_int();
    
    int i;
    
    for (i=0;i<M;i++) {
        int A, B;
        A=read_int();
        B=read_int();
        dependencia_para[A].push_back(B);
        depende_de[B]++;
    }
    
    int j;
    for (j=0; j<N; j++) {
        if (!depende_de[j]) no_deps.insert(j);
    }
    
    int possivel = 1;
    for (i=0; i<N; i++) {
        if (no_deps.empty()) { possivel = 0; break; }
        int j = *no_deps.begin();
        no_deps.erase(no_deps.begin());
        
        ordem[i] = j;
        
        for (int k = 0; k < dependencia_para[j].size(); k++) {
            int dependencia_n = dependencia_para[j][k];
            depende_de[dependencia_n]--;
            if (!depende_de[dependencia_n]) no_deps.insert(dependencia_n);
        } 
    }
    
    if (possivel) {
        for (i=0;i<N;i++) {
            printf("%d\n", ordem[i]);
        } 
    }
    else printf("*"); 
         
    return 0;
}
