#include <stdio.h>
#include <string.h>

double pow(double b, int e) {
    double res = 1;
    for (int i = 0; i < e; i++) {
        res *= b;
    }
    return res;
}

int E1, E2, AT, D;

int main() {
    int teste = 0;
    while (scanf("%d %d %d %d", &E1, &E2, &AT, &D) && E1) {
        int n1 = (E1+D-1)/D;
        int n2 = (E2+D-1)/D;

        if (AT == 3) {
            printf("%.1lf\n", 100*n1 / ((double)(n1+n2)));
        }

        else {
            double p = AT/6.0;
            double q = 1-p;
            printf("%.1lf\n", 100*(1 - pow(q/p, n1)) / (1 - pow(q/p, n1+n2)));
        }
    }
}