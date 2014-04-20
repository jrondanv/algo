#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <cmath>
using namespace std;

int arr[1010];
int n,a,b,k;

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        arr[a-1]++;
    }
    
    printf("%d\n",*min_element(arr,arr+k));
} 
