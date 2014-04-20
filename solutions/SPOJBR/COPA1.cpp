#include <stdio.h>

int resultados[15];

int main() {
    for (int i = 0; i < 15; i++){
        int A,B;
        scanf("%d %d", &A, &B);
        if (A > B) resultados[14-i] = 1;
        else resultados[14-i] = 0;
    }
    
    int i = 1;
    for (int j = 0; j < 4; j++) {
        i = (2*i+resultados[i-1]);
    }
    
    printf("%c\n", 'A'+31-i);
}
