#include <stdio.h>
#include <ctype.h>

int main() {
	char fl;
	
	while (1) {
		int tauto = 1;
		fl=getchar();
		
		if (fl == '*') break;
		fl = tolower(fl);
		
		char c = 'a';
		while (c != ' ' && c != '\n') {
			c=getchar();
		}
		
		if (c == '\n') {
			if (tauto) printf("Y\n");
			else printf("N\n");
			continue;
		}
		
		while (1) {
			c=getchar();
		
			if (tolower(c) != fl) tauto = 0;
		
			c = 'a';
			while (c != ' ' && c != '\n') {
				c=getchar();
			}
		
			if (c == '\n') {
				if (tauto) printf("Y\n");
				else printf("N\n");
				break;
			}
		}
	}
	
	return 0;
}