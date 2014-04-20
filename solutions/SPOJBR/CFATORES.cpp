#include <stdio.h>

int primes[1000];

void fill_prime_list() {
    int i;

    for (i = 3; i < 1000; i += 2) {
        primes[i] = 1;
    }
    
    primes[2] = 1;
    primes[0] = 0;
    primes[1] = 0;

    for (i = 3; i < 1000; i += 2) {
        if (primes[i]) {
            int j;
            for (j = 2*i; j < 1000; j += i) primes[j] = 0;
        }
    }
}

int count_factors(int n) {
    int i = 2;
    int c = 0;

    while (n > 1) {
        while (!primes[i] && i < 1000) i++;
        if (i == 1000) return c + 1;

        if (n % i == 0){ c++; }
        while (n % i == 0) n /= i;
        
        i++;
    }

    return c;
}


int main(void) {
    int n;

    fill_prime_list();

    while (scanf("%d", &n) && n) {
        printf("%d : %d\n", n, count_factors(n));

    }

    return 0;
}