#include <stdio.h>
#include <algorithm>
#include <map>

using namespace std;

struct point {
    int x, y;
    bool operator< (point ot) const { return x<ot.x || (x==ot.x && y<ot.y); }
};

map<point, map<long long, int> > est;
point pts[1000];

long long comb(long long a){
    return a*(a-1)/2;
}

int main(){
    int n;

    while(scanf("%d", &n) && n){
        est.clear();
        long long resp = 0;
        for(int c = 0; c<n; c++){
            scanf("%d %d", &pts[c].x, &pts[c].y);
            
            est[pts[c]][0]++;
            
            for(int k = 0; k<c; k++){
                long long dx = pts[c].x - pts[k].x;
                long long dy = pts[c].y - pts[k].y;
                long long dist = dx*dx+dy*dy;
                
                est[pts[c]][dist]++;
                est[pts[k]][dist]++;
            }
        }

        //for(int c = 0; c<n; c++) sort(&dist[c][0],&dist[c][n]);

        for(int c = 0; c<n; c++){
            map<long long, int>::iterator it;
            for (it = est[pts[c]].begin(); it != est[pts[c]].end(); it++) {
                resp += comb( it->second );
            }         
        }

        printf("%lld\n", resp);
    }
    
    return 0;
}

