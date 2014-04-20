#include <stdio.h>
#include <string.h>
#include <algorithm>

#define INF 1000000000

using namespace std;

struct team {
    int prob;
    int tent;
    int min;
};

team result[100];

int compara(team a, team b) {
    return (a.prob > b.prob || (a.prob == b.prob && a.tent*20+a.min < b.tent*20+b.min));
}

int tied(team a, team b) {
    return (a.prob == b.prob && a.tent*20+a.min == b.tent*20+b.min);
}

int main() {
    int T, P;
    while (scanf("%d %d", &T, &P) && T) {
        memset(result,0,sizeof(result));
        
        for (int t = 0; t < T; t++) {
            for (int p = 0; p < P; p++) {
                int tent, min; char c;
                if (scanf("%d/%d", &tent, &min) == 1) {
                    scanf("%c", &c);
                }
                
                else {
                    result[t].prob++;
                    result[t].min += min;
                    result[t].tent += tent-1;
                }
            }
        }
        
        sort(result,result+T,compara);
        
        int lower_bound = -INF;
        int upper_bound = +INF;
        
        for (int t = 0; t < T-1; t++) {
            if (result[t].prob > result[t+1].prob) continue;
            else if (result[t].tent == result[t+1].tent) continue;
            
            if (tied(result[t], result[t+1])) {
                lower_bound = upper_bound = 20;
                continue;
            }
            
            int num = (result[t+1].min-result[t].min);
            int den = (result[t].tent-result[t+1].tent);
             int val = num/den;
            
            if (result[t].tent < result[t+1].tent) val++;
            else val -= (num % den == 0) ? 1 : 0;
            
            //printf("val=%d obtida pelos times %d e %d!\n", val, t, t+1);
            //printf("time1 = (%d,%d,%d) time2 = (%d, %d, %d)\n", result[t].prob, result[t].tent, result[t].min, result[t+1].prob,result[t+1].tent,result[t+1].min);
            if (result[t].tent < result[t+1].tent) lower_bound = max(val,lower_bound);
            else upper_bound = min(val,upper_bound);
        }
        
        if (lower_bound <= 0) printf("1");
        else printf("%d", lower_bound);
        
        printf(" ");
        
        if (upper_bound == INF) printf("*");
        else printf("%d", upper_bound);
        
        printf("\n");
    }
    
    return 0;
}
