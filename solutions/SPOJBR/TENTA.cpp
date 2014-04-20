#include <stdio.h>
#include <algorithm>

int n;

int next_perm(int* arr) {
	int max = -1;
	
	int i;
	for (i=0; i<n-1; i++) {
		if (arr[i] < arr[i+1]) max = i;
	}
	
	if (max == -1) return -1;
	
	int l;
	for (i=max+1; i<n; i++) {
		if (arr[max] < arr[i]) l=i;
	}
	
	int temp = arr[max];
	arr[max] = arr[l];
	arr[l] = temp;
	
	for (i=max+1; i<(max+1+n)/2; i++) {
		temp = arr[i];
		arr[i] = arr[n+max-i];
		arr[n+max-i] = temp;
	}
}

int main() {
	int arr[8];
	
	while (1) {
		scanf("%d", &n);
		if (n == 0) break;
		
		int i;
		for (i=0; i<n; i++) {
			scanf("%d", arr+i);
		}
		
		std::sort(arr, arr+n);
		
		while (1) {
			for (i=0; i<n; i++) {
				printf("%d ", arr[i]);
			}
			printf("\n");
		
			if (next_perm(arr) == -1) break;
		}
		printf("\n");
	}
}