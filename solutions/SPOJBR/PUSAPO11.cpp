#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int M,x,d;

int lado[3];

 #define getchar_unlocked() getchar()

inline int read_int() {
    char c;
    while ((c=getchar_unlocked()) < 48 || c > 57);
    int p = c-48;
    while ((c=getchar_unlocked()) >= 48 && c <= 57) p=p*10+c-48;
    return p;
}

int pedra[100];

int main() {
    N=read_int(); M=read_int();
    
    for (int i = 0; i < M; i++) {
        x=read_int(); d=read_int();
        x--;
        int st = x%d;
        for (int st = x%d; st < N; st+=d) pedra[st]=1;  
    }
    
    for (int i = 0; i < N; i++) printf("%d\n",pedra[i]);
}

