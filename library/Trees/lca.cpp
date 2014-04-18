// L: nível do nó (raiz é 0, filhos da raiz 1, etc...
// P: P[i][0] é o pai do nó i;

int L[100010];
int P[100010][20];
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

void build_lca() {
    for (int i = 0; i < N; i++)
          for (int j = 1; 1 << j < N; j++)
              P[i][j] = -1;
              
    for (int i = 1; i < N; i++) {        
        for (int j = 1; 1 << j < N; j++) {
            if (P[i][j - 1] != -1) {
                P[i][j] = P[P[i][j - 1]][j - 1]; 
            }
        }
    }    
}
        
        
        
