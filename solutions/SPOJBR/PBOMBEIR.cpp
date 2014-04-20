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
   bool operator < (point q) const { return cmp(q) < 0; }
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

point circumcenter(point p, point q, point r) {
   point a = p - r, b = q - r, c = point(a * (p + r) / 2, b * (q + r) / 2);
   return point(c % point(a.y, b.y), point(a.x, b.x) % c) / (a % b);
}

int cmp(point a, point b) {
    return a.cmp(b);
}

int main() {
    int T;
    scanf("%d", &T);
    
    for (int t = 0; t < T; t++) {
        point a,b,c;
        //printf("scanning");
        scanf("%lf %lf %lf %lf %lf %lf",&a.x,&a.y,&b.x,&b.y,&c.x,&c.y);
        
        if (! (cmp(a,b) && cmp(b,c) && cmp(a,c)) ) printf("There is an infinity of possible locations.\n");
        else if (!ccw(a,b,c)) printf("There is no possible location.\n");
        else {
            point res = circumcenter(a,b,c);
            printf("The equidistant location is (%.7lf, %.7lf).\n", res.x, res.y);
        }
    }
    
    return 0;
}
