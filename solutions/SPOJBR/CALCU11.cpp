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

int ans[2][4];

int main() {
    resp=1;
    for (N=read_int(); N; N--) {
        a=*p;
        op=(*(p+=2))&1;
            switch (a) {
                case 56: ans[op][0]++;
                case 52: ans[op][0]++;
                case 50: ans[op][0]++;break;
                case 57: ans[op][1]++;
                case 51: ans[op][1]++;break;
                case 53: ans[op][2]++;break;
                case 55: ans[op][3]++;break;
                case 54: ans[op][0]++; ans[op][1]++; break;
            }
        p+=2;
    }
    for (int i = 0; i < 4; i++) ans[0][i]-=ans[1][i];
    for (int i = 0; i < ans[0][0]; i++) resp <<= 1;
    for (int i = 0; i < ans[0][1]; i++) resp *= 3;
    for (int i = 0; i < ans[0][2]; i++) resp *= 5;
    for (int i = 0; i < ans[0][3]; i++) resp *= 7;
    printf("%d", resp);
}

