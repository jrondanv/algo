#include <stdio.h>
#include <algorithm>

int x[1010];
int y[1010];

int S;

int main() {
    int teste = 1;
    while (scanf("%d", &S) && S) {
        for (int i = 0; i < S; i++) {
            scanf("%d %d", &x[i], &y[i]);
        }
        
        std::nth_element(x,x+S/2,x+S);
        std::nth_element(y,y+S/2,y+S);
        
        printf("Teste %d\n", teste++);
        printf("%d %d\n\n", x[S/2], y[S/2]);
    }
}
