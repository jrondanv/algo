#include <stdio.h>
#include <stdlib.h>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int resp;
int a;
long long N, M;
int op;

const int SIZE = 1 << 19;
char buff[SIZE], *ps = buff + SIZE;

char read_char()
{
    if( ps == buff + SIZE )
    {
        fread( buff, 1, SIZE, stdin );
        ps = buff;
    }
    return *(ps++);
}

inline int read_int()
{
    char c;

    while((c = read_char())<48 || c>57 );

    int r = c-'0';
    while( (c = read_char())>=48 && c<=57) {
        r = 10*r + c - '0';
    }

    return r;
}

int main() {
    scanf("%lld", &N);
    for (long long i = 2; i*i <= N; i++) {
        if (N%i == 0) {
            printf("S\n");
            return 0;
        }
    }
    
    printf("N");
}
