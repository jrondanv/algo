#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <map>

using namespace std;

int arm[100000];
int N,M;

int main() {
    string a,b;
    while (scanf("%d %d",&N, &M) && N) {
        
        for (int i = 0; i < M; i++) {
            scanf("%d", &arm[i]);
        }
        
        int best = 0;
        int l=0, r=0;
        
        while (r != M-1) {
            while (arm[r]-arm[l]<N && r != M-1) {
                best = max(best,r-l+1);
                r++;
            }
            
            while (arm[r]-arm[l] >= N) {
                l++;
            }   
        }
        
        best = max(best,r-l+1);
        
        printf("%d\n", N-best);
    }
}
