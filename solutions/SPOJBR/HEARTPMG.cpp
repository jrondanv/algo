#include <stdio.h>
#include <string.h>
#include <vector>
#include <stdlib.h>
#include <algorithm>
using namespace std;

#define pop(x) __builtin_popcount(x)
#define ind(x) __builtin_ctz(x)
#ifndef ONLINE_JUDGE
#define getchar_unlocked() getchar()
#endif

int a,b,c, t;
char baloes[101];
int bal[101];

inline int read_int() {
    char c;
    while ((c=getchar_unlocked()) < 48 || c > 57);
    int p = c-48;
    while ((c=getchar_unlocked()) >= 48 && c <= 57) p=p*10+c-48;
    return p;
}

int pd[101][3][10];
int valor[3];

int main(){
    int teste=0;
    for (t=read_int(); t; t--) {
        valor[0]=read_int(); valor[1]=read_int(); valor[2]=read_int();
        
        gets(baloes);
        int num = 0;
        for (; baloes[num]!=0; num++) {
             bal[num]=baloes[num]-'a';
        }
        
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 10; j++) {
                pd[num][i][j]=0;
            }
        }
        for (int i = num-1; i >= 0; i--) {
            for (int tipo = 0; tipo < 3; tipo++) {
                int pot = 1;
                for (int mult = 0; mult < 10; mult++) {
                    if (tipo == bal[i]) {
                        pd[i][tipo][mult] = valor[tipo]*pot + pd[i+1][tipo][mult==9?mult:mult+1];
                    }
                    else {
                        pd[i][tipo][mult] = max(valor[bal[i]] + pd[i+1][bal[i]][1], pd[i+1][tipo][mult]);
                    }
                    
                    pot <<= 1;    
                }
            }
        }
        
        printf("%d\n",pd[0][0][0]);
    }
}

