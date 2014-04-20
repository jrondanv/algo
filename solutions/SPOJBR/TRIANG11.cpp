#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int K,x,y,d;

int lado[3];

// #define getchar_unlocked() getchar()

inline int read_int() {
    char c;
    while ((c=getchar_unlocked()) < 48 || c > 57);
    int p = c-48;
    while ((c=getchar_unlocked()) >= 48 && c <= 57) p=p*10+c-48;
    return p;
}

int main() {
    lado[0]=read_int();lado[1]=read_int();lado[2]=read_int();
    sort(lado,lado+3);
    
    int a=lado[0],b=lado[1],c=lado[2];
    
    if (c >= a+b) printf("n");
    else if(a*a+b*b > c*c) printf("a");
    else if (a*a+b*b==c*c) printf("r");
    else printf("o");
}

