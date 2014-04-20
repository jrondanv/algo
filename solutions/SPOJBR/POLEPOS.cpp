#include <stdio.h>
#include <string>
#include <map>
#include <cstring>
#include <algorithm>
#include <cctype>

using namespace std;

int grid[1010];

int N;

int main() {
    while (scanf("%d", &N) && N) {
        int c, p;
        bool ok = true;
        
        memset(grid,-1,sizeof(grid));
        
        for (int i = 0; i < N; i++) {
            scanf("%d %d", &c, &p);
            if (i+p < 0 || i+p >= N) {
                ok = false;
                continue;
            }
            
            if (grid[i+p] != -1) {
                ok = false;
                continue;
            }
            
            grid[i+p] = c;
        }
        
        if (!ok) printf("-1\n");
        else {
            for (int i = 0; i < N; i++) {
                printf("%d", grid[i]);
                if (i != N-1) printf(" ");
            }
            printf("\n");
        }
    }
}


