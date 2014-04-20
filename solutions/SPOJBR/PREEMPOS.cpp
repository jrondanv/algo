#include <stdio.h>
#include <queue>
#include <string.h>

using namespace std;
typedef char cadeia[100];

void printPreEm(char* pre, char* em) {
    //printf("<%s>, <%s>\n", pre, em);
    if (em[0] == '\0') {
        return;
    }
    
    char root = pre[0];
    
    int i;
    for (i = 0; em[i] != root; i++);
    
    em[i] = '\0';
    
    printPreEm(pre+1, em);
    printPreEm(pre+i+1,em+i+1);
    
    printf("%c", root);
}

int main() {
    int T;
    scanf("%d", &T);
    
    for (int t = 0; t < T; t++) {
        int N;
        scanf("%d", &N);
        
        char pre[100];
        char pos[100];
        
        scanf(" %s %s", pre, pos);
        
        printPreEm(pre,pos);
        printf("\n");
    }
    
    return 0;
}
        
