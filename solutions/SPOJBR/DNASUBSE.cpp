#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int pd[1010][1010];
int suf[1010][1010];

int main() {
    int K;
    while (scanf("%d", &K) && K) {
        char s1[1010];
        char s2[1010];
        
        scanf(" %s %s", s1, s2);
        
        int l1 = strlen(s1);
        int l2 = strlen(s2);
        
        for (int i = 0; i <= l1; i++) {
            pd[i][0] = 0;
            suf[i][0] = 0;
        }
        for (int i = 0; i <= l2; i++) {
            pd[0][i] = 0;
            suf[0][i] = 0;
        }
        
        for (int i = 1; i <= l1; i++) {
            for (int j = 1; j <= l2; j++) {
                int temp = 0;
                
                if (s1[i-1] == s2[j-1]) suf[i][j] = suf[i-1][j-1] + 1;
                else suf[i][j] = 0;
                
                
                pd[i][j] = max(pd[i-1][j], pd[i][j-1]);
                
                for (int k = K; k <= suf[i][j]; k++) {
                        pd[i][j] = max(pd[i][j], pd[i-k][j-k]+k);
                }      
            }
        }
        
        printf("%d\n", pd[l1][l2]);
    }
    
    return 0;
}
        
