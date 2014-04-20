#include <map>
#include <set>
#include <algorithm>
#include <stdio.h>
#include <string.h>

using namespace std;

set<int> s;
pair<int, int> re[1100];

int n,k,c,m,a,b;
int t, teste;

int p[1000];

int main()
{
    while (scanf("%d %d %d", &n, &c, &k) && n) {
        memset(p,0,sizeof(p));
        s.clear();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < c; j++) {
                scanf("%d", &a);
                p[a]++;
            }
        }

        for (int i = 1; i<=k; i++) {
            re[i] = make_pair(p[i], i);
        }

        sort(re+1,re+k+1);

        for (int i = 1; i <= k; i++) {
            if (i==1 || re[i].first == re[i-1].first) s.insert(re[i].second);
            else break;
        }

        bool f = false;
        for (set<int>::iterator iter = s.begin(); iter != s.end(); iter++) {
            if (f) printf(" ");
            f = true;
            printf("%d", *iter);
        }
        printf("\n");
    }
}    
