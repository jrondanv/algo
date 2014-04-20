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

// Encontra o menor círculo que contém todos os pontos dados.
typedef pair<point, double> circle;

bool in_circle(circle C, point p){
   return cmp(abs(p - C.first), C.second) <= 0;
}
point circumcenter(point p, point q, point r) {
   point a = p - r, b = q - r, c = point(a * (p + r) / 2, b * (q + r) / 2);
   return point(c % point(a.y, b.y), point(a.x, b.x) % c) / (a % b);
}
circle spanning_circle(vector<point>& T) {
   int n = T.size();
   random_shuffle(all(T));
   circle C(point(), -INF);
   for (int i = 0; i < n; i++) if (!in_circle(C, T[i])) {
       C = circle(T[i], 0);
       for (int j = 0; j < i; j++) if (!in_circle(C, T[j])) {
           C = circle((T[i] + T[j]) / 2, abs(T[i] - T[j]) / 2);
           for (int k = 0; k < j; k++) if (!in_circle(C, T[k])) {
               point o = circumcenter(T[i], T[j], T[k]);
               C = circle(o, abs(o - T[k]));
           }
       }
   }
   return C;
}

vector<point> cidades;

int main() {
    int N, teste = 1;
    while (scanf("%d", &N) && N) {
        cidades.clear();
        
        for (int i = 0; i < N; i++) {
            point c;
            scanf("%lf %lf", &c.x, &c.y);
            cidades.push_back(c);
        }
    
        circle r = spanning_circle(cidades);
        printf("Instancia %d\n", teste++);
        printf("%.2lf %.2lf %.2lf\n\n", r.first.x, r.first.y, r.second);
    }
    
    return 0;
}
        
