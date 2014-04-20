#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int N,K;

int main() {  
    scanf("%d %d", &K, &N);
    
    int ans = 1;
    for (int i = 0; i <= N; i++) {
        if (ans > K) {
            printf("%d\n", i);
            return 0;
        }
        ans *= 2;
    }
    
    N++;
    for (int i = N; ; i++) {
        long long a = 1;
        long long term = 1;
        for (int k = 1; k < N; k++) {
            term = (term*(i-k+1))/k;
            //printf("sum %lld\n",term);
            a += term;
        }
        
        //printf("a for j = %d is %lld\n", i, a);
        if (a > K) {
            printf("%d\n", i);
            return 0;
        }
    } 
}
