#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int n,T,l;
char s[10000];
char ans[10000];

int last[200];

char tradcima[200], tradbaixo[200], traddir[200], tradesq[200];

void do_it(char a, char b, char* transA, char* transB) {
    char targ = a;
    if (last[a] < last[b]) targ = b;

    if (last[targ] == 0) {
        printf("<none>");
        return;
    }
    
    for (int i = 0; i < last[targ]; i++) printf("%c", s[i]);
    printf("%c", transB[targ]);
    for (int i = last[targ]+1; i < l; i++) printf("%c", transA[s[i]]);
}

int main() {
    for (scanf("%d", &T), gets(s); T; T--) {
        gets(s);
        l = strlen(s);

        strcpy(ans,s);

        tradcima['s'] = tradcima['p'] = 's';
        tradcima['q'] = tradcima['r'] = 'r';

        tradbaixo['s'] = tradbaixo['p'] = 'p';
        tradbaixo['q'] = tradbaixo['r'] = 'q';

        traddir['p'] = traddir['q'] = 'p';
        traddir['s'] = traddir['r'] = 's';

        tradesq['p'] = tradesq['q'] = 'q';
        tradesq['s'] = tradesq['r'] = 'r';

        for (char let = 'p'; let <= 's'; let++) last[let] = 0;

        for (int i = 0; i < l; i++) {
            last[s[i]] = i;            
        }

        do_it('s', 'r', tradcima, tradbaixo); printf(" ");
        do_it('p', 'q', tradbaixo, tradcima); printf(" ");

        do_it('q', 'r', tradesq, traddir); printf(" ");
        do_it('p', 's', traddir, tradesq); printf("\n");
    }
}