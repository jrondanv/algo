#include <stdio.h>

int L[100010];
int P[100010][20];
long long D[100010];
int N;

int query(int p, int q)
{
      int tmp, log, i;
   
      if (L[p] < L[q])
          tmp = p, p = q, q = tmp;
  
      for (log = 1; 1 << log <= L[p]; log++);
      log--;
   
      for (i = log; i >= 0; i--)
          if (L[p] - (1 << i) >= L[q])
              p = P[p][i];
   
      if (p == q)
          return p;
   
      for (i = log; i >= 0; i--)
          if (P[p][i] != -1 && P[p][i] != P[q][i])
              p = P[p][i], q = P[q][i];
   
      return P[p][0];
}

int main() {
    while (scanf("%d", &N) && N) {
        int ult = 0;
        
        D[0] = 0;
        L[0] = 0;
        
        for (int i = 0; i < N; i++)
          for (int j = 0; 1 << j < N; j++)
              P[i][j] = -1;
        
        for (int i = 1; i < N; i++) {
            int A, C;
            scanf("%d %d", &A, &C);
            
            D[i] = D[A]+C;
            L[i] = L[A]+1;
            P[i][0] = A;
            
            for (int j = 1; 1 << j < N; j++) {
                if (P[i][j - 1] != -1) {
                    P[i][j] = P[P[i][j - 1]][j - 1]; 
                }
            }    
        }
        
        int Q;
        scanf("%d", &Q);
        
        for (int q = 0; q < Q-1; q++) {
            int v,w;
            scanf("%d %d", &v, &w);
            printf("%lld ", D[v]+D[w]-2*D[query(v,w)]);
        }
        
        int v,w;
        scanf("%d %d", &v, &w);
        printf("%lld\n", D[v]+D[w]-2*D[query(v,w)]);
    }
    
    return 0;
}
