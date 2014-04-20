#include <stdio.h>
#include <string.h>


char entrada[100000];
char prog[100000];

int loop_end[100000];
int loop_begin[100000];
int vet[30000];

int fila[100000];
int fim;

int main() {
    int T,t;
    scanf("%d", &T);
    for (t = 1; t <= T; t++) {
        int i,j;
        
        fim=0;
        memset(vet,0,sizeof(vet));
        
        scanf(" %s", entrada);
        scanf(" %s", prog);
        
        printf("Instancia %d\n", t);
        
        int len = strlen(prog);
        char* ent = entrada;
        int* ponteiro = vet;
        
        for (i = 0; i < len; i++) {
            if (prog[i] == '[') fila[fim++]=i;
            else if (prog[i] == ']') {
                loop_end[fila[fim-1]] = i;
                loop_begin[i] = fila[fim-1];
                fim--;
            }
        }
        
        i = 0;
        while (i < len) {
            //printf("i = %d, char = %c, pont = %d, v[pont] = %d\n",i,prog[i],ponteiro,vet[ponteiro]);
            switch (prog[i]) {
                case '+': (*ponteiro)++; break;
                case '-': (*ponteiro)--; break;
                case '>': ponteiro++; break;
                case '<': ponteiro--; break;
                case '.': putchar(*ponteiro); break;
                case ',': 
                    *ponteiro = *ent;
                    if (*ent != '\0') ent++;
                    break;
                case '[':
                    if (*ponteiro == 0) i = loop_end[i];
                    break;
                case ']':
                    i = loop_begin[i]-1;
                    break;
                case '#':
                    for (j = 0; j < 10; j++) putchar(vet[j]);
                    break;
            }
            i++;
        }  
        
        printf("\n\n");  
    }
    
    return 0;
}
                
        
        
