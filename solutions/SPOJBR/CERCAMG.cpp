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

// Comparação radial.
bool radial_lt(point p, point q) {
    point P = p - point::pivot, Q = q - point::pivot;
    double R = P % Q;
    if (cmp(R)) return R > 0;
    return cmp(P * P, Q * Q) < 0;
}

// Determina o fecho convexo de um conjunto de pontos no plano.
// Destrói a lista de pontos T.
polygon convex_hull(vector<point>& T) {
    int j = 0, k, n = T.size(); polygon U(n);
    point::pivot = *min_element(all(T));
    sort(all(T), radial_lt);
// Descomentar para manter pontos colineares
//  for (k = n-2; k >= 0 && ccw(T[0], T[n-1], T[k]) == 0; k--);
//  reverse((k+1) + all(T));
    for (int i = 0; i < n; i++) {
// troque o >= por > para manter pontos colineares
        while (j > 1 && ccw(U[j-1], U[j-2], T[i]) >= 0) j--;
        U[j++] = T[i];
    }
    U.erase(j + all(U));
    return U;
}

// Calcula a área orientada do polígono T.
double poly_area(polygon& T) {
    double s = 0; int n = T.size();
    for (int i = 0; i < n; i++)
        s += T[i] % T[(i+1) % n];
    return s / 2;
}

int a, d, x, y;
const double pi = 2*acos(0);

int main() {
    while (scanf("%d %d", &a, &d) > 0) {
        vector<point> ent;
        for (int i = 0; i < a; i++) {
            scanf("%d %d", &x, &y);
            ent.push_back(point(x,y));
        }

        polygon CH = convex_hull(ent);
        double tot = 0;
        for (int i = 0; i < CH.size(); i++) {
            tot += abs(CH[(i+1)%CH.size()]-CH[i]);
        }
        printf("%.2lf\n", tot);
    }
}