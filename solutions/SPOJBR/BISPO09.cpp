#include <stdio.h>
#include <string.h>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int Q;

#ifdef FFAO
#define getchar_unlocked getchar
#endif

bool overflowByMultiplication(long long a, long long b) {
    long p = a*b;
    double q = .9*a*b;
    return q < 0? (p > q): (p < q);
}


inline int read_int() {
    char c;
    while ((c=getchar_unlocked()) < 48 || c > 57);
    int p = c-48;
    while ((c=getchar_unlocked()) >= 48 && c <= 57) p=p*10+c-48;
    return p;
}

int gcd(int a, int b) {
    return b?gcd(b,a%b):a;
}

long long L, W;
long long mdc;
long long mmc;
long long p1, p2;
long long n1, n2;

int x, y;

long long pos[4];

long long mulmod(long long a,long long b,long long c){
    long long p = a*b;
    double q = .9*a*b;
    if (p > q) return p%c;

    long long x = 0,y=a%c;
    while(b > 0){
        if(b%2 == 1){
            x = (x+y)%c;
        }
        y = (y*2)%c;
        b /= 2;
    }
    return x%c;
}

// retorna (d, a, b), onde d = ax + by.
struct bezout {int d, a, b;};
bezout extgcd(int x, int y){
    if(y==0) return (bezout){x, 1, 0};
    bezout s = extgcd(y, x%y);
    return (bezout){s.d, s.b, s.a-x/y*s.b};
}

long long crt(long long m1, long long m2) {
    if (m1 % mdc != m2 % mdc) return -1;
    long long r = m1 % mdc;

    long long q1 = m1 / mdc;
    long long q2 = m2 / mdc;
    
    long long tentative = mulmod(q2*n1,p1,mmc) + mulmod(q1*n2,p2,mmc);
    tentative = (tentative + r) % mmc;

    //long long tentative = ( q2*p1*n1 + q1*p2*n2 + r ) % mmc;
    //printf("tentative = %lld\n", tentative);
    if (tentative < 0) tentative += mmc;

    return tentative;
}

int main() {
    L=read_int();
    W=read_int();
    Q=read_int();

    n1 = 2*L-2;
    n2 = 2*W-2;
    bezout ans = extgcd(n1, n2);

    mdc = ans.d;
    p1 = ans.a;
    p2 = ans.b;
    mmc = n1*(n2/mdc);

    if (p1 < 0) p1 += mmc;
    if (p2 < 0) p2 += mmc;

    long long lim = (L-1)*(W-1)/gcd(L-1,W-1) + 1;

    for (int i = 0; i < Q; i++) {
        x = read_int();
        y = read_int();
        x--; y--;

        pos[0] = crt(x, y);
        pos[1] = crt(2*L-x-2, y);
        pos[2] = crt(x, 2*W-y-2);
        //printf("arguments to 3: %lld,%lld,%lld,%lld\n",2*L-x-3, 2*L-2, 2*W-y-3, 2*W-2 );
        pos[3] = crt(2*L-x-2, 2*W-y-2);

        sort(pos, pos+4);
        int correct = 4;

        for (int i = 0; i < 4; i++) {
            if (pos[i] == -1 || pos[i] >= lim || (i > 0 && pos[i] == pos[i-1])) correct--;
        }

        printf("%d", correct);
        for (int i = 0; i < 4; i++) {
            if (pos[i] == -1 || pos[i] >= lim || (i > 0 && pos[i] == pos[i-1])) continue;
            printf(" %lld", pos[i]+1);
        }
        printf("\n");
    }
}
