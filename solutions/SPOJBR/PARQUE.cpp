#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int pd[110][110];

char s1[110];
char s2[110];
char res[220];

int main() {
    int teste = 1;
    while (1) {
        scanf("%s", s1);
        
        if (strcmp(s1, "#") == 0) break;
        
        scanf("%s", s2);
        
        memset(pd,0,sizeof(pd));
        
        int l1 = strlen(s1);
        int l2 = strlen(s2);
        
        for (int i = 1; i <= l1; i++) {
            for (int j = 1; j <= l2; j++) {
                if (s1[i-1] == s2[j-1]) pd[i][j] = pd[i-1][j-1] + 1;
                else pd[i][j] = max(pd[i-1][j], pd[i][j-1]);
            }
        } 
        
        int k = l1+l2-pd[l1][l2];
        res[k--] = '\0';        
        
        int i = l1;
        int j = l2;
        while (i > 0 && j > 0) {
            if (s1[i-1] == s2[j-1]) {
                res[k] = s1[i-1]; 
                i--;
                j--;
            }
            else if (pd[i][j] == pd[i-1][j]) {
                res[k] = s1[i-1];
                i--;
            }
            else {
                res[k] = s2[j-1];
                j--;
            }
            k--;
        }
        
        while (i > 0) {
            res[k--] = s1[i-1];
            i--;
        }
        while (j > 0) {
            res[k--] = s2[j-1];
            j--;
        }
        
        printf("Teste %d\n", teste++);
        printf("%s\n", res);
        printf("\n");
    }
    
    return 0;
}
