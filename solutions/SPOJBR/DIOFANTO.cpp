#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int memo[1300031];

const int py = 1300031;

int inv(const int px) {
    if (memo[px]) return memo[px];
    
    int x = px;
	int y = py;
	
	//Setup initial variables
	//Maintain throughout that ax * px + bx * py = x and that ay * px + by * py = y
	int ax = 1;
	int ay = 0;
	int bx = 0;
	int by = 1;
	
	//Perform extended gcd
	while(x)
	{
		if(x <= y)
		{
			int m = y / x;
			y -= m * x;
			ay -= ax * m;
			by -= bx * m;
		}
		else
		{
			swap(x, y);
			swap(ax, ay);
			swap(bx, by);
		}
	}
	
	//you can assert that ay * px + by * py = y = gcd(px, py)
	//you can assert that ax * px + bx * py = x = 0
	
	//If we're taking the modular inverse of px (mod py), then for it to exist gcd(px, py) = 1
	//If it does exist, it is given by ay (mod py)
	int inverse = ay % py;
	if(inverse < 0) inverse += py;

    memo[px] = inverse;
    memo[inverse] = px;
    
    return inverse;
}

long long binom(int n, int k) {
    long long result = 1;    
    int lim = min(k,n-k);
    for (int i = 1; i <= lim; i++){
        result *= n-i+1;
        result *= inv(i);
        result = result % 1300031;
    }
    return result;
}

int main() {
    int T;
    scanf("%d", &T);
    
    memset(memo,0,sizeof(memo));
    for (int t = 0; t < T; t++) {
        int a,b;
        scanf("%d %d", &a, &b);
        
        printf("%lld\n", binom(a+b-1,b));
    }
    
    return 0;
}

