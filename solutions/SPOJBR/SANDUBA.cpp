#include <stdio.h>
#include <cstring>
#include <map>
#include <algorithm>
#include <cctype>

using namespace std;

#define MOD 1300031

int T, N;
int g[120][120];

int arr[100010];

int main(){
	for (scanf("%d", &T); T; T--) {
        scanf("%d", &N);
        long long soma = 0;
        int res = 0;
        
        for (int i = 1; i <= N; i++) scanf("%d", &arr[i]);
        
        for (int i = N; i >= 1; i--) {
            soma = (soma+arr[i]) % MOD;
            res = (res + ((soma*arr[i])%MOD))%MOD;
        }
        
        printf("%d\n",res);
    }
}




