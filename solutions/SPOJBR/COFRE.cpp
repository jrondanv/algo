#include <stdio.h>
int main(void) {
    int n;
    int teste = 0;
    
    scanf("%d", &n);
    while (n != 0) {
          teste++;
          printf("Teste %d\n", teste);
          
          int d = 0;
          int i = 0;
          
          for (;i < n; i++) {
              int j, z;
              scanf("%d %d", &j, &z);
              d += j - z;
              printf("%d\n", d);
          }
          
          printf("\n");
          scanf("%d", &n);
    }
    return 0; 
}