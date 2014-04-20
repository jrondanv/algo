#include <stdio.h>
#include <algorithm>

using namespace std;

int att[11];
int def[11];

int main() {
	int A,D;
	
	while (scanf("%d %d", &A, &D) && A) {
		for (int i = 0; i < A; i++) {
		    scanf("%d", att+i);
        }
        for (int i = 0; i < D; i++) {
            scanf("%d", def+i);
        }
        
        sort(att, att+A);
        sort(def, def+D);
        
        int atac = att[0];
        if (atac < def[1]) printf("Y\n");
        else printf("N\n");
	}
	return 0;
}
