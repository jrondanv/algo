#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <inttypes.h>
#include <ctype.h>
#include <algorithm>
#include <utility>
#include <iostream>

using namespace std;

#define TRACE(x...) x
#define PRINT(x...) TRACE(printf(x))
#define WATCH(x) TRACE(cout << #x" = " << x << "\n")

#define _inline(f...) f() __attribute__((always_inline)); f
#define _foreach(it, b, e) for (typeof(b) it = (b); it != (e); it++)
#define foreach(x...) _foreach(x)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

const int INF = 0x3F3F3F3F;
const double EPS = 1e-10;

_inline(int cmp)(double x, double y = 0, double tol = EPS) {
   return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

struct point {
   double x, y;
   point(double x = 0, double y = 0): x(x), y(y) {}
   point operator +(point q) { return point(x + q.x, y + q.y); }
   point operator -(point q) { return point(x - q.x, y - q.y); }
   point operator *(double t) { return point(x * t, y * t); }
   point operator /(double t) { return point(x / t, y / t); }
   double operator *(point q) { return x * q.x + y * q.y; }
   double operator %(point q) { return x * q.y - y * q.x; }
   int cmp(point q) const {
       if (int t = ::cmp(x, q.x)) return t;
       return ::cmp(y, q.y);
   }
   bool operator ==(point q) const { return cmp(q) == 0; }
   bool operator !=(point q) const { return cmp(q) != 0; }
   bool operator < (point q) const { return cmp(q) <= 0; }
   friend ostream& operator <<(ostream& o, point p) {
       return o << "(" << p.x << ", " << p.y << ")";
   }
   static point pivot;
};
point point::pivot;
double abs(point p) { return hypot(p.x, p.y); }
double arg(point p) { return atan2(p.y, p.x); }
typedef vector<point> polygon;

_inline(int ccw)(point p, point q, point r) {
   return cmp((p - r) % (q - r));
}
_inline(double angle)(point p, point q, point r) {
   point u = p - q, v = r - q;
   return atan2(u % v, u * v);
}

// Decide se os segmentos fechados pq e rs têm pontos em comum.
bool seg_intersect(point p, point q, point r, point s) {
   if (p == r || p == s && (q != r && q != s)) return false;
   if (q == r || q == s && (p != r && p != s)) return false;
   
   point A = q - p, B = s - r, C = r - p, D = s - q;
   int a = cmp(A % C) + 2 * cmp(A % D);
   int b = cmp(B % C) + 2 * cmp(B % D);
   if (a == 3 || a == -3 || b == 3 || b == -3) return false;
   if (a || b || p == r || p == s || q == r || q == s) return true;
   int t = (p < r) + (p < s) + (q < r) + (q < s);
   return t != 0 && t != 4;
}
 
point p[350]; 
int n;

int marc[350];
double d[350];

int main() {
    while (scanf("%lf %lf %lf %lf %d", &p[0].x, &p[0].y, &p[1].x, &p[1].y, &n) && (p[0].x || p[0].y || p[1].x || p[1].y || n)) {
        for (int i = 0; i < n; i++) {
            scanf("%lf %lf %lf %lf", &p[2*i+2].x, &p[2*i+2].y, &p[2*i+3].x, &p[2*i+3].y);
        }
        
        int tot = 2*n+2;
        
        memset(marc,0,sizeof(marc));
        for (int i = 0; i < tot; i++) d[i] = INF;
        d[0] = 0;
        
        int curr = 0;
        while (curr != -1) {
            marc[curr]=1;
            
            if (curr == 1) break;
            
            for (int i = 0; i < tot; i++) {
                if (!marc[i]) {
                    bool poss = true;
                    for (int j = 0; j < n; j++) {
                        if (seg_intersect(p[curr], p[i], p[2*j+2], p[2*j+3])) {
                            poss = false;
                            break;
                        }
                    }
                    
                    if (poss) {
                        d[i] = min(d[i], d[curr]+abs(p[i]-p[curr]));
                    }
                }        
            }
            
            curr = -1;
            double min_d = INF;
            
            for (int i = 0; i < tot; i++) {
                if (!marc[i] && d[i] < min_d) {
                    min_d = d[i];
                    curr = i;
                }
            }
        }
        
        printf("%.2lf\n", d[1]);
    }

}
