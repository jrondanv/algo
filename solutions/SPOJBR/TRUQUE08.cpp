#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 1000000000
int n, m,a,b,c;

char nome[310][110];
int len[310];
int pd[310];

char ans[310][110];
int occ[310];

int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", nome[i]);
        len[i] = strlen(nome[i]);
    }

    int cur = n-1;
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < len[i]; k++) {
            cur = (cur+1)%n;
            while (occ[cur]) cur = (cur+1) % n;
        }
        occ[cur] = 1;
        strcpy(ans[cur], nome[i]);
    }

    for (int i = 0; i < n; i++) {
        printf("%s\n", ans[i]);
    }
}
