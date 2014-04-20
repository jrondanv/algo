#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 1000000000
int n, m,a,b,c;

int g[1010][1010];
int dist[1010], marc[1010];

int main(int argc, char const *argv[])
{
    scanf("%d %d", &n, &m);

    for (int i = 0; i <= n+1; i++) {
        dist[i] = INF;
        for (int j = 0; j <= n+1; j++) {
            g[i][j] = 1000000000;
        }
    }

    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &a, &b, &c);
        g[a][b] = g[b][a] = c;
    }

    int curr = 0;
    dist[0] = 0;
    do {
        marc[curr]=1;
        for (int i = 0; i <= n+1; i++) {
            if (g[curr][i] + dist[curr] < dist[i]) {
                dist[i] = g[curr][i] + dist[curr];
            }
        }

        int best = INF;
        curr = -1;
        for (int i = 0; i <= n+1; i++) {
            if (!marc[i] && dist[i]<best) {
                best=dist[i];
                curr = i;
            }
        }
    } while (curr != -1);

    printf("%d\n", dist[n+1]);

}
