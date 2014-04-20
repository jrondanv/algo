#include <stdio.h>
#include <algorithm>
#include <math.h>

const double EPS=1e-6;

using namespace std;
 
struct point {
    int x, y;
    
    bool operator<(const point& ot) const {
        return x < ot.x || (x==ot.x && y<ot.y);
    }
    
    bool operator==(const point& ot) const {
        return x==ot.x && y==ot.y;
    }
};

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

struct seg {
    point mid, slope;
    
    bool operator<(const seg& ot) const {
        if (!(mid == ot.mid)) return (mid < ot.mid);
        return slope < ot.slope;
    }
};

int N;
point p[1000];
seg s[1000000];

int main() {
    scanf("%d", &N);
    
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &p[i].x, &p[i].y);
    }
    
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            s[cnt].mid.x = p[i].x + p[j].x;
            s[cnt].mid.y = p[i].y + p[j].y;
            
            s[cnt].slope.y = p[i].y-p[j].y;
            s[cnt].slope.x = p[i].x-p[j].x;
            
            int mdc = gcd(s[cnt].slope.y, s[cnt].slope.x);
            s[cnt].slope.y /= mdc;
            s[cnt].slope.x /= mdc;
            
            if (s[cnt].slope.y < 0) {
                 s[cnt].slope.y = -s[cnt].slope.y;
                 s[cnt].slope.x = -s[cnt].slope.x;
            }
            
            //printf("%lf %lf\n", s[cnt].slope, s[cnt].intercept);
            cnt++;
        }
    }
    
    sort(s, s+cnt);
    
    int cur = 1;
    int resp = 0;
    int col = 1;
    int comb_sum = 0, comb_diff = 0;
    
    for (int i = 1; i < cnt; i++) {
        bool eq = false;
        
        if (s[i].mid == s[i-1].mid) {
            comb_sum += cur;
            cur++;
            
            if (s[i].slope == s[i-1].slope) {
                eq = true;
            }
        }
        else{
            //printf("cur=%lld\n",cur);
            resp += comb_sum;
            cur = 1;
            comb_sum = 0;
        }
        
        if (eq) {
            comb_diff += col++;
        }
        else {
            resp -= comb_diff;
            col = 1;
            comb_diff = 0;
        }
    }
    
    resp += comb_sum;
    resp -= comb_diff;
    
    printf("%d\n", resp);
}

