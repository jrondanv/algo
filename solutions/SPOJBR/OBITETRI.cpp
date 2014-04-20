#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

struct jogador {
	char nome[20];
	int p;
	bool operator<(jogador ot) const {
		if (p == ot.p) return strcmp(nome, ot.nome) < 0;
		return p > ot.p;
	}
};

int main() {
	int teste = 0;
	int N;
	
	while (scanf("%d", &N) && N != 0) {
		jogador j[N];
		
		int i;
		for (i=0; i<N; i++) {
			scanf("%s", j[i].nome);
			
			int p[12];
			int jo;
			for (jo=0; jo<12; jo++) {
				scanf("%d", p+jo);
			}
			
			sort(p, p+12);
			
			int pt = 0;
			for (jo=1; jo<11; jo++) pt += p[jo];
			
			j[i].p = pt;
		}
		
		sort(j, j+N);
		
		int coloc = 0;
		int lv = -1;
		printf("Teste %d\n", ++teste);
		for (i=0; i<N; i++) {
			if (j[i].p != lv) {
				coloc = i+1; 
				lv = j[i].p;
			}
			
			printf("%d %d %s\n", coloc, j[i].p, j[i].nome);
		}
		printf("\n");
	}
	
	return 0;
}