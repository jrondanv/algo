#include <stdio.h>

int main() {
	int ano;
	scanf("%d", &ano);
	
	printf("%d\n", (ano-10)/76 * 76 + 86);
}