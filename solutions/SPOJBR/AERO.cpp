#include <stdio.h>

int main(void) {
    int a, n;
    int teste = 1;

    while(scanf("%d %d", &a, &n) && a) {
        printf("Teste %d\n", teste++);

        int i;
        int aer[a];

        for (i=0;i<a;i++) {
            aer[i]=0;
        }

        for (i=0;i<n; i++) {
            int c, d;
            scanf("%d %d", &c, &d);

            aer[c-1]++;
            aer[d-1]++;
        }
        
        int max = 0;
        for (i=0; i<a; i++) {
            if (aer[i] > max) max = aer[i];
        }
        
        for (i = 0; i<a; i++) {
            if (aer[i] == max) printf("%d ", i+1);
        }
        printf("\n\n");
    }

    return 0;
}