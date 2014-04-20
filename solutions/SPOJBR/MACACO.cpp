#include <stdio.h>

#define max(a, b) a > b ? a : b
#define min(a, b) a > b ? b : a

int main(void) {
    int l, c;
    int a, n;
    int teste = 1;

    while (scanf("%d", &n) && n) {
        int a = -10000, b = 10000, c = 10000, d = -10000;
        int none = 0;

        for (int i = 0; i < n; i++) {
            int x, y, u, v;
            scanf("%d %d %d %d", &x, &y, &u, &v);

            if (x > c || y < d || u < a || v > b) none = 1;


            a = max(a, x);
            b = min(b, y);
            c = min(c, u);
            d = max(d, v);
        }
        
        printf("Teste %d\n", teste++);
        if (none) printf("nenhum\n");
        else printf("%d %d %d %d\n", a, b, c, d);
        printf("\n");
    }
    
    return 0;
}