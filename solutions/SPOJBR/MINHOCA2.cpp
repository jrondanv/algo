#include <algorithm>
#include <cstdio>
#include <cstring>

#define INF 1000000000

using namespace std;

int pdl[1010][1010];
int pdr[1010][1010];
int pd[1010][1010];
int arr[1010][1010];

int N, M;
int main() {
    int teste = 1;
    while (scanf("%d %d", &N, &M) && N) {
        for (int i = 1; i <= M; i++) pd[0][i] = -INF;
        for (int i = 1; i <= N; i++) pdl[i][0] = pdr[i][M+1] = -INF;
        
        for (int i = 1; i <= N; i++) 
            for (int j = 1; j <= M; j++) 
                scanf("%d", &arr[i][j]);
        
        pdl[1][0] = 0;
        
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                pdl[i][j] = max(pdl[i][j-1], pd[i-1][j])+arr[i][j];
            }
            
            for (int j = M; j >= 1; j--) {
                pdr[i][j] = max(pdr[i][j+1], pd[i-1][j])+arr[i][j];
                pd[i][j] = max(pdl[i][j], pdr[i][j]);
            }
        }
        
        printf("Teste %d\n", teste++);
        printf("%d\n", pd[N][M]);
        printf("\n");
    }
}
    
