#include <stdio.h>

unsigned long long kfac(int n, int k) {
    unsigned long long res = 1;
    while (n>1) {
        res *= n;
        n -= k;
    }
    
    return res;
}

int main(void) {
    int n, p, i;
    char t;

    scanf("%d", &p);

    for (i = 0; i < p; i++) {
        scanf("%d", &n);

        int k = 0;
        while (getchar() != '\n') {
            k += 1;
        }

        printf("%llu\n", kfac(n, k));
    }

    return 0;
}