#include <stdio.h>
#include <stdlib.h>
#include <set>
#include <vector>
#include <cmath>

using namespace std;
int N,l;
char out[101];

#define getchar_unlocked() getchar()

inline int scan(int& r) {
    int c;
    while ((c=getchar_unlocked())<48||c>57);
    r = c-48;
    while ((c=getchar_unlocked())>=48&&c<=57)r=r*10+c-48;
}

int mine[50];

int main() {
    scan(N);
    for (int i = 0; i < N; i++) {
        int ind = 2*i;
        out[ind+1]='\n';
        l=getchar_unlocked();
        getchar_unlocked();
        out[ind]+=l-96;
        if (i==0||i==N-1) out[ind] += 48;
        out[ind-2]+=l;
        out[ind+2]+=l;
    }  
    out[2*N]='\0'; 
    printf("%s",out);
    //fwrite(out,1,2*N,stdout);
}
