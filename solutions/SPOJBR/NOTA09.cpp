#include <stdio.h>

int n;

int main() {
    scanf("%d", &n);
    if (n == 0) printf("E");
    else if (n < 36) printf("D");
    else if (n < 61) printf("C");
    else if (n < 86) printf("B");
    else printf("A");
}