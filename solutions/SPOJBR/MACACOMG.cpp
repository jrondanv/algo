#include <stdio.h>
#include <algorithm>

int off[2000000], n;

int main() {
    while (scanf("%d", &n) && n) {
        for (int i = 0; i < n; i++) {
            scanf("%d", &off[i]);
        }

        std::sort(off,off+n);

        int big = 0;

        for (int i = 0; i < n/2; i++) {
            big = std::max(big, off[i]+off[n-i-1]);
        }
        printf("%d\n", big);
    }
}