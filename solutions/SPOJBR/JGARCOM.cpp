#include <stdio.h>

int main() {
    int N, A,L,P;
    scanf("%d", &N);
    
    int cnt = 0;
    for (int i = 0; i<N; i++) {
        int B,C;
        scanf("%d %d", &B,&C);
        
        if (B>C) cnt+=C;
    }
    printf("%d\n", cnt);
}