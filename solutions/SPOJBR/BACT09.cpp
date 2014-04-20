#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <cmath>
using namespace std;

double arr[50000];
int n,a,b;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a, &b);
        arr[i]=b*log(a);
    }
    printf("%d\n",max_element(arr,arr+n)-arr);
} 
