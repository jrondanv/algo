#include <stdio.h>

int usado[1000001];

int main() {
    int N;
    
    scanf("%d", &N);
    
    int N2 = N*N;
    
    int r_sum;
    int c_sum[N];
    int d1_sum = 0, d2_sum = 0;
    
    int t;
    if (N & 1) t = N*((N*N+1) / 2);
    else t = (N/2)*(N*N+1);
    
    int r, c;
    for (c=0; c<N; c++) c_sum[c] = 0;
    
    int eh_magico = 1;
    
    for (r = 0; r<1000001; r++) {
        usado[r]=0;
    }
    
    for (r=0; r<N; r++) {
        r_sum = 0;
        for (c=0; c<N; c++) {
            int x;
            scanf("%d", &x);
            if (!eh_magico) continue;
            
            if (x > N2) eh_magico = 0;
            
            if (usado[x]) eh_magico = 0;
            else usado[x] = 1;
            
            r_sum += x;
            c_sum[c] += x;
            
            if (r_sum > t || c_sum[c] > t) {
                      eh_magico = 0;
            }
            
            if (r == c) {
                  d1_sum += x;
                  if (d1_sum > t) { eh_magico=0;}
            }
            
            if (c+r+1==N) {
                          d2_sum += x;
                          if (d2_sum > t) { eh_magico=0;}
            }
        }
        
        if (r_sum != t) {
                  eh_magico = 0;
        }
    }
    
    for (c=0;c<N;c++) {
        if (c_sum[c] != t) { eh_magico = 0; break; }
    }
    if (d1_sum != t || d2_sum != t) eh_magico = 0;
    
    if (eh_magico) printf("%d", t);
    else printf("0");
     
    return 0;
}
