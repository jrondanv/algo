#include <stdio.h>
#include <algorithm>

int main() {
    int a,b;
    scanf("%d %d", &a, &b);

    if (a > b) std::swap(a,b);

    if (a == 1) printf("%d\n", b);
    else if (a == 2) printf("%d\n", (b/4)*4 + std::min(2, (b%4)) * 2);
    else printf("%d\n", (a*b+1)/2);
}