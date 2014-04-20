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

int main() {
    scanf("%d", &N);
    //scanf("%d %d", &N, &M);
    int prev = 0, pd=10000001, curr;
    for (int i = 0; i < N; i++) {
        scanf("%d", &curr);
        if (curr-prev != pd) {
            if (pd == 10000000) pd = curr-prev;
            else {
                resp++;
                pd = 10000000;
            }
        }
        prev=curr;
    }
    
    printf("%d\n",resp);
}
