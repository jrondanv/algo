#include <stdio.h>
#include <string.h>
#include <vector>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    else return gcd(b, a%b);
}

int a,b,c,d;
int t;

int main(){
    for (scanf("%d", &t); t; t--) {
        scanf("%d %d %d %d",&a,&b,&c,&d);
        int da=abs(c-a);
        int db=abs(d-b);
        printf("%d\n",gcd(da,db)+1);
    }
}
