#include <stdio.h>

int main() {
    
    int p,n,c;
    int pc[1000];

    while (scanf("%d %d %d", &p, &n, &c) && p) {
        int i,j;
        int cnt = 0;

        for (j=0; j<p; j++) pc[j]=0;

        for (i=0;i<n;i++) {
            for (j=0;j<p;j++) {
                int bit;
                scanf("%d", &bit);
                
                if (bit == 1) pc[j]++;
                else {
                    if (pc[j] >= c)cnt++;
                    pc[j] = 0;
                }
            }
        }

        for (j=0; j<p; j++) if (pc[j] >= c) cnt++;

        printf("%d\n", cnt);
    }

    return 0;
}