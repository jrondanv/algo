#include <stdio.h>

int main(void) {
    int n;
    int teste = 1;

    while (scanf("%d", &n) && n) {
        int diff = 0;
        for (int i=0; i<n; i++) {
            int a, b;
            scanf("%d %d", &a, &b);
            diff += a - b;
        }

        printf("Teste %d\n", teste++);

        if (diff > 0) printf("Aldo\n");
        else printf("Beto\n");
        
        printf("\n");
    }    

    return 0;
}