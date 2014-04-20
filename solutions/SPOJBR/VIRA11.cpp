#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

inline int read_int() {
    char c;
    while ((c=getchar_unlocked()) < 48 || c > 57);
    int p = c-48;
    while ((c=getchar_unlocked()) >= 48 && c <= 57) p=p*10+c-48;
    return p;
}

int N;
int arr[1010];
int v[1010]; 
int soma[2][1010];

int main() {
    N=read_int();
    char c;
    
    for (int i = 0; i < N; i++) {
        while ((c=getchar_unlocked())!='P' && c!='B');
        if (c=='P') arr[i]=1;
        else arr[i]=0;
    }
    
    for (int i = N-1; i >= 0; i--) {
        v[i] = arr[i]^v[i+1];
    } 
    
    soma[0][1]=v[0];
    int at = 1, prev = 0;

    for (int n = 1; n < N; n++) { 
        for (int x = 1; x <= n+1; x++) {
            int curr;
            if (v[n] == 1) curr = soma[prev][n]-soma[prev][x-1]+10007;
            else curr = soma[prev][x-1];
            soma[at][x] = (soma[at][x-1] + curr) % 10007;
        }
        swap(at,prev);
    }
    
    printf("%d\n", soma[prev][N]);
}

