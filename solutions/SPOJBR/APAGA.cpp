#include <stdio.h>

char stack[100001];

int main(void) {
    int n, d;

    while (scanf("%d %d", &n, &d) && n) {

        char inteiros[n+1];
        scanf("%s", inteiros);
        
        
        int fim = 0;

        int popped = 0;

        int i = 0;
        int k = 0;

        while (popped < d) {
            int on_st = 0;
            while (popped < d && fim) {
                if (stack[fim-1] < inteiros[i]) {
                    on_st = 1;
                    fim--;
                    popped++;
                }
                else break;
            }
            if (on_st || fim < n - d) stack[fim++] = inteiros[i];
            else popped++;
            i++;
        }
        
        for (; i<n; i++) {
            stack[fim++] = inteiros[i];
        }

        for (i = 0; i < (n - d); i++) {
            printf("%c", stack[i]);
        }


        printf("\n");
    }
    
    return 0;
}

