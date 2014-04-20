#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;

int pow10(int n) {
    if (n == -1) return 0;
    int r = 1;
    while (n) {
        r *= 10;
        n--;
    }
    return r;
}

int countleadingzeros(int n) {
    return (n == 0) ? 1 : pow10(n) + countleadingzeros(n - 1);
}

int countpaddingzeros(int n, int r) {
    return (r + 1) * max(0, n - max(0, (int)floor(log10(r))) - 1);
}

int cd(int d, int low, int high);

int countdigits(int d, int low, int high, bool inner) {
    if (high == 0)
        return (d == 0) ? 1 : 0;

    if (low > 0)
        return cd(d, 0, high) - cd(d, 0, low);

    int n = (int)floor(log10(high));
    int m = (high + 1) / pow10(n);
    int r = high - m * pow10(n);
    return
        (max(m, 1) * n * pow10(n-1)) +                             // (1)
        ((d < m) ? pow10(n) : 0) +                                 // (2)
        (((r >= 0) && (n > 0)) ? countdigits(d, 0, r, true) : 0) +   // (3)
        (((r >= 0) && (d == m)) ? (r + 1) : 0) +                     // (4)
        (((r >= 0) && (d == 0)) ? countpaddingzeros(n, r) : 0) -     // (5)
        (((d == 0) && !inner) ? countleadingzeros(n) : 0);           // (6)
}

int cd(int d, int low, int high) {
    return countdigits(d, low, high, false);
}

int main() {
    int a, b;
    while (scanf("%d %d", &a, &b) && a) {
        for (int i = 0; i < 10; i++) {
            printf("%d", cd(i,a-1,b));
            if (i == 9) printf("\n");
            else printf(" ");
        }
    }
    
    return 0;
}
