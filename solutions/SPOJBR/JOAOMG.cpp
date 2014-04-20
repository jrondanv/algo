#include <stdio.h>
#include <string.h>
#include <vector>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int ent[1001];
int aux[1001];

int a,b,c,d;
int t, N;

int main(){
    while (scanf("%d", &N) && N) {
        printf("%d: ", N);
        int pN=N;
        while (pN%10 == 0) pN /= 10;
        if (pN == 1) {
            if (N != 1) printf("N\n");
            else printf("S\n");
            continue;
        }
        
        int sq = N*N;
        int p10=1;
        int p = 0;
        int q = sq;
        
        bool poss = false;
        for (int i = 0; q && !poss; i++) {
            p = p + (q % 10)*p10;
            q /= 10;
            p10 *= 10;
            if (p+q == N) poss=true;
        }
        
        if (poss) printf("S\n");
        else printf("N\n");
    }
}
