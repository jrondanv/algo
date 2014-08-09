//Problem Name : 171B - Star
//Execution Time : 30 ms
//Memory : 1400 KB
#include <stdio.h>

int a;
int main() {
    scanf("%d", &a);
    int start = 1;
    int inc = 12;
    for (int i = 1; i < a; i++) {
        start += inc;
        inc += 12;
    }
    printf("%d\n",start);
}
