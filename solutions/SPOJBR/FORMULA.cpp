#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std;

int N;
char c;

int result[110][110];
int pont[20][110];

int score[20][110];

int G, P, S, K;

int main() {
    while (scanf("%d %d", &G, &P) && G) {
        for (int i = 0; i < G; i++)
            for (int j = 0; j < P; j++)
                scanf("%d", &result[i][j]);
        
        scanf("%d", &S);
        for (int i = 0; i < S; i++) {
            scanf("%d", &K);
            for (int j = 1; j <= P; j++) {
                if (j > K) pont[i][j-1] = 0;
                else scanf("%d", &pont[i][j-1]);
            }
        }
        
        memset(score,0,sizeof(score));
        for (int i = 0; i < G; i++) {
            for (int j = 0; j < P; j++) {
                for (int k = 0; k < S; k++) {
                    score[k][j] += pont[k][ result[i][j]-1 ];
                }
            }
        }
        
        for (int i = 0; i < S; i++) {
            int m = *max_element(score[i], score[i]+P);
            bool found = false;
            for (int j = 0; j < P; j++) {
                if (score[i][j] == m) {
                    if (found) printf(" ");
                    else found = true;
                    printf("%d", j+1);
                }
            }
            printf("\n");
        }
    }
}
