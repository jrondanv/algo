#include <stdio.h>

struct us {
    int x, y;
    int capac;
    int conn;
};

int dist(us a, us b) {
    int dx=a.x-b.x;
    int dy=a.y-b.y;
    
    return dx*dx+dy*dy;
}

us usina[10000];

int main() {
    int N,C;
    
    while (scanf("%d %d", &N, &C) && N) {
        for (int i = 0; i < N; i++) {
            scanf("%d %d %d", &usina[i].x, &usina[i].y, &usina[i].capac);
        
            if (i != 0) {
                int min_dist = 1000000000;
                int id = -1;
                for (int j = 0; j < i; j++) {
                    int d = dist(usina[i], usina[j]);
                    if (d < min_dist) {
                        min_dist = d;
                        id = j;
                    }
                }
                usina[i].conn = id;
            }
            else usina[i].conn = 0;
        }
        
        int cnt = 0;
        for (int j = N-1; j >= 0; j--) {
            if (usina[j].capac >= C) cnt++;
            else {
                usina[usina[j].conn].capac += usina[j].capac;
            }
        } 
        
        printf("%d\n", cnt);
    }
    
    return 0;
}
        
