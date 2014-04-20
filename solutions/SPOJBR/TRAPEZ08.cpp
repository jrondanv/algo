#include <stdio.h>
#include <algorithm>
#include <set>
using namespace std;

set< pair<int, int> > poss;

struct trap {
    int P, R, id;

    bool operator< (trap ot) const {
        return R+P > ot.R+ot.P;
    }
};

int n, S;
trap t[100010];
int ans[100010];

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &t[i].P, &t[i].R);
        S += t[i].P;
        t[i].id = i+1;
    }
    sort(t,t+n);

    int P = 0;
    bool ok=true;

    int add = 0;
    for (int i = 0; i < n; i++) {
        while (add < n && t[add].R + t[add].P >= S) {
            poss.insert(make_pair(t[add].id, add));
            add++;
        }
        if (poss.empty()) {
            printf("IMPOSSIVEL\n");
            return 0;
        }
        ans[i] = poss.begin()->first;
        S -= t[poss.begin()->second].P;
        poss.erase(poss.begin());
        
    }
    
    for (int i = 0; i < n; i++) {
        printf("%d\n", ans[i]);
    }
}