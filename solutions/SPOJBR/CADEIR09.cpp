#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;

int g[201][201];
int curr[201];

struct sw {
    char t;
    int a, b;
};

sw li[1000];

int a, b, c;
int best;

int main(int argc, char const *argv[])
{
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &g[i][j]);
            g[i][j]--;
        }
    }

    int cnt = 0;

    for (int i = 0; i < m; i++) {
        curr[i] = g[0][i]%m;
    }

    for (int i = 0; i < m; i++) {
        if (curr[i] == i) continue;

        for (int j = i; j < m; j++) {
            if (curr[j] == i) {
                li[cnt].t = 'C';
                li[cnt].a = i;
                li[cnt++].b = j;

                swap(curr[i], curr[j]);
                break;
            } 
        }
    }

    for (int i = 0; i < n; i++) {
        curr[i] = g[i][0]/m;
    }

    for (int i = 0; i < n; i++) {
        if (curr[i] == i) continue;

        for (int j = i; j < n; j++) {
            if (curr[j] == i) {
                li[cnt].t = 'L';
                li[cnt].a = i;
                li[cnt++].b = j;
                swap(curr[i], curr[j]);
                break;
            } 
        }
    }

    printf("%d\n", cnt);
    for (int i = 0; i < cnt; i++) {
        printf("%c %d %d\n", li[i].t, li[i].a+1, li[i].b+1);
    }
}
