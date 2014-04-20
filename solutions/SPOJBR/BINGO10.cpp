#include <stdio.h>
#include <stdlib.h>
#include <set>

using namespace std;

int b[100];
set<int> res;

int main() {
    int N, B;
    while (scanf("%d %d", &N, &B) && N) {
        res.clear();
        for (int i = 0; i < B; i++) {
            scanf("%d", &b[i]);
            for (int j = 0; j < i; j++) {
                res.insert(abs(b[i]-b[j]));
            }
        }
        
        if (res.size() == N) printf("Y\n");
        else printf("N\n");
    }
    
    return 0;
}
        

