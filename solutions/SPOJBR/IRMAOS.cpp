#include <stdio.h>

int map[10000];
int map2[10000];

int main() {
    int N, R, C, K;
    
    while (scanf("%d %d %d %d", &N, &R, &C, &K) && N) {
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                scanf("%d", &map[C*i+j]);  
            }
        }
        
        int* curr = map;
        int* temp = map2;
        int* aux;
        
        while (K) {
            //printf("K = %d\n", K);
            for (int i = 0; i < R; i++) {
                for (int j = 0; j < C; j++) {
                    if (i != 0 && (curr[C*i+j]-curr[C*(i-1)+j]+N)%N == 1) temp[C*i+j] = curr[C*(i-1)+j];
                    else if (i != R-1 && (curr[C*i+j]-curr[C*(i+1)+j]+N)%N == 1) temp[C*i+j] = curr[C*(i+1)+j];
                    else if (j != 0 && (curr[C*i+j]-curr[C*i+j-1]+N)%N == 1) temp[C*i+j] = curr[C*i+j-1];
                    else if (j != C-1 && (curr[C*i+j]-curr[C*i+j+1]+N)%N == 1) temp[C*i+j] = curr[C*i+j+1];
                    else temp[C*i+j] = curr[C*i+j];
                }
            }
            
            aux = temp;
            temp = curr;
            curr = aux;
            K--;
        }
        
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                printf("%d", curr[C*i+j]);
                if (j != C-1) printf(" ");
                else printf("\n");
            }
        }
    }
}
