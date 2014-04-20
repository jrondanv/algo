#include <stdio.h>
#include <string.h>

char nome[21];
int score;

int main(void) {
    int m, n, i;
    int teste = 1;
    
    int w_score = 999999;
    char w_name[21];

    while (scanf("%d", &n)!=EOF) {
        for (i = 0; i < n; i++) {
            scanf("%s %d", nome, &score);

            if (score < w_score || (score == w_score && strcmp(nome, w_name) > 0)) {
                strcpy(w_name, nome);
                w_score = score;
            }
        }
        
        printf("Instancia %d\n", teste++);
        printf("%s\n", w_name);
        printf("\n");
    }
}
