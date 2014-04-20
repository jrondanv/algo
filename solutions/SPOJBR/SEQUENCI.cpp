#include <stdio.h>
#include <cstring>
#include <map>
#include <algorithm>
#include <cctype>

using namespace std;

int N;
int ehsoma[1001];

int main(){
    int teste=1;
	while (scanf("%d", &N) > 0 && N) {
        memset(ehsoma,0,sizeof(ehsoma));
        
        printf("Case #%d:", teste++);
        
        bool ok = true;
        int ele;
        int prev = 0;
        for (int i = 0; i < N; i++) {
            scanf("%d", &ele);
            printf(" %d", ele); 
            
            if (ehsoma[ele]) ok = false;
            if (ele <= prev) ok = false;
            
            prev = ele;
            
            for (int i = 1000; i >= 1+ele; i--) {
                if (ehsoma[i-ele]) ehsoma[i]=1;
            }
            ehsoma[ele]=1;
        }
        
        if (!ok) printf("\nThis is not an A-sequence.\n");
        else printf("\nThis is an A-sequence.\n");
    }
}



