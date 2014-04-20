#include <stdio.h>

int main(void) {
    int n;
    int teste = 1;

    while (scanf(" %d", &n) && n) {
        int poss[12];
        for (int i=0; i<12; i++) {
            poss[i] = -1;
        }

        for (int i=0; i<n; i++) {
            int inp[10];
            for (int i=0; i<10; i++) {
                scanf(" %d", inp+i);
            }

            char cod[14];
            scanf("%[^\n]", cod);
            
            /*printf("inp: ");
                for (int j=0; j<12; j++) {
                    printf("%d ", inp[j]);
                } */

            for (int i=0; i<12; i+=2) {
                int ind = (cod[i+1] - 'A') * 2;
                if (poss[i] == -1) {
                    poss[i] = inp[ind];
                    poss[i+1] = inp[ind+1];
                }
                else {
                    if (poss[i] != inp[ind] && poss[i] != inp[ind+1]) poss[i] = -2;
                    if (poss[i+1] != inp[ind] && poss[i+1] != inp[ind+1]) poss[i+1] = -2;
                }
            }
                /*printf("poss: ");
                for (int j=0; j<12; j++) {
                    printf("%d ", poss[j]);
                } */



        }

        printf("Teste %d\n", teste++);

        for (int i=0; i<12; i+=2) {
            int num = poss[i] == -2 ? poss[i+1] : poss[i];
            i == 10 ? printf("%d\n", num) : printf("%d ", num);
        }

        printf("\n");
    }    

    return 0;
}