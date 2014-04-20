#include <stdio.h>
#include <string.h>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct cid {
    int lat, lon;
    bool operator< (cid ot) const {
        return (lon<ot.lon || (lon==ot.lon && lat < ot.lat));
    }
};

int prevb[510][510];
int pd[510][510];
cid c[510];

int daybegin, best;

int n, T;

int calc() {
    memset(pd,0,sizeof(pd));
    pd[0][0]=1;
    daybegin = 0;

    for (int i = 1; i <= n; i++) {
        if (c[i].lon != c[i-1].lon) {
            for (int j = daybegin; j < i; j++) {
                for (int t = 0; t <= T; t++) {
                    prevb[j][t] = pd[j][t];
                }
            }

            for (int k = daybegin; k < i; k++) {
                for (int t = 0; t <= T; t++) {
                    for (int j = daybegin; j < i; j++) {
                        int cost = abs(c[k].lat - c[j].lat);
                        if (t >= cost && prevb[j][t-cost]) {
                            pd[k][t] = max(pd[k][t], prevb[j][t-cost] + abs(j-k));
                        }
                    }
                }
            }   

            daybegin = i;
        }
        
        for (int j = 0; j < i; j++) {
            if (c[i].lon == c[j].lon) continue;
            for (int t = 0; t <= T; t++) {
                int cost = abs(c[i].lat-c[j].lat);
                if (t >= cost && pd[j][t-cost]) {
                    pd[i][t] = max(pd[i][t], pd[j][t-cost]+1);
                }
            }
        }
    }

    /*for (int i = 1; i <= n; i++) {
        int best = 0;
        int p = 0;
        for (int t = 0; t <= T; t++) {
            if (pd[i][t] > best){ best = pd[i][t]; p = t; }
        }
        printf("%d: %d %d (%d,%d)\n", i, best, p, c[i].lat, c[i].lon);
    }*/
    int best = 0;
    for (int t = 0; t <= T; t++) {
        if (pd[n][t] > best) best = pd[n][t];
    }
    return best;
}

int main() {
    scanf("%d %d", &n, &T);

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &c[i].lat, &c[i].lon);
        if (i != 0) {
            c[i].lon = c[i].lon - c[0].lon;
            if (c[i].lon < 0) c[i].lon += 360;
        }
    }

    c[0].lon = -1;
    c[n].lat = c[0].lat;
    c[n].lon = 100000;

    for (int i = 0; i < n; i++) {
        if (c[i].lon == 0 && c[i].lat > c[0].lat) c[i].lon = 400;
    }

    sort(c+1, c+n);
    best = max(best, calc());

    for (int i = 0; i < n; i++) {
        if (c[i].lon == 0 && c[i].lat < c[0].lat) c[i].lon = 400;
        else if (c[i].lon == 400) c[i].lon = 0;
    }

    sort(c+1, c+n);
    best = max(best, calc());

    for (int i = 0; i < n; i++) {
        if (c[i].lon == 400) c[i].lon = 0; 
    }

    sort(c+1, c+n);
    best = max(best, calc());

    for (int i = 0; i < n; i++) {
        if (c[i].lon == 0) c[i].lon = 400; 
    }

    sort(c+1, c+n);
    best = max(best, calc());
    
    printf("%d\n", best-2);
}
