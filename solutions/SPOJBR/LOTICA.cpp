#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std;

int N;

int pr;

int main() {
    while (scanf("%d", &N) && N) {
        for (int i = 0; i < N; i++) {
            pr = -1;
            int d;
            for (int j = 0; j < 5; j++) {
                scanf("%d", &d);
                if (d <= 127) {
                    if (pr == -1) pr = j;
                    else pr = -2;
                }
            }
            
            if (pr < 0) printf("*\n");
            else printf("%c\n",pr+'A');
        }
    }
}
