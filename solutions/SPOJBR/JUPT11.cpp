#include <stdio.h>
#include <set>
#include <cstring>

#ifdef FFAO
#define getchar_unlocked getchar
#endif

char get_command() {
    char c;
    while ( (c=getchar_unlocked()) != 'E' && c != 'H');
    return c;
}

inline int read_int() {
    char c;
    while ((c=getchar_unlocked()) < 48 || c > 57);
    int p = c-48;
    while ((c=getchar_unlocked()) >= 48 && c <= 57) p=p*10+c-48;
    return p;
}

using namespace std;

int tree[100010];
int arr[100010];
long long inv[100010];
long long Bpow[100010];

long long B;
int P,L,N;

long long modpow(long long B, int ex, int P) {
    if (ex == 0) return 1;
    if (ex == 1) return B%P;

    long long temp = modpow(B,ex/2,P);
    temp = (temp * temp) % P;

    if (ex&1) temp = (temp*B) % P;

    return temp;
}

int read(int a) {
    int s = 0;
    while (a > 0) {
        s = (s + tree[a]) % P;
        a -= a&-a;
    }
    return s;
}

void update(int a, int delta) {
    while (a <= L) {
        tree[a] = (tree[a] + delta) % P;
        a += a&-a;
    }
}

int main() {
    while (B=read_int()) {
        P=read_int();
        L=read_int();
        N=read_int();

        long long tinv = modpow(B, P-2, P);

        inv[0] = 1;
        Bpow[0] = 1;
        for (int i = 1; i <= L; i++) {
            inv[i] = (inv[i-1]*tinv)%P;
            Bpow[i] = (Bpow[i-1]*B)%P;
        }

        memset(tree,0,sizeof(tree));
        memset(arr,0,sizeof(arr));

        for (int i = 0; i < N; i++) {
            char op = get_command();
            int a = read_int(), b = read_int();

            if (op == 'E') {
                update(a, (((Bpow[L-a] * (b - arr[a-1])) % P) + P) % P);
                arr[a-1] = b;
            }
            else {
                printf("%lld\n", (((( read(b) - read(a-1) ) * inv[L-b]) % P) + P) % P);
            }
        }
        printf("-\n");
    }   

}