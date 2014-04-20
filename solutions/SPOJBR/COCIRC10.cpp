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
#include <map>

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

struct cmpcirc {
    int operator() (circle a, circle b) {
        if (int t = a.first.cmp(b.first)) return t < 0 ? 1 : 0;
        return ::cmp(a.second, b.second) < 0 ? 1 : 0;    
    }
};

void pp(point a) {
    printf("(%lf, %lf)", a.x, a.y);
}

void pc(circle a) {
    printf("C: ");
    pp(a.first);
    printf("/%lf", a.second);
}

bool in_circle(circle C, point p){
   return cmp(abs(p - C.first), C.second) == 0;
}
point circumcenter(point p, point q, point r) {
   point a = p - r, b = q - r, c = point(a * (p + r) / 2, b * (q + r) / 2);
   return point(c % point(a.y, b.y), point(a.x, b.x) % c) / (a % b);
}

int C[200000];

int spanning_circle(vector<point>& T) {
   map<circle, int, cmpcirc> circles;
   map<circle, int, cmpcirc>::iterator it;
   
   int n = T.size();
   random_shuffle(all(T));
   
   int max = 0;
   
   for (int i = 0; i < n; i++) {
       for (int j = i+1; j < n; j++) { 
           for (int k = j+1; k < n; k++) { 
            if (ccw(T[i], T[j], T[k]) != 0) {
               point o = circumcenter(T[i], T[j], T[k]);
               circle C = circle(o, abs(o - T[k]));
               
               it = circles.find(C);
               if (it == circles.end()) {
                    circles.insert(pair<circle,int>(C,1));
                }
                else it->second++;
            }
            
           }
       }
   }
   
   it = circles.begin();
   for (; it != circles.end(); it++) {
        //pc(it->first);
        //printf(" (%d occ)\n", it->second);
        if (it->second > max) max = it->second;
   }
   return max!=0 ? C[max] : 2;
}
    
int main() {
    vector<point> v;
    
    for (int i = 0; i <= 100; i++) {
        C[i*(i-1)*(i-2) / 6] = i;
    }
    
    int N;
    while (scanf("%d", &N) && N) {
        v.clear();
        
        for (int i = 0; i < N; i++) {
            point p;
            scanf("%lf %lf", &p.x, &p.y);
            v.push_back(p);
        }
        
        if (N <= 2) printf("%d\n", N);
        printf("%d\n", spanning_circle(v));
    }
}    

