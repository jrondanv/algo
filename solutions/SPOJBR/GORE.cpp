#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int m = 200010;

int get_0(int tree[], int i) {
  if (i > m) i = m;
  int s = 0;
  while (i > 0) {
    s += tree[i];
    i ^= i & -i;
  }
  return s;
}

void add_0(int* tree, int i, int val) {
  while (i<=m) {
    tree[i] += val;
    i += i & -i;
  }
}

struct point {
    int x, y, id;
    
    bool operator< (point b) const {
        return (x < b.x) || (x == b.x && y < b.y);
    }
}; 

int tree[200010];
point p[100010];

int res[100010];

point active[200010];
int inic;
int fim;

void pp(point a) {
    printf("(%d, %d)", a.x, a.y);
}

int main() {
    int T;
    scanf("%d", &T);
    
    for (int t = 0; t < T; t++) {
        inic = fim = 0;
        memset(tree, 0, sizeof(tree));
        
        int N, D;
        scanf("%d %d", &N, &D);
        
        for (int i = 0; i < N; i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            
            p[i].x = x-y+100001;
            p[i].y = x+y+1;
            p[i].id = i;
        }
    
        sort(p, p+N);
        
        int next_active = 0;
        
        for (int i = 0; i < N; i++) {
            while (next_active < N && p[next_active].x - p[i].x <= D) {
                add_0(tree, p[next_active].y, 1);
                active[fim++] = p[next_active];
                next_active++;
            }
            
            while (p[i].x - active[inic].x > D) {
                add_0(tree, active[inic++].y, -1);
            }
            
            res[p[i].id] = get_0(tree, p[i].y+D) - get_0(tree, p[i].y-D-1);
        }
        
        for (int i = 0; i < N-1; i++) {
            printf("%d ", res[i]-1);
        }
        printf("%d\n", res[N-1]-1);
    }

}
