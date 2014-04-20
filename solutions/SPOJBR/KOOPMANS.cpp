#include <stdio.h>

long long I,F,N;

#define MOD 1300031

long long mod(long long x) {
    long long res = x%MOD;
    
    if (res < 0) return res+MOD;
    return res;
}

long long gcd(long long a, long long b) {
    return b==0 ? a : gcd(b,a%b);
}

long long mmc(long long a, long long b) {
    return a*b/gcd(a,b);
}

long long PA(long long n, long long lim) {
    long long num_mult = lim/n;
    long long max_mult = num_mult*n + n;
    
    long long res = (max_mult * num_mult) / 2;
    return mod(res);
}

long long soma(long long n) {
    return mod(PA(n, F) - PA(n, I-1));
}

long long mults[30];

long long sum(int i, long long prod) {
    long long n_prod;
    long long res = 0;
    for (int j = i+1; j < N; j++) {
        n_prod = mmc(prod, mults[j]);
        
        if (n_prod <= F) {
            res = mod(res + soma(n_prod));
            res = mod(res - sum(j, n_prod));
        }
    }
    
    return res;
}

int main() {
    int T;
    scanf("%d", &T);
    
    for (int t = 0; t < T; t++) {
        scanf("%lld %lld %lld", &I,&F,&N);

        for (int i = 0; i < N; i++) scanf("%lld", &mults[i]);
        
        printf("%lld\n", sum(-1, 1));
    }
    
    return 0;
}

