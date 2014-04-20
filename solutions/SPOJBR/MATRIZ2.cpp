#include <stdio.h>
 
int main() {
        int n, p, q, r, s, x, y, i, j;
        scanf("%d %d %d %d %d %d %d %d %d", &n, &p, &q, &r, &s, &x, &y, &i, &j);
        
        long long int res = 0;
        int k;
        
        for (k=1; k<=n; k++) {
                int A = (p*i + q*k) % x; // A[i, k]
                int B = (r*k + s*j) % y; 
                
                res += A*B;
        }
        
        printf("%lld\n", res);
}