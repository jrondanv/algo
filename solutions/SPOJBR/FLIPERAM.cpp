#include <stdio.h>
#include <vector>
#include <algorithm>

int main(void) {
    int m, n, i;

    scanf("%d %d", &n, &m);

    std::vector<int> best;
    for (i = 0; i<m; i++) {
        best.push_back(0);
    }
    
    for (i = 0; i < n; i++) {
        int score, j;
        scanf("%d", &score);
        
        for (j = 0; j < m; j++) {
            if (best[j] < score) {
                best.insert(best.begin() + j, score);
                best.pop_back();
                break;
            }
        }
    }
    
    std::sort(best.begin(), best.end());

    for (i = m-1; i >= 0; i--) {
        printf("%d\n", best[i]);
    }
}