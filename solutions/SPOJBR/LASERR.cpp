#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int A,C;

int main () {
    while (scanf("%d %d", &A, &C) && A) {
        int prev = A;
        int cnt = 0;
        for (int i = 0; i < C; i++) {
            int h;
            scanf("%d", &h);
            
            cnt += max(prev-h, 0);
            prev = h;
        }
        
        printf("%d\n",cnt);
    }
}
