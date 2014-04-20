#include <stdio.h>
#include <cmath>
#include <algorithm>

using namespace std;

#define INF 1e16
#define eps 1e-8
#define MAXN 210

struct point {
    double x,y;
    
    point() {}
    point(double xx, double yy) : x(xx), y(yy) {}
    
    point operator*(double ot) {
        return point(x*ot, y*ot);
    }
    
    point operator+(point ot) {
        return point(x+ot.x, y+ot.y);
    }
    
    point operator-(point ot) {
        return point(x-ot.x, y-ot.y);
    }
    
    point operator/(double ot) {
        return point(x/ot, y/ot);
    }
};

struct inter {
    double x,y;
    bool entry;
    double comp;
    
    bool operator< (inter ot) const {
        return comp < ot.comp;
    }
};

double dist(point a, point b) {
    double dx = a.x-b.x;
    double dy = a.y-b.y;
    return sqrt(dx*dx+dy*dy);
}

double distsq(point a, point b) {
    double dx = a.x-b.x;
    double dy = a.y-b.y;
    return dx*dx+dy*dy;
}


int N,K;
point p[MAXN];
inter it[2*MAXN];

struct distst {
    int id, dst;
    bool operator<(distst ot) const {return dst<ot.dst;}
};

distst dst[200][200];

double calc_depth(double r, int i) {
    int left_inter = 0;
    
    point left = p[i];
    left.y -= r;
    
    //printf("left = (%lf, %lf)\n",left.x,left.y);
    int tam = 0;
    double comp = r*r;
    
    for (int k = 0; k < N; k++) {
        int j = dst[i][k].id;
        if (i==j) continue;
        
        double d = dst[i][k].dst;
        
        if (d > 2*r + eps) break;
        if (fabs(d)<eps) {
            left_inter++;
            continue;
        }
        
        bool is_left = distsq(p[j], left) < comp+eps;
        if (is_left) {
            left_inter++;
        }
        
        double a = (d*d) / (2*d);
        
        point diff = p[j] - p[i];
        point p2 = p[i] + (diff * a) / d;
        
        double h = sqrt(r*r - a*a);
        
        it[tam].x = p2.x + h*( p[j].y - p[i].y ) / d;
        it[tam].y = p2.y - h*( p[j].x - p[i].x ) / d;  
        
        it[tam+1].x = p2.x - h*( p[j].y - p[i].y ) / d;
        it[tam+1].y = p2.y + h*( p[j].x - p[i].x ) / d; 
        
        it[tam].x -= p[i].x;
        it[tam].y -= p[i].y;
        it[tam+1].x -= p[i].x;
        it[tam+1].y -= p[i].y;
        
        it[tam].comp = atan2(it[tam].x, it[tam].y);
        it[tam+1].comp = atan2(it[tam+1].x, it[tam+1].y);
        
        if (it[tam] < it[tam+1]) {
            it[tam].entry = true;
            it[tam+1].entry = false;
        }
        else {
            it[tam].entry = false;
            it[tam+1].entry = true;
        }
        
        if (is_left) {
            swap(it[tam].entry, it[tam+1].entry);
        }
        
        tam+=2;
    }
    
    int curr,best;
    curr = best = left_inter;
    
    sort(it,it+tam);
    //printf("left_inter = %d\n", left_inter);
    
    for (int j = 0; j < tam; j++) {
        if (it[j].entry) curr++;
        else curr--;
        
        best = max(curr,best);
    }
    
    return best;
}


double maxdst;

double oracle(int i, int k) {
    maxdst = 0;
    for (int j = 0; j < N; j++) {
        if (j == i) continue;
        double d = dist(p[i],p[j]);
        maxdst = max(d,maxdst);  
    }
    
    maxdst = min(maxdst, 14142.136);
    
    double beg = dst[i][k].dst/2, end = maxdst;
    while (end-beg >= 1e-5) {
        double mid = (beg+end)/2;
        //printf("beg = %lf end = %lf, mid = %lf\n", beg, end, mid);
        int depth = calc_depth(mid, i);
        
        if (depth >= k) end=mid;
        else beg=mid;
    } 
    return beg;
}

int main() {
    while (scanf("%d %d", &N, &K) && N) {
        for (int i = 0; i < N; i++) {
            scanf("%lf %lf", &p[i].x, &p[i].y);
        }
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                dst[i][j].id = j;
                dst[i][j].dst = dist(p[i],p[j]);
            }
            sort(dst[i],dst[i]+N);
        }
        
        double best = INF;
        for (int i = 0; i < N; i++) {
            //printf("beginning binary search for point %d\n",i);
            double ret = oracle(i,K-1);
            //printf("this val = %lf\n",ret);
            best = min(best, ret);
        }
        
        printf("%.3lf\n", best);
    }
}


