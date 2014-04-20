#include <stdio.h>

int main(void) {
    char t;
    int comeco = 1;
    int zero = 0;
    int soma[2] = {0, 0};
    int ind = 0;

    while (scanf("%c", &t)) {
        if (t == '\n') {
            if (zero) break;

            if ((soma[0]-soma[1]) % 11 == 0) printf(" is a multiple of 11.\n");
            else printf(" is not a multiple of 11.\n");

            comeco = 1;
            soma[0] = 0;
            soma[1] = 0;
            continue;
        }

        if (zero) {
            printf("0");
            zero = 0;
        }

        if (comeco) {
            if (t == '0') zero = 1;
            else printf("%c", t);
            comeco = 0;
        }
        else {
            printf("%c", t);
        }

        int val = 0;
        val = t - '0';

        ind = 1-ind;
        soma[ind] += val;
    }
    
    return 0;
}