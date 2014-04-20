#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector< pair<int, int> > ordem;
int o,p,b;

int main(int argc, char const *argv[])
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) ordem.push_back(make_pair(0, n-i));

    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &o, &p, &b);
        ordem[o-1].first++;
        ordem[p-1].first++;
        ordem[b-1].first++;
    }

    sort(ordem.begin(),ordem.end());
    for (int i = n-1; i >= 0; i--) {
        printf("%d ", n-ordem[i].second+1);
    }
}
