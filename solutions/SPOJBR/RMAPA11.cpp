#include <stdio.h>

inline int read_int() {
    char c;
    while ((c=getchar_unlocked()) < 48 || c > 57);
    int p = c-48;
    while ((c=getchar_unlocked()) >= 48 && c <= 57) p=p*10+c-48;
    return p;
}

int main() {
    int soma = 0;
    int marc = 0;
    
    int n,m;
    
    n=read_int();
    m=read_int();
    
    int g[n][n];
    int marcado[n];
    int d[n];
    
    int i,j;
    
    for(i=0;i<n;i++) {
        for (j=0;j<n;j++) {
            g[i][j] = 1000000;
        }
    }
    
    for (i=0;i<m;i++){
        int u,v,c;
        u=read_int(); v=read_int(); c=read_int();
        
        g[u-1][v-1]=c;
        g[v-1][u-1]=c;
    }
    
    
    for (i=0;i<n;i++) {
        marcado[i]=0;
        d[i] = 1000000;
    }
    d[0] = 0;
    
    while (marc != n) {
          int max_d = 1000000;
          int max_ind = 0;
          
          for (i=0; i<n; i++) {
              if (!marcado[i] && d[i] < max_d) {
                       max_d = d[i];
                       max_ind = i;
              }
          }
          
          marcado[max_ind] = 1;
          soma += max_d;
          for (i=0; i<n; i++) {
              d[i] = d[i]<g[max_ind][i]?d[i]:g[max_ind][i];
          }
          
          marc++;
    }
    
    printf("%d", soma);
    
    return 0;
}
