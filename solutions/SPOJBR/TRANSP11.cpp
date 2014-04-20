#include <stdio.h>
#include <stdlib.h>
#include <set>
#include <vector>
#include <cmath>

using namespace std;

int a,b,c,x,y,z;

int main() {
    scanf("%d %d %d %d %d %d", &a, &b, &c, &x, &y, &z);
    printf("%d\n", (x/a)*(y/b)*(z/c));
}
