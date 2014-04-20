#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

int n;
char s[2010];
int d[2010];

int main() {
    int t = 0;
    while (scanf("%d", &n) && n) {
        scanf("%s", s);

        vector<int> d1 (n);
        int l=0, r=-1;
        for (int i=0; i<n; ++i) {
        	int k = (i>r ? 0 : min (d1[l+r-i], r-i)) + 1;
        	while (i+k < n && i-k >= 0 && s[i+k] == s[i-k])  ++k;
        	d1[i] = --k;
        	if (i+k > r)
        		l = i-k,  r = i+k;
        }
        
        vector<int> d2 (n);
        l=0, r=-1;
        for (int i=0; i<n; ++i) {
        	int k = (i>r ? 0 : min (d2[l+r-i+1], r-i+1)) + 1;
        	while (i+k-1 < n && i-k >= 0 && s[i+k-1] == s[i-k])  ++k;
        	d2[i] = --k;
        	if (i+k-1 > r)
        		l = i-k,  r = i+k-1;
        }
        
        memset(d,0,sizeof(d));
        
        /*for (int i = 0; i < n; i++){
            printf("%d ", d1[i]);
        }
        printf("\n");
        for (int i = 0; i < n; i++){
            printf("%d ", d2[i]);
        }
        printf("\n");*/
        
        for (int i = n-1; i >= 0; i--) {
            d[i] = d[i+1]+1;
            for (int j = i+1; j < n; j++) {
                //if (j-i % 2 == 1) printf("i=%d j=%d testing %d d=%d\n",i,j,(i+j+1)/2,d2[(i+j+1)/2]);
                //else printf("i=%d j=%d testing %d d=%d\n",i,j,(i+j)/2,d1[(i+j)/2]);
                
                if ((j-i) % 2 == 1 && d2[(i+j+1)/2] >= (j-i+1)/2) d[i] = min(d[i], d[j+1]+1);
                else if ((j-i) % 2 == 0 && d1[(i+j)/2] >= (j-i)/2) d[i] = min(d[i], d[j+1]+1);
            }
        }
        
        printf("Teste %d\n",++t);
        printf("%d\n\n", d[0]);
    }
}
