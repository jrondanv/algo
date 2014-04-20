#include <stdio.h>
#include <algorithm>

using namespace std;

struct consulta {
    int inic;
    int fim;
};

consulta cons[10010]; 

int compara(consulta a, consulta b) {
    return a.fim < b.fim;
}

int main() {
    int N;
    scanf("%d", &N);
    
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &cons[i].inic, &cons[i].fim);
    }
    
    sort(cons, cons+N, compara);
    
    int cnt = 0;
    int fim = -1;
    for (int i = 0; i < N; i++) {
        if (cons[i].inic >= fim) {
            cnt++;
            fim = cons[i].fim;
        }
    }
    printf("%d\n", cnt);
    return 0;
}
