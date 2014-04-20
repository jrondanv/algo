#include <stdio.h>

int main() {
    while(1){
        long i = 0;
        long N;
        long paridade;
        long elevado;
        long j = 0;
        scanf("%ld", &N);
        if (N == 0) break;

        while (N != 0){
            paridade = 0;
            i = 0;
            elevado = 1;
            while (elevado <= N){
                   if (elevado >= 1073741824) break;
                   elevado*=2;
            }

            if (N < 1073741824) elevado /= 2;

            printf("The parity of ");

            while(1){
                if (elevado <= N){
                   printf("1");
                   ++paridade;
                   N -= elevado;
                   elevado /= 2;
                } else {
                   printf("0");
                   elevado /= 2;
                }
                if (elevado == 0) break;

            }

            printf(" is %ld (mod 2).\n", paridade);
        }
    }
    return 0;
}

