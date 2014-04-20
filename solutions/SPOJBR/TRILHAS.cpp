#include <algorithm>
#include <cstdio>
#include <cstring>

#define INF 1000000000

using namespace std;

int N,M;
int tr[1000];

int main() {
    scanf("%d", &N);
    
    int melhor;
    int men_esf = -1, esf1, esf2;
    
    for (int i = 0; i < N; i++) {
        scanf("%d", &M);
        for (int j = 0; j < M; j++) scanf("%d", &tr[j]);
        
        esf1 = esf2 = 0;
        for (int j = 1; j < M; j++) {
            esf1 += max(0, tr[j] - tr[j-1]);
            esf2 += max(0, tr[M-j-1] - tr[M-j]);   
        }
        
        int esf = min(esf1, esf2);
        
        if (men_esf == -1 || esf < men_esf) {
            melhor = i+1;
            men_esf = esf;
        }
    }
    
    printf("%d\n", melhor);
}