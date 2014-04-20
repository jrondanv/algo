#include <stdio.h>
#include <stdlib.h>
#include <set>
#include <vector>
#include <cctype>

using namespace std;

int resp;
int a;
int N, M;
int op;

const int SIZE = 1 << 19;
char buff[SIZE], *p = buff + SIZE;

char read_char()
{
    if( p == buff + SIZE )
    {
        fread( buff, 1, SIZE, stdin );
        p = buff;
    }
    return *(p++);
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

#define MAX 1010
int pa[MAX], rank[MAX];

// Inicializa um set x
void make_set(int x) {
   pa[x] = x;
    rank[x] = 0;
}

void link(int x,int y) {
    if (rank[x] > rank[y])
         pa[y] = x;
     else {
         pa[x] = y;
         if (rank[x] == rank[y])
             rank[y] = rank[y] + 1;
     }
}

// Find the set ID of item x
int find_set(int x) {
    if (x != pa[x])
        pa[x] = find_set(pa[x]);
   return pa[x];
}

// Union two set containing item x and item y
void union_set(int x,int y) {
    link (find_set(x), find_set(y));
}

int main() {
    N=read_int(); M=read_int();
    for (int i = 1; i <= N; i++) make_set(i);
    
    for (int i = 0; i < M; i++) {
        int a=read_int(), b=read_int();
        union_set(a,b);
    }
    
    for (int i = 1; i <= N; i++) {
        resp += pa[i]==i;
    }
    printf("%d\n",resp);
}

