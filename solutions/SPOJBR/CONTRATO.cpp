#include <stdio.h>
#include <string.h>

char num[110];

int main() {
    int D;
    
    while (scanf("%d", &D) && D) {
        scanf("%s", num);
        
        int l = strlen(num);
        int ns = 1;
        
        for (int i = 0; i < l; i++) {
            if (num[i] - '0' == D) continue;
            else if (num[i] == '0' && !ns) putchar(num[i]); 
            else if (num[i] != '0') {
                putchar(num[i]);
                ns = 0;
            }
        }
        
        if (ns) putchar('0');
        printf("\n");
    }
    
    return 0;
}
