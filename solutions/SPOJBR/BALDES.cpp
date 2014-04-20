#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

#include <stdio.h>

int numbers[200000];
int aux[200000];

typedef unsigned long long ull;

ull mcount(int* arr, int e, int d, int* aux) {
	int i = e;
	int j = (e+d)/2 + 1;
	int k = 0;
	
	ull invcnt = 0;
	
	while (i <= (e+d)/2 && j <= d) {
		if (arr[i] <= arr[j]) {
			aux[k] = arr[i];
			i++;
		}
		
		else if (arr[j] < arr[i]) {
			invcnt += (e+d)/2 - i + 1;
			aux[k] = arr[j];
			j++;
		}
		
		k++;
	}
	
	while (i <= (e+d)/2) {
		aux[k] = arr[i];
		i++;
		k++;
	}
	
	while (j <= d) {
		aux[k] = arr[j];
		j++;
		k++;
	}
	
	for (i=0; i<k; i++) {
		arr[i+e] = aux[i];
	}
	
	return invcnt;
}

ull msort(int* arr, int e, int d, int* aux) {
	if (e == d) return 0;
	
	int m = (e+d)/2;
	
	ull invs = msort(arr, e, m, aux) +
			   msort(arr, m+1, d, aux);
			   
	return invs + mcount(arr, e, d, aux);
}

int main() {
    int n;
	while (scanf("%d", &n) && n) {
		int j;
		for (j = 0; j < n; j++) {
			scanf("%d", numbers+j);
		}
		
		ull cnt = msort(numbers, 0, n-1, aux);
		
		if (cnt & 1) printf("Marcelo\n");
		else printf("Carlos\n");
	}
}
