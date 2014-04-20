#include <stdio.h>

int sum9s(int n) {
    int s = 0;
    while (n) {
        s += n % 10;
        n /= 10;
    }
    
    return s;
}

int main(void) {
    int s = 0, d = 1;
    char t;
    int zero = 0;
    int comeco = 1;

    while (1) {
        t = getchar();

        if (t == '\n') {
            if (zero) break;

            if (s % 9 != 0) printf(" is not a multiple of 9.\n");
            else {
                while (s != 9) {
                    s = sum9s(s);
                    d++;
                }
                printf(" is a multiple of 9 and has 9-degree %d.\n", d);
            }

            comeco = 1;
            s = 0;
            d = 1;
            continue;
        }

        if (comeco) {
            if (t == '0') zero = 1;
            else printf("%c", t);
            comeco = 0;
        }
        else if (zero) {
            printf("0%c", t);
            zero = 0;
        }
        else printf("%c", t);

        s += t - '0';

    }

    return 0;
}