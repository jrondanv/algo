#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;

int n;

struct ponto {
    double x, y;
};

double distancia(ponto p1, ponto p2) {
    double dx = p1.x-p2.x;
    double dy = p1.y-p2.y;
    return sqrt(dx*dx+dy*dy);
}

ponto p[1000];

int main() {
    while (scanf("%d", &n) && n) {
        double soma = 0;
        int marc = 0;
        
        double g[n][n];
        int marcado[n];
        double d[n];
        
        int i,j;
        
        for (int i = 0; i < n; i++) {
            scanf("%lf %lf", &p[i].x, &p[i].y);
        }

        for(i=0;i<n;i++) {
            for (j=0;j<n;j++) {
                g[i][j] = distancia(p[i],p[j]);
            }
        }
        
        for (i=0;i<n;i++) {
            marcado[i]=0;
            d[i] = 1000000000;
        }
        d[0] = 0;
        
        while (marc != n) {
              double max_d = 1000000000;
              int max_ind = 0;
              
              for (i=0; i<n; i++) {
                  if (!marcado[i] && d[i] < max_d) {
                           max_d = d[i];
                           max_ind = i;
                  }
              }
              
              marcado[max_ind] = 1;
              soma = max(soma,max_d);
              for (i=0; i<n; i++) {
                  d[i] = d[i]<g[max_ind][i]?d[i]:g[max_ind][i];
              }
              
              marc++;
        }
        
        printf("%.4lf\n", soma);
    }
    
    return 0;
}
