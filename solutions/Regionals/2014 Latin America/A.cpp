#include <stdio.h>

int arr[10][10];

int main() {
	while (true) {
		for (int k = 0; k < 2; k++) {
			for (int i = 0; i < 5; i++) {
				if (scanf("%d", &arr[k][i]) == EOF) return 0;
			}
		}
		
		bool ok = true;
		for (int i = 0; i < 5; i++) {
			if (arr[0][i] ^ arr[1][i] == 0) ok = false;
		}
		
		printf("%c\n", ok ? 'Y' : 'N');
	}
}
