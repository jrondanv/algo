#include <stdio.h>

int main(void) {
    int a, n;
    int teste = 1;

    while(scanf("%d", &n) && n != -1) {
        printf("Teste %d\n", teste++);

        printf("%d", (1 << 2*n) + (1 << (n+1)) + 1);
        printf("\n\n");
    }

    return 0;
}