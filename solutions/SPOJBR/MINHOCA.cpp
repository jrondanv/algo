#include <stdio.h>

int main(void) {
    int l, c;
    int a, n;
    int teste = 1;

    scanf("%d %d", &l, &c); 
    
    int rowsum[l];
    int colsum[c];
    
    int r, cl;
    
    for (r=0; r<l; r++) rowsum[r] = 0;
    for (cl=0; cl<l; cl++) colsum[cl] = 0;

    for (r=0; r<l; r++) {
        for (cl=0; cl<c; cl++) {
            int k;
            scanf("%d", &k);
            
            colsum[cl] += k;
            rowsum[r] += k;
        }
    }

    int max = 0;

    for (r=0; r<l; r++) {
        if (rowsum[r] > max) max = rowsum[r];
    }
    
    for (cl=0; cl<l; cl++) {
        if (colsum[cl] > max) max = colsum[cl];
    }
    
    printf("%d", max);

    return 0;
}