#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include <algorithm>

int n,m;

int main() {
    scanf("%d %d", &n, &m);
    int p = 0, b;
    for (int i = 0; i < n; i++) {
        scanf("%d", &b);
        if (b-p > m) {
            printf("N\n");
            return 0;
        }
        p=b;
    }

    if (42195-p > m) {
        printf("N\n");
        return 0;
    }

    printf("S\n");
}

