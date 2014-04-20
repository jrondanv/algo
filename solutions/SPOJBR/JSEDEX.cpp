#include <stdio.h>

int main() {
    int N, A,L,P;
    scanf("%d %d %d %d", &N,&A,&L,&P);
    
    if (A<N || L<N || P<N) printf("N\n");
    else printf("S\n");
}