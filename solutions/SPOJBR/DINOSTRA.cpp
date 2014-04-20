#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <functional>

using namespace std;

int n;
int pri[1000], s[1025];
int tam;

void sieve(int n) {
    for (int i = 2; i <= n; i++) {
        if (!s[i]) {
            pri[tam++]=i;
            for (int j = i*i; j<=n; j+=i) s[j]=1;
        }
    }
}

bool dino(int n) {
    int pr = 0;
    int exp = 0;
    int exp2 = 0;
    for (int i = 0; i < tam && pri[i]*pri[i] <= n; i++) {
        //printf("testing %d %% %d\n",n,pri[i]);
        if (n % pri[i] == 0) {
            //printf("divisible by %d\n",pri[i]);
            int k = 0;
            while (n % pri[i] == 0) {
                n /= pri[i];
                k++;
            }
            if (k > exp) exp = k;
            else exp2 = max(exp2,k);
            pr++;
        }
    }
    
    if (n != 1) pr++;
    //printf("pr=%d exp=%d %d\n",pr,exp,exp2);
    if (pr >= 4) return true;
    if (pr == 1 && exp >= 8) return true;
    if (pr == 3 && exp >= 2) return true;
    
    if (pr == 2) {
        if (exp >= 5) return true;
        else if (exp >= 2 && exp2 >= 2) return true;
    }
    
    return false;
}

int main() {
	sieve(1024);
	int teste=1;
	while (scanf("%d", &n)>0) {
        printf("Instancia %d\n", teste++);
        if (dino(n)) printf("sim\n");
        else printf("nao\n");
        printf("\n");
    }
}
