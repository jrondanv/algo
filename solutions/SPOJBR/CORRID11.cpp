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

struct c {
    int tmp;
    int id;
    bool operator< (const c& ot) {
        return tmp<ot.tmp;
    }
} t[1001];

int main() {
    N=read_int(); M=read_int();
    //scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        t[i].id=i+1;
        for (int j = 0; j < M; j++) t[i].tmp+=read_int();
    }
    
    printf("%d\n",min_element(t,t+N)->id);
}


