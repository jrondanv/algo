#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

int n;
int arr[1100];

int main() {
	while (scanf("%d", &n) > 0) {
		for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
		std::sort(arr, arr+n);

		int ans1 = 0, ans2 = 0;
		for (int i = 0; i < n; i += 2) {
			ans1 += std::min(abs(arr[i+1]-arr[i]), 24 - abs(arr[i+1]-arr[i]));
		} 
		for (int i = 1; i < n-1; i += 2) {
			ans2 += std::min(abs(arr[i+1]-arr[i]), 24 - abs(arr[i+1] - arr[i]));
		}
		ans2 += std::min(abs(arr[0]-arr[n-1]), 24 - abs(arr[0] - arr[n-1]));

		printf("%d\n", std::min(ans1,ans2));
	}
}