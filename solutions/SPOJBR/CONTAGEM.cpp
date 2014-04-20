#include <stdio.h>
#include <string.h>

char inp[70];

int main() {
    unsigned long long int resp;
    int teste = 1;
    
    while (scanf("%s", inp) != EOF) {
        int lim = strlen(inp);
        resp = 0;
        
        for (int i = 0; i < lim; i++) {
            resp = resp*2 + inp[i]-'a';
        }
        
        printf("Palavra %d\n", teste++);
        printf("%llu\n\n", resp);
    }
    
    return 0;
}
    
