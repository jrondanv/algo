#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;

int g[100][100];
int a, b, c;
int best;

int main(int argc, char const *argv[])
{
    scanf("%d %d", &n, &m);
    best = -1;

    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &a, &b, &c);
        g[a-1][b-1]=c;
        g[b-1][a-1]=c;
    }

    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            for (int k = j+1; k < n; k++) {
                int th = g[i][j]+g[i][k]+g[j][k];
                if (th > best) {
                    best = th;
                    a = i+1; b = j+1; c = k+1;
                }
            }
        }
    }

    printf("%d %d %d\n", a,b,c);
}
