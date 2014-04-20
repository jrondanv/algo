#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <cctype>

namespace IO
{
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

    while( !isdigit( c = read_char() ) );

    int r = c-'0';
    while( isdigit( c = read_char() ) ) r = 10*r + c - '0';

    return r;
}
}

using namespace IO;
using namespace std;

#define MAX 1440

struct tarefa {
    int pts;
    int inic;
    int fim;
};

char dias[5][5] = {"Seg", "Ter", "Qua", "Qui", "Sex"};

int pd[7][1500];

char dia[7];
int inic, fim;

int compara(tarefa a, tarefa b) {
    return a.fim < b.fim;
}

tarefa t[5][10010];

int main() {
    int N;
    while ((N=read_int()) && N) {
        memset(t,0,sizeof(t));
        memset(pd,0,sizeof(pd));
        
        for (int i = 0; i < 5; i++) t[i][0].pts = 1;
        
        for (int i = 0; i < N; i++) {
            int id, pts;
            id=read_int();
            pts=read_int();
            
            for (int i = 0; i < 3; i++) dia[i] = read_char();
            
            inic=read_int()*60+read_int();
            fim=read_int()*60+read_int();
            
            tarefa* p;
            
            for (int j = 0; j < 5; j++) {
                if (strcmp(dia, dias[j]) == 0) {
                    p = &t[j][t[j][0].pts++];
                    break;
                }
            }
            
            p->pts = pts;
            p->inic = inic;
            p->fim = fim;
        }
        
        int total = 0;
        
        for (int i = 0; i < 5; i++) {
            sort(&t[i][1], &t[i][t[i][0].pts], compara);
        
            int next = 1;
            for (int k = 0; k < 1440; k++) {
                if (k != 0) pd[i][k] = pd[i][k-1];
                while (next < t[i][0].pts && t[i][next].fim == k) {
                    pd[i][k] = max(pd[i][t[i][next].inic] + t[i][next].pts, pd[i][k]);
                    next++;
                }
            }
            
            total += pd[i][1439];
        }
        
        printf("Total de pontos: %d\n", total);
        for (int i = 0; i < 5; i++) {
            printf("%s: %d\n", dias[i], pd[i][1439]);
        }
    }
}




