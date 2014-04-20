#include <stdio.h>

int main() {
	while (1) {
		char c = getchar();
		if (c == '*') break;
		
		int validos = 0;
		int tot = 0;
		
		while (1) {
			c = getchar();
			switch (c) {
				case 'W': tot += 64; break;
				case 'H': tot += 32; break;
				case 'Q': tot += 16; break;
				case 'E': tot += 8; break;
				case 'S': tot += 4; break;
				case 'T': tot += 2; break;
				case 'X': tot += 1; break;
			}
			
			if (c == '/') {
				if (tot == 64) validos++;
				tot = 0;
			}
			
			if (c == '\n') {
				printf("%d\n", validos);
				break;
			}
		}
	}
	
	return 0;
}