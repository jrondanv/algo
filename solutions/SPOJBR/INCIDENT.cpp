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
 
int n,m,l;
 
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
 
// Decide se os segmentos fechados pq e rs têm pontos em comum.
bool seg_intersect(point p, point q, point r, point s) {
    point A = q - p, B = s - r, C = r - p, D = s - q;
    int a = cmp(A % C) + 2 * cmp(A % D);
    int b = cmp(B % C) + 2 * cmp(B % D);
    if (a == 3 || a == -3 || b == 3 || b == -3) return false;
    if (a || b || p == r || p == s || q == r || q == s) return true;
    int t = (p < r) + (p < s) + (q < r) + (q < s);
    return t != 0 && t != 4;
}
 
int cont = 1;
 
pair<point, point> parede[50];
point tele[50];
point loc[200];
 
double dist[200][2];
int marc[200];
double g[200][200];
int t[200][200];
 
int main() {
    while (scanf("%d %d %d", &n, &m, &l) > 0) {
        int p = m;
 
        for (int i = 0; i < m; i++) {
            scanf("%lf %lf %lf %lf", &parede[i].first.x, &parede[i].first.y,
                                     &parede[i].second.x, &parede[i].second.y);
             
            loc[2*i] = parede[i].first;
            loc[2*i+1] = parede[i].second;
        }
 
        for (int i = 0; i < l; i++) {
            scanf("%lf %lf", &tele[i].x, &tele[i].y);
            loc[2*m+i] = tele[i];
        }
 
        scanf("%lf %lf %lf %lf", &loc[2*m+l].x, &loc[2*m+l].y, &loc[2*m+l+1].x, &loc[2*m+l+1].y);
 
        int tot_v = l + 2*m + 2;
 
        for (int i = 0; i < tot_v; i++) {
            for (int j = i+1; j < tot_v; j++) {
                bool blocked = false;
                for (int block = 0; block < p; block++) {
                    if (i / 2 == block || j / 2 == block) continue;
                    if (seg_intersect(loc[i], loc[j], loc[2*block], loc[2*block+1])) blocked = true;
                }
 
                //printf("%d %d\n", i, j);
                //cout << loc[i] << " " << loc[j] << endl;
                if (!blocked) g[i][j] = g[j][i] = abs(loc[j] - loc[i]);
                else g[i][j] = g[j][i] = 1e15;
 
                i -= 2*p; j -= 2*p;
                if (!blocked && i >= 0 && i < l && j >= 0 && j < l) t[2*p+i][2*p+j] = t[2*p+j][2*p+i] = 1;
                else t[2*p+i][2*p+j] = t[2*p+j][2*p+i] = 0;
                i += 2*p; j += 2*p;
            }
 
            dist[i][0] = dist[i][1] = 1e15;
        }
 
        dist[2*p+l][0] = 0;
        double ans = 1e15;
        int j = 0;
 
        while (true) {
            int curv = -1, curt;
            j--;
             
            while (curv == -1) {
                j++;
                if (j == n+1) break;
 
                for (int i = 0; i < tot_v; i++) {
                    if (marc[i] != cont) {
                        if (curv == -1 || dist[i][j&1] < dist[curv][j&1]) {
                            curv = i;
                            curt = j&1;
                        }
                    }
                }
 
                if (curv == -1) cont++;
            }
 
            if (j == n+1) break;
 
            //printf("%d %d %lf\n", curv, curt, dist[curv][curt]);
            if (curv == 2*p+l+1) {
                ans = min(ans, dist[curv][curt]);
            }
 
            marc[curv] = cont;
 
            for (int i = 0; i < tot_v; i++) {
                dist[i][curt] = min(dist[i][curt], dist[curv][curt] + g[i][curv]);
                if (t[i][curv] && curt != n) {
                    dist[i][curt^1] = min(dist[i][curt^1], dist[curv][curt]);
                }
            }
        }
 
        printf("%.1lf\n", ans);
    }
}