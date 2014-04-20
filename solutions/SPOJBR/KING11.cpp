#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
 
const int INF = 1000001000;

int n, m, ga;
int a, b, t;
int k, mana, pt, v, hp;

int op,id,tam;

int h[3];

int main() {
    while (scanf("%d %d %d", &h[0], &h[1], &h[2]) && h[0]) {
    	sort(h,h+3);

    	if (h[0] == h[1] && h[1] == h[2] && h[0] == h[2]) {
    		if (h[0] == 13) printf("*\n");
    		else printf("%d %d %d\n", h[0]+1, h[0]+1,h[0]+1);
    	}

    	else if (h[0] != h[1] && h[1] != h[2]) {
    		printf("1 1 2\n");
    	}

    	else if (h[1] == h[2]) {
    		swap(h[2], h[0]);
    	}

    	if (h[0] == h[1] && h[1] != h[2]) {
    		int p[3];
    		p[0] = h[0]; p[1] = h[1]; p[2] = h[2]+1;

    		if (p[2] == p[0]) p[2]++;

    		if (p[2] == 14) {
    			p[0]++; p[1]++; p[2] = 1;
    		}

    		if (p[0] == 14) {
    			p[0]=p[1]=p[2]=1;
    		}
    		
    		sort(p, p+3);
    		printf("%d %d %d\n", p[0], p[1], p[2]);
    	}
    }
}