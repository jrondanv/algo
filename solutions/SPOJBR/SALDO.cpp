#include <stdio.h>

int main() {
    int n;
    int teste = 1;
    
    while (scanf("%d", &n) && n) {
          int i;
          int bsal = -1;
          int bper_st = 0;
          int bper_fim = 0;
          int perat_st = 0;
          int perat_soma = 0;
          
          for ( i = 0; i < n; i++) {
              int a, b;
              scanf("%d %d", &a, &b);
              perat_soma += a-b;
              
              if (perat_soma < 0) {
                             perat_st = i+1;
                             perat_soma = 0;
              }
              
              else if (perat_soma > bsal) {
                   bsal = perat_soma;
                   bper_st = perat_st;
                   bper_fim = i;
              }
              
              else if (perat_soma == bsal) {
                   if (i - perat_st > bper_fim - bper_st) {
                      bsal = perat_soma;
                      bper_st = perat_st;
                      bper_fim = i; 
                   }
              }     
          }
          
          printf("Teste %d\n", teste++);
          if (bsal > 0) printf("%d %d\n", bper_st+1, bper_fim+1);
          else printf("nenhum\n");
    }
    return 0;
}     
