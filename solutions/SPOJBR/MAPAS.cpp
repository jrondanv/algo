#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;

struct mapa {
    int id,x1,x2,y1,y2,area;
    bool operator<(mapa b) const {
        return x1<b.x1 || (x1==b.x1 && x2>b.x2);
    }
};

const double TOL = 1e-6;

mapa mapas[30000];
int nextx[30000];

int M,R,x,y;
int best;
double best_dist;

double dist(int i) {
    double xc = (mapas[i].x1 + mapas[i].x2)/2.0;
    double yc = (mapas[i].y1 + mapas[i].y2)/2.0;
    
    return (x-xc)*(x-xc) + (y-yc)*(y-yc);
}

void new_best(int i) {
    best = i;
    best_dist = dist(i);
}
    
bool eq(double a, double b) {
    return fabs(a-b) < TOL;
}
    

int main() {
    int t = 1;
    while (scanf("%d %d",&M,&R) && M) {
        for (int i = 0; i < M; i++) {
            scanf("%d %d %d %d %d",&mapas[i].id,&mapas[i].x1,&mapas[i].y1,&mapas[i].x2,&mapas[i].y2);
            mapas[i].area=(mapas[i].y2-mapas[i].y1)*(mapas[i].x2-mapas[i].x1);
        }
        
        sort(mapas,mapas+M);
        
        int first = 0;
        int prev = mapas[0].x1;
        for (int i = 1; i < M; i++) {
            if (mapas[i].x1 != prev) {
                for (int j = first; j < i; j++) nextx[j]=i;
                prev=mapas[i].x1;
                first=i;
            }
        }
        for (int j = first; j<M; j++) nextx[j]=-1;
        
        printf("Teste %d\n", t++);
        for (int k = 0; k < R; k++) {
            scanf("%d %d", &x, &y);
            
            int i = 0;
            best = -1;
            best_dist = -1;
            while (mapas[i].x1 <= x && i != -1 && i < M) {
                if (mapas[i].x2 < x) {
                    i = nextx[i];
                    continue;
                }
                
                if (mapas[i].y1 <= y && mapas[i].y2 >= y) {
                    if (best == -1) new_best(i);
                    else if (mapas[i].area < mapas[best].area) new_best(i);   
                    else if (mapas[i].area == mapas[best].area) {
                        double d = dist(i);
                        if (d < best_dist) new_best(i);
                        else if (eq(d,best_dist) && mapas[i].id < mapas[best].id) new_best(i);
                    }
                }
                
                i++;
            }
            
            if (best==-1)printf("0\n");
            else printf("%d\n",mapas[best].id);
        }
        printf("\n");
    }
}
