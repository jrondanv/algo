#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>

using namespace std;

typedef long long int ll;

struct point {
    ll x, y;
    double comp;
    
    bool operator< (point ot) const {
        return comp < ot.comp;
    }
    bool operator== (point ot) const {
        return x==ot.x && y==ot.y;
    }
};

point p[1010];
point q[1010];

bool col(point a, point b, point c) {
    ll area = a.x*b.y + b.x*c.y + c.x*a.y - b.x*a.y - c.x*b.y - a.x*c.y;
    return area == 0;
}

int T, N;

int main() {  
    for (scanf("%d", &T); T; T--) {
        scanf("%d", &N);
        
        
        int best = 1;
        for (int i = 0; i < N; i++) {
            scanf("%lld %lld", &p[i].x, &p[i].y);
            q[i] = p[i];
        } 
        
        if (N == 1) {
            printf("1\n");
            continue;
        }
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N-1; j++) {
                if (q[j] == p[i]) swap(q[j], q[N-1]);
                q[j].comp = atan2(q[j].y - p[i].y, q[j].x - p[i].x);
            }
            
            sort(q,q+N-1);
            
            int cur = 1;
            
            //printf("ponto (%lld,%lld), comp %lf\n",q[0].x,q[0].y,q[0].comp);
            for (int j = 1; j < N-1; j++) {
                //printf("ponto (%lld,%lld), comp %lf\n",q[j].x,q[j].y,q[j].comp);
                if (col(p[i],q[j-1],q[j])) {
                    //printf("eh colinear\n");
                    cur++;
                }
                else {
                    best = max(best,cur);
                    cur = 1;
                }
            }
            
            best = max(best,cur);
        }
        
        printf("%d\n", best+1);
    } 
}
