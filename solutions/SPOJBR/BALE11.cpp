#include <stdio.h>
#include <stdlib.h>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int resp;
int a;
int N, M;
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

int tree[100001];

int read(int x) {
    int r = 0;
    while (x > 0) {
        r+=tree[x];
        x -= x&-x;
    }
    return r;
}
int upd(int x) {
    while (x <= 100000) { 
        tree[x]++;
        x += x&-x;
    }
}

int main() {
    N=read_int();
    //scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        a=100001-read_int();
        resp += read(a);
        upd(a);
    }
    
    printf("%d\n",resp);
}
