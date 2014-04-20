#include <stdio.h>
#include <stdlib.h>
#include <set>
#include <vector>
#include <cctype>

using namespace std;

int resp;
int a;
int N;
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

int mapa[100][100];

int main() {
    N=read_int();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            mapa[i][j]=read_int();
        }
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ",mapa[i][j]+read_int());
        }
        printf("\n");
    }
}
