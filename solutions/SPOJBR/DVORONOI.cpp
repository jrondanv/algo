#include <stdio.h>
#include <math.h>

struct point {
    double x, y, z;
    
    point(double mx=0, double my=0, double mz=0) : x(mx), y(my), z(mz) {}
    
    point operator+ (point& other) {
        return point(x+other.x,y+other.y,z+other.z);
    }
    
    point operator- (point& other) {
        return point(x-other.x,y-other.y,z-other.z);
    }
    
    point operator* (double ot) {
        return point(ot*x, ot*y, ot*z);
    }
    
    point operator* (point& other) {
        return point(y*other.z - z*other.y, z*other.x - x*other.z, x*other.y - y*other.x);
    }
    
    point operator/ (double ot) {
        return point(ot/x, ot/y, ot/z);
    }
    
    double operator% (point& other) {
        return x*other.x + y*other.y + z*other.z;
    }
    
    double mag() {
        return sqrt(x*x + y*y + z*z);
    }
};

typedef point vector;

point vet(point a, point b, point c) {
    point x = (a - b);
    point y = (a - c);
    return x*y;
}

double area(point a, point b, point c) {
    point x = (a - b);
    point y = (a - c);
    return (x * y).mag() / 2;
}

vector projection(vector a, vector b) {
    double k = (a%b) / (b.x*b.x + b.y*b.y + b.z*b.z);
    return b * k;
}

double height(point a, point b, point c, point d) {
    vector n = vet(a,b,c);   
    return projection(a-d, n).mag();
}

int main() {
    int T;
    scanf("%d", &T);
    
    for (int t = 0; t < T; t++) {
        point a,b,c,d;
        scanf("%lf %lf %lf", &a.x, &a.y, &a.z);
        scanf("%lf %lf %lf", &b.x, &b.y, &b.z);
        scanf("%lf %lf %lf", &c.x, &c.y, &c.z);
        scanf("%lf %lf %lf", &d.x, &d.y, &d.z);
        
        printf("%.6lf\n", height(a,b,c,d) * area(a,b,c) / 3);
    }
    
    return 0;
}
