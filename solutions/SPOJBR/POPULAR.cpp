#include <stdio.h>

int main() {
    int n;
    int cnt[100];
    
    while (scanf("%d", &n) && n) {
          int i;
          for (i=0; i<n; i++) {
              cnt[i]=0;
          }
          
          for (i=0; i<n; i++) {
              int j;
              for (j=0; j<n; j++) {
                  int a;
                  scanf(" %d", &a);
                  cnt[j]+=a;
              }
          }
          
          int max=0;
          for (i=0; i<n; i++) {
              if (cnt[i] > max) max = cnt[i];
          }
          
          printf("%d\n", max);
    }    
              
    
    return 0;
}
