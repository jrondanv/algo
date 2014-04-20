#include <stdio.h>
#include <string.h>

int table[4][5][5] = {{{0, 6, 2, 6, 4},  {2, 2, 4, 2, 8},  {4, 4, 8,4,6},  {6,6,2,6,4},  {8,8,6,8,2}},
{{0,2,8,8,4},  {2,4,6,6,8},  {4,8,2,2,6},  {6,2,8,8,4},  {8,6,4,4,2}},
{{0,4,2,4,4},  {2,8,4,8,8},  {4,6,8,6,6},  {6,4,2,4,4},  {8,2,6,2,2}},
{{0,8,8,2,4},  {2,6,6,4,8},  {4,2,2,8,6},  {6,8,8,2,4},  {8,4,4,6,2}}};

int L(int n) {
    int digs[9];
    if (n == 0 || n == 1) return 1;
    
    int i = 0;
    while (n > 0) {
        digs[i] = n % 5;
        n /= 5;
        i++;
    }

    i--;

    int last_s = 0;
    for (; i >= 0; i--) {
        int index = (i) % 4;
        last_s = table[index][last_s/2][digs[i]];
    }
    
    return last_s;
}


void flush(void) {
    while (getchar() != '\n');
}

int main(void) {
    int n;
    int teste = 1;

    while (scanf("%d", &n) != EOF) {
        printf("Instancia %d\n", teste++);
        printf("%d\n\n", L(n));
    }
    
    return 0;
}