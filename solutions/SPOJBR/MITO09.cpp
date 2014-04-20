#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include <algorithm>

int n,m;
int a[510][510];

int main() {
    scanf("%d", &n);

    int x,y;
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &x, &y);
        if (a[x][y]) {
            printf("1\n");
            return 0;
        }
        a[x][y]=1;
    }
    printf("0\n");
}

