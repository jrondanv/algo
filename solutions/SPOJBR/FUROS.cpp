#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <cmath>

int N;

using namespace std;

struct ponto {
    int x, y;
};
    
double dist (ponto a, ponto b) {
    double dx = a.x-b.x;
    double dy = a.y-b.y;
    return sqrt(dx*dx+dy*dy);
}    

ponto p[1000];
double m[1000];

int main() {
    int t = 1;
    while (scanf("%d", &N) && N) {
        printf("Teste %d\n", t++);
        
        for (int i = 0; i < N; i++) {
            scanf("%d %d", &p[i].x, &p[i].y);
        }
        
        for (int i = 0; i < N; i++) {
            m[i] = 0;
            for (int j = 0; j < N; j++) {
                m[i] = max(m[i], dist(p[i],p[j]));
            }
        }
        
        double resp = 1e9;
        for (int i = 0; i < N; i++) {
            resp = min(resp, m[i]);
        }
        
        printf("%d\n\n", (int) ceil(2*resp+5));
    }
    
}
