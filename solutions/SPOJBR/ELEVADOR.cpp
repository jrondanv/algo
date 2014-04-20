#include <stdio.h>
#include <string.h>
#include <vector>
#include <map> 
#include <algorithm>
#include <string>
#include <stack>
#include <math.h>
#include <sstream>
  
using namespace std;
 
int l,c,r1,r2;

bool testa(int x, int y) {
    return (x-r1)*(x-r1) + (y-r1)*(y-r1) >= (r1+r2)*(r1+r2);
}

int main() {
    while (scanf("%d %d %d %d", &l, &c, &r1, &r2) && l) {
        bool ok = false;
        if (min(l,c) >= 2*max(r1,r2)) {
            ok |= testa(r2,c-r2);
            ok |= testa(l-r2,r2);
            ok |= testa(l-r2,c-r2);
        }
        if (ok) printf("S\n");
        else printf("N\n");
    }
}