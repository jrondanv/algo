#include <stdio.h>
#include <algorithm>

int main() {
    int L,D,K,P;
    scanf("%d %d %d %d", &L, &D, &K, &P);

    printf("%d\n", L*K + (L/D)*P);
    return 0;
}
